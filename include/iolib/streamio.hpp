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

#ifndef _EXNG2_IOLIB_STREAMIO_HPP_
#	define _EXNG2_IOLIB_STREAMIO_HPP_

#	include <xbase.hpp>
#	include <systemlib/error.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Base definitions
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class IO {
	public:
		// error classes
		class IOError;
		class StreamOpenError;
		class StreamCreateError;
		class StreamReadError;
		class StreamWriteError;
		class StreamSeekError;

		typedef enum {
			MODE_READ				 = 0,
			MODE_WRITE,
			MODE_APPEND,
			MODE_READTEXT,
			MODE_WRITETEXT,
			MODE_APPENDTEXT
		} OpenMode;

		typedef enum {
			FROM_START,
			FROM_CURRENT,
			FROM_END
		} SeekMode;
};

class IO::IOError						: public RuntimeError { DEFINE_MIN_RTTI };
class IO::StreamOpenError		: public IO::IOError { DEFINE_MIN_RTTI };
class IO::StreamCreateError : public IO::IOError { DEFINE_MIN_RTTI };
class IO::StreamReadError		: public IO::IOError { DEFINE_MIN_RTTI };
class IO::StreamWriteError	: public IO::IOError { DEFINE_MIN_RTTI };
class IO::StreamSeekError		: public IO::IOError { DEFINE_MIN_RTTI };

#if defined(XP_AMIGAOS3_68K)
  #include "platforms/amigaos3_68k/iolib/streamio_native.hpp"
#elif defined(XP_AMIGAOS3_PPC)
  #include "platforms/amigaos3_wos/iolib/streamio_native.hpp"
#elif defined(XP_AMIGAOS4)
  #include "platforms/amigaos4/iolib/streamio_native.hpp"
#elif defined(XP_AROS_X86)
  #include "platforms/aros_i386/iolib/streamio_native.hpp"
#elif defined(XP_MORPHOS)
  #include "platforms/morphos/iolib/streamio_native.hpp"
#elif defined(XP_LINUX_PPC)
  #include "platforms/linux_ppc/iolib/streamio_native.hpp"
#elif defined(XP_LINUX_X86)
  #include "platforms/linux_i386/iolib/streamio_native.hpp"
#elif defined(XP_WIN9X)
  #include "platforms/win9x/iolib/streamio_native.hpp"
#elif defined(XP_WIN2K)
	#include "platforms/win2k/iolib/streamio_native.hpp"
#elif defined(XP_MACOSX)
	#include "platforms/macosx/iolib/streamio_native.hpp"
#else
	#error "Platform implementation not defined"
#endif


#endif
