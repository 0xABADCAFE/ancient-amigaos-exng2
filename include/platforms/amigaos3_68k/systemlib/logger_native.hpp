///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         include/systemlib/logger.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Top level include, must be included by all EXNG2 applications.
//  Comment(s):
//  Library:      Startup
//  Created:      2006-10-08
//  Updated:      2006-10-08
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _EXNG2_SYSTEMLIB_LOGGER_NATIVE_HPP_
# define _EXNG2_SYSTEMLIB_LOGGER_NATIVE_HPP_

# include <cstdio>

class SystemLog {

  public:
    typedef enum {
      QUIET       = 0,
      ERRORS      = 1,
      WARNINGS    = 2,
      ALL         = 3,
    } Verbosity;

    typedef enum {
      ERROR   = 1,
      WARNING = 2,
      INFO    = 3
    } Level;

    static void       write(Level l, const char* msg, ...);
    static Verbosity  setVerbosity(Verbosity v);

  protected:
    static void       lock();
    static void       printf(Level l, const char* msg, ...);
    static void       unlock();


  private:
    static void       init();
    static void       done();

    static Verbosity  verbosity;
    static std::FILE* logFile;
    static OSNative::SignalSemaphore* logSemaphore;

    friend class Startup;

    LOGGING_DEFINE_CLASSNAME
};

inline void SystemLog::lock()
{
  OSNative::ObtainSemaphore(logSemaphore);
}

inline void SystemLog::unlock()
{
  std::fflush(logFile);
  OSNative::ReleaseSemaphore(logSemaphore);
}



#endif
