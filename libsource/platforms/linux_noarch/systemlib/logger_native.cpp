///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/linux_noarch/systemlib/logger_native.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Debug logging
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
#include <systemlib/application.hpp>
#include <private/systemlib/error.hpp>


#include <cstdarg>
#include <syslog.h>

using namespace EXNGPrivate;

SystemLog::Verbosity  SystemLog::verbosity    = SystemLog::QUIET;
const char*           SystemLog::ident        = 0;
int                   SystemLog::facility     = 0;
int                   SystemLog::level[3]     = { LOG_ERR, LOG_WARNING, LOG_NOTICE };
//std::FILE*            SystemLog::logFile      = 0;

LOGGING_DECLARE_CLASSNAME(SystemLog)

void SystemLog::init()
{
  int debugLevel  = Application::getArgInteger("-sysdebug", 0, Application::ARG_CASE_SENSITIVE);
  facility        = Application::getArgInteger("-logfacility", LOG_LOCAL0, Application::ARG_CASE_SENSITIVE);
  ident           = Application::getArg(0); // name of the executable

  if (debugLevel>=QUIET && debugLevel <= INFO) {
    verbosity = (Verbosity) debugLevel;
  }
  #ifdef EXNG2_BUILD_LOGGED
  write(INFO, "%s - opened logfile at verbosity level %d\n", loggingClassName, verbosity);
  #endif
}

void SystemLog::done()
{
  #ifdef EXNG2_BUILD_LOGGED
  write(INFO, "%s - closing logfile\n", loggingClassName);
  #endif
}

void SystemLog::lock()
{
  openlog(ident, LOG_PID, facility);
}

void SystemLog::unlock()
{
  closelog();
}


SystemLog::Verbosity SystemLog::setVerbosity(SystemLog::Verbosity v)
{
  Verbosity oldV = verbosity;
  verbosity = v;
  return oldV;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SystemLog::write(Level level, const char* fmt, ...)
{
  if ((int)level <= (int)verbosity) {
    va_list args;
    openlog(ident, LOG_PID, facility);
    va_start(args, fmt);
    vsyslog(facility|level, fmt, args);
    va_end(args);
    closelog();
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SystemLog::printf(Level level, const char* fmt, ...)
{
  if ((int)level <= (int)verbosity) {
    va_list args;
    va_start(args, fmt);
    vsyslog(facility|level, fmt, args);
    va_end(args);
  }
}


/*
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SystemLog::init()
{
  sint32      debugLevel    = Application::getArgInteger("-sysdebug", 0, Application::ARG_CASE_SENSITIVE);
  const char* logName       = Application::getArgString("-syslog", 0, Application::ARG_CASE_SENSITIVE);
  const char* usingLogName  = 0;
  std::FILE*  customLog     = 0;

  if (debugLevel>=QUIET && debugLevel <= INFO) {
    verbosity = (Verbosity) debugLevel;
  }
  if (logName && (customLog = std::fopen(logName,"a")) ) {
    logFile       = customLog;
    usingLogName  = logName;
  } else {
    logFile       = stdout;
    usingLogName  = "<standard output>";
  }
  #ifdef EXNG2_BUILD_LOGGED
  write(INFO, "%s - opened logfile %s at verbosity level %d\n", loggingClassName, usingLogName, verbosity);
  #endif
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SystemLog::done()
{
  #ifdef EXNG2_BUILD_LOGGED
  write(INFO, "%s - closing logfile\n", loggingClassName);
  #endif
  if (logFile && logFile != stdout) {
    std::fclose(logFile);
  }
  if (logSemaphore) {
    FreeMem(logSemaphore, sizeof(SignalSemaphore));
  }

  #ifdef EXNG2_BUILD_PARANOID
  logFile       = 0;
  logSemaphore  = 0;
  #endif
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

SystemLog::Verbosity SystemLog::setVerbosity(SystemLog::Verbosity v)
{
  Verbosity oldV = verbosity;
  verbosity = v;
  return oldV;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SystemLog::write(Level level, const char* msg, ...)
{
  static const char levels[] = {' ','E','W','I'};

  static time_t last = 0;

  ObtainSemaphore(logSemaphore);

  if (logFile && ((int)level <= (int)verbosity)) {
    tm*     timeData;
    time_t  sysTime;
    time(&sysTime);

    if (sysTime!=last) {
      timeData = localtime(&sysTime);
      last = sysTime;
      std::fprintf(logFile, "%s\n", asctime(timeData));
    }

    va_list argList;
    va_start(argList, msg);
    std::fprintf(logFile, "[%c]: ", (int)levels[level]);
    std::vfprintf(logFile, msg, argList);
    std::fflush(logFile);
    va_end(argList);

  }
  ReleaseSemaphore(logSemaphore);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SystemLog::printf(Level level, const char* msg, ...)
{
  if (logFile && ((int)level <= (int)verbosity)) {
    va_list argList;
    va_start(argList, msg);
    std::vfprintf(logFile, msg, argList);
    va_end(argList);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

*/
