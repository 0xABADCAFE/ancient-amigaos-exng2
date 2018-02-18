///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/amigaos3_68k/systemlib/thread_native.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Native thread classes
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

#include <systemlib/thread.hpp>
#include <systemlib/logger.hpp>
/*
#ifdef EXNG2_BUILD_LOGGED
#undef EXNG2_BUILD_LOGGED
#undef LOGGING_DECLARE_FUNCNAME
#define LOGGING_DECLARE_FUNCNAME(x)
#endif
*/
using namespace OSNative;
using namespace EXNGPrivate;

namespace EXNGPrivate {
	class Unhandled68KTrap : public RuntimeError { DEFINE_MIN_RTTI };
};

DECLARE_MIN_RTTI(Thread::ThreadError)
DECLARE_MIN_RTTI(Thread::ThreadSecurityViolation)
DECLARE_MIN_RTTI(Thread::ThreadStateViolation)
DECLARE_MIN_RTTI(Thread::ThreadStartupFailure)
DECLARE_MIN_RTTI(EXNGPrivate::Unhandled68KTrap)


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  low level exception handling
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" {
	void trapCPU68K(void);	// assembler
	void throw68K(void)
	{
		throw Unhandled68KTrap();
	}

}

