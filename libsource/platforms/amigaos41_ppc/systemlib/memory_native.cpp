///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/amigaos41_ppc/systemlib/memory_native.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Memory allocation and tracking
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

// size_t            RawMemHandler::puddleSize     = 4096;
// size_t            RawMemHandler::threshSize     = 0;
// void*             RawMemHandler::memPool        = 0;
SignalSemaphore*  RawMemHandler::poolSemaphore  = 0;

LOGGING_DECLARE_CLASSNAME(RawMemHandler)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void RawMemHandler::init()
{
//   LOGGING_DECLARE_FUNCNAME(init)

  if (!(poolSemaphore = (SignalSemaphore*)IExec->AllocMem(sizeof(SignalSemaphore), MEMF_SHARED))) {
    THROW_NSX(Mem, Exhausted(sizeof(SignalSemaphore)));
  }

  IExec->InitSemaphore(poolSemaphore);

//   EXNG2_DISALLOWED((!(memPool = IExec->CreatePool(MEMF_SHARED, puddleSize, threshSize))), Exhausted(puddleSize), Mem)
//
//   #ifdef EXNG2_BUILD_LOGGED
//   SystemLog::write(
//     SystemLog::INFO,
//     "%s::%s - OK [puddle: %d, threshold %d]\n",
//     loggingClassName, loggingFuncName,
//     puddleSize,
//     threshSize
//   );
//   #endif
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void RawMemHandler::done()
{
//   LOGGING_DECLARE_FUNCNAME(done)
//
//   if (memPool) {
//     #ifdef EXNG2_BUILD_LOGGED
//     if (Mem::getNumAllocations()>0) {
//       SystemLog::write(
//         SystemLog::WARNING,
//         "%s::%s - %lu unfreed chunks, totalling %lu bytes\n",
//         loggingClassName, loggingFuncName,
//         Mem::getNumAllocations(),
//         Mem::getTotalSize()
//       );
//       Mem::debug();
//     }
//     #endif
//     IExec->DeletePool(memPool);
//     memPool = 0;
//   }
  if (poolSemaphore) {
    IExec->FreeMem(poolSemaphore, sizeof(SignalSemaphore));
    poolSemaphore = 0;
  }
//
//   #ifdef EXNG2_BUILD_LOGGED
//   SystemLog::write(
//     SystemLog::INFO,
//     "%s::%s - OK\n", loggingClassName, loggingFuncName
//   );
//   #endif
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void* RawMemHandler::alloc(size_t size, uint32 flags)
{
  if (flags & Mem::ZEROFILL) {
    return IExec->AllocMem(size, MEMF_SHARED|MEMF_CLEAR);
  }
  else {
    return IExec->AllocMem(size, MEMF_SHARED);
  }
//   void* block = IExec->AllocPooled(memPool, size);
//   if (block && (flags & Mem::ZEROFILL)) {
//     RawMemHandler::zero(block, size);
//   }
//   return block;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void RawMemHandler::free(void* ptr, size_t size)
{
  IExec->FreeMem(ptr, size);
  //IExec->FreePooled(memPool, ptr, size);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


