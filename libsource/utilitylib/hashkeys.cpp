///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         utilitylib/hashkeyd.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Simple text hashing
//  Comment(s):
//  Library:      utility
//  Created:      2007-04-07
//  Updated:      2007-04-07
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill, Serkan YAZICI
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <xbase.hpp>
#include <utilitylib/hashkeys.hpp>
#include <private/systemlib/error.hpp>

uint32 Key32::evalHash(const char* text)
{
	if (!text) {
		EXNGPrivate::throwNullPointer();
	}
	ruint32 v = 0;
	ruint32 m = 0x80000000;
	ruint8* p = (uint8*)text;
	while (*p) {
		// bitwise rotate (so bits are never lost) and xor with byte
		v = (v<<1) | ((v&m) ? 1UL : 0);
		v ^= (uint32) *p++;
	}
	return v;
}

////////////////////////////////////////////////////////////////////////////////

uint64 Key64::evalHash(const char* text)
{
	if (!text) {
		EXNGPrivate::throwNullPointer();
	}
	uint64 v = 0;
	ruint8* p = (uint8*)text;
	while (*p) {
		// bitwise rotate (so bits are never lost) and xor with byte
		v = (v<<1) | ((v&0x8000000000000000ULL) ? 1ULL : 0);
		v ^= (uint64) *p++;
	}
	return v;
}

