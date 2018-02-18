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
//                Karl Churchill, Serkan YAZICI
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#ifndef _EXNG2_SYSTEMLIB_ERROR_PRIVATE_HPP_
#	define _EXNG2_SYSTEMLIB_ERROR_PRIVATE_HPP_

namespace EXNGPrivate {
	extern "C" {
		void throwInvalidValue(void);
		void throwNullPointer(void);
		void throwZeroDivide(void);
		void throwIllegalAddress(void);
		void throwBadAlignment(void);
		void throwRangeError(void);
		void throwObjectModified(void);
		void throwObjectDestroyed(void);
		void throwResourceError(const char* name);
		void throwResourceInvalid(const char* name);
		void throwResourceExhausted(const char* name);
		void throwResourceUnavailable(const char* name);
		void throwResourceLocked(const char* name);
		void throwResourceVersion(const char* name);
	};
};

#endif
