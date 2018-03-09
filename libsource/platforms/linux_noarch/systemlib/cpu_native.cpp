///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/linux_noarch/systemlib/cpu_native.cpp
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
#include <systemlib/memory.hpp>

#include <cstring>
#include <cstdlib>

using namespace EXNGPrivate;

uint32        CPU::cpuCount = 0;
CPU::CPUSpec* CPU::cpuSpec  = 0;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 CPU::getCPUCount()
{
  return cpuCount;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

float64 CPU::getCPUSpeed(uint32 cpu)
{
  if (cpu>cpuCount) {
    THROW_NSX(Error, Range());
  }
  return cpuSpec[cpu].speed;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const char* CPU::getCPUName(uint32 cpu)
{
  if (cpu>cpuCount) {
    THROW_NSX(Error, Range());
  }
  return cpuSpec[cpu].name;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CPU::init()
{
  cpuCount = 1;

  // parse /proc/cpuinfo
  ProcFSParser cpuInfo;
  cpuInfo.parse("/proc/cpuinfo");

  size_t lines = cpuInfo.getTotalLineCount();
  for (size_t i=0;i<lines;i++) {
    if (std::strncmp(cpuInfo.getLine(i), "processor", 9)==0) {
      ++cpuCount;
    }
  }

  SystemLog::write(SystemLog::INFO, "Detected %u CPUs", (unsigned)cpuCount);

  cpuSpec = (CPUSpec*)Mem::alloc(cpuCount * sizeof(CPUSpec), Mem::ZEROFILL);

  size_t cpu = 0;
  for (size_t i=0;i<lines;i++) {
    const char* line = cpuInfo.getLine(i);
    if (std::strncmp(line, "model name", 10)==0) {
      std::strncpy(cpuSpec[cpu].name, line+12, 63);
    }
    else if (std::strncmp(line, "cpu MHz", 7)==0) {
      cpuSpec[cpu].speed = std::strtod(line+11, 0);
    }
    else if (std::strncmp(line, "processor", 9)==0) {
      ++cpu;
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CPU::done()
{
  Mem::free(cpuSpec);
  cpuSpec = 0;
}

