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
#include <iolib/xsfio.hpp>

using namespace EXNGPrivate;

DECLARE_MIN_RTTI(XSF::XSFError)
DECLARE_MIN_RTTI(XSF::IncompatibleVersionError)
DECLARE_MIN_RTTI(XSF::IncompatibleFormatError)
DECLARE_MIN_RTTI(XSF::IncompatibleSubformatError)
DECLARE_MIN_RTTI(XSF::BadStorableError)
DECLARE_MIN_RTTI(XSF::UnreadyStorableError)

extern "C" {
	void throwXSFError(void)
	{
		throw XSF::XSFError();
	}

	void throwIncompatibleVersionError(void)
	{
		throw XSF::IncompatibleVersionError();
	}

	void throwIncompatibleFormatError(void)
	{
		throw XSF::IncompatibleFormatError();
	}

	void throwIncompatibleSubformatError(void)
	{
		throw XSF::IncompatibleSubformatError();
	}

	void throwBadStorableError(void)
	{
		throw XSF::BadStorableError();
	}

	void throwUnreadyStorableError(void)
	{
		throw XSF::UnreadyStorableError();
	}
};

