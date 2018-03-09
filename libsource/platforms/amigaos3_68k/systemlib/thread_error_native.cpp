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

using namespace OSNative;
using namespace EXNGPrivate;

namespace EXNGPrivate {
  class Unhandled68KTrap : public Error::Runtime { DEFINE_MIN_RTTI };
};

DECLARE_MIN_RTTI(Thread::Error)
DECLARE_MIN_RTTI(Thread::SecurityViolation)
DECLARE_MIN_RTTI(Thread::StateViolation)
DECLARE_MIN_RTTI(Thread::StartupFailure)
DECLARE_MIN_RTTI(EXNGPrivate::Unhandled68KTrap)


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  low level exception handling
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" {
  void trapCPU68K(void);  // assembler
  void throw68K(void)               { throw Unhandled68KTrap(); }
}

#ifndef EXNG2_BUILD_AVOID_BLOAT
# include <private/systemlib/error.hpp>
extern "C" {
  // needed by assembler components
  void throwErrorNullPointer(void)       { throw Error::NullPointer(); }
  void throwErrorZeroDivide(void)        { throw Error::ZeroDivide(); }
  void throwErrorIllegalAddress(void)    { throw Error::IllegalAddress(); }
  void throwErrorBadAlignment(void)      { throw Error::BadAlignment(); }
  void throwErrorRange(void)             { throw Error::Range(); }
}
#endif

