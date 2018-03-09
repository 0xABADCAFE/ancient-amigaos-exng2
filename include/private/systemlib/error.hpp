///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         private/systemlib/error.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Exception throwing utils for asm and private library code
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



#ifndef _EXNG2_SYSTEMLIB_ERROR_PRIVATE_HPP_
# define _EXNG2_SYSTEMLIB_ERROR_PRIVATE_HPP_

namespace EXNGPrivate {
  extern "C" {
    void throwErrorInvalidValue(void);
    void throwErrorNullPointer(void);
    void throwErrorZeroDivide(void);
    void throwErrorIllegalAddress(void);
    void throwErrorBadAlignment(void);
    void throwErrorRange(void);
    void throwErrorObjectModified(void);
    void throwErrorObjectDestroyed(void);
    void throwErrorObjectStateViolation(void);
    void throwErrorResourceError(const char* name);
    void throwErrorResourceInvalid(const char* name);
    void throwErrorResourceExhausted(const char* name);
    void throwErrorResourceUnavailable(const char* name);
    void throwErrorResourceLocked(const char* name);
    void throwErrorResourceVersion(const char* name);
  };
};

#endif
