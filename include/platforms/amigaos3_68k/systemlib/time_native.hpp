///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/amigaos3_68k/systemlib/time.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Time related classes, nativce implementation
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

#ifndef _EXNG2_SYSTEMLIB_TIME_NATIVE_HPP_
# define _EXNG2_SYSTEMLIB_TIME_NATIVE_HPP_

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Time::MilliClock
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace OSNative {
  extern "C" {
    #include <proto/timer.h>
  }
  #include <library_inlines/timer.hpp>
};

class Time::MilliClock {
  public:
    void      set();
    uint32    elapsed() const;
    float64   elapsedFrac() const;
  public:
    MilliClock();

  private:
    static uint32       clockFreq;
    OSNative::EClockVal mark;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Time::Clock
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Time::Clock {
  public:
    void                  set();
    const Time::Interval& elapsed() const;
    const Time::Interval& last()    const { return t; }

  public:
    Clock();

  private:
    OSNative::timeval       mark;
    mutable Time::Interval  t;

    static void init();

    friend class Startup;
};

#ifdef __STORMGCC__
#undef YEAR_ZERO
#define YEAR_ZERO 0
#endif


#endif
