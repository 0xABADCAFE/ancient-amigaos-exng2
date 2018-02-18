///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         systemlib/cpu.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Processor controll and enumeration
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



#ifndef _EXNG2_SYSTEMLIB_CPU_HPP_
#	define _EXNG2_SYSTEMLIB_CPU_HPP_

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#	if defined(XP_AMIGAOS3_68K)
#		include "platforms/amigaos3_68k/systemlib/cpu_native.hpp"
#	elif defined(XP_AMIGAOS3_PPC)
#		include "platforms/amigaos3_wos/systemlib/cpu_native.hpp"
#	elif defined(XP_AMIGAOS4)
#		include "platforms/amigaos4/systemlib/cpu_native.hpp"
#	elif defined(XP_AROS_X86)
#		include "platforms/aros_i386/systemlib/cpu_native.hpp"
#	elif defined(XP_MORPHOS)
#		include "platforms/morphos/systemlib/cpu_native.hpp"
#	elif defined(XP_LINUX_PPC)
#		include "platforms/linux_ppc/systemlib/cpu_native.hpp"
#	elif defined(XP_LINUX_X86)
#		include "platforms/linux_i386/systemlib/cpu_native.hpp"
#	elif defined(XP_WIN9X)
#		include "platforms/win9x/systemlib/cpu_native.hpp"
#	elif defined(XP_WIN2K)
#		include "platforms/win2k/systemlib/cpu_native.hpp"
#	elif defined(XP_MACOSX)
#		include "platforms/macosx/systemlib/cpu_native.hpp"
#	else
#		error "Platform implementation not defined"
#	endif

#endif
