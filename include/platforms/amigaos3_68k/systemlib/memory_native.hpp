///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/amigaos3_68k/systemlib/memory.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Allocator and high performance copy/set routines
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


#ifndef _EXNG2_SYSTEMLIB_MEMORY_NATIVE_HPP_
#	define _EXNG2_SYSTEMLIB_MEMORY_NATIVE_HPP_

#	include "platforms/amigaos3_68k/systemlib/logger_native.hpp"


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Mem
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Mem : private SystemLog {
	public:
		typedef enum {
			ALIGN_DEFAULT	= 0,
			ALIGN_16			= 2,
			ALIGN_32			= 4,
			ALIGN_64			= 8,
			ALIGN_CACHE		= 16
		} AlignType;

		static void*	alloc(size_t size, bool zero=false, AlignType align=ALIGN_DEFAULT);
		static void		free(void* p);
		static void		copy(void* dst, const void* src, size_t len);
		static void		swap16(void* dst, const void* src, size_t num);
		static void		swap32(void* dst, const void* src, size_t num);
		static void		swap64(void* dst, const void* src, size_t num);
		static void		zero(void* dst, size_t len);
		static void		set(void* dst, int val, size_t len);
		static void		set16(void* dst, uint16 val, size_t num);
		static void		set32(void* dst, uint32 val, size_t num);
		static void		set64(void* dst, const uint64& val, size_t num);

		static uint32 getNumAllocations();
		static uint32 getPeakAllocations();
		static uint32 getTotalSize();
		static uint32 getPeakSize();
		static uint32 getTotalRequestedSize();
		static uint32 getPeakRequestedSize();

		static void		debug();

	private:
		static void		init();
		static void		done();

		// data

		struct MemInfo;

		static uint32 	memIdentifier;
		static size_t		puddleSize;
		static size_t		threshSize;
		static uint32		numAlloc;
		static uint32		peakAlloc;
		static uint32		totSize;
		static uint32		peakSize;
		static uint32		totRequested;
		static uint32		peakRequested;
		static MemInfo*	head;
		static void*		memPool;
		static OSNative::SignalSemaphore* poolSemaphore;

		friend class	Startup;

		LOGGING_DEFINE_CLASSNAME
};


////////////////////////////////////////////////////////////////////////////////

inline uint32 Mem::getNumAllocations()
{
	return numAlloc;
}

inline uint32 Mem::getPeakAllocations()
{
	return peakAlloc;
}

inline uint32 Mem::getTotalSize()
{
	return totSize;
}

inline uint32 Mem::getPeakSize()
{
	return peakSize;
}

inline uint32 Mem::getTotalRequestedSize()
{
	return totRequested;
}

inline uint32 Mem::getPeakRequestedSize()
{
	return peakRequested;
}

////////////////////////////////////////////////////////////////////////////////

inline void Mem::copy(void* dst, const void* src, size_t len)
{
	asm(
		"\n/*************************************/\n\n"
		"\tmove.l %0, a0\n"
		"\tmove.l %1, a1\n"
		"\tmove.l %2, d0\n"
		"\tjsr _Mem_copy\n"
		"\n/*************************************/\n\n"
		:																// no outputs
		: "g"(dst), "g"(src), "g"(len)	// inputs
		: "d0", "d1", "a0", "a1","cc"		// clobbers
	);
}

////////////////////////////////////////////////////////////////////////////////

inline void Mem::swap16(void* dst, const void* src, size_t num)
{
	asm(
		"\n/*************************************/\n\n"
		"\tmove.l %0, a0\n"
		"\tmove.l %1, a1\n"
		"\tmove.l %2, d0\n"
		"\tjsr _Mem_swap16\n"
		"\n/*************************************/\n\n"
		:																	// no outputs
		: "g"(dst), "g"(src), "g"(num)		// inputs
		: "d0", "d1", "a0", "a1", "cc"		// clobbers
	);
}

////////////////////////////////////////////////////////////////////////////////

inline void Mem::swap32(void* dst, const void* src, size_t num)
{
	asm(
		"\n/*************************************/\n\n"
		"\tmove.l %0, a0\n"
		"\tmove.l %1, a1\n"
		"\tmove.l %2, d0\n"
		"\tjsr _Mem_swap32\n"
		"\n/*************************************/\n\n"
		:																	// no outputs
		: "g"(dst), "g"(src), "g"(num)		// inputs
		: "d0", "d1", "a0", "a1","cc"			// clobbers
	);
}

////////////////////////////////////////////////////////////////////////////////

inline void Mem::swap64(void* dst, const void* src, size_t num)
{
	asm(
		"\n/*************************************/\n\n"
		"\tmove.l %0, a0\n"
		"\tmove.l %1, a1\n"
		"\tmove.l %2, d0\n"
		"\tjsr _Mem_swap64\n"
		"\n/*************************************/\n\n"
		:																	// no outputs
		: "g"(dst), "g"(src), "g"(num)		// inputs
		: "d0", "d1", "a0", "a1","cc"			// clobbers
	);
}

////////////////////////////////////////////////////////////////////////////////

inline void Mem::zero(void* dst, size_t len)
{
	asm(
		"\n/*************************************/\n\n"
		"\tmove.l %0, a0\n"
		"\tmove.l %1, d0\n"
		"\tjsr _Mem_zero\n"
		"\n/*************************************/\n\n"
		:																	// no outputs
		: "g"(dst), "g"(len)							// inputs
		: "d0", "d1", "a0", "a1","cc"			// clobbers
	);
}

////////////////////////////////////////////////////////////////////////////////

inline void Mem::set(void* dst, int val, size_t len)
{
	asm(
		"\n/*************************************/\n\n"
		"\tmove.l %0, a0\n"
		"\tmove.l %1, d0\n"
		"\tmove.l %2, d1\n"
		"\tjsr _Mem_set\n"
		"\n/*************************************/\n\n"
		:																	// no outputs
		: "g"(dst), "g"(val), "g"(len)		// inputs
		: "d0", "d1", "a0", "a1","cc"			// clobbers
	);
}

////////////////////////////////////////////////////////////////////////////////

inline void Mem::set16(void* dst, uint16 val, size_t num)
{
	asm(
		"\n/*************************************/\n\n"
		"\tmove.l %0, a0\n"
		"\tmove.l %1, d0\n"
		"\tmove.l %2, d1\n"
		"\tjsr _Mem_set16\n"
		"\n/*************************************/\n\n"
		:																	// no outputs
		: "g"(dst), "g"(val), "g"(num)		// inputs
		: "d0", "d1", "a0", "a1","cc"			// clobbers
	);
}

////////////////////////////////////////////////////////////////////////////////

inline void Mem::set32(void* dst, uint32 val, size_t num)
{
	asm(
		"\n/*************************************/\n\n"
		"\tmove.l %0, a0\n"
		"\tmove.l %1, d0\n"
		"\tmove.l %2, d1\n"
		"\tjsr _Mem_set32\n"
		"\n/*************************************/\n\n"
		:																	// no outputs
		: "g"(dst), "g"(val), "g"(num)		// inputs
		: "d0", "d1", "a0", "a1","cc"			// clobbers
	);
}

////////////////////////////////////////////////////////////////////////////////

inline void Mem::set64(void* dst, const uint64& val, size_t num)
{
	asm(
		"\n/*************************************/\n\n"
		"\tmove.l %0, a0\n"
		"\tmove.l %1, a1\n"
		"\tmove.l %2, d0\n"
		"\tjsr _Mem_set64\n"
		"\n/*************************************/\n\n"
		:																	// no outputs
		: "g"(dst), "g"(&val), "g"(num)		// inputs
		: "d0", "d1", "a0", "a1","cc"			// clobbers
	);
}

#endif
