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

const char* CPU::cpuNames[] = {
  "PPC603",
  "PPC604",
  "PPC750",
  "PPC7400",
  "PPC (AltiVec)",
  "PPC4XX"
};

sint32 CPU::cpuType()
{
  static sint32 cpu = -1;
  if (cpu<0) {
    cpu = 0;
  }
  return cpu;
}

void CPU::flushDataCache(void* adr, uint32 l)
{
  IExec->CacheClearE(adr, l, CACRF_ClearD);
}

void CPU::flushInstCache(void* adr, uint32 l)
{
  IExec->CacheClearE(adr, l, CACRF_ClearI);
}

void CPU::flushAllCaches(void* adr, uint32 l)
{
  IExec->CacheClearE(adr, l, CACRF_ClearD|CACRF_ClearI);
}

float64 CPU::getCPUSpeed(uint32)
{
  static float64 speed=0;
  return speed;
}


