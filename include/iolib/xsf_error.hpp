///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         iolib/xsfio.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  XSF IO definitions
//  Comment(s):
//  Library:      IO
//  Created:      2007-04-19
//  Updated:      2007-04-19
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _EXNG2_IOLIB_XSF_ERROR_HPP_
# define _EXNG2_IOLIB_XSF_ERROR_HPP_

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Exception classes
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class XSF::Error                  : virtual public ::Error::Runtime { DEFINE_MIN_RTTI };

class XSF::InvalidStreamTypeError : public XSF::Error, public ::Error::ResourceInvalid {
  DEFINE_MIN_RTTI
  public:
    InvalidStreamTypeError();
};

class XSF::VersionError           : public XSF::Error, public ::Error::ResourceVersion {
  DEFINE_MIN_RTTI
  public:
    VersionError();
};

class XSF::PayloadTypeError       : public XSF::Error, public ::Error::ResourceInvalid {
  DEFINE_MIN_RTTI
  public:
    PayloadTypeError();
};

class XSF::PayloadVersionError    : public XSF::Error, public ::Error::ResourceVersion {
  DEFINE_MIN_RTTI
  public:
    PayloadVersionError();
};

class XSF::UnreadyStorableError   : public XSF::Error, public ::Error::ObjectStateViolation { DEFINE_MIN_RTTI };
class XSF::BadStorableError       : public XSF::Error       { DEFINE_MIN_RTTI };
class XSF::MachineLimitError      : public XSF::Error       { DEFINE_MIN_RTTI };

#endif
