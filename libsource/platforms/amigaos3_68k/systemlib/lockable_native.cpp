///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/amigaos3_68k/systemlib/lockable_native.cpp
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
#include <private/systemlib/error.hpp>
#include <systemlib/logger.hpp>

//#include <cstdio>

using namespace OSNative;
using namespace EXNGPrivate;

#ifdef EXNG2_BUILD_LOGGED
namespace {
  const char* destroyedBefore = "%s::%s - aborted: destructor invoked prior to attempt\n";
  const char* destroyedDuring = "%s::%s - aborted: destructor invoked whilst waiting\n";
};
#endif

LOGGING_DECLARE_CLASSNAME(Thread::Lockable)


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Lockable
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Thread::Lockable::Lockable() : destroyed(false)
{
  InitSemaphore(&lock);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Thread::Lockable::~Lockable()
{
  LOGGING_DECLARE_FUNCNAME(~Lockable)

  // protect against the side effects of multiple deletion. Altough that itself
  // is a major programmer error, allowing it to go beyond upsetting the allocator
  // is not a good idea :-)
  if (!destroyed) {
    // phase 1 - get an exclusive lock and set the destroyed flag then release
    ObtainSemaphore(&lock);
    destroyed = true;

    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::INFO, "%s::%s - Marked instance destroyed, waiting for other requestors to acknowledge\n",
      loggingClassName, loggingFuncName
    );
    #endif

    ReleaseSemaphore(&lock);
    // From this point on, all user calls to lock an object will fail.
    // Pending locks will awaken in order of their queue position only to
    // find the object is due for destruction and will immediately
    // relinquish any lock they obtain, returning an error.

    // phase 2 - wait to get an exclusive lock then release
    ObtainSemaphore(&lock);

    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::INFO, "%s::%s - All outstanding requests aborted\n",
      loggingClassName, loggingFuncName
    );
    #endif

    ReleaseSemaphore(&lock);

    // This causes the destructor to pause again until it can get an
    // exclusive lock on the semaphore. In the meantime, all the other
    // threads that were pending will have aborted their calls, informing
    // the callers the object is going to get deleted. Waiting in this
    // fashion ensures that whilst this process takes place, the object
    // itself is not yet deleted, otherwise you would end up with references
    // to the newly freed memory in the processing of the other calls.
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


bool Thread::Lockable::tryLock()
{
  LOGGING_DECLARE_FUNCNAME(tryLock)

  // If the destructor has gotten past stage 1, the destroyed flag is set.
  // We must check this first and exit immediately if it is found to be set.

  //assertAlive();
  if (destroyed) {
    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::INFO, destroyedBefore,
      loggingClassName, loggingFuncName
    );
    #endif
    THROW_NSX(Error, ObjectDestroyed());
  }

  if (AttemptSemaphore(&lock)) {
    // If we have obtained te semaphore, it might be that the destructor
    // is now midway having flagged the destruction and waiting for all
    // the other threads to release their locks again.
    if (destroyed) {
      ReleaseSemaphore(&lock);
      #ifdef EXNG2_BUILD_LOGGED
      SystemLog::write(
        SystemLog::INFO, destroyedDuring,
        loggingClassName, loggingFuncName
      );
      #endif
      THROW_NSX(Error, ObjectDestroyed());
    }
    // OK, we now own the lock
    return true;
  }
  return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Thread::Lockable::waitLock()
{
  LOGGING_DECLARE_FUNCNAME(waitLock)

  // If the destructor has gotten past stage 1, the destroyed flag is set.
  // We must check this first and exit immediately if it is found to be set.

  //assertAlive();
  if (destroyed) {
    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::INFO, destroyedBefore,
      loggingClassName, loggingFuncName
    );
    #endif
    THROW_NSX(Error, ObjectDestroyed());
  }

  ObtainSemaphore(&lock);
  if (destroyed) {
    // If we have obtained te semaphore, it might be that the destructor
    // is now midway having flagged the destruction and waiting for all
    // the other threads to release their locks again.
    ReleaseSemaphore(&lock);
    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::INFO, destroyedDuring,
      loggingClassName, loggingFuncName
    );
    #endif
    THROW_NSX(Error, ObjectDestroyed());
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Thread::Lockable::tryReadOnlyLock()
{
  LOGGING_DECLARE_FUNCNAME(tryReadOnlyLock)

  // If the destructor has gotten past stage 1, the destroyed flag is set.
  // We must check this first and exit immediately if it is found to be set.

  //assertAlive();
  if (destroyed) {
    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::INFO, destroyedBefore,
      loggingClassName, loggingFuncName
    );
    #endif
    THROW_NSX(Error, ObjectDestroyed());
  }

  if (AttemptSemaphoreShared(&lock)) {
    // If we have obtained te semaphore, it might be that the destructor
    // is now midway having flagged the destruction and waiting for all
    // the other threads to release their locks again.
    if (destroyed) {
      ReleaseSemaphore(&lock);
      #ifdef EXNG2_BUILD_LOGGED
      SystemLog::write(
        SystemLog::INFO, destroyedDuring,
        loggingClassName, loggingFuncName
      );
      #endif
      THROW_NSX(Error, ObjectDestroyed());
    }
    // OK, we now own the lock
    return true;
  }
  return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Thread::Lockable::waitReadOnlyLock()
{
  LOGGING_DECLARE_FUNCNAME(waitReadOnlyLock)

  // If the destructor has gotten past stage 1, the destroyed flag is set.
  // We must check this first and exit immediately if it is found to be set.

  //assertAlive();
  if (destroyed) {
    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::INFO, destroyedBefore,
      loggingClassName, loggingFuncName
    );
    #endif
    THROW_NSX(Error, ObjectDestroyed());
  }

  ObtainSemaphoreShared(&lock);
  if (destroyed) {
    // If we have obtained te semaphore, it might be that the destructor
    // is now midway having flagged the destruction and waiting for all
    // the other threads to release their locks again.
    ReleaseSemaphore(&lock);
    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::INFO, destroyedDuring,
      loggingClassName, loggingFuncName
    );
    #endif
    THROW_NSX(Error, ObjectDestroyed());
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 Thread::Lockable::pending()
{
  LOGGING_DECLARE_FUNCNAME(pending)

  //assertAlive();
  if (destroyed) {
    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::INFO, destroyedBefore,
      loggingClassName, loggingFuncName
    );
    #endif
    THROW_NSX(Error, ObjectDestroyed());
  }
  //return lock.ss_NestCount - lock.ss_QueueCount - 1;
  return lock.ss_QueueCount;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Thread::Lockable::freeLock()
{
  if (!destroyed) {
    ReleaseSemaphore(&lock);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 Thread::Lockable::active()
{
  LOGGING_DECLARE_FUNCNAME(active)

  //assertAlive();
  if (destroyed) {
    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::INFO, destroyedBefore,
      loggingClassName, loggingFuncName
    );
    #endif
    THROW_NSX(Error, ObjectDestroyed());
  }
  return lock.ss_NestCount;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Thread* Thread::Lockable::getExclusiveOwner()
{
  LOGGING_DECLARE_FUNCNAME(getExclusiveOwner)

  //assertAlive();
  if (destroyed) {
    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::INFO, destroyedBefore,
      loggingClassName, loggingFuncName
    );
    #endif
    THROW_NSX(Error, ObjectDestroyed());
  }
  if (lock.ss_Owner) {
    return Thread::threadForTask(lock.ss_Owner);
  }
  return 0;
}



