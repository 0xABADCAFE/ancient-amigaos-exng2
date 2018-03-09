///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/linux_noarch/systemlib/cpu.hpp
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

# include <systemlib/time.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  CPU
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "procfsparser.hpp"

namespace EXNGPrivate {

  class CPU {
    public:
      static uint32       getCPUCount();
      static float64      getCPUSpeed(uint32);
      static const char*  getCPUName(uint32);

      static void         init();
      static void         done();

    private:

      struct CPUSpec {
        float64 speed;
        char    name[64];
      };

      static uint32         cpuCount;
      static CPUSpec*       cpuSpec;
  };

};

#endif
