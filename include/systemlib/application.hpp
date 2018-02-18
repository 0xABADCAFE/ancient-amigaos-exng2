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
//                Karl Churchill, Serkan YAZICI
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#ifndef _EXNG2_SYSTEMLIB_APPLICATION_HPP_
#	define _EXNG2_SYSTEMLIB_APPLICATION_HPP_

#	include <systemlib/runnable.hpp>
#	include <systemlib/startup.hpp>

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
			ARG_CASE_SENSITIVE	= 1,
			ARG_MANDATORY				= 2
		};

		static sint32				getNumArgs();
		static const char*	getArg(uint32 argNum);
		static const char*	getArgString(const char* name, const char* defVal, uint16 flags);
		static sint32				getArgInteger(const char* name, sint32 defVal, uint16 flags);
		static uint32				getArgHex(const char* name, uint32 defVal, uint16 flags);
		static uint32				getArgOct(const char* name, uint32 defVal, uint16 flags);
		static float64			getArgReal(const char* name, float64 defVal, uint16 flags);
		static bool					getArgSwitch(const char* name, uint16 flags);

		// factory and cleanup
		static Application*	createInstance();
		static void					destroyInstance(Application* app);

	protected:
		Application() {}
	private:
		Application(const Application&) : Runnable() {}
		Application& operator=(const Application&)	{ return *this; }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Implementation
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class Application::TooFewArguments : public RuntimeError { DEFINE_MIN_RTTI };
class Application::MissingArgument : public RuntimeError {
	DEFINE_MIN_RTTI
	private:
		const char* argName;

	public:
		const char* getName() const { return argName; }
		MissingArgument(const char* argName) : argName(argName) {}
};

class Application::InvalidArgument : public RuntimeError {
	DEFINE_MIN_RTTI
	private:
		const char* argName;

	public:
		const char* getName() const { return argName; }
		InvalidArgument(const char* argName) : argName(argName) {}
};

inline sint32				Application::getNumArgs()
{
	return Startup::getNumArgs();
}

inline const char*	Application::getArg(uint32 argNum)
{
	return Startup::getArg(argNum);
}

inline const char*	Application::getArgString(const char* name, const char* defVal, uint16 flags)
{
	return Startup::getArgString(name, defVal, flags);
}

inline sint32				Application::getArgInteger(const char* name, sint32 defVal, uint16 flags)
{
	return Startup::getArgInteger(name, defVal, flags);
}

inline uint32				Application::getArgHex(const char* name, uint32 defVal, uint16 flags)
{
	return Startup::getArgHex(name, defVal, flags);
}

inline uint32				Application::getArgOct(const char* name, uint32 defVal, uint16 flags)
{
	return Startup::getArgOct(name, defVal, flags);
}

inline float64			Application::getArgReal(const char* name, float64 defVal, uint16 flags)
{
	return Startup::getArgReal(name, defVal, flags);
}

inline bool					Application::getArgSwitch(const char* name, uint16 flags)
{
	return Startup::getArgSwitch(name, flags);
}


#endif
