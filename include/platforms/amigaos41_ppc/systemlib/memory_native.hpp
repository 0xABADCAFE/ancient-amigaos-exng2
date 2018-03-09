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
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef _EXNG2_SYSTEMLIB_MEMORY_NATIVE_HPP_
# define _EXNG2_SYSTEMLIB_MEMORY_NATIVE_HPP_

# include "platforms/amigaos41_ppc/systemlib/logger_native.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Mem
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef EXNG2_BUILD_AVOID_BLOAT
namespace EXNGPrivate {
  extern "C" void throwMemExhausted(size_t);
};
#endif

class RawMemHandler {
  protected:
    enum {
      ALIGN_CACHE = 32
    };

    static void*  alloc(size_t size, uint32 flags);
    static void   free(void* p, size_t size);
    static void   copy(void* dst, const void* src, size_t len);
    static void   swap16(void* dst, const void* src, size_t num);
    static void   swap32(void* dst, const void* src, size_t num);
    static void   swap64(void* dst, const void* src, size_t num);
    static void   zero(void* dst, size_t len);
    static void   set(void* dst, int val, size_t len);
    static void   set16(void* dst, uint16 val, size_t num);
    static void   set32(void* dst, uint32 val, size_t num);
    static void   set64(void* dst, const uint64& val, size_t num);

    static size_t getRemainingFreeSize();

    static void   debug();
    static void   init();
    static void   done();

    static bool   validAllocator()  { return poolSemaphore!=0;                          }
    static void   lockAllocator()   { OSNative::IExec->ObtainSemaphore(poolSemaphore);   }
    static void   unlockAllocator() { OSNative::IExec->ReleaseSemaphore(poolSemaphore);  }

    // amiga implemenentation data data
//     static size_t   puddleSize;
//     static size_t   threshSize;
//     static void*    memPool;
    static OSNative::SignalSemaphore* poolSemaphore;

    LOGGING_DEFINE_CLASSNAME
};


////////////////////////////////////////////////////////////////////////////////

inline size_t RawMemHandler::getRemainingFreeSize()
{
  return OSNative::IExec->AvailMem(MEMF_SHARED|MEMF_LARGEST);
}


////////////////////////////////////////////////////////////////////////////////

inline void RawMemHandler::copy(void* dst, const void* src, size_t len)
{
  OSNative::IExec->CopyMem(src, dst, len);
}

#include <cstring>

inline void RawMemHandler::zero(void* dst, size_t len)
{
  std::memset(dst, 0, len);
}

extern "C" {
  void ASM_RawMemHandler_swap16_16(void* dst, const void* src, size_t len);
  void ASM_RawMemHandler_swap16_32(void* dst, const void* src, size_t len);
  void ASM_RawMemHandler_swap32(void* dst, const void* src, size_t len);
  void ASM_RawMemHandler_swap64(void* dst, const void* src, size_t len);
}

inline void RawMemHandler::swap16(void* dst, const void* src, size_t len)
{
  if (len) {
    // choose aligned version
    switch ((((uint32)dst)|((uint32)src))&3UL) {
      case 0:   ASM_RawMemHandler_swap16_32(dst, src, len);        break;
      case 2:   ASM_RawMemHandler_swap16_16(dst, src, len);        break;
      default:  THROW_NSX(Error, BadAlignment());                   break;
    }
  }
}

inline void RawMemHandler::swap32(void* dst, const void* src, size_t len)
{
  if (len) {
    if (((((uint32)dst)|((uint32)src))&1UL)==0) {
      ASM_RawMemHandler_swap32(dst, src, len);
    } else {
      THROW_NSX(Error, BadAlignment());
    }
  }
}

inline void RawMemHandler::swap64(void* dst, const void* src, size_t len)
{
  if (len) {
    if (((((uint32)dst)|((uint32)src))&1UL)==0) {
      ASM_RawMemHandler_swap64(dst, src, len);
    } else {
      THROW_NSX(Error, BadAlignment());
    }
  }
}

// inline void RawMemHandler::copy(void* dst, const void* src, size_t len)
// {
//   asm(
//     "\n/*************************************/\n\n"
//     "\tmove.l %0, a0\n"
//     "\tmove.l %1, a1\n"
//     "\tmove.l %2, d0\n"
//     "\tjsr _Mem_copy\n"
//     "\n/*************************************/\n\n"
//     :                               // no outputs
//     : "g"(dst), "g"(src), "g"(len)  // inputs
//     : "d0", "d1", "a0", "a1","cc"   // clobbers
//   );
// }
//
// ////////////////////////////////////////////////////////////////////////////////
//
// inline void RawMemHandler::swap16(void* dst, const void* src, size_t num)
// {
//   asm(
//     "\n/*************************************/\n\n"
//     "\tmove.l %0, a0\n"
//     "\tmove.l %1, a1\n"
//     "\tmove.l %2, d0\n"
//     "\tjsr _Mem_swap16\n"
//     "\n/*************************************/\n\n"
//     :                                 // no outputs
//     : "g"(dst), "g"(src), "g"(num)    // inputs
//     : "d0", "d1", "a0", "a1", "cc"    // clobbers
//   );
// }
//
// ////////////////////////////////////////////////////////////////////////////////
//
// inline void RawMemHandler::swap32(void* dst, const void* src, size_t num)
// {
//   asm(
//     "\n/*************************************/\n\n"
//     "\tmove.l %0, a0\n"
//     "\tmove.l %1, a1\n"
//     "\tmove.l %2, d0\n"
//     "\tjsr _Mem_swap32\n"
//     "\n/*************************************/\n\n"
//     :                                 // no outputs
//     : "g"(dst), "g"(src), "g"(num)    // inputs
//     : "d0", "d1", "a0", "a1","cc"     // clobbers
//   );
// }
//
// ////////////////////////////////////////////////////////////////////////////////
//
// inline void RawMemHandler::swap64(void* dst, const void* src, size_t num)
// {
//   asm(
//     "\n/*************************************/\n\n"
//     "\tmove.l %0, a0\n"
//     "\tmove.l %1, a1\n"
//     "\tmove.l %2, d0\n"
//     "\tjsr _Mem_swap64\n"
//     "\n/*************************************/\n\n"
//     :                                 // no outputs
//     : "g"(dst), "g"(src), "g"(num)    // inputs
//     : "d0", "d1", "a0", "a1","cc"     // clobbers
//   );
// }
//
// ////////////////////////////////////////////////////////////////////////////////
//
// inline void RawMemHandler::zero(void* dst, size_t len)
// {
//   asm(
//     "\n/*************************************/\n\n"
//     "\tmove.l %0, a0\n"
//     "\tmove.l %1, d0\n"
//     "\tjsr _Mem_zero\n"
//     "\n/*************************************/\n\n"
//     :                                 // no outputs
//     : "g"(dst), "g"(len)              // inputs
//     : "d0", "d1", "a0", "a1","cc"     // clobbers
//   );
// }
//
// ////////////////////////////////////////////////////////////////////////////////
//
// inline void RawMemHandler::set(void* dst, int val, size_t len)
// {
//   asm(
//     "\n/*************************************/\n\n"
//     "\tmove.l %0, a0\n"
//     "\tmove.l %1, d0\n"
//     "\tmove.l %2, d1\n"
//     "\tjsr _Mem_set\n"
//     "\n/*************************************/\n\n"
//     :                                 // no outputs
//     : "g"(dst), "g"(val), "g"(len)    // inputs
//     : "d0", "d1", "a0", "a1","cc"     // clobbers
//   );
// }
//
// ////////////////////////////////////////////////////////////////////////////////
//
// inline void RawMemHandler::set16(void* dst, uint16 val, size_t num)
// {
//   asm(
//     "\n/*************************************/\n\n"
//     "\tmove.l %0, a0\n"
//     "\tmove.l %1, d0\n"
//     "\tmove.l %2, d1\n"
//     "\tjsr _Mem_set16\n"
//     "\n/*************************************/\n\n"
//     :                                 // no outputs
//     : "g"(dst), "g"(val), "g"(num)    // inputs
//     : "d0", "d1", "a0", "a1","cc"     // clobbers
//   );
// }
//
// ////////////////////////////////////////////////////////////////////////////////
//
// inline void RawMemHandler::set32(void* dst, uint32 val, size_t num)
// {
//   asm(
//     "\n/*************************************/\n\n"
//     "\tmove.l %0, a0\n"
//     "\tmove.l %1, d0\n"
//     "\tmove.l %2, d1\n"
//     "\tjsr _Mem_set32\n"
//     "\n/*************************************/\n\n"
//     :                                 // no outputs
//     : "g"(dst), "g"(val), "g"(num)    // inputs
//     : "d0", "d1", "a0", "a1","cc"     // clobbers
//   );
// }
//
// ////////////////////////////////////////////////////////////////////////////////
//
// inline void RawMemHandler::set64(void* dst, const uint64& val, size_t num)
// {
//   asm(
//     "\n/*************************************/\n\n"
//     "\tmove.l %0, a0\n"
//     "\tmove.l %1, a1\n"
//     "\tmove.l %2, d0\n"
//     "\tjsr _Mem_set64\n"
//     "\n/*************************************/\n\n"
//     :                                 // no outputs
//     : "g"(dst), "g"(&val), "g"(num)   // inputs
//     : "d0", "d1", "a0", "a1","cc"     // clobbers
//   );
// }

#endif
