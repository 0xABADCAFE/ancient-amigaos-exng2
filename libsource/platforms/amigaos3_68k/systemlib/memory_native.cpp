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
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <xbase.hpp>
#include <systemlib/memory.hpp>
#include <systemlib/logger.hpp>
#include <private/systemlib/error.hpp>

using namespace OSNative;
using namespace EXNGPrivate;

size_t            RawMemHandler::puddleSize     = 4096;
size_t            RawMemHandler::threshSize     = 0;
void*             RawMemHandler::memPool        = 0;
SignalSemaphore*  RawMemHandler::poolSemaphore  = 0;

LOGGING_DECLARE_CLASSNAME(RawMemHandler)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void RawMemHandler::init()
{
  LOGGING_DECLARE_FUNCNAME(init)

  puddleSize = Application::getArgInteger("-amiga_puddlesize", puddleSize, 0);
  threshSize = puddleSize - 4*RawMemHandler::ALIGN_CACHE;

  if (puddleSize<2048 || puddleSize>65536) {
    THROW_NSX(Error, Range());
  }
  if (!(poolSemaphore = (SignalSemaphore*)AllocMem(sizeof(SignalSemaphore), MEMF_PUBLIC))) {
    THROW_NSX(Mem, Exhausted(sizeof(SignalSemaphore)));
  }
  if (!(memPool = CreatePool(MEMF_PUBLIC, puddleSize, threshSize))) {
    THROW_NSX(Mem, Exhausted(puddleSize));
  }
  InitSemaphore(poolSemaphore);

  #ifdef EXNG2_BUILD_LOGGED
  SystemLog::write(
    SystemLog::INFO,
    "%s::%s - OK [puddle: %d, threshold %d]\n",
    loggingClassName, loggingFuncName,
    puddleSize,
    threshSize
  );
  #endif
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void RawMemHandler::done()
{
  LOGGING_DECLARE_FUNCNAME(done)

  if (memPool) {
    #ifdef EXNG2_BUILD_LOGGED
    if (Mem::getNumAllocations()>0) {
      SystemLog::write(
        SystemLog::WARNING,
        "%s::%s - %lu unfreed chunks, totalling %lu bytes\n",
        loggingClassName, loggingFuncName,
        Mem::getNumAllocations(),
        Mem::getTotalSize()
      );
      Mem::debug();
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
  SystemLog::write(
    SystemLog::INFO,
    "%s::%s - OK\n", loggingClassName, loggingFuncName
  );
  #endif
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void* RawMemHandler::alloc(size_t size, uint32 flags)
{
  void* block = AllocPooled(memPool, size);
  if (block && (flags & Mem::ZEROFILL)) {
    RawMemHandler::zero(block, size);
  }
  return block;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void RawMemHandler::free(void* ptr, size_t size)
{
  FreePooled(memPool, ptr, size);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


