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
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <xbase.hpp>
#include <iolib/streamio.hpp>

using namespace EXNGPrivate;

DECLARE_MIN_RTTI(IO::Error)
DECLARE_MIN_RTTI(IO::OpenError)
DECLARE_MIN_RTTI(IO::CreateError)
DECLARE_MIN_RTTI(IO::ReadError)
DECLARE_MIN_RTTI(IO::WriteError)
DECLARE_MIN_RTTI(IO::SeekError)
DECLARE_MIN_RTTI(IO::TimeoutError)

#ifdef EXNG2_BUILD_AVOID_BLOAT
extern "C" {
  void throwIOError(void)
  {
    throw IO::Error();
  }

  void throwIOOpenError(void)
  {
    throw IO::OpenError();
  }

  void throwIOCreateError(void)
  {
    throw IO::CreateError();
  }

  void throwIOReadError(void)
  {
    throw IO::ReadError();
  }

  void throwIOWriteError(void)
  {
    throw IO::WriteError();
  }

  void throwIOSeekError(void)
  {
    throw IO::SeekError();
  }

  void throwIOTimeoutError(void)
  {
    throw IO::TimeoutError();
  }
};
#endif

