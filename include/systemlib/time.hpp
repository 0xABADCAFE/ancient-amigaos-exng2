///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         systemlib/time.hpp
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



#ifndef _EXNG2_SYSTEMLIB_TIME_HPP_
# define _EXNG2_SYSTEMLIB_TIME_HPP_

# include <private/systemlib/error.hpp>

namespace Time {

  enum {
    MILLIS_PER_SEC  = 1000,
    MILLIS_PER_MIN  = 60000,
    MILLIS_PER_HOUR = 3600000,
    MILLIS_PER_DAY  = 86400000,
    SECS_PER_MIN    = 60,
    SECS_PER_HOUR   = 360,
    SECS_PER_DAY    = 86400,
    MINS_PER_HOUR   = 60,
    MINS_PER_DAY    = 1440,
    HOURS_PER_DAY   = 24
  };

  class Interval;
  class Clock;
  class MilliClock;
  class Datestamp;

  bool  leapYear(sint32 year);

};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Time::Interval
//
//  Represents a measure of time to the nearest millisecond, using 64 bit accuracy
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Time::Interval {
  public:
    sint64  totMillis() const { return millis; }
    sint64  totSecs()   const { return millis / Time::MILLIS_PER_SEC; }
    sint64  totMins()   const { return millis / Time::MILLIS_PER_MIN; }
    sint64  totHours()  const { return millis / Time::MILLIS_PER_HOUR; }
    sint64  totDays()   const { return millis / Time::MILLIS_PER_DAY; }
    sint32  days()      const { return (sint32)totDays(); }
    sint32  millisecs() const { return (sint32)(millis     % Time::MILLIS_PER_SEC); }
    sint32  secs()      const { return (sint32)(totSecs()  % Time::SECS_PER_MIN); }
    sint32  mins()      const { return (sint32)(totMins()  % Time::MINS_PER_HOUR); }
    sint32  hours()     const { return (sint32)(totHours() % Time::HOURS_PER_DAY); }

    void    set(sint32 dy, sint32 hr, sint32 mn, sint32 sc, sint32 ms);

    Interval&   operator+=(const Interval& t);
    Interval&   operator-=(const Interval& t);
    Interval&   operator+=(sint32 t)        { millis += t; return *this; }
    Interval&   operator-=(sint32 t)        { millis -= t; return *this; }
    Interval&   operator*=(sint32 t)        { millis *= t; return *this; }
    Interval&   operator/=(sint32 t)        { if (!t) { THROW_NSX(Error, ZeroDivide()); } millis /= t; return *this; }
    Interval&   operator*=(float64 f)       { millis = (sint64)(f*(float64)millis); return *this; }
    Interval&   operator/=(float64 f)       { millis = (sint64)(f/(float64)millis); return *this; }

    Interval() : millis(0)                                          {}
    Interval(const Interval& t) : millis (t.millis)                 {}
    Interval(sint64 ms) : millis (ms)                               {}
    Interval(sint32 sc, sint32 ms)                                  { millis = Time::MILLIS_PER_SEC*sc + ms; }
    Interval(sint32 dy, sint32 hr, sint32 mn, sint32 sc, sint32 ms) { set(dy, hr, mn, sc, ms); }

  private:
    sint64 millis;
    friend class Time::Clock;
};


inline Time::Interval operator+(const Time::Interval& a, const Time::Interval& b)
{
  Time::Interval sum(a.totMillis() + b.totMillis());
  return sum;
}

inline Time::Interval operator-(const Time::Interval& a, const Time::Interval& b)
{
  Time::Interval diff(a.totMillis() - b.totMillis());
  return diff;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Time::Datestamp
//
//  Stores a ms precision date value, with timezone data in 8 bytes with the following limits
//
//  Year         0 ... 131071
//  Month        1 ... 12
//  Day          1 ... 31
//  Hour         0 ... 23
//  Min          0 ... 59
//  Sec          0 ... 59 (60 allowed for leap second)
//  Milli        0 ... 999
//  TZ Mins   -720 ... 840 (for -12:00 ... +14:00
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace EXNGPrivate {
  class DatestampModifier;
};

class Time::Datestamp {

  public:
    sint32  millisec()  const { return (data[1] & MASK_MS); }
    sint32  sec()       const { return (data[1] & MASK_SEC )    >> OFS_SEC; }
    sint32  min()       const { return (data[1] & MASK_MIN )    >> OFS_MIN; }
    sint32  hour()      const { return (data[1] & MASK_HOUR)    >> OFS_HOUR; }
    sint32  day()       const { return (data[1] & MASK_DAY )    >> OFS_DAY; }
    sint32  month()     const { return (data[0] & MASK_MONTH); }
    sint32  year()      const { return (data[0] & MASK_YEAR)    >> OFS_YEAR; }
    sint32  tzMinutes() const { return ((sint32)(data[0] & MASK_TZ_MIN) >> OFS_TZ_MIN); }
    sint32  tzMin()     const { return ((sint32)(data[0] & MASK_TZ_MIN) >> OFS_TZ_MIN)%60; }
    sint32  tzHour()    const { return ((sint32)(data[0] & MASK_TZ_MIN) >> OFS_TZ_MIN)/60; }

    bool    leapYear()  const { return Time::leapYear(year()); }

    bool    operator< (const Datestamp& ds) const;
    bool    operator<=(const Datestamp& ds) const;
    bool    operator==(const Datestamp& ds) const;
    bool    operator!=(const Datestamp& ds) const { return !(*this==ds); }
    bool    operator>=(const Datestamp& ds) const { return !(*this<ds); }
    bool    operator> (const Datestamp& ds) const { return !(*this<=ds); }

    void    now();

    void    set(uint32 y, uint16 m, uint16 d, uint16 hr, uint16 mn, uint16 sc, uint16 ms);

    void    setTimeZoneOffset(sint16 mins);

    Datestamp& operator+=(const Time::Interval& i);

    Datestamp(bool init=true)
    {
      if (init) {
        now();
      }
      else {
        data[0]=0;
        data[1]=0;
      }
    }

    Datestamp(uint32 y, uint16 m, uint16 d, uint16 hr, uint16 mn, uint16 sc, uint16 ms)
    {
      set(y, m, d, hr, mn, sc, ms);
    }

    Datestamp(uint32 y, uint16 m, uint16 d, uint16 hr, uint16 mn, uint16 sc, uint16 ms, sint16 tz)
    {
      set(y, m, d, hr, mn, sc, ms);
      setTimeZoneOffset(tz);
    }

    static bool leapYear(sint32 year);

  private:
    enum {
      OFS_MS        = 0,
      OFS_SEC       = 10,
      OFS_MIN       = 16,
      OFS_HOUR      = 22,
      OFS_DAY       = 27,
      OFS_MONTH     = 0,
      OFS_YEAR      = 4,
      OFS_TZ_MIN    = 21,
      MASK_MS       = ((1<<(OFS_SEC     - OFS_MS      ))-1) << OFS_MS,
      MASK_SEC      = ((1<<(OFS_MIN     - OFS_SEC     ))-1) << OFS_SEC,
      MASK_MIN      = ((1<<(OFS_HOUR    - OFS_MIN     ))-1) << OFS_MIN,
      MASK_HOUR     = ((1<<(OFS_DAY     - OFS_HOUR    ))-1) << OFS_HOUR,
      MASK_DAY      = ((1<<(32          - OFS_DAY     ))-1) << OFS_DAY,
      MASK_MONTH    = ((1<<(OFS_YEAR    - OFS_MONTH   ))-1) << OFS_MONTH,
      MASK_YEAR     = ((1<<(OFS_TZ_MIN  - OFS_YEAR    ))-1) << OFS_YEAR,
      MASK_TZ_MIN   = ((1<<(32          - OFS_TZ_MIN  ))-1) << OFS_TZ_MIN,

      MAX_TZ        = 840,
      MIN_TZ        = -720,

    };

    bool sameTimezone(const Datestamp& ds) const
    {
      return (data[0]&MASK_TZ_MIN)==(ds.data[0]&MASK_TZ_MIN);
    }

    sint32 evalTimezoneDelta(const Datestamp& ds) const;

    uint64 getComparable() const;

    void set(uint32 s, uint32 us);

    uint32 data[2];
    static sint16 locTZMinutes;

    friend class Time::Clock;
    friend class EXNGPrivate::DatestampModifier;
};

#define YEAR_ZERO 1900

//# include XP_INCLUDE_PLATFORM("systemlib/time_native.hpp")

# include <private/systemlib/time.hpp>
# include <systemlib/time_native.hpp>

#endif
