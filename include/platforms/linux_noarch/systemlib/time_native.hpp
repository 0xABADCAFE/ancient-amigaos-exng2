///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/linux_noarch/systemlib/time.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Time related classes, native implementation
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

# include <sys/time.h>
# include <time.h>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  MilliClock
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Time::MilliClock {
  public:
    void      set()                 { gettimeofday(&mark, 0); }
    uint32    elapsed()     const;
    float64   elapsedFrac() const;
  public:
    MilliClock();

  private:
    timeval mark;
};

class Time::Clock {
  friend void Startup::init(int argN, char** argV);
  //friend class Startup;

  public:
    void            set()           { gettimeofday(&mark, 0); t.millis = 0; }
    const Interval& elapsed() const;
    const Interval& last()    const { return t; }

  public:
    Clock();

  private:
    static void init();

    timeval mark;
    mutable Interval  t;

};

#endif
