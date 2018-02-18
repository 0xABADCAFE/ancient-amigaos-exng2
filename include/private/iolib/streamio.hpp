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
//                Karl Churchill, Serkan YAZICI
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _EXNG2_IOLIB_STREAMIO_PRIVATE_HPP_
#	define _EXNG2_IOLIB_STREAMIO_PRIVATE_HPP_

namespace EXNGPrivate {
	extern "C" {
		void throwIOError(void);
		void throwStreamOpenError(void);
		void throwStreamCreateError(void);
		void throwStreamReadError(void);
		void throwStreamWriteError(void);
		void throwStreamSeekError(void);
	};
};

#endif
