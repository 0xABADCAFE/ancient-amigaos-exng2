///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         systemlib/time.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Time class
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
#include <ctime>

using namespace std;
using namespace Time;

bool Time::leapYear(sint32 year)
{
  if ((year % 4) == 0) {
    if ((year % 100) == 0) {
      if ((year % 400) == 0) {
        return true;
      }
      else {
        return false;
      }
    }
    else {
      return true;
    }
  }
  else {
    return false;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Interval::set(sint32 dy, sint32 hr, sint32 mn, sint32 sc, sint32 ms)
{
  millis =  (sint64)ms +
            ((sint64)sc * MILLIS_PER_SEC) +
            ((sint64)mn * MILLIS_PER_MIN) +
            ((sint64)hr * MILLIS_PER_HOUR) +
            ((sint64)dy * MILLIS_PER_DAY);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint16 Datestamp::locTZMinutes = 0;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Datestamp::set(uint32 y,  uint16 m, uint16 d, uint16 hr, uint16 mn, uint16 sc, uint16 ms)
{
  sc += (ms/1000);
  ms %= 1000;

  tm timeData = {
    sc,
    mn,
    hr,
    d,
    m - 1,
    y - YEAR_ZERO,
    0, 0, 0
#if defined(__GNUC__) && (__GNUC__ > 3)
    ,0, 0
#endif
  };

  if (mktime(&timeData)<0) {
    THROW_NSX(Error, Range());
  }

  data[0] = ((uint32)locTZMinutes)          << OFS_TZ_MIN  |
            (timeData.tm_year + YEAR_ZERO)  << OFS_YEAR    |
            (timeData.tm_mon  + 1);
  data[1] = (ms)                            << OFS_MS      |
            (timeData.tm_sec)               << OFS_SEC     |
            (timeData.tm_min)               << OFS_MIN     |
            (timeData.tm_hour)              << OFS_HOUR    |
            (timeData.tm_mday)              << OFS_DAY;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Datestamp::operator==(const Datestamp& ds) const
{
  // if both timestamps have the same timezone, comparison is trivial
  if (sameTimezone(ds)) {
    return (data[0]==ds.data[0] && data[1]==ds.data[1]);
  }
  else {
    // convert each to comparable value (basically seconds<<10 + ms)
    uint64 t1 = getComparable();
    uint64 t2 = ds.getComparable() + (evalTimezoneDelta(ds)<<OFS_SEC);
    return t1<t2;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Datestamp::operator< (const Datestamp& ds) const
{
  // if both timestamps have the same timezone, comparison is trivial

  if (sameTimezone(ds)) {
  #if (X_ENDIAN == XA_BIGENDIAN)
    return *((const uint64*)data) < *((const uint64*)ds.data);
  #else
    uint64 t2 = (uint64)(ds.data[0])<<32 | ds.data[1];
    uint64 t1 = (uint64)(data[0])<<32 | data[1];
    return t1<t2;
  #endif
  }
  else {
    // convert each to comparable value (basically seconds<<10 + ms)
    uint64 t1 = getComparable();
    uint64 t2 = ds.getComparable() + (evalTimezoneDelta(ds)<<OFS_SEC);
    return t1<t2;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Datestamp::operator<=(const Datestamp& ds) const
{
  // if both timestamps have the same timezone, comparison is trivial

  if (sameTimezone(ds)) {
  #if (X_ENDIAN == XA_BIGENDIAN)
    return *((const uint64*)data) < *((const uint64*)ds.data);
  #else
    uint64 t2 = (uint64)(ds.data[0])<<32 | ds.data[1];
    uint64 t1 = (uint64)(data[0])<<32 | data[1];
    return t1<=t2;
  #endif
  }
  else {
    // convert each to comparable value (basically seconds<<10 + ms)
    uint64 t1 = getComparable();
    uint64 t2 = ds.getComparable() + (evalTimezoneDelta(ds)<<OFS_SEC);
    return t1<=t2;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Datestamp& Datestamp::operator+=(const Time::Interval& i)
{
/*
void Datestamp::set(uint32 y,  uint16 m, uint16 d, uint16 hr, uint16 mn, uint16 sc, uint16 ms)
*/
  sint32 ms = millisec() + i.millisecs();
  sint32 sc = sec() + i.secs();

  if (ms>999) {
    sc += ms/1000;
    ms %= 1000;
  }

  tm timeData = {
    sc,
    min()   + i.mins(),
    hour()  + i.hours(),
    day()   + i.totDays(),
    month() - 1,
    year()  - YEAR_ZERO,
    0, 0, 0
#if defined(__GNUC__) && (__GNUC__ > 3)
    ,0, 0
#endif
  };

  mktime(&timeData);

  sc = tzMinutes();

  data[0] = ((uint32)sc)                   << OFS_TZ_MIN  |
            (timeData.tm_year + YEAR_ZERO) << OFS_YEAR    |
            (timeData.tm_mon  + 1);
  data[1] = (ms)                           << OFS_MS      |
            (timeData.tm_sec)              << OFS_SEC     |
            (timeData.tm_min)              << OFS_MIN     |
            (timeData.tm_hour)             << OFS_HOUR    |
            (timeData.tm_mday)             << OFS_DAY;

  return *this;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Datestamp::setTimeZoneOffset(sint16 tz)
{
  if (tz<MIN_TZ || tz>MAX_TZ) {
    THROW_NSX(Error, Range());
  }
  data[0] &= ~(MASK_TZ_MIN);
  data[0] |= ((uint32)tz)<<OFS_TZ_MIN;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Datestamp::set(uint32 s, uint32 us)
{
  time_t t = s;

  tm* timeData = localtime(&t);

  data[0] = ((uint32)locTZMinutes)          << OFS_TZ_MIN  |
            (timeData->tm_year + YEAR_ZERO) << OFS_YEAR    |
            (timeData->tm_mon  + 1);
  data[1] = (us/1000)                       << OFS_MS      |
            (timeData->tm_sec)              << OFS_SEC     |
            (timeData->tm_min)              << OFS_MIN     |
            (timeData->tm_hour)             << OFS_HOUR    |
            (timeData->tm_mday)             << OFS_DAY;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 Datestamp::evalTimezoneDelta(const Datestamp& ds) const
{
  sint32 tz = (((const sint32*)data)[0]-((const sint32*)ds.data)[0])>>OFS_TZ_MIN;
  return tz*60;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint64 Datestamp::getComparable() const
{
  tm timeData = {
    sec(),
    min(),
    hour(),
    day(),
    month() - 1,
    year()  - YEAR_ZERO,
    0, 0, 0
#if defined(__GNUC__) && (__GNUC__ > 3)
    ,0, 0
#endif
  };

  uint64 asSeconds = (uint64)mktime(&timeData);

  return asSeconds<<OFS_SEC | (uint64)millisec();
}
