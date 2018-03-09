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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Main program entry point
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef EXNG2_BUILD_LOGGED

#include <systemlib/logger.hpp>

// Verbose logging
// We aim to be able to report untrapped exceptions arising at each
// distinct stage

int main (int argN, char** argV)
{
  static const char* errorTemplate = "Unspecified exception during %s\n";
  Application*  app       = 0;
  sint32        returnVal = 0;

  try {
    Startup::init(argN, argV);
    SystemLog::write(SystemLog::INFO, "eXtropia C++ framework compiled with EXNG2_BUILD_LOGGED option\n");
    SystemLog::write(SystemLog::INFO, "Startup complete, creating application instance\n");

    Application::setStage(Application::APP_STARTUP);
    app = Application::createInstance();

    SystemLog::write(SystemLog::INFO, "Application instance created, invoking run()\n");

    Application::setStage(Application::APP_RUNTIME);
    returnVal = app->run();
  }
  catch (Error::Runtime& err) {
    err.log();
  }
  catch (...) {
    SystemLog::write(
      SystemLog::ERROR,
      errorTemplate,
      Application::getStage()
    );
  }

  // cleanup
  try {
    SystemLog::write(SystemLog::INFO, "Destroying application\n");
    Application::setStage(Application::APP_CLEANUP);
    Application::destroyInstance(app);
  }
  catch (Error::Runtime& err) {
    err.log();
  }
  catch (...) {
    SystemLog::write(
      SystemLog::ERROR,
      errorTemplate,
      Application::getStage()
    );
  }
  SystemLog::write(SystemLog::INFO, "Freeing framework\n");
  Startup::done();
  return (int)returnVal;
}

#else

int main (int argN, char** argV)
{
  Application*  app = 0;
  sint32        returnVal = 0;
  try {
    Startup::init(argN, argV);
    Application::setStage(Application::APP_STARTUP);
    app = Application::createInstance();
    Application::setStage(Application::APP_RUNTIME);
    returnVal = app->run();
  }
  catch (...) { }
  try {
    Application::setStage(Application::APP_CLEANUP);
    Application::destroyInstance(app);
  }
  catch (...) { }
  Startup::done();
  return (int)returnVal;
}

#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


