///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         iolib/streamio.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  IO definitions
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

#ifndef _EXNG2_IOLIB_XSFIO_PRIVATE_HPP_
# define _EXNG2_IOLIB_XSFIO_PRIVATE_HPP_

#ifdef EXNG2_BUILD_AVOID_BLOAT
namespace EXNGPrivate {
  extern "C" {
    void throwXSFError(void);
    void throwXSFInvalidStreamTypeError(void);
    void throwXSFVersionError(void);
    void throwXSFPayloadTypeError(void);
    void throwXSFPayloadVersionError(void);
    void throwXSFBadStorableError(void);
    void throwXSFUnreadyStorableError(void);

  };
};
#endif

#endif
