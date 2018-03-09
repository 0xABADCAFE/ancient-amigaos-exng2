///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         systemlib/memory.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Common memory allocation and tracking
//  Comment(s):
//  Library:      System
//  Created:      2006-10-08
//  Updated:      2006-10-08
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <xbase.hpp>
#include <systemlib/memory.hpp>
#include <systemlib/logger.hpp>
#include <private/systemlib/error.hpp>

using namespace EXNGPrivate;

struct Mem::MemInfo {
  uint32        identifier;
  uint32        flags;
  size_t        size;
  size_t        userSize;
  Mem::MemInfo* prev;
  Mem::MemInfo* next;
  void*         baseAddress;
  uint32        pad;
};

uint32            Mem::memIdentifier  = ('X'<<24)|('R'<<16)|('M'<<8)|('A');
size_t            Mem::numAlloc       = 0;
size_t            Mem::peakAlloc      = 0;
size_t            Mem::totSize        = 0;
size_t            Mem::peakSize       = 0;
size_t            Mem::totRequested   = 0;
size_t            Mem::peakRequested  = 0;
Mem::MemInfo*     Mem::head           = 0;


LOGGING_DECLARE_CLASSNAME(Mem)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Mem::init()
{
  RawMemHandler::init();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Mem::done()
{
  if (head) {
    MemInfo* pMI;
    MemInfo* next;
    debug();
    RawMemHandler::lockAllocator();

    for (pMI = head; pMI; pMI = next) {
      next = pMI->next;
      pMI->identifier = 0;
      RawMemHandler::free(pMI->baseAddress, pMI->size);
    }

    RawMemHandler::unlockAllocator();
  }
  RawMemHandler::done();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void* Mem::alloc(size_t size, uint32 flags)
{
  LOGGING_DECLARE_FUNCNAME(alloc)

  if (!RawMemHandler::validAllocator()) {
    if (flags & NO_THROW) {
      return 0;
    }
    else {
      THROW_NSX(Error,ResourceUnavailable("allocator"));
    }
  }

  size_t allocSize  = size + sizeof(MemInfo) + (RawMemHandler::ALIGN_CACHE<<1);

  // the allocator does some low level pointer stuff which I'd rather not do but
  // as long as the user obeys the "never free whatever you didn't allocate" things
  // should be ok.

  RawMemHandler::lockAllocator();
  void* block   = RawMemHandler::alloc(allocSize, flags);
  void* result  = 0;
  if (block) {
    size_t    mask    = RawMemHandler::ALIGN_CACHE-1;
    MemInfo*  info    = (MemInfo*)((mask+(size_t)block) & ~mask); // this is aligned
    info->identifier  = memIdentifier;
    info->flags       = 0;
    info->size        = allocSize;
    info->userSize    = size;
    info->baseAddress = block;
    result            = (((uint8*)info)+sizeof(MemInfo));

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
    SystemLog::write(
      SystemLog::INFO,
      "%s::%s - requested %" XPF_U64 " bytes, allocated %" XPF_U64 " at %p, info at %p\n",
      loggingClassName, loggingFuncName,
      (uint64)size,
      (uint64)allocSize,
      block,
      info
    );
    #endif
  }
  RawMemHandler::unlockAllocator();

  if (!result && !(flags & NO_THROW)) {
    THROW_NSX(Mem, Exhausted(size));
  }
  return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Mem::free(void* ptr)
{
  LOGGING_DECLARE_FUNCNAME(free)

  if (!ptr || !RawMemHandler::validAllocator()) {
    return;
  }

  // the allocator does some low level pointer stuff which I'd rather not do but
  // as long as the user obeys the "never free whatever you didn't allocate" things
  // should be ok.

  MemInfo* info = (MemInfo*)(((size_t)ptr)-sizeof(MemInfo));
  if (info->identifier == memIdentifier) {
    RawMemHandler::lockAllocator();

    info->identifier = 0;

    #ifdef EXNG2_BUILD_PARANOID
    void* addr  = info->baseAddress;
    size_t size = info->size;
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

    RawMemHandler::free(info->baseAddress, info->size);
    RawMemHandler::unlockAllocator();

    numAlloc--;

  #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::INFO,
      "%s::%s - freed %" XPF_U64 " [%" XPF_U64 "] bytes, allocated at %p\n",
      loggingClassName, loggingFuncName,
      (uint64)size, (uint64)user,
      addr
    );
  }
  else {
    SystemLog::write(
      SystemLog::WARNING,
      "%s::%s - attempt to free unknown allocation at %p\n",
      loggingClassName,
      loggingFuncName,
      ptr
    );
  #endif
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Mem::debug()
{
  MemInfo* pMI;
  SystemLog::lock();
  RawMemHandler::lockAllocator();
  SystemLog::printf(
    SystemLog::INFO,
    "     Memory chunk list, %" XPF_U64 " chunks totalling %" XPF_U64 " bytes\n",
    (uint64)numAlloc,
    (uint64)totSize
  );
  for (pMI = head; pMI; pMI = pMI->next) {
    SystemLog::printf(
      SystemLog::INFO,
      "     %" XPF_U64 " [%" XPF_U64 "] bytes allocated at %p\n",
      (uint64)pMI->size,
      (uint64)pMI->userSize,
      pMI->baseAddress
    );
  }
  RawMemHandler::unlockAllocator();
  SystemLog::unlock();
}


