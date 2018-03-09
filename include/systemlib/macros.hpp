///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         systemlib/macros.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Gubbins
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

#ifndef _EXNG2_SYSTEMLIB_MACROS_HPP_
# define _EXNG2_SYSTEMLIB_MACROS_HPP_

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


# ifdef EXNG2_BUILD_LOGGED
#   define LOGGING_DEFINE_CLASSNAME private: static const char* loggingClassName;
#   define LOGGING_DECLARE_CLASSNAME(name) const char* name::loggingClassName = #name;
#   define LOGGING_DECLARE_FUNCNAME(name) static const char* loggingFuncName = #name "()";
# else
#   define LOGGING_DEFINE_CLASSNAME
#   define LOGGING_DECLARE_CLASSNAME(name)
#   define LOGGING_DECLARE_FUNCNAME(name)
# endif

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


# ifdef EXNG2_BUILD_AVOID_BLOAT
#   define DEFINE_MIN_RTTI private: virtual void _dfRTTI();
#   define DECLARE_MIN_RTTI(name) void name::_dfRTTI() {}
#   define THROW_NSX(ns,ex) EXNGPrivate::throw##ns##ex
# else
#   define DEFINE_MIN_RTTI
#   define DECLARE_MIN_RTTI(name)
#   define THROW_NSX(ns,ex) throw ns::ex
# endif

# if defined(__GNUC__) && (__GNUC__ < 3) && (__GNUC_MINOR__ <= 95)
#   define ALIGN_INHERITED private: long _inheritedSizeAlign;
# else
#   define ALIGN_INHERETED
# endif

#endif
