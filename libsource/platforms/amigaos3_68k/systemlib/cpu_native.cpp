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
#include <systemlib/cpu.hpp>

#include <systemlib/time.hpp>

#include <systemlib/logger.hpp>

namespace OSNative {
  extern "C" {
    #include <exec/execbase.h>
  }
};

using namespace OSNative;
using namespace EXNGPrivate;

char* CPU::cpuNames[] = {
  "MC680x0",
  "MC68020",
  "MC68030",
  "MC68040",
  "MC68060",
  "ColdFire v4",  // cold fusion accelerator, if it ever gets released!
  "ColdFire v5"
};

char* CPU::fpuNames[] = {
  "MC6888x",
  "MC68881",
  "MC68882",
  "MC68040",
  "MC68040+68882emu",
  "MC68060",
  "MC68060+68882emu"
  "Software"
};

// why arent these in my ndk 44.1 release execbase.h?

#ifndef AFB_68060
#define AFB_68060 7
#endif

#ifndef AFF_68060
#define AFF_68060 (1<<AFB_68060)
#endif

sint32 CPU::cpuType()
{
  static sint32 cpu = -1;
  if (cpu<0) {
    // fixme : add 68060 detection
    uint16 info = SysBase->AttnFlags;
    // is this correct ?
    if (info & AFF_68060) {
      cpu = MC68060;
    }
    else if (info & AFF_68040) {
      cpu = MC68040;
    }
    else if (info & AFF_68030) {
      cpu = MC68030;
    }
    else if (info & AFF_68020) {
      cpu = MC68020;
    }
    else {
      cpu = MC680x0;
    }
  }
  return cpu;
}

sint32 CPU::fpuType()
{
  static sint32 fpu = -1;
  if (fpu<0) {
    uint16 info = SysBase->AttnFlags;
    // is this correct ?
    if (info & AFF_68060) {
      if (info & AFF_FPU40) {
        if (info & (AFF_68882|AFF_68881)) {
          fpu = MC68060FPEM;
        }
        else {
          fpu = MC68060FP;
        }
      }
    }
    else if (info & AFF_FPU40) {
      if (info & (AFF_68882|AFF_68881)) {
        fpu = MC68040FPEM;
      }
      else {
        fpu = MC68040FP;
      }
    }
    else if (info & AFF_68882) {
      fpu = MC68882;
    }
    else if (info & AFF_68881) {
      fpu = MC68881;
    }
    else {
      fpu = SOFTFP;
    }
  }
  return fpu;
}

void CPU::flushDataCache(void* adr, uint32 l)
{
  CacheClearE(adr, l, CACRF_ClearD);
}

void CPU::flushInstCache(void* adr, uint32 l)
{
  CacheClearE(adr, l, CACRF_ClearI);
}

void CPU::flushAllCaches(void* adr, uint32 l)
{
  CacheClearE(adr, l, CACRF_ClearD|CACRF_ClearI);
}

float64 CPU::getCPUSpeed(uint32)
{
  static float64 speed=0;
  if (speed<1.0) {
    Forbid();
    sint32 lpc=1000000;
    sint32 val=lpc;
    Time::MilliClock clock;
    clock.set();
    asm volatile (
      "1: subq.l #1, %0" "\n\t"
      "bgt.b 1b"
      : "=d"(val) : "0"(val) : "cc"
    );
    speed = 1000.0*clock.elapsedFrac(); // in us
    Permit();

    float64 cyclesPerLoop = 1.0;

    #ifdef EXNG2_BUILD_LOGGED
    const char* logTemplate = "%s class CPU, timing loop took %f us\n";
    #endif

    switch(cpuType()) {
      case MC68020:
        // real world system took 573419.85 microseconds @ 14.32MHz
        #ifdef EXNG2_BUILD_LOGGED
        SystemLog::write(SystemLog::INFO, logTemplate, cpuNames[MC68020], speed);
        #endif
        cyclesPerLoop = 8.211372257; // 8 cycles, ideally
        break;
      case MC68030:
        // real world system took 326713.93 microseconds @ 25MHz
        #ifdef EXNG2_BUILD_LOGGED
        SystemLog::write(SystemLog::INFO, logTemplate, cpuNames[MC68030], speed);
        #endif
        cyclesPerLoop = 8.167265599; // 8 cycles, ideally
        break;
      case MC68040:
        #ifdef EXNG2_BUILD_LOGGED
        SystemLog::write(SystemLog::INFO, logTemplate, cpuNames[MC68040], speed);
        #endif
        cyclesPerLoop = 3.02380338; //3 cycles, ideally (brank taken requires 2 cycles)
        break;
      case MC68060:
        // real world system took 20258.564181 microseconds @ 50MHz
        #ifdef EXNG2_BUILD_LOGGED
        SystemLog::write(SystemLog::INFO, logTemplate, cpuNames[MC68060], speed);
        #endif
        cyclesPerLoop = 1.012945443; // 1 cycle, ideally (branch folded)
        break;
      default:
        break;
    }
    speed = (float64)lpc*cyclesPerLoop/speed;
  }
  return speed;
}


