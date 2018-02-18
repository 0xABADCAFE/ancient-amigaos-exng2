///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         systemlib/startup.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Main startup code, CLI argument parsing etc
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

#include <xbase.hpp>
#include <systemlib/memory.hpp>
#include <systemlib/logger.hpp>

#include <new>

#include <cstdlib>
#include <cstring>

namespace std {
	extern "C" {
		#include <errno.h>
	}
};

DECLARE_MIN_RTTI(Application)
DECLARE_MIN_RTTI(Application::TooFewArguments)
DECLARE_MIN_RTTI(Application::InvalidArgument)
DECLARE_MIN_RTTI(Application::MissingArgument)

namespace EXNGPrivate {

	void throwTooFewArgs()
	{
		throw Application::TooFewArguments();
	}

	void throwInvalidArg(const char* name)
	{
		throw Application::InvalidArgument(name);
	}

	void throwMissingArg(const char* name)
	{
		throw Application::MissingArgument(name);
	}
}

using namespace std;
using namespace EXNGPrivate;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Runtime startup class
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32	Startup::numArgs = 0;
char**	Startup::argPtrs = 0;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Startup::init(int argN, char** argV)
{
	numArgs = argN;
	argPtrs = new char*[argN];
	for (sint32 i=0; i<argN; i++) {
		argPtrs[i] = argV[i];
	}
	// Initialise other essential core subystems
	SystemLog::init();
	Mem::init();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Startup::done()
{
	// Finalise other essential core subsystems
	Mem::done();
	SystemLog::done();
	delete[] argPtrs;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const char* Startup::getArg(uint32 argNum)
{
	if (argNum>numArgs) {
		throwTooFewArgs();
	}
	return argPtrs[argNum];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 Startup::locateArgument(const char* name, uint16 flags)
{
	if (numArgs>1) {
		for (sint32 i=0; i<numArgs; i++) {
			if (flags & Application::ARG_CASE_SENSITIVE) {
				if (strcmp(name, argPtrs[i]) == 0) {
					return i;
				}
			}
			else {
				if (stricmp(name, argPtrs[i]) == 0) {
					return i;
				}
			}
		}
	}
	if (flags & Application::ARG_MANDATORY) {
		throwMissingArg(name);
	}
	return -1;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const char* Startup::getArgString(const char* name, const char* defVal, uint16 flags)
{
	sint32 i = locateArgument(name, flags);
	if (++i == 0) {
		return defVal;
	}
	else if (i<numArgs) {
		return argPtrs[i];
	}
	throwInvalidArg(name);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 Startup::getArgInteger(const char* name, sint32 defVal, uint16 flags)
{
	// We don't use cstdlib because there is no provision for detecting garbage
	// input within the source string.

	sint32 i = locateArgument(name, flags);
	if (++i == 0) {
		return defVal;
	}
	else if (i<numArgs) {
		// work from the last character in the string backwards.
		const char*	strVal	= argPtrs[i];
		sint32			strPos	= strlen(strVal);
		sint32			result	= 0;
		sint32			scale		= 1;

		while (--strPos > 0) {
			sint32 val = strVal[strPos] - '0';
			if (val<0 || val>9) {
				throwInvalidArg(name);
			}
			result	+= val*scale;
			scale		*= 10;
		}
		// Allow first character to be minus sign indicator
		if (strVal[0] == '-') {
			result = -result;
		}
		else {
			sint32 val = strVal[0] - '0';
			if (val < 0 || val > 9) {
				throwInvalidArg(name);
			}
			result	+= val*scale;
		}
		return result;
	}
	throwInvalidArg(name);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 Startup::getArgHex(const char* name, sint32 defVal, uint16 flags)
{
	// We don't use cstdlib because there is no provision for detecting garbage
	// input within the source string.

	sint32 i = locateArgument(name, flags);
	if (++i == 0) {
		return defVal;
	}
	else if (i<numArgs) {
		// work from the last character in the string backwards.
		const char*	strVal	= argPtrs[i];
		sint32			strPos	= strlen(strVal);
		uint32			result	= 0;
		uint32			shift		= 0;

		while (--strPos >= 0) {
			sint32 val = strVal[strPos];
			if (val >= '0' && val <= '9') {
				val -= '0';
			}
			else if (val >= 'a' && val <= 'f') {
				val = 10+(val - 'a');
			}
			else if (val >= 'A' && val <= 'F') {
				val = 10+(val - 'A');
			}
			else {
				throwInvalidArg(name);
			}
			result	+= val<<shift;
			shift		+= 4;
		}
		return result;
	}
	throwInvalidArg(name);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 Startup::getArgOct(const char* name, sint32 defVal, uint16 flags)
{
	// We don't use cstdlib because there is no provision for detecting garbage
	// input within the source string.

	sint32 i = locateArgument(name, flags);
	if (++i == 0) {
		return defVal;
	}
	else if (i<numArgs) {
		// work from the last character in the string backwards.
		const char*	strVal	= argPtrs[i];
		sint32			strPos	= strlen(strVal);
		uint32			result	= 0;
		uint32			shift		= 0;

		while (--strPos >= 0) {
			sint32 val = strVal[strPos]-'0';
			if (val<0 || val>7) {
				throwInvalidArg(name);
			}
			result	+= val<<shift;
			shift		+= 3;
		}
		return result;
	}
	throwInvalidArg(name);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

float64 Startup::getArgReal(const char* name, float64 defVal, uint16 flags)
{
	// We use cstdlib here because it is able to signal an error when there
	// is a problem with the input. Granted it's errno which is pretty sucky
	// but at least we aren't using it much.

	sint32 i = locateArgument(name, flags);
	if (++i == 0) {
		return defVal;
	}
	else if (i<numArgs) {
		errno = E_OK;
		float64 result = strtod(argPtrs[i],0);
		if (errno!=E_OK) {
			errno = E_OK;
			throwInvalidArg(name);
		}
		return result;
	}
	throwInvalidArg(name);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Startup::getArgSwitch(const char* name, uint16 flags)
{
	sint32 i = locateArgument(name, flags);
	if (++i == 0) {
		return false;
	}
	return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

