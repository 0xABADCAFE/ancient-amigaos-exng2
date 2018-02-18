///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         systemlib/thread.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Threading and semaphores
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

#ifndef _EXNG2_SYSTEMLIB_THREAD_HPP_
#	define _EXNG2_SYSTEMLIB_THREAD_HPP_

#	include <xbase.hpp>
#	include <systemlib/error.hpp>
#	include <systemlib/runnable.hpp>
#	include <systemlib/time.hpp>

#	if defined(XP_AMIGAOS3_68K)
#		include "platforms/amigaos3_68k/systemlib/thread_native.hpp"
#	elif defined(XP_AMIGAOS3_PPC)
#		include "platforms/amigaos3_wos/systemlib/thread_native.hpp"
#	elif defined(XP_AMIGAOS4)
#		include "platforms/amigaos4/systemlib/thread_native.hpp"
#	elif defined(XP_AROS_X86)
#		include "platforms/aros_i386/systemlib/thread_native.hpp"
#	elif defined(XP_MORPHOS)
#		include "platforms/morphos/systemlib/thread_native.hpp"
#	elif defined(XP_LINUX_PPC)
#		include "platforms/linux_ppc/systemlib/thread_native.hpp"
#	elif defined(XP_LINUX_X86)
#		include "platforms/linux_i386/systemlib/thread_native.hpp"
#	elif defined(XP_WIN9X)
#		include "platforms/win9x/systemlib/thread_native.hpp"
#	elif defined(XP_WIN2K)
#		include "platforms/win2k/systemlib/thread_native.hpp"
#	elif defined(XP_MACOSX)
#		include "platforms/macosx/systemlib/thread_native.hpp"
#	else
#		error "Platform implementation not defined"
#	endif

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Auxilliaries
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ThreadRunObserver {
	// Notified on exit of Threaded::run()
	DEFINE_MIN_RTTI
	public:
		virtual void notifyReturned(Thread* thread, sint32 returned) = 0;
		virtual void notifyThrown(Thread* thread, const RuntimeError* error=0) = 0;
		virtual ~ThreadRunObserver() {}
};

class ThreadStateObserver {
	// Notified on changes of idle / running state
	DEFINE_MIN_RTTI
	public:
		virtual void notifyAwakened(Thread* thread, Thread::WakeEvent type) = 0;
		virtual ~ThreadStateObserver() {}
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Error classes
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Thread::ThreadError							: public RuntimeError { DEFINE_MIN_RTTI };
class Thread::ThreadSecurityViolation	: public Thread::ThreadError { DEFINE_MIN_RTTI };
class Thread::ThreadStateViolation		: public Thread::ThreadError { DEFINE_MIN_RTTI };
class Thread::ThreadStartupFailure		: public Thread::ThreadError { DEFINE_MIN_RTTI };

class LockExclusive {
	private:
		Lockable* object;

	public:
		LockExclusive(Lockable* o) : object(o)	{ object->waitLock(); }
		~LockExclusive()												{ object->freeLock(); }
};

class LockShared {
	private:
		Lockable* object;

	public:
		LockShared(Lockable* o) : object(o)	{ object->waitReadOnlyLock(); }
		~LockShared()												{ object->freeLock(); }
};


#endif
