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
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _EXNG2_SYSTEMLIB_THREAD_HPP_
# define _EXNG2_SYSTEMLIB_THREAD_HPP_

# include <xbase.hpp>
# include <systemlib/error.hpp>
# include <systemlib/runnable.hpp>
# include <systemlib/time.hpp>

# include <systemlib/thread_native.hpp>

//#include XP_INCLUDE_PLATFORM("systemlib/thread_native.hpp")


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Auxilliaries
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Thread::RunObserver {
  // Notified on exit of Threaded::run()
  DEFINE_MIN_RTTI
  public:
    virtual void notifyReturned(Thread* thread, sint32 returned) = 0;
    virtual void notifyThrown(Thread* thread, const ::Error::Runtime* error=0) = 0;
    virtual ~RunObserver() {}
};

class Thread::StateObserver {
  // Notified on changes of idle / running state
  DEFINE_MIN_RTTI
  public:
    virtual void notifyAwakened(Thread* thread, Thread::WakeEvent type) = 0;
    virtual ~StateObserver() {}
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Error classes
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Thread::Error             : virtual public ::Error::Runtime                             { DEFINE_MIN_RTTI };
class Thread::SecurityViolation : public Thread::Error                                        { DEFINE_MIN_RTTI };
class Thread::StateViolation    : public Thread::Error, public ::Error::ObjectStateViolation  { DEFINE_MIN_RTTI };
class Thread::StartupFailure    : public Thread::Error                                        { DEFINE_MIN_RTTI };

class Thread::LockExclusive {
  private:
    Thread::Lockable* object;

  public:
    LockExclusive(Thread::Lockable* o) : object(o)  { object->waitLock(); }
    ~LockExclusive()                                { object->freeLock(); }
};

class Thread::LockShared {
  private:
    Thread::Lockable* object;

  public:
    LockShared(Thread::Lockable* o) : object(o) { object->waitReadOnlyLock(); }
    ~LockShared()                               { object->freeLock(); }
};

#include <systemlib/thread_inline.hpp>
#endif
