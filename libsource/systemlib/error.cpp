///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         systemlib/error.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Runtime error exception classes
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
#include <typeinfo>

DECLARE_MIN_RTTI(RuntimeError)
DECLARE_MIN_RTTI(InvalidValue)
DECLARE_MIN_RTTI(NullPointer)
DECLARE_MIN_RTTI(ZeroDivide)
DECLARE_MIN_RTTI(IllegalAddress)
DECLARE_MIN_RTTI(BadAlignment)
DECLARE_MIN_RTTI(RangeError)
DECLARE_MIN_RTTI(ObjectModified)
DECLARE_MIN_RTTI(ObjectDestroyed)
DECLARE_MIN_RTTI(ResourceError)
DECLARE_MIN_RTTI(ResourceInvalid)
DECLARE_MIN_RTTI(ResourceExhausted)
DECLARE_MIN_RTTI(ResourceUnavailable)
DECLARE_MIN_RTTI(ResourceLocked)
DECLARE_MIN_RTTI(ResourceVersion)


const char* RuntimeError::getClass() const
{
	return typeid(*this).name();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Private Exception throwers - Given C linkage as used by asm code. Also used to avoid inline exception bloat
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" {
	void throwInvalidValue(void)										{ throw InvalidValue(); }
	void throwNullPointer(void)											{ throw NullPointer(); }
	void throwZeroDivide(void)											{ throw ZeroDivide(); }
	void throwIllegalAddress(void)									{ throw IllegalAddress(); }
	void throwBadAlignment(void) 										{ throw BadAlignment(); }
	void throwRangeError(void)											{ throw RangeError(); }
	void throwObjectModified(void)									{ throw ObjectModified(); }
	void throwObjectDestroyed(void)									{ throw ObjectDestroyed(); }
	void throwResourceError(const char* name) 			{ throw ResourceError(name); }
	void throwResourceInvalid(const char* name) 		{ throw ResourceInvalid(name); }
	void throwResourceExhausted(const char* name) 	{ throw ResourceExhausted(name); }
	void throwResourceUnavailable(const char* name) { throw ResourceUnavailable(name); }
	void throwResourceLocked(const char* name) 			{ throw ResourceLocked(name); }
	void throwResourceVersion(const char* name) 		{ throw ResourceVersion(name); }
}

