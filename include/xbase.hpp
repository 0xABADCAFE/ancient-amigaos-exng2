///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         xbase.hpp
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
//                Karl Churchill, Serkan YAZICI
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _EXNG2_BASE_HPP_
#	define _EXNG2_BASE_HPP_

#ifndef __cplusplus
#	error "The eXtropia Studios Application Framework is for C++ use only"
#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  General Library Build options
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#define EXNG2_BUILD_PARANOID		// Paranoid safety
#define EXNG2_BUILD_LOGGED			// Low level logging
#define EXNG2_BUILD_AVOID_BLOAT	// Enable space saving code modifications

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Logging macros
//
//  LOGGING_DEFINE_CLASSNAME                  : Adds private static class name member to class definition for logging
//                                              purposes.
//
//  LOGGING_DECLARE_CLASSNAME(<class name>)   : Declares the above class name, to be used in the implementation only.
//
//  LOGGING_DECLARE_FUNCNAME(<function name>) : Declares a static function name to be used within the current method.
//
//  When EXNG2_BUILD_LOGGED is enabled, the names are accessed as loggingClassName and loggingFuncName respectively.
//  You may not depend on the existence of these variables unless you know that they have been appropriately declared
//  and that the logging mode is enabled.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifdef EXNG2_BUILD_LOGGED
#	define LOGGING_DEFINE_CLASSNAME private: static const char* loggingClassName;
#	define LOGGING_DECLARE_CLASSNAME(name) const char* name::loggingClassName = #name;
#	define LOGGING_DECLARE_FUNCNAME(name) static const char* loggingFuncName = #name "()";
#else
#	define LOGGING_DEFINE_CLASSNAME
#	define LOGGING_DECLARE_CLASSNAME(name)
#	define LOGGING_DECLARE_FUNCNAME(name)
#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Code bloat avoidance
//
//  DEFINFE_MIN_RTTI               : Adds a private member that forces the compiler (gcc 2.95.x) to emit a polymorphic
//                                   classes virtual function table / RTTI data. Make this macro the first line in the
//                                   class definition. Does nothing when EXNG2_BUILD_AVOID_BLOAT disabled.
//
//  DECLARE_MIN_RTTI(<class name>) : Declares the above member for the specified class.
//
//  THROW(<exception constructor>) : Throws the specified exception. When EXNG2_BUILD_AVOID_BLOAT enabled, replaces
//                                   the usual throw statement with a call to an external function that throws the
//                                   exception instead. These functions belong to the EXNGPrivate namespace and are
//                                   provided as an interface for library code that might use assembler or have to
//                                   be called from C code. This reduces bloat by eliminating redundant restore points
//                                   particularly within inline functions.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifdef EXNG2_BUILD_AVOID_BLOAT
#	define DEFINE_MIN_RTTI private: virtual void _dfRTTI();
#	define DECLARE_MIN_RTTI(name) void name::_dfRTTI() {}
#	define THROW(except) EXNGPrivate::throw##except
#else
#	define DEFINE_MIN_RTTI
#	define DECLARE_MIN_RTTI(name)
#	define THROW(except) throw except
#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Target Platform
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define XP_AMIGAOS3_68K	// AmigaOS 3.x+
/*
#define XP_AMIGAOS3_PPC	// AmigaOS 3.x / WarpOS 4.x / 5.x
#define XP_AMIGAOS4			// AmigaOS 4.x PowerPC
#define XP_AROS_X86			// AROS (x86)
#define XP_MORPHOS_PPC	// MorphOS PowerPC
#define XP_LINUX_PPC		// Linux PowerPC
#define XP_LINUX_X86		// Linux i386
#define XP_WIN9X				// Windows 95/98/Me
#define XP_WIN2K				// Windows 2000/XP
#define XP_MACOSX_PPC		// MacOS X PPC
#define XP_MACOSX_X86		// MacOS X X86
*/

#include <cstddef>
#include <systemlib/hwsignature.hpp>
#include <systemlib/error.hpp>

#if defined(XP_AMIGAOS3_68K)
  #include "platforms/amigaos3_68k/systemlib/xbase_native.hpp"
#elif defined(XP_AMIGAOS3_PPC)
  #include "platforms/amigaos3_wos/systemlib/xbase_native.hpp"
#elif defined(XP_AMIGAOS4)
  #include "platforms/amigaos4/systemlib/xbase_native.hpp"
#elif defined(XP_AROS_X86)
  #include "platforms/aros_i386/systemlib/xbase_native.hpp"
#elif defined(XP_MORPHOS)
  #include "platforms/morphos/systemlib/xbase_native.hpp"
#elif defined(XP_LINUX_PPC)
  #include "platforms/linux_ppc/systemlib/xbase_native.hpp"
#elif defined(XP_LINUX_X86)
  #include "platforms/linux_i386/systemlib/xbase_native.hpp"
#elif defined(XP_WIN9X)
  #include "platforms/win9x/systemlib/xbase_native.hpp"
#elif defined(XP_WIN2K)
	#include "platforms/win2k/systemlib/xbase_native.hpp"
#elif defined(XP_MACOSX)
	#include "platforms/macosx/systemlib/xbase_native.hpp"
#else
	#error "Platform implementation not defined"
#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Application
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <systemlib/application.hpp>

#endif
