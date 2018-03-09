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

#ifndef _EXNG2_IOLIB_STREAMIO_PRIVATE_HPP_
# define _EXNG2_IOLIB_STREAMIO_PRIVATE_HPP_

#ifdef EXNG2_BUILD_AVOID_BLOAT
namespace EXNGPrivate {
  extern "C" {
    void throwIOError(void);
    void throwIOOpenError(void);
    void throwIOCreateError(void);
    void throwIOReadError(void);
    void throwIOWriteError(void);
    void throwIOSeekError(void);
    void throwIOTimeoutError(void);
    void throwIOSocketConnectError(void);
  };
};
#endif

#endif
