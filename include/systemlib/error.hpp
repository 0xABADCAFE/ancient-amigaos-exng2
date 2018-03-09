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
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _EXNG2_SYSTEMLIB_ERROR_HPP_
# define _EXNG2_SYSTEMLIB_ERROR_HPP_

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Base RuntimeError class
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Error {
  class Runtime;
  class InvalidValue;
  class NullPointer;
  class ZeroDivide;
  class IllegalAddress;
  class BadAlignment;
  class Range;
  class ObjectModified;
  class ObjectDestroyed;
  class ObjectStateViolation;
  class Resource;
  class ResourceInvalid;
  class ResourceExhausted;
  class ResourceUnavailable;
  class ResourceLocked;
  class ResourceVersion;
};

class Error::Runtime
{
  DEFINE_MIN_RTTI
  public:
    virtual const char* getClass() const;
    virtual void log() const;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Basic errors
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Error::InvalidValue          : virtual public Error::Runtime  { DEFINE_MIN_RTTI };
class Error::Range                 : public Error::InvalidValue     { DEFINE_MIN_RTTI };
class Error::IllegalAddress        : public Error::InvalidValue     { DEFINE_MIN_RTTI };
class Error::NullPointer           : public Error::IllegalAddress   { DEFINE_MIN_RTTI };
class Error::BadAlignment          : public Error::IllegalAddress   { DEFINE_MIN_RTTI };
class Error::ZeroDivide            : virtual public Error::Runtime  { DEFINE_MIN_RTTI };
class Error::ObjectModified        : virtual public Error::Runtime  { DEFINE_MIN_RTTI };
class Error::ObjectDestroyed       : virtual public Error::Runtime  { DEFINE_MIN_RTTI };
class Error::ObjectStateViolation  : virtual public Error::Runtime  { DEFINE_MIN_RTTI };

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Base ResourceError class
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Error::Resource : virtual public Error::Runtime
{
  DEFINE_MIN_RTTI
  private:
    const char* resName;

  public:
    const char* getName() const { return resName; }
    void        log()     const;

  public:
    Resource(const char* resName) : resName(resName) {};
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Basic Resource errors
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class Error::ResourceInvalid : public Error::Resource
{
  DEFINE_MIN_RTTI
  public:
    ResourceInvalid(const char* resName) : Resource(resName) {}
};

class Error::ResourceExhausted : public Error::Resource
{
  DEFINE_MIN_RTTI
  public:
    ResourceExhausted(const char* resName) : Resource(resName) {}
};

class Error::ResourceUnavailable : public Error::Resource
{
  DEFINE_MIN_RTTI
  public:
    ResourceUnavailable(const char* resName) : Resource(resName) {}
};

class Error::ResourceLocked : public Error::Resource
{
  DEFINE_MIN_RTTI
  public:
    ResourceLocked(const char* resName) : Resource(resName) {}
};

class Error::ResourceVersion : public Error::Resource
{
  DEFINE_MIN_RTTI
  public:
    ResourceVersion(const char* resName) : Resource(resName) {}
};


# ifdef EXNG2_BUILD_AVOID_BLOAT
#   include <private/systemlib/error.hpp>
# endif

#endif
