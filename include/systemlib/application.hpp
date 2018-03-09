///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         systemlib/application.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Application class definition
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


#ifndef _EXNG2_SYSTEMLIB_APPLICATION_HPP_
# define _EXNG2_SYSTEMLIB_APPLICATION_HPP_

# include <systemlib/runnable.hpp>
# include <systemlib/startup.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Application interface
//
//  Application* Application::createInstance()
//
//  You must provide this function. It is expected to return an instance of your derived Application class.
//  You must also initialise any EXNG library modules that you use before you instansiate your Application if your
//  application derives any class belonging to that library, e.g:
//
//  Application* Application::createInstance()
//  {
//    Graphics::init();
//    return new MyGraphicApplication();
//  }
//
//
//  void Application::destroyInstance(Application* app)
//
//  You must provide this function. It is expected to destroy an instance of your derived Application class and should
//  be able to gracefully handle the case where app is null.
//  You must also finalize any EXNG modules that you used after you destroy your application, e.g:
//
//  void Application::destroyInstance(Application* app)
//  {
//    delete app;
//    Graphics::done();
//  }
//
//  sint32 Application::run()
//
//  You must override this method to provide the entry point for your application class. It will be called after your
//  application has been sucessfully instansiated.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Application : public Runnable, private Startup {
  DEFINE_MIN_RTTI
  public:
    // application exceptions
    class TooFewArguments;
    class MissingArgument;
    class InvalidArgument;

    // startup argument flags
    enum {
      ARG_CASE_SENSITIVE  = 1,
      ARG_MANDATORY       = 2,

      ARG_MIN_BASE        = 2,
      ARG_MAX_BASE        = 36
    };

    static sint32       getNumArgs();
    static const char*  getArg(uint32 argNum);
    static const char*  getArgString(const char* name, const char* defVal, uint16 flags);
    static sint64       getArgInteger(const char* name, sint64 defVal, uint16 base, uint16 flags);
    static uint64       getArgUnsigned(const char* name, uint64 defVal, uint16 base, uint16 flags);

    static sint64       getArgInteger(const char* name, sint64 defVal, uint16 flags);
    static uint64       getArgHex(const char* name, uint64 defVal, uint16 flags);
    static uint64       getArgOct(const char* name, uint64 defVal, uint16 flags);
    static uint64       getArgBin(const char* name, uint64 defVal, uint16 flags);
    static float64      getArgReal(const char* name, float64 defVal, uint16 flags);
    static bool         getArgSwitch(const char* name, uint16 flags);

    // factory and cleanup
    static Application* createInstance();
    static void         destroyInstance(Application* app);

    // logging assist
    static const char*  getStage()
    {
      return stages[currentStage];
    }

  protected:
    Application() {}
  private:
    Application(const Application&) : Runnable() {}
    Application& operator=(const Application&)  { return *this; }

    typedef enum {
      LIB_INIT    = 0,
      APP_STARTUP = 1,
      APP_RUNTIME = 2,
      APP_CLEANUP = 3,
      LIB_EXIT    = 4
    } AppStage;

    static void         setStage(AppStage stage) { currentStage = stage; }
    static AppStage     currentStage;
    static const char*  stages[LIB_EXIT+1];
    friend int main(int, char**);
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Implementation
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class Application::TooFewArguments : virtual public ::Error::Runtime { DEFINE_MIN_RTTI };
class Application::MissingArgument : public ::Error::Resource {
  DEFINE_MIN_RTTI
  public:
    MissingArgument(const char* argName) : Resource(argName) {}
};

class Application::InvalidArgument : public ::Error::Resource, public ::Error::InvalidValue {
  DEFINE_MIN_RTTI
  public:
    InvalidArgument(const char* argName) : Resource(argName) {}
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline sint32       Application::getNumArgs()
{
  return Startup::getNumArgs();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline const char*  Application::getArg(uint32 argNum)
{
  return Startup::getArg(argNum);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline const char*  Application::getArgString(const char* name, const char* defVal, uint16 flags)
{
  return Startup::getArgString(name, defVal, flags);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline sint64       Application::getArgInteger(const char* name, sint64 defVal, uint16 base, uint16 flags)
{
  return Startup::getArgInteger(name, defVal, base, flags);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline sint64       Application::getArgInteger(const char* name, sint64 defVal, uint16 flags)
{
  return Startup::getArgInteger(name, defVal, 10, flags);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline uint64       Application::getArgUnsigned(const char* name, uint64 defVal, uint16 base, uint16 flags)
{
  return Startup::getArgInteger(name, defVal, base, flags);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline uint64       Application::getArgHex(const char* name, uint64 defVal, uint16 flags)
{
  return Startup::getArgUnsigned(name, defVal, 16, flags);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline uint64       Application::getArgOct(const char* name, uint64 defVal, uint16 flags)
{
  return Startup::getArgUnsigned(name, defVal, 8, flags);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline uint64       Application::getArgBin(const char* name, uint64 defVal, uint16 flags)
{
  return Startup::getArgUnsigned(name, defVal, 2, flags);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline float64      Application::getArgReal(const char* name, float64 defVal, uint16 flags)
{
  return Startup::getArgReal(name, defVal, flags);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline bool         Application::getArgSwitch(const char* name, uint16 flags)
{
  return Startup::getArgSwitch(name, flags);
}


#endif
