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
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _EXNG2_BASE_HPP_
# define _EXNG2_BASE_HPP_

#ifndef __cplusplus
# error "The eXtropia Studios Application Framework is for C++ use only"
#endif


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  General Library Build options
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef EXNG2_BUILD_FINAL
# define EXNG2_BUILD_AVOID_BLOAT
#else
# define EXNG2_BUILD_PARANOID    // Paranoid safety
# define EXNG2_BUILD_LOGGED      // Low level logging
# define EXNG2_BUILD_AVOID_BLOAT // Enable space saving code modifications
#endif

#include <systemlib/macros.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Target Platform
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define XP_AMIGAOS3_68K "amigaos3_68k/"
#define XP_AMIGAOS3_PPC "amigaos3_wos/"
#define XP_AMIGAOS4_PPC "amigaos4/"
#define XP_MORPHOS_PPC "morphos/"
#define XP_AROS_X86 "aros_x86/"
#define XP_LINUX_PPC "linux_ppc/"
#define XP_LINUX_PPC64 "linux_ppc64/"
#define XP_LINUX_X86 "linux_x86/"
#define XP_LINUX_X64 "linux_x64/"

#ifndef XP_PLATFORM
#error Platform not specified, please add -DXP_PLATFORM=XP_<platform> in your CXX flags
#endif

//#define XP_PLATFORM XP_AMIGAOS3_68K
#define EXPAND_XP_PLATFORM
#define XP_INCLUDE_PLATFORM(x) "platforms/"##XP_PLATFORM##x

#include <cstddef>
#include <systemlib/hwsignature.hpp>
#include <systemlib/error.hpp>

#include <systemlib/xbase_native.hpp>

//#include XP_INCLUDE_PLATFORM("systemlib/xbase_native.hpp")

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Application
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <systemlib/application.hpp>

#endif
