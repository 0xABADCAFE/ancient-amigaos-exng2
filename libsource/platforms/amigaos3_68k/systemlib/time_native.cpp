///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/amigaos3_68k/systemlib/time_native.hpp
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
#include <systemlib/logger.hpp>
#include <time.h>

namespace OSNative {
  extern "C" {
    #include <clib/alib_protos.h>
    #include <proto/locale.h>
  }
};

using namespace OSNative;
using namespace Time;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  MilliClock
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern  Device* TimerBase;

uint32  MilliClock::clockFreq = 0;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 MilliClock::elapsed() const
{
  EClockVal current;
  ReadEClock(&current);
  ruint32 ticks;
  if (current.ev_hi == mark.ev_hi) {
    ticks = current.ev_lo - mark.ev_lo;
  }
  else {
    ticks = 0xFFFFFFFF-mark.ev_lo + current.ev_lo;
  }
  return (1000*ticks)/clockFreq;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

float64 MilliClock::elapsedFrac() const
{
  EClockVal current;
  ReadEClock(&current);
  float64 ticks;
  static float64 cF = 1000.0/(float64)clockFreq;
  if (current.ev_hi == mark.ev_hi) {
    ticks = (current.ev_lo - mark.ev_lo);
  }
  else {
    ticks = (0xFFFFFFFF-mark.ev_lo + current.ev_lo);
  }
  return (cF*ticks);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

MilliClock::MilliClock()
{
  clockFreq = ReadEClock(&mark);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MilliClock::set()
{
  ReadEClock(&mark);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Clock
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const Interval& Clock::elapsed() const
{
  timeval current;
  GetSysTime(&current);
  SubTime(&current, &mark);
  t.millis  = ((current.tv_secs*1000)+(current.tv_micro/1000));
  return t;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Clock::set()
{
  OSNative::GetSysTime(&mark);
  t.millis = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Clock::Clock()
{
  set();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Clock::init()
{
  LOGGING_DECLARE_FUNCNAME(Clock::init)

  const char* libraryName = "locale.library";

  if ((::LocaleBase = (struct LocaleBase*) OpenLibrary(libraryName, 0))) {
    Locale* locale = OpenLocale(0);

    Datestamp::locTZMinutes = locale->loc_GMTOffset;

    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::INFO, "%s default locale indicates timezone %+" XPF_S32 ":%02" XPF_S32 "\n",
      loggingFuncName,
      (sint32)Datestamp::locTZMinutes/60,
      (sint32)(Datestamp::locTZMinutes< 0 ? -Datestamp::locTZMinutes : Datestamp::locTZMinutes)%60
    );
    #endif

    CloseLocale(locale);
    CloseLibrary((Library*)::LocaleBase);
  }
  #ifdef EXNG2_BUILD_LOGGED
  else {
    SystemLog::write(
      SystemLog::WARNING, "%s unable to open %s, timezone assumed to be GMT\n",
      loggingFuncName,
      libraryName
    );
  }
  #endif

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Datestamp
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace {
  // Jan 1st 1978 00:00:)0
  uint32 amigaEpochOffset = 252460800;
}


void Datestamp::now()
{
  timeval current;
  GetSysTime(&current);
  set(current.tv_secs+amigaEpochOffset, current.tv_micro);
}
