///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         systemlib/error.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Runtime exception definition
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

#ifndef _EXNG2_SYSTEMLIB_ERROR_HPP_
#	define _EXNG2_SYSTEMLIB_ERROR_HPP_

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Base RuntimeError class
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class RuntimeError
{
	DEFINE_MIN_RTTI
	public:
		virtual const char* getClass() const;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Basic errors
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class InvalidValue		: public RuntimeError { DEFINE_MIN_RTTI };
class NullPointer			: public RuntimeError { DEFINE_MIN_RTTI };
class ZeroDivide			: public RuntimeError { DEFINE_MIN_RTTI };
class IllegalAddress	: public RuntimeError { DEFINE_MIN_RTTI };
class BadAlignment		: public RuntimeError { DEFINE_MIN_RTTI };
class RangeError			: public RuntimeError { DEFINE_MIN_RTTI };
class ObjectModified	: public RuntimeError { DEFINE_MIN_RTTI };
class ObjectDestroyed : public RuntimeError { DEFINE_MIN_RTTI };

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Base ResourceError class
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ResourceError : public RuntimeError
{
	DEFINE_MIN_RTTI
	private:
		const char* resName;

	public:
		const char* getResourceName() const { return resName; }
		ResourceError(const char* resName) : resName(resName) {};
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Basic Resource errors
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class ResourceInvalid : public ResourceError
{
	DEFINE_MIN_RTTI
	public:
		ResourceInvalid(const char* resName) : ResourceError(resName) {}
};

class ResourceExhausted : public ResourceError
{
	DEFINE_MIN_RTTI
	public:
		ResourceExhausted(const char* resName) : ResourceError(resName) {}
};

class ResourceUnavailable	: public ResourceError
{
	DEFINE_MIN_RTTI
	public:
		ResourceUnavailable(const char* resName) : ResourceError(resName) {}
};

class ResourceLocked : public ResourceError
{
	DEFINE_MIN_RTTI
	public:
		ResourceLocked(const char* resName) : ResourceError(resName) {}
};

class ResourceVersion : public ResourceError
{
	DEFINE_MIN_RTTI
	public:
		ResourceVersion(const char* resName) : ResourceError(resName) {}
};

#	ifdef EXNG2_BUILD_AVOID_BLOAT
#		include <private/systemlib/error.hpp>
#	endif

#endif
