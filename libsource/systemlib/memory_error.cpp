///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         systemlib/memory_error.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Memory exhaustion exception
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
#include <systemlib/memory.hpp>

DECLARE_MIN_RTTI(Mem::Exhausted)

Mem::Exhausted::Exhausted(size_t s) : Error::ResourceExhausted("memory"), allocSize(s)
{
}

void Mem::Exhausted::log() const
{
  SystemLog::write(
    SystemLog::ERROR,
    "%s <failed to allocate %" XPF_U64 " bytes of %s> in %s\n",
    getClass(),
    (uint64) allocSize,
    getName(),
    Application::getStage()
  );
  Mem::debug();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  low level exception handling
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef EXNG2_BUILD_AVOID_BLOAT
namespace EXNGPrivate {
  extern "C" void throwMemExhausted(size_t s)
  {
    throw Mem::Exhausted(s);
  }
};
#endif
