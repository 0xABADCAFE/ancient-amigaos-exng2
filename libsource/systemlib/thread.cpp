///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         systemlib/time.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Time class
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
#include <systemlib/thread.hpp>

DECLARE_MIN_RTTI(ThreadRunObserver)
DECLARE_MIN_RTTI(ThreadStateObserver)
DECLARE_MIN_RTTI(Lockable)
DECLARE_MIN_RTTI(Thread)

using namespace EXNGPrivate;

extern "C" {

void throwThreadError(void)
{
	throw Thread::ThreadError();
}

void throwThreadSecurityViolation(void)
{
	throw Thread::ThreadSecurityViolation();
}

void throwThreadStateViolation(void)
{
	throw Thread::ThreadStateViolation();
}

void throwThreadStartupFailure(void)
{
	throw Thread::ThreadStartupFailure();
}

}
