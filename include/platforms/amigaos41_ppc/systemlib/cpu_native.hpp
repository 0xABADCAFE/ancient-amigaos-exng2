///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/amigaos3_68k/systemlib/cpu.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Processor query, native implementation
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



#ifndef _EXNG2_SYSTEMLIB_CPU_NATIVE_HPP_
# define _EXNG2_SYSTEMLIB_CPU_NATIVE_HPP_

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  CPU
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace EXNGPrivate {

class CPU {

  public:
    static void         init() {}
    static void         done() {}

    static uint32       getCPUCount()       { return 1; }
    static float64      getCPUSpeed(uint32);
    static const char*  getCPUName(uint32)  { return cpuNames[cpuType()]; }
    static void         synchronise()       { /*asm("\n\tnop\n");*/ }

    static void         flushDataCache(void* adr, uint32 l=0xFFFFFFFF);
    static void         flushInstCache(void* adr, uint32 l=0xFFFFFFFF);
    static void         flushAllCaches(void* adr, uint32 l=0xFFFFFFFF);

  protected:
    // processor definitions are not public to discourage casual use
    enum {
      PPC603      = 0,
      PPC604      = 2,
      PPC750      = 3,
      PPC7400     = 4,
      PPCALTIVEC  = 5,
      PPC4XX      = 6
    };

    static sint32 cpuType();

  private:

    static const char* cpuNames[];

};

};

#endif
