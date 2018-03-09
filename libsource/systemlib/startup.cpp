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
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <xbase.hpp>
#include <systemlib/memory.hpp>
#include <systemlib/logger.hpp>
#include <systemlib/cpu.hpp>
#include <systemlib/time.hpp>
#include <private/systemlib/error.hpp>

#include <new>

#include <cstdlib>
#include <cstring>

namespace std {
  extern "C" {
    #include <errno.h>
  }
};

#ifdef EXNG2_BUILD_AVOID_BLOAT
namespace EXNGPrivate {
  void throwApplicationTooFewArguments();
  void throwApplicationInvalidArgument(const char* name);
  void throwApplicationMissingArgument(const char* name);
}
#endif

using namespace std;
using namespace EXNGPrivate;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Runtime startup class
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32  Startup::numArgs = 0;
char**  Startup::argPtrs = 0;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Startup::init(int argN, char** argV)
{
  numArgs = argN;
  argPtrs = argV;
  // Initialise other essential core subystems
  SystemLog::init();
  Mem::init();
  CPU::init();
  Time::Clock::init();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Startup::done()
{
  // Finalise other essential core subsystems
  CPU::done();
  Mem::done();
  SystemLog::done();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const char* Startup::getArg(uint32 argNum)
{
  if ((sint32)argNum>numArgs) {
    THROW_NSX(Application, TooFewArguments());
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
        if (strcasecmp(name, argPtrs[i]) == 0) {
          return i;
        }
      }
    }
  }
  if (flags & Application::ARG_MANDATORY) {
    THROW_NSX(Application, MissingArgument(name));
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
  THROW_NSX(Application, InvalidArgument(name));
  return 0;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint64 Startup::getArgInteger(const char* name, sint64 defVal, uint16 base, uint16 flags)
{
  // We don't use cstdlib because there is no provision for detecting garbage
  // input within the source string.

  sint32 i = locateArgument(name, flags);
  if (++i == 0) {
    return defVal;
  }
  else if (i<numArgs) {
    char*   endPtr;
    sint64  result = strtoll(argPtrs[i], &endPtr, (int)base);
    if (*endPtr) {
      THROW_NSX(Application, InvalidArgument(name));
    }
    return result;
  }
  THROW_NSX(Application, InvalidArgument(name));
  return 0;
}

uint64 Startup::getArgUnsigned(const char* name, uint64 defVal, uint16 base, uint16 flags)
{
  // We don't use cstdlib because there is no provision for detecting garbage
  // input within the source string.

  sint32 i = locateArgument(name, flags);
  if (++i == 0) {
    return defVal;
  }
  else if (i<numArgs) {
    char*   endPtr;
    uint64  result = strtoull(argPtrs[i], &endPtr, (int)base);
    if (*endPtr) {
      THROW_NSX(Application, InvalidArgument(name));
    }
    return result;
  }
  THROW_NSX(Application, InvalidArgument(name));
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
    errno = 0;
    float64 result = strtod(argPtrs[i],0);
    if (errno!=0) {
      errno = 0;
      THROW_NSX(Application, InvalidArgument(name));
    }
    return result;
  }
  THROW_NSX(Application, InvalidArgument(name));
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

