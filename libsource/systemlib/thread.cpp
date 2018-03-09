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
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <xbase.hpp>
#include <systemlib/thread.hpp>

#include <private/systemlib/error.hpp>

DECLARE_MIN_RTTI(Thread::RunObserver)
DECLARE_MIN_RTTI(Thread::StateObserver)
DECLARE_MIN_RTTI(Thread::Lockable)
DECLARE_MIN_RTTI(Thread)

#ifdef EXNG2_BUILD_AVOID_BLOAT

using namespace EXNGPrivate;

extern "C" {

  void throwThreadError(void)
  {
    throw Thread::Error();
  }

  void throwThreadSecurityViolation(void)
  {
    throw Thread::SecurityViolation();
  }

  void throwThreadStateViolation(void)
  {
    throw Thread::StateViolation();
  }

  void throwThreadStartupFailure(void)
  {
    throw Thread::StartupFailure();
  }

}

#endif
