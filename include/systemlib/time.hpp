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
//                Karl Churchill, Serkan YAZICI
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#ifndef _EXNG2_SYSTEMLIB_TIME_HPP_
#	define _EXNG2_SYSTEMLIB_TIME_HPP_

#	include <private/systemlib/error.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Interval
//
//  Represents a measure of time to the nearest millisecond, using 64 bit accuracy
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Interval {
	public:
		enum {
			MILLIS_PER_SEC	= 1000,
			MILLIS_PER_MIN	= 60000,
			MILLIS_PER_HOUR	= 3600000,
			MILLIS_PER_DAY	= 86400000,
			SECS_PER_MIN		= 60,
			SECS_PER_HOUR		= 360,
			SECS_PER_DAY		= 86400,
			MINS_PER_HOUR		= 60,
			MINS_PER_DAY		= 1440,
			HOURS_PER_DAY		= 24
		};

		sint64	totMillis()	const { return millis; }
		sint64	totSecs()		const { return millis/MILLIS_PER_SEC; }
		sint64	totMins()		const { return millis/MILLIS_PER_MIN; }
		sint64	totHours()	const { return millis/MILLIS_PER_HOUR; }
		sint64	totDays()		const { return millis/MILLIS_PER_DAY; }
		sint32	days()			const { return (sint32)totDays(); }
		sint32	millisecs()	const { return (sint32)(millis%MILLIS_PER_SEC); }
		sint32	secs() 			const { return (sint32)(totSecs()%SECS_PER_MIN); }
		sint32	mins()			const { return (sint32)(totMins()%MINS_PER_HOUR); }
		sint32	hours()			const { return (sint32)(totHours()%HOURS_PER_DAY); }

		void		set(sint32 dy, sint32 hr, sint32 mn, sint32 sc, sint32 ms);

		Interval&		operator+=(const Interval& t);
		Interval&		operator-=(const Interval& t);
		Interval&		operator+=(sint32 t)				{ millis += t; return *this; }
		Interval&		operator-=(sint32 t)				{ millis -= t; return *this; }
		Interval&		operator*=(sint32 t)				{ millis *= t; return *this; }
		Interval&		operator/=(sint32 t)				{ if (!t) { EXNGPrivate::throwZeroDivide(); } millis /= t; return *this; }
		Interval&		operator*=(float64 f)				{ millis = (sint64)(f*(float64)millis); return *this; }
		Interval&		operator/=(float64 f)				{ millis = (sint64)(f/(float64)millis); return *this; }

		Interval() : millis(0)																					{}
		Interval(const Interval& t) : millis (t.millis)									{}
		Interval(sint64 ms) : millis (ms)																{}
		Interval(sint32 sc, sint32 ms)																	{ millis = MILLIS_PER_SEC*sc + ms; }
		Interval(sint32 dy, sint32 hr, sint32 mn, sint32 sc, sint32 ms)	{ set(dy, hr, mn, sc, ms); }

	private:
		sint64 millis;
		friend class Clock;
};


inline Interval operator+(const Interval& a, const Interval& b)
{
	Interval sum(a.totMillis() + b.totMillis());
	return sum;
}

inline Interval operator-(const Interval& a, const Interval& b)
{
	Interval diff(a.totMillis() - b.totMillis());
	return diff;
}

struct Time {
	uint32	year;
	uint16	millis;
	uint8		second;
	uint8		minute;
	uint8		hour;
	uint8		weekday;
	uint8		day;
	uint8		month;
};

#	if defined(XP_AMIGAOS3_68K)
#		include "platforms/amigaos3_68k/systemlib/time_native.hpp"
#	elif defined(XP_AMIGAOS3_PPC)
#		include "platforms/amigaos3_wos/systemlib/time_native.hpp"
#	elif defined(XP_AMIGAOS4)
#		include "platforms/amigaos4/systemlib/time_native.hpp"
#	elif defined(XP_AROS_X86)
#		include "platforms/aros_i386/systemlib/time_native.hpp"
#	elif defined(XP_MORPHOS)
#		include "platforms/morphos/systemlib/time_native.hpp"
#	elif defined(XP_LINUX_PPC)
#		include "platforms/linux_ppc/systemlib/time_native.hpp"
#	elif defined(XP_LINUX_X86)
#		include "platforms/linux_i386/systemlib/time_native.hpp"
#	elif defined(XP_WIN9X)
#		include "platforms/win9x/systemlib/time_native.hpp"
#	elif defined(XP_WIN2K)
#		include "platforms/win2k/systemlib/time_native.hpp"
#	elif defined(XP_MACOSX)
#		include "platforms/macosx/systemlib/time_native.hpp"
#	else
#		error "Platform implementation not defined"
#	endif

#endif
