///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/amigaos3_68k/systemlib/thread_native.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Native thread classes
//  Comment(s):
//  Library:      System
//  Created:      2007-01-12
//  Updated:      2007-01-12
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <systemlib/thread.hpp>
#include <systemlib/logger.hpp>
#include <private/systemlib/error.hpp>
#include <cstdio>

using namespace OSNative;
using namespace EXNGPrivate;
using namespace Time;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  RootThreadWrapper
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace EXNGPrivate {

  class RootThreadWrapper : public Thread {
    protected:
      sint32 run();

    private:
      RootThreadWrapper();

    public:
      static Thread* bind();

      ~RootThreadWrapper();
  };

};

extern "C" {
  void trapCPU68K(); // see thread_native_asm.asm
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Thread
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Static data
Task*   Thread::main        = Thread::findTask();//FindTask(0);
Thread* Thread::rootThread  = RootThreadWrapper::bind();
uint32  Thread::nextId      = 0;
uint32  Thread::numThreads  = 0;
uint32  Thread::numActive   = 0;
sint8   Thread::priTab[10] = {
  0,    // PRI_NORMAL,
  -127, // PRI_MINIMUM
  -100, // PRI_BACKGROUND
  -10,  // PRI_LOW
  -5,   // PRI_BELOWNORMAL
  5,    // PRI_ABOVENORMAL
  10,   // PRI_HIGH
  20,   // PRI_REALTIME
  100,  // PRI_MAXIMUM
  0     // PAD
};

LOGGING_DECLARE_CLASSNAME(Thread)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Thread::Thread()
: classID(IDTAG), internal(0), external(0), oldTrap(0), runJob(0), runObs(0), stateObs(0), sleeper(), uptime(),
  priority(PRI_NORMAL), stateFlags(0), sleepFlags(0), taskState(0)
{
  // used only by RootThreadWrapper
  internal = (Process*)main;
  sharedInit(0);
  setRealStackSize();
}

Thread::Thread(Thread::Priority pri, uint32 stack)
: classID(IDTAG), internal(0), external(0), oldTrap(0), runJob(0), runObs(0), stateObs(0), sleeper(), uptime(),
  priority((uint8)pri), stateFlags(0), sleepFlags(0), taskState(0)
{
  sharedInit(stack);
}

Thread::Thread(Runnable* job, Thread::Priority pri, uint32 stack)
: classID(IDTAG), internal(0), external(0), oldTrap(0), runJob(job), runObs(0), stateObs(0), sleeper(), uptime(),
  priority((uint8)pri), stateFlags(0), sleepFlags(0), taskState(0)
{
  sharedInit(stack);
}

void Thread::sharedInit(uint32 stack)
{
  stackSize = stack<4096 ? 4096 : stack;
  std::sprintf(name, "exng2_%08X", (unsigned)nextId++);
  numThreads++;
  if (!internal) {
    parent = threadForTask(findTask()/*FindTask(0)*/);
  }
  else {
    parent = 0;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Thread::~Thread()
{
  LOGGING_DECLARE_FUNCNAME(~Thread)

  if (internal) {

    if (hasStarted()) {
      stop();
    }

    external = findTask();//FindTask(0);
    taskState |= TASKSTATE_KILL;
    signalInternal(SIGNAL_STOP);
    while (taskState & TASKSTATE_KILL) {
      if (Wait(SIGNAL_ACK|SIGNAL_SYSBREAK)==SIGNAL_SYSBREAK) {
        taskState &= ~TASKSTATE_KILL;
        #ifdef EXNG2_BUILD_LOGGED
        SystemLog::write(
          SystemLog::WARNING, "%s::%s - %s manually terminated (Process crashed?)\n",
          loggingClassName, loggingFuncName, name
        );
        #endif
      }
    }
  }
  numThreads--;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Thread* Thread::threadForTask(Task* task)
{
  if (task==main) {
    return rootThread;
  }
  if (task) {
    Thread* thread = (Thread*)(task->tc_UserData);
    if (thread && thread->classID == IDTAG) {
      return thread;
    }
  }
  //throwThreadSecurityViolation();
  THROW_NSX(Thread, SecurityViolation());
  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Interval Thread::getUptime() const
{
  if (!hasStarted()) {
    return uptime.last();
  }
  return uptime.elapsed();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Thread::Priority Thread::setPriority(Priority p)
{
  Priority oldPri = (Priority)priority;
  if (oldPri !=p) {
    priority = (uint8)p;
    if (internal) {
      SetTaskPri(&(internal->pr_Task), priTab[priority]);
    }
  }
  return oldPri;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 Thread::setStackSize(uint32 size)
{
  LOGGING_DECLARE_FUNCNAME(setStackSize)

  protectFromSelf();
  protectStartedState();
  uint32 oldStack = stackSize;

  size = size<4096 ? 4096 : size;
  if (size!=stackSize) {
    if (internal) {
      external = findTask();//FindTask(0);
      taskState |= TASKSTATE_KILL;
      signalInternal(SIGNAL_STOP);
      while (taskState & TASKSTATE_KILL) {
        if (Wait(SIGNAL_ACK|SIGNAL_SYSBREAK)==SIGNAL_SYSBREAK) {
          taskState &= ~TASKSTATE_KILL;
          #ifdef EXNG2_BUILD_LOGGED
          SystemLog::write(
            SystemLog::WARNING, "%s::%s - %s manually interrupted (Process crashed?)\n",
            loggingClassName, loggingFuncName, name
          );
          #endif
        }
      }
      internal = 0;
    }
    stackSize = size;
  }
  return oldStack;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Thread::start()
{
  //LOGGING_DECLARE_FUNCNAME(start)

  protectFromSelf();
  protectStartedState();
  // if the internal thread exists, clear any parked state and give it a prod, otherwise spawn it
  if (internal) {
    taskState &= ~TASKSTATE_PARKED;
    signalInternal(SIGNAL_ACK);
  } else {
    spawn();
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Thread::stop()
{
  //LOGGING_DECLARE_FUNCNAME(stop)

  protectFromSelf();
  protectStoppedState();

  // set the stop flag, signal for a stop and then wait for the flag to be cleared.
  // This is only done when process() inner loop returns from a run() attempt
  external = findTask();//FindTask(0);
  taskState |= TASKSTATE_STOP;
  signalInternal(SIGNAL_STOP);
  while (taskState & TASKSTATE_STOP) {
    Wait(SIGNAL_ACK);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Thread::join()
{
  //LOGGING_DECLARE_FUNCNAME(join)

  protectFromSelf();
  if (hasStarted()) {
    // set the join flag then wait for the flag to be cleared.
    // This is only done when process() inner loop returns from a run() attempt
    external = findTask();//FindTask(0);
    taskState |= TASKSTATE_JOIN;
    while (taskState & TASKSTATE_JOIN) {
      Wait(SIGNAL_ACK);
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Thread::wake()
{
  protectFromSelf();
  protectStoppedState();
  signalInternal(SIGNAL_WAKE);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Thread::signalInternal(uint32 trigger)
{
  OSNative::Signal(&(internal->pr_Task),trigger);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Thread::signalExternal(uint32 trigger)
{
  OSNative::Signal(external,trigger);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Thread::spawn()
{
  LOGGING_DECLARE_FUNCNAME(spawn)

  //  Synchronization:
  //
  //  Create the Process, which immediately enters a wait state
  //  Modify the Task such that tc_UserData points to this instance
  //  Signal the Task to continue
  //  Wait for the Task to signal us back that it has completed (or not) any initialisation

  TagItem spawnTags[] = {
    NP_Entry,       (uint32)&Thread::entryPoint,
    NP_StackSize,   (uint32)stackSize,
    NP_Priority,    (uint32)priTab[priority],
    NP_Name,        (uint32)name,
    TAG_DONE, 0UL
  };

  // we expect a successful startup to clear this flag
  taskState = TASKSTATE_FAILED;
  external  = findTask();//FindTask(0);
  if (!(internal = CreateNewProc(spawnTags))) {
    taskState = 0;

    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::ERROR, "%s::%s - %s failed to create Process\n",
      loggingClassName, loggingFuncName, name
    );
    #endif

    THROW_NSX(Thread, StartupFailure());
  }

  // associate this Thread instance with the Task and signal that its ok to proceed
  internal->pr_Task.tc_UserData = (void*)this;

  signalInternal(SIGNAL_ACK);

  // the Task ought to  have initialised the Sleeper. If it failed to do so, it will not
  // have cleared the TASKSTATE_FAIL bit, so check on that.
  Wait(SIGNAL_ACK);

  if (taskState & TASKSTATE_FAILED) {
    taskState = 0;
    internal = 0;

    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::ERROR, "%s::%s - %s failed to initialise\n",
      loggingClassName, loggingFuncName, name
    );
    #endif

    THROW_NSX(Thread, StartupFailure());
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Thread::enableLowLevelExceptions()
{
  taskState |= TASKSTATE_TRAPS;
  if (internal) {
    internal->pr_Task.tc_TrapCode = (void*)&trapCPU68K;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Thread::disableLowLevelExceptions()
{
  taskState &= ~TASKSTATE_TRAPS;
  if (internal) {
    internal->pr_Task.tc_TrapCode = oldTrap;
  }
}

Thread::WakeEvent Thread::sleep(uint32 period, uint32 flags)
{
  return getCurrent()->suspend(period, flags);
}

Thread::WakeEvent Thread::resumeSleep()
{
  return getCurrent()->resumeSuspension();
}

void Thread::abortSleep()
{
  getCurrent()->abortSuspension();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Methods called by internal Process only
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void  Thread::entryPoint()
{
  LOGGING_DECLARE_FUNCNAME(entryPoint)

  // Immediately drop into a wait state until we are told to proceed
  Wait(SIGNAL_ACK);
  try {
    Thread* thread = getCurrent();
    thread->process();
  }
  catch (...) {

    #ifdef EXNG2_BUILD_LOGGED
    Task* t = findTask();//FindTask(0);
    SystemLog::write(
      SystemLog::ERROR, "%s::%s - Unknown Task 0x%08X\n",
      loggingClassName, loggingFuncName, (unsigned)t
    );
    #endif

  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Thread::WakeEvent Thread::handleWakeup(uint32 gotSignals)
{
  LOGGING_DECLARE_FUNCNAME(handleWakeup)

  WakeEvent result = WAKE_UNKNOWN;

  if ((taskState & TASKSTATE_KILL) || (sleepFlags & SLEEP_DISPOSE_TIMEOUT)) {
    abortSuspension();
  }

  if (gotSignals & SIGNAL_STOP) {
    if (taskState & TASKSTATE_KILL) {

//      #ifdef EXNG2_BUILD_LOGGED
//      SystemLog::write(
//        SystemLog::INFO, "%s::%s - %s [i] woken by termination request\n",
//        loggingClassName, loggingFuncName, name
//      );
//      #endif

      result = WAKE_SHUTDOWN;
    }
    else {

//      #ifdef EXNG2_BUILD_LOGGED
//      SystemLog::write(
//        SystemLog::INFO, "%s::%s - %s [i] woken by stop() call\n",
//        loggingClassName, loggingFuncName, name
//      );
//      #endif

      result = WAKE_STOP;
    }
  }
  else if ((gotSignals & SIGNAL_WAKE) && !(sleepFlags & SLEEP_IGNORE_WAKE)) {

//    #ifdef EXNG2_BUILD_LOGGED
//    SystemLog::write(
//      SystemLog::INFO, "%s::%s - %s [i] woken by wake request\n",
//      loggingClassName, loggingFuncName, name
//    );
//    #endif

    result = WAKE_WAKE;
  }

  else if ((gotSignals & SIGNAL_SYSBREAK) && !(sleepFlags & SLEEP_IGNORE_SYSBREAK)) {

//    #ifdef EXNG2_BUILD_LOGGED
//    SystemLog::write(
//      SystemLog::INFO, "%s::%s - %s [i] woken by system break signal\n",
//      loggingClassName, loggingFuncName, name
//    );
//    #endif

    result = WAKE_SYSBREAK;
  }
  else if (gotSignals & sleeper.getTimerSignal()) {

//    #ifdef EXNG2_BUILD_LOGGED
//    SystemLog::write(
//      SystemLog::INFO, "%s::%s - %s [i] woken on timeout\n",
//      loggingClassName, loggingFuncName, name
//    );
//    #endif

    result = WAKE_TIMEOUT;
  }
  else {
    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::WARNING, "%s::%s - %s [i] woken by unknown or unexpected signal\n",
      loggingClassName, loggingFuncName, name
    );
    #endif
  }
  if (stateObs) {
    stateObs->notifyAwakened(this, result);
  }

  return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Thread::WakeEvent Thread::suspend(uint32 period, uint32 flags)
{
  //LOGGING_DECLARE_FUNCNAME(suspend)

  protectFromOther();
  uint32 trgSignals = SIGNAL_STOP|SIGNAL_SYSBREAK|SIGNAL_WAKE;
  if (flags & SLEEP_IGNORE_WAKE) {
    trgSignals &= ~SIGNAL_WAKE;
  }
  if (flags & SLEEP_IGNORE_SYSBREAK) {
    trgSignals &= ~SIGNAL_SYSBREAK;
  }
  sleepFlags = (uint8)flags;

//  #ifdef EXNG2_BUILD_LOGGED
//  SystemLog::write(
//    SystemLog::INFO, "%s::%s - %s [i] sleeping for %lu ms, interruptable on signals: 0x%08X\n",
//    loggingClassName, loggingFuncName, name, period, trgSignals|sleeper.getTimerSignal()
//  );
//  #endif

  return handleWakeup(sleeper.suspend(period, trgSignals));
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Thread::abortSuspension()
{
  //LOGGING_DECLARE_FUNCNAME(abortSuspension)

  protectFromOther();
  sleepFlags |= SLEEP_DISPOSE_TIMEOUT;
  sleeper.abortDelay();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Thread::WakeEvent Thread::resumeSuspension()
{
  //LOGGING_DECLARE_FUNCNAME(resumeSuspension)
  protectFromOther();
  if (sleepFlags & SLEEP_DISPOSE_TIMEOUT) {
    return WAKE_DISPOSED;
  }
  return handleWakeup(sleeper.suspend());
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 Thread::run()
{
  // may be overidden directly
  if (runJob) {
    return runJob->run();
  }
  THROW_NSX(Thread, StartupFailure());
  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Thread::process()
{
  LOGGING_DECLARE_FUNCNAME(process)

  if(sleeper.init()) {
    setRealStackSize();
    // if low level trapping was requested before the thread was started, activate it now
    if (taskState & TASKSTATE_TRAPS) {
      internal->pr_Task.tc_TrapCode = (void*)&trapCPU68K;
    }

    // clear the task state and alert our parent task
    taskState = 0;
    signalExternal(SIGNAL_ACK);

    // loop until we kill the task (on destruction only)
    while (!(taskState & TASKSTATE_KILL)) {

//      #ifdef EXNG2_BUILD_LOGGED
//      SystemLog::write(
//        SystemLog::INFO, "%s::%s - %s [i] starting\n",
//        loggingClassName, loggingFuncName, name
//      );
//      #endif

      // invoke run
      numActive++;
      try {
        sint32 result = 0;
        stateFlags  = STATE_STARTED;
        uptime.set();
        result = run();
        uptime.elapsed();
        stateFlags  &= ~STATE_STARTED;
        stateFlags  |= STATE_COMPLETED;

//        #ifdef EXNG2_BUILD_LOGGED
//        SystemLog::write(
//          SystemLog::INFO, "%s::%s - %s [i] completed with returncode %d\n",
//          loggingClassName, loggingFuncName, name, result
//        );
//        #endif

        // notify observers of task completion
        if (runObs) {
          runObs->notifyReturned(this, result);
        }
      }
      catch (Error::Runtime& e) {
        stateFlags &= ~STATE_STARTED;
        stateFlags |= STATE_THROWN;

        #ifdef EXNG2_BUILD_LOGGED
        SystemLog::write(
          SystemLog::WARNING, "%s::%s - %s [i] threw %s\n",
          loggingClassName, loggingFuncName, name, e.getClass()
        );
        #endif

        // notify observers of failure
        if (runObs) {
          runObs->notifyThrown(this, &e);
        }
      }
      catch (...) {
        stateFlags &= ~STATE_STARTED;
        stateFlags |= STATE_THROWN;

        #ifdef EXNG2_BUILD_LOGGED
        SystemLog::write(
          SystemLog::WARNING, "%s::%s - %s [i] threw exception\n",
          loggingClassName, loggingFuncName, name
        );
        #endif

        if (runObs) {
          runObs->notifyThrown(this, 0);
        }
      }

      // was a stop() or join() called?
      if (taskState & (TASKSTATE_STOP|TASKSTATE_JOIN)) {
        taskState &= ~(TASKSTATE_STOP|TASKSTATE_JOIN);
        signalExternal(SIGNAL_ACK);
      }

      numActive--;

      // park the process, unless/until the kill flag is set
      taskState |= TASKSTATE_PARKED;
      while ((taskState & (TASKSTATE_PARKED|TASKSTATE_KILL))==TASKSTATE_PARKED) {

//        #ifdef EXNG2_BUILD_LOGGED
//        SystemLog::write(
//          SystemLog::INFO, "%s::%s - %s [i] parking\n",
//          loggingClassName, loggingFuncName, name
//        );
//        #endif

        // wait for wakeup call or termination request
        Wait(SIGNAL_ACK|SIGNAL_STOP);
      }
    }

//    #ifdef EXNG2_BUILD_LOGGED
//    SystemLog::write(
//      SystemLog::INFO, "%s::%s - %s [i] terminating\n",
//      loggingClassName, loggingFuncName, name
//    );
//    #endif

    // finalize stuff we allocated
    internal->pr_Task.tc_TrapCode = oldTrap;
    sleeper.done();
    taskState &= ~TASKSTATE_KILL;
  } else {
    // falied to initialise sleeper
    taskState = TASKSTATE_FAILED;
  }
  // signal the parent - it's all out of our hands now
  signalExternal(SIGNAL_ACK);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  RootThreadWrapper methods
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

RootThreadWrapper::RootThreadWrapper() : Thread()
{
  sleeper.init();
  uptime.set();
  stateFlags = STATE_STARTED;
  oldTrap = internal->pr_Task.tc_TrapCode;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

RootThreadWrapper::~RootThreadWrapper()
{
  sleeper.done();
  internal->pr_Task.tc_TrapCode = oldTrap;
  internal = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 RootThreadWrapper::run()
{
  THROW_NSX(Thread, StateViolation());
  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Thread* RootThreadWrapper::bind()
{
  static RootThreadWrapper root;
  return &root;
}

