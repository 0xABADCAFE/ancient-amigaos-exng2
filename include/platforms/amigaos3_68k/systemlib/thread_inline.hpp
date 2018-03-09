///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/amigaos3_68k/systemlib/thread_native.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Multithreading services
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

inline sint32 Thread::getNumThreads()
{
  return numThreads;
}

inline sint32 Thread::getNumActive()
{
  return numActive;
}

inline uint32 Thread::getStates() const
{
  return stateFlags;
}

inline bool Thread::hasStarted() const
{
  return stateFlags & STATE_STARTED;
}

inline bool Thread::hasCompleted() const
{
  return stateFlags & STATE_COMPLETED;
}

inline bool Thread::hasThrown() const
{
  return stateFlags & STATE_THROWN;
}

inline bool Thread::isRunning() const
{
  return stateFlags == STATE_STARTED;
}

inline bool Thread::isSleeping() const
{
  return stateFlags == (STATE_STARTED|STATE_SLEEPING);
}

inline const char* Thread::getResourceName() const
{
  return name;
}

inline bool Thread::stopRequested() const
{
  return (taskState & (TASKSTATE_STOP|TASKSTATE_KILL));
}

inline Thread::Priority Thread::getPriority() const
{
  return (Thread::Priority)priority;
}

inline uint32 Thread::getStackSize() const
{
  return stackSize;
}

inline Thread* Thread::getParent() const
{
  return parent;
}

inline Thread* Thread::getCurrent()
{
  return threadForTask(OSNative::FindTask(0));
}

// mutators
inline void Thread::setRunObserver(Thread::RunObserver* o)
{
  runObs = o;
}

inline void Thread::setStateObserver(Thread::StateObserver* o)
{
  stateObs = o;
}

inline void Thread::setRealStackSize()
{
  stackSize = ((uint32)(internal->pr_Task.tc_SPUpper)) -
              ((uint32)(internal->pr_Task.tc_SPLower)) - 2;
}

// Protectors
inline void Thread::protectFromSelf() const
{
  if (findTask() == &(internal->pr_Task)) {
    THROW_NSX(Thread, SecurityViolation());
  }
}

inline void Thread::protectFromOther() const
{
  if (findTask() != &(internal->pr_Task)) {
    THROW_NSX(Thread, SecurityViolation());
  }
}

inline void Thread::protectStartedState() const
{
  if (hasStarted()) {
    THROW_NSX(Thread, StateViolation());
  }
}

inline void Thread::protectStoppedState() const
{
  if (!hasStarted()) {
    THROW_NSX(Thread, StateViolation());
  }
}

inline uint32 EXNGPrivate::ThreadImplementor::await(uint32 trigger)
{
  return OSNative::Wait(trigger);
}

