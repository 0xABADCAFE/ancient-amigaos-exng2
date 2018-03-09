///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         systemlib/cpu.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Processor controll and enumeration
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



#ifndef _EXNG2_SYSTEMLIB_CPU_HPP_
# define _EXNG2_SYSTEMLIB_CPU_HPP_

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  ProcessorInfo
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Machine {
  class ProcessorInfo;
};

# include <systemlib/cpu_native.hpp>

//# include XP_INCLUDE_PLATFORM("systemlib/cpu_native.hpp")

class Machine::ProcessorInfo : private EXNGPrivate::CPU {
  public:
    static uint32         getProcessorCount()
    {
      return CPU::getCPUCount();
    }

    static const char*    getProcessorName(uint32 cpu)
    {
      return CPU::getCPUName(cpu);
    }

    static float64        getProcessorSpeed(uint32 cpu)
    {
      return CPU::getCPUSpeed(cpu);
    }
};

#endif
