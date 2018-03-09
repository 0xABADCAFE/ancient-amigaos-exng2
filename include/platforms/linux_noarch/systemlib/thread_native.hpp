///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/linux_noarch/systemlib/thread_native.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Multithreading services - generic pthread version
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

#ifndef _EXNG2_SYSTEMLIB_THREAD_NATIVE_HPP_
# define _EXNG2_SYSTEMLIB_THREAD_NATIVE_HPP_

#include <pthread.h>

namespace EXNGPrivate {
  class RootThreadWrapper;
  class ThreadImplementor {
    protected:
      static uint32 await(uint32 signals);
  };
  extern "C" {
    void throwThreadError(void);
    void throwThreadSecurityViolation(void);
    void throwThreadStateViolation(void);
    void throwThreadStartupFailure(void);
  }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Thread
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Thread : protected Runnable {

  DEFINE_MIN_RTTI

  public:
    // thread exception classes
    class Error;
    class SecurityViolation;
    class StateViolation;
    class StartupFailure;

    // auxilliaries
    class RunObserver;
    class StateObserver;
    class Lockable;
    class LockExclusive;
    class LockShared;

    // thread priorities
    typedef enum {
      PRI_NORMAL      = 0,
      PRI_MINIMUM     = 1,
      PRI_BACKGROUND  = 2,
      PRI_LOW         = 3,
      PRI_BELOWNORMAL = 4,
      PRI_ABOVENORMAL = 5,
      PRI_HIGH        = 6,
      PRI_REALTIME    = 7,
      PRI_MAXIMUM     = 8
    } Priority;

    typedef enum {
      WAKE_TIMEOUT  = 0,  // sleep ended normally
      WAKE_WAKE     = 1,  // sleep interrupted by wake call
      WAKE_STOP     = 2,  // sleep interrupted by stop call
      WAKE_SHUTDOWN = 3,  // sleep interrupted by thread termination (destructor invoked)
      WAKE_SYSBREAK = 4,  // sleep interrupted by system break
      WAKE_USER     = 5,  // sleep interrupted by user defined event
      WAKE_DISPOSED = 6,  // returned when sleep request is disposed
      WAKE_UNKNOWN  = 7   // sleep interrupted by unknown source
    } WakeEvent;

    // sleep() / suspend() flags
    enum {
      SLEEP_IGNORE_WAKE       = (1<<0), // ignore interrupts from wake()
      SLEEP_IGNORE_SYSBREAK   = (1<<1), // ignore interrupts from system break calls
      SLEEP_IGNORE_UNKNOWN    = (1<<2), // ignore interrupts from unknown sources
      SLEEP_DISPOSE_TIMEOUT   = (1<<3)  // dispose of pending timeout if woken unexpetedly
    };

    // thread state flags
    enum {
      STATE_STARTED     = (1<<0),   // set once the thread has started entered Runnable::run()
      STATE_COMPLETED   = (1<<1),   // set once the thread has returned from Runnable::run()
      STATE_SLEEPING    = (1<<2),   // set when the thread is asleep
      STATE_THROWN      = (1<<3)    // set when the thread has thrown an uncaught error
    };

  public:

    // state inspectors
    uint32        getStates()       const;
    bool          hasStarted()      const;
    bool          hasCompleted()    const;
    bool          hasThrown()       const;
    bool          isRunning()       const;
    bool          isSleeping()      const;

    // other inspectors
    Priority      getPriority()     const;
    uint32        getStackSize()    const;
    Interval      getUptime()       const;
    Thread*       getParent()       const;
    const char*   getResourceName() const;
    static sint32 getNumThreads();
    static sint32 getNumActive();

    // mutators
    void          setRunObserver(Thread::RunObserver* observer);
    void          setStateObserver(Thread::StateObserver* observer);
    Priority      setPriority(Priority p);
    uint32        setStackSize(uint32 s);

    // control
    void          enableLowLevelExceptions();
    void          disableLowLevelExceptions();
    void          start();
    void          stop();
    void          wake();
    void          join();


  public:
    Thread(Runnable* job, Priority pri, uint32 stackSize);
    virtual ~Thread();

    // static utilities
    static Thread*    getCurrent();
    static WakeEvent  sleep(uint32 period, uint32 flags);
    static WakeEvent  resumeSleep();
    static void       abortSleep();

  protected:
    Thread(Priority pri, uint32 stackSize);

    sint32      run();
    WakeEvent   suspend(uint32 period, uint32 flags);
    WakeEvent   resumeSuspension();
    void        abortSuspension();
    bool        stopRequested()       const;

    // check and throw security methods
    void        protectFromSelf()     const;  // methods forbidden from the internal thread
    void        protectFromOther()    const;  // methods forbidden from external threads
    void        protectStartedState() const;  // throws if called after run() invoked
    void        protectStoppedState() const;  // throws if called after run() returned or not yet invoked


  private:
    enum {
      IDTAG           = 0x58534C54,
      MAX_NAME_LENGTH = 16,

      TASKSTATE_PARKED    = (1<<0),
      TASKSTATE_FAILED    = (1<<1),
      TASKSTATE_STOP      = (1<<2),
      TASKSTATE_TRAPS     = (1<<3),
      TASKSTATE_JOIN      = (1<<4),
      TASKSTATE_KILL      = (1<<7),

    };

    void            sharedInit(uint32 stack);
    static Thread*  getRootThread();
    static Thread*  threadForTask(pthread_t);

    // pthread entry point, invoked by pthread_create()
    static void     entryPoint(void* args);

    // Private constructor wrapping the main thread, used RootThreadWrapper
    Thread();

    uint32          classID;

    pthread_t       internal;
    pthread_t       external;

    Thread*         parent;
    Runnable*       runJob;
    RunObserver*    runObs;
    StateObserver*  stateObs;
    Clock           uptime;
    uint32          stackSize;
    uint8           priority;
    uint8           sleepFlags;
    uint8           stateFlags;
    uint8           taskState;
    char            name[MAX_NAME_LENGTH];

    static Thread*  rootThread;
    static uint32   nextId;
    static uint32   numThreads;
    static uint32   numActive;
    static sint8    priTab[10];

    LOGGING_DEFINE_CLASSNAME

    friend class EXNGPrivate::RootThreadWrapper;
    friend class EXNGPrivate::ThreadImplementor;
    friend class Lockable;
};



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Lockable
//
//  Shared access control service.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Thread::Lockable {
  DEFINE_MIN_RTTI
  public:
    bool      tryLock();
    bool      tryReadOnlyLock();
    void      waitLock();
    void      waitReadOnlyLock();
    sint32    pending();
    sint32    active();
    void      freeLock();
    Thread*   getExclusiveOwner();

  protected:
    Lockable();
    virtual ~Lockable();

  private:
    bool destroyed;

    LOGGING_DEFINE_CLASSNAME
};

# include "thread_inline.hpp"

#endif
