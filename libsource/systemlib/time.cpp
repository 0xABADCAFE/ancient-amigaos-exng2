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
//                Karl Churchill, Serkan YAZICI
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <xbase.hpp>
#include <systemlib/time.hpp>


void Interval::set(sint32 dy, sint32 hr, sint32 mn, sint32 sc, sint32 ms)
{
	millis =	(sint64)ms +
			 			((sint64)sc * MILLIS_PER_SEC) +
			 			((sint64)mn * MILLIS_PER_MIN) +
			 			((sint64)hr * MILLIS_PER_HOUR) +
			 			((sint64)dy * MILLIS_PER_DAY);
}

