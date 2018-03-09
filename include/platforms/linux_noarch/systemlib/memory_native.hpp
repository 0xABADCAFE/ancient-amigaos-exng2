///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/linux_noarch/systemlib/memory.hpp
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

# include "platforms/linux_noarch/systemlib/logger_native.hpp"

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
      ALIGN_CACHE = 64
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

    static void   init();
    static void   done();

    static bool   validAllocator()  { return true; }
    static void   lockAllocator()   { }
    static void   unlockAllocator() { }

    LOGGING_DEFINE_CLASSNAME
};

#endif
