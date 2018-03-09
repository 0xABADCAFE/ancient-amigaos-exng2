///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         iolib/streamio_error.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Stream Error
//  Comment(s):
//  Library:      System
//  Created:      2007-01-12
//  Updated:      2007-01-12
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <xbase.hpp>
#include <iolib/xsfio.hpp>

using namespace EXNGPrivate;

DECLARE_MIN_RTTI(XSF::Error)
DECLARE_MIN_RTTI(XSF::InvalidStreamTypeError)
DECLARE_MIN_RTTI(XSF::VersionError)
DECLARE_MIN_RTTI(XSF::PayloadTypeError)
DECLARE_MIN_RTTI(XSF::PayloadVersionError)
DECLARE_MIN_RTTI(XSF::BadStorableError)
DECLARE_MIN_RTTI(XSF::UnreadyStorableError)

#ifdef EXNG2_BUILD_AVOID_BLOAT
extern "C" {
  void throwXSFError(void)
  {
    throw XSF::Error();
  }

  void throwXSFInvalidStreamTypeError(void)
  {
    throw XSF::InvalidStreamTypeError();
  }

  void throwXSFVersionError(void)
  {
    throw XSF::VersionError();
  }

  void throwXSFPayloadTypeError(void)
  {
    throw XSF::PayloadTypeError();
  }

  void throwXSFPayloadVersionError(void)
  {
    throw XSF::PayloadVersionError();
  }

  void throwXSFBadStorableError(void)
  {
    throw XSF::BadStorableError();
  }

  void throwXSFUnreadyStorableError(void)
  {
    throw XSF::UnreadyStorableError();
  }
};

namespace {
  const char* xsf       = "xsf";
  const char* payload   = "payload";
};

XSF::InvalidStreamTypeError::InvalidStreamTypeError() : ResourceInvalid(xsf) {}
XSF::VersionError::VersionError()                     : ResourceVersion(xsf) {}
XSF::PayloadTypeError::PayloadTypeError()             : ResourceInvalid(payload) {}
XSF::PayloadVersionError::PayloadVersionError()       : ResourceVersion(payload) {}

#endif
