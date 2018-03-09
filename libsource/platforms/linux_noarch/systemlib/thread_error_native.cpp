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
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <systemlib/thread.hpp>
#include <systemlib/logger.hpp>
#include <private/systemlib/error.hpp>


using namespace EXNGPrivate;


DECLARE_MIN_RTTI(Thread::Error)
DECLARE_MIN_RTTI(Thread::SecurityViolation)
DECLARE_MIN_RTTI(Thread::StateViolation)
DECLARE_MIN_RTTI(Thread::StartupFailure)

