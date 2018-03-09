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
#include <systemlib/logger.hpp>

DECLARE_MIN_RTTI(Application)
DECLARE_MIN_RTTI(Application::TooFewArguments)
DECLARE_MIN_RTTI(Application::InvalidArgument)
DECLARE_MIN_RTTI(Application::MissingArgument)

#ifdef EXNG2_BUILD_AVOID_BLOAT
namespace EXNGPrivate {

  void throwApplicationTooFewArguments()
  {
    throw Application::TooFewArguments();
  }

  void throwApplicationInvalidArgument(const char* name)
  {
    throw Application::InvalidArgument(name);
  }

  void throwApplicationMissingArgument(const char* name)
  {
    throw Application::MissingArgument(name);
  }
}
#endif

Application::AppStage Application::currentStage = Application::LIB_INIT;

const char* Application::stages[Application::LIB_EXIT+1] = {
  "framework init",
  "app startup",
  "app runtime",
  "app cleanup",
  "framework exit"
};

