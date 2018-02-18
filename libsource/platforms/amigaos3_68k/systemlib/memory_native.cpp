///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/amigaos3_68k/systemlib/cpu_native.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  CPU control and query
//  Comment(s):
//  Library:      System
//  Created:      2006-10-08
//  Updated:      2006-10-08
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill, Serkan YAZICI
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <xbase.hpp>
#include <systemlib/memory.hpp>
#include <systemlib/logger.hpp>
#include <private/systemlib/error.hpp>

using namespace OSNative;
using namespace EXNGPrivate;

struct Mem::MemInfo {
	uint32				identifier;
	uint32				flags;
	size_t				size;
	size_t				userSize;
	Mem::MemInfo*	prev;
	Mem::MemInfo*	next;
	void*					baseAddress;
	uint32				pad;
};

size_t						Mem::puddleSize			= 4096;
size_t						Mem::threshSize			= 0;
uint32						Mem::memIdentifier	= ('X'<<24)|('R'<<16)|('M'<<8)|('A');
uint32						Mem::numAlloc				= 0;
uint32						Mem::peakAlloc			= 0;
uint32						Mem::totSize				= 0;
uint32						Mem::peakSize				= 0;
uint32						Mem::totRequested		= 0;
uint32						Mem::peakRequested	= 0;
Mem::MemInfo*			Mem::head						= 0;
void*							Mem::memPool				= 0;
SignalSemaphore*	Mem::poolSemaphore	= 0;

LOGGING_DECLARE_CLASSNAME(Mem)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Mem::init()
{
	LOGGING_DECLARE_FUNCNAME(init)

	puddleSize = Application::getArgInteger("-amigapuddlesize", puddleSize, 0);
	if (puddleSize<2048 || puddleSize>65536) {
		throwRangeError();
	}
	threshSize = puddleSize - 4*Mem::ALIGN_CACHE;
	if (!(poolSemaphore = (SignalSemaphore*)AllocMem(sizeof(SignalSemaphore), MEMF_PUBLIC))) {
		throwResourceExhausted("memory [semaphore]");
	}
	if (!(memPool = CreatePool(MEMF_PUBLIC, puddleSize, threshSize))) {
		throwResourceExhausted("memory [pool]");
	}
	InitSemaphore(poolSemaphore);

	#ifdef EXNG2_BUILD_LOGGED
	SystemLog::write(SystemLog::INFO, "%s::%s - OK [puddle: %d, threshold %d]\n", loggingClassName, loggingFuncName, puddleSize, threshSize);
	#endif
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Mem::done()
{
	LOGGING_DECLARE_FUNCNAME(done)

	if (memPool) {
		#ifdef EXNG2_BUILD_LOGGED
		if (numAlloc>0) {
			SystemLog::write(SystemLog::WARNING, "%s::%s - %lu unfreed chunks, totalling %lu bytes\n", loggingClassName, loggingFuncName, numAlloc, totSize);
			debug();
		}
		#endif
		DeletePool(memPool);
		memPool = 0;
	}
	if (poolSemaphore) {
		FreeMem(poolSemaphore, sizeof(SignalSemaphore));
		poolSemaphore = 0;
	}

	#ifdef EXNG2_BUILD_LOGGED
	SystemLog::write(SystemLog::INFO, "%s::%s - OK\n", loggingClassName, loggingFuncName);
	#endif
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void* Mem::alloc(size_t size, bool zero=false, AlignType align=ALIGN_DEFAULT)
{
	LOGGING_DECLARE_FUNCNAME(alloc)

	// we ignore the alignment and just go for cache aligned stuff for 680x0
	uint32 alignLen = ALIGN_CACHE;
	uint32 allocSize = size + sizeof(MemInfo) + (alignLen<<1);

	// the allocator does some low level pointer stuff which I'd rather not do but
	// as long as the user obeys the "never free whatever you didn't allocate" things
	// should be ok.

	ObtainSemaphore(poolSemaphore); // lock the memory list
	void* block 	= AllocPooled(memPool, allocSize);
	void*	result	= 0;
	if (block) {
		uint32		mask		= alignLen-1;
		MemInfo*	info		= (MemInfo*)((mask+(uint32)block) & ~mask); // this is aligned
		info->identifier	= memIdentifier;
		info->flags				= 0;
		info->size				= allocSize;
		info->userSize		= size;
		info->baseAddress	= block;
		result						= (((uint8*)info)+sizeof(MemInfo));

		if ((++numAlloc) > peakAlloc) {
			peakAlloc = numAlloc;
		}

		totSize += allocSize;
		if (totSize > peakSize) {
			peakSize = totSize;
		}
		totRequested += size;
		if (totRequested > peakRequested) {
			peakRequested = totRequested;
		}

		if (!head) {
			info->prev = 0;
			info->next = 0;
			head = info;
		}
		else {
			info->next = head;
			info->prev = 0;
			head->prev = info;
			head = info;
		}

		#ifdef EXNG2_BUILD_LOGGED
		SystemLog::write(SystemLog::INFO, "%s::%s - requested %lu bytes, allocated %lu at 0x%08X, info at 0x%08X\n", loggingClassName, loggingFuncName, size, allocSize, (unsigned)block, (unsigned)info);
		#endif
	}
	ReleaseSemaphore(poolSemaphore);
	if (result) {
		if (zero) {
			Mem::zero(result, size);
		}
	} else {
		throwResourceExhausted("memory [alloc]");
	}
	return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Mem::free(void* ptr)
{
	LOGGING_DECLARE_FUNCNAME(free)

	if (!ptr || !memPool) {
		return;
	}

	// the allocator does some low level pointer stuff which I'd rather not do but
	// as long as the user obeys the "never free whatever you didn't allocate" things
	// should be ok.

	MemInfo* info = (MemInfo*)(((uint32)ptr)-sizeof(MemInfo));
	if (info->identifier == memIdentifier) {
		ObtainSemaphore(poolSemaphore);
		info->identifier = 0;

		#ifdef EXNG2_BUILD_PARANOID
		void* addr	= info->baseAddress;
		size_t size	= info->size;
		size_t user = info->userSize;
		#endif

		if (info==head) {
			if (info->next) {
				head = info->next;
				head->prev = 0;
			} else {
				head = 0;
			}
		}
		else {
			if (info->next) {
				info->next->prev = info->prev;
			}
			if (info->prev) {
				info->prev->next = info->next;
			}
		}

		totSize -= info->size;
		totRequested -= info->userSize;

		FreePooled(memPool, info->baseAddress, info->size);
		ReleaseSemaphore(poolSemaphore);

		numAlloc--;

	#ifdef EXNG2_BUILD_LOGGED
		SystemLog::write(SystemLog::INFO, "%s::%s - freed %lu [%lu] bytes, allocated at 0x%08X\n", loggingClassName, loggingFuncName, size, user, (unsigned)addr);
	}
	else {
		SystemLog::write(SystemLog::WARNING, "%s::%s - attempt to free unknown allocation at 0x%08X\n", loggingClassName, loggingFuncName, (unsigned)ptr);
	#endif
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Mem::debug()
{
	MemInfo* pMI;
	SystemLog::lock();
	ObtainSemaphore(poolSemaphore);
	SystemLog::printf(SystemLog::INFO, "Mem::debug() - chunk list, %lu chunks totalling %lu bytes\n", numAlloc, totSize);
	for (pMI = head; pMI; pMI = pMI->next) {
		SystemLog::printf(SystemLog::INFO, "%lu [%lu] bytes allocated at 0x%08X\n", pMI->size, pMI->userSize, pMI->baseAddress);
	}
	ReleaseSemaphore(poolSemaphore);
	SystemLog::unlock();
}
