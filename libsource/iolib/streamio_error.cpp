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
//                Karl Churchill, Serkan YAZICI
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <xbase.hpp>
#include <iolib/streamio.hpp>

using namespace EXNGPrivate;

DECLARE_MIN_RTTI(IO::IOError)
DECLARE_MIN_RTTI(IO::StreamOpenError)
DECLARE_MIN_RTTI(IO::StreamCreateError)
DECLARE_MIN_RTTI(IO::StreamReadError)
DECLARE_MIN_RTTI(IO::StreamWriteError)
DECLARE_MIN_RTTI(IO::StreamSeekError)

extern "C" {
	void throwIOError(void)
	{
		throw IO::IOError();
	}

	void throwStreamOpenError(void)
	{
		throw IO::StreamOpenError();
	}

	void throwStreamCreateError(void)
	{
		throw IO::StreamCreateError();
	}

	void throwStreamReadError(void)
	{
		throw IO::StreamReadError();
	}

	void throwStreamWriteError(void)
	{
		throw IO::StreamWriteError();
	}

	void throwStreamSeekError(void)
	{
		throw IO::StreamSeekError();
	}
};

