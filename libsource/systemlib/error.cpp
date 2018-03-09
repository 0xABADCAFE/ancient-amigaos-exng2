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
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <xbase.hpp>
#include <systemlib/logger.hpp>
#include <private/systemlib/error.hpp>
#include <typeinfo>

DECLARE_MIN_RTTI(Error::Runtime)
DECLARE_MIN_RTTI(Error::InvalidValue)
DECLARE_MIN_RTTI(Error::NullPointer)
DECLARE_MIN_RTTI(Error::ZeroDivide)
DECLARE_MIN_RTTI(Error::IllegalAddress)
DECLARE_MIN_RTTI(Error::BadAlignment)
DECLARE_MIN_RTTI(Error::Range)
DECLARE_MIN_RTTI(Error::ObjectModified)
DECLARE_MIN_RTTI(Error::ObjectDestroyed)
DECLARE_MIN_RTTI(Error::ObjectStateViolation)
DECLARE_MIN_RTTI(Error::Resource)
DECLARE_MIN_RTTI(Error::ResourceInvalid)
DECLARE_MIN_RTTI(Error::ResourceExhausted)
DECLARE_MIN_RTTI(Error::ResourceUnavailable)
DECLARE_MIN_RTTI(Error::ResourceLocked)
DECLARE_MIN_RTTI(Error::ResourceVersion)

const char* Error::Runtime::getClass() const
{
  return typeid(*this).name();
}

void Error::Runtime::log() const
{
  SystemLog::write(
    SystemLog::ERROR,
    "%s in %s\n",
    getClass(),
    Application::getStage()
  );
}

void Error::Resource::log() const
{
  SystemLog::write(
    SystemLog::ERROR,
    "%s <%s> in %s\n",
    getClass(),
    getName(),
    Application::getStage()
  );
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Private Exception throwers, Used to avoid inline exception bloat on older gcc
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef EXNG2_BUILD_AVOID_BLOAT
extern "C" {
  void throwErrorInvalidValue(void)                     { throw Error::InvalidValue(); }
  void throwErrorNullPointer(void)                      { throw Error::NullPointer(); }
  void throwErrorZeroDivide(void)                       { throw Error::ZeroDivide(); }
  void throwErrorIllegalAddress(void)                   { throw Error::IllegalAddress(); }
  void throwErrorBadAlignment(void)                     { throw Error::BadAlignment(); }
  void throwErrorRange(void)                            { throw Error::Range(); }
  void throwErrorObjectModified(void)                   { throw Error::ObjectModified(); }
  void throwErrorObjectDestroyed(void)                  { throw Error::ObjectDestroyed(); }
  void throwErrorObjectStateViolation(void)             { throw Error::ObjectStateViolation(); }
  void throwErrorResourceError(const char* name)        { throw Error::Resource(name); }
  void throwErrorResourceInvalid(const char* name)      { throw Error::ResourceInvalid(name); }
  void throwErrorResourceExhausted(const char* name)    { throw Error::ResourceExhausted(name); }
  void throwErrorResourceUnavailable(const char* name)  { throw Error::ResourceUnavailable(name); }
  void throwErrorResourceLocked(const char* name)       { throw Error::ResourceLocked(name); }
  void throwErrorResourceVersion(const char* name)      { throw Error::ResourceVersion(name); }
}
#endif

