///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         systemlib/startup.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Protected interface for accessing the application startup paramterers
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

#ifndef _EXNG2_SYSTEMLIB_STARTUP_HPP_
#	define _EXNG2_SYSTEMLIB_STARTUP_HPP_


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Runtime startup class
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Startup {

	public:
		static void		init(int argN, char** argV);
		static void		done();

	protected:
		static sint32				getNumArgs() { return numArgs; }
		static const char*	getArg(uint32 argNum);
		static const char*	getArgString(const char* name, const char* defVal, uint16 flags);
		static sint32				getArgInteger(const char* name, sint32 defVal, uint16 flags);
		static sint32				getArgHex(const char* name, sint32 defVal, uint16 flags);
		static sint32				getArgOct(const char* name, sint32 defVal, uint16 flags);
		static float64			getArgReal(const char* name, float64 defVal, uint16 flags);
		static bool					getArgSwitch(const char* name, uint16 flags);

	private:
		static sint32				locateArgument(const char* name, uint16 flags);

		static sint32	numArgs;
		static char**	argPtrs;

};

#endif
