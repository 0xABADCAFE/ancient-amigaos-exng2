///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/linux_noarch/systemlib/time_native.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Time related classes
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
#include <systemlib/time.hpp>

using namespace Time;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 MilliClock::elapsed() const
{
  timeval current;
  gettimeofday(&current, 0);
  if (current.tv_sec == mark.tv_sec) {
    return (current.tv_usec - mark.tv_usec)/1000;
  }
  return (1000*(current.tv_sec - mark.tv_sec)) + ((current.tv_usec - mark.tv_usec)/1000);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

float64 MilliClock::elapsedFrac() const
{
  timeval current;
  gettimeofday(&current, 0);
  if (current.tv_sec == mark.tv_sec) {
    return 0.001*(current.tv_usec - mark.tv_usec);
  }
  return (1000.0*(current.tv_sec - mark.tv_sec)) + (0.001*(current.tv_usec - mark.tv_usec));
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

MilliClock::MilliClock()
{
  set();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Clock
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const Interval& Clock::elapsed() const
{
  timeval current;
  gettimeofday(&current, 0);
  if (current.tv_sec == mark.tv_sec) {
    t.millis = (current.tv_usec - mark.tv_usec)/1000;
  } else {
    t.millis = (1000*(current.tv_sec - mark.tv_sec)) + ((current.tv_usec - mark.tv_usec)/1000);
  }
  return t;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Clock::Clock()
{
  set();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Clock::init()
{
  // nothing to do here
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Datestamp
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Datestamp::now()
{
  timeval current;
  gettimeofday(&current, 0);
  set(current.tv_sec, current.tv_usec);
}