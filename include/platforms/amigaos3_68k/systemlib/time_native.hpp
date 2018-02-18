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
//                Karl Churchill, Serkan YAZICI
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _EXNG2_SYSTEMLIB_TIME_NATIVE_HPP_
#	define _EXNG2_SYSTEMLIB_TIME_NATIVE_HPP_

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  MilliClock
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace OSNative {
	extern "C" {
		#include <proto/timer.h>
	}
};

class MilliClock {
	public:
		void			set();
		uint32		elapsed() const;
		float64		elapsedFrac() const;
	public:
		MilliClock();

	private:
		static uint32				clockFreq;
		OSNative::EClockVal	mark;
};

class Clock {
	public:
		void						set();
		const Interval&	elapsed() const;
		const Interval&	last()		const { return t; }

	public:
		Clock();

	private:
		OSNative::timeval	mark;
		mutable Interval	t;
};

#endif
