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
//                Karl Churchill, Serkan YAZICI
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

int main (int argN, char** argV)
{
	static const char* errorString[] = {
		"Unhandled %s in startup: argument '%s' %s\n",
		"Unhandled %s in startup: resource '%s' %s\n",
		"Unhandled %s in startup\n",
		"Unhandled %s in cleanup\n"
	};
	Application*	app = 0;
	sint32				returnVal = 0;

	try {
		Startup::init(argN, argV);
		SystemLog::write(SystemLog::INFO, "eXtropia C++ framework compiled with EXNG2_BUILD_LOGGED option\n");
		SystemLog::write(SystemLog::INFO, "Startup complete, creating application instance\n");
		app = Application::createInstance();
		SystemLog::write(SystemLog::INFO, "Application instance created, invoking run()\n");
		returnVal = app->run();
	}
	catch (Application::MissingArgument& arg) {
		SystemLog::write(SystemLog::ERROR, errorString[0], arg.getClass(), arg.getName(), "is required");
	}
	catch (Application::InvalidArgument& arg) {
		SystemLog::write(SystemLog::ERROR, errorString[0], arg.getClass(), arg.getName(), "is invalid");
	}
	catch (ResourceUnavailable& res) {
		SystemLog::write(SystemLog::ERROR, errorString[1], res.getClass(), res.getResourceName(), " is unavailable");
	}
	catch (ResourceError& err) {
		SystemLog::write(SystemLog::ERROR, errorString[1], err.getClass(), err.getResourceName(), " encountered a problem");
	}
	catch (RuntimeError& err) {
		SystemLog::write(SystemLog::ERROR, errorString[2], err.getClass());
	}
	catch (...) {
		SystemLog::write(SystemLog::ERROR, errorString[2], "exception");
	}
	try {
		SystemLog::write(SystemLog::INFO, "Destroying application\n");
		Application::destroyInstance(app);
	}
	catch (RuntimeError& err) {
		SystemLog::write(SystemLog::ERROR, errorString[3], err.getClass());
	}
	catch (...) {
		SystemLog::write(SystemLog::ERROR, errorString[3], "exception");
	}
	Startup::done();
	return (int)returnVal;
}

#else

int main (int argN, char** argV)
{
	Application*	app = 0;
	sint32				returnVal = 0;
	try {
		Startup::init(argN, argV);
		app = Application::createInstance();
		returnVal = app->run();
	}
	catch (...) {	}
	try {
		Application::destroyInstance(app);
	}
	catch (...) { }
	Startup::done();
	return (int)returnVal;
}

#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


