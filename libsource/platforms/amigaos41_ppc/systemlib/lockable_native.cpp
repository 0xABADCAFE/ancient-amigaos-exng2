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

#include <cstdio>

using namespace OSNative;
using namespace EXNGPrivate;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Lockable
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Thread::Lockable::Lockable() : destroyed(false)
{
  IExec->InitSemaphore(&lock);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Thread::Lockable::~Lockable()
{
  // protect against the side effects of multiple deletion. Altough that itself
  // is a major programmer error, allowing it to go beyond upsetting the allocator
  // is not a good idea :-)
  if (!destroyed) {
    // phase 1 - get an exclusive lock and set the destroyed flag then release
    IExec->ObtainSemaphore(&lock);
    destroyed = true;
    IExec->ReleaseSemaphore(&lock);
    // From this point on, all user calls to lock an object will fail.
    // Pending locks will awaken in order of their queue position only to
    // find the object is due for destruction and will immediately
    // relinquish any lock they obtain, returning an error.

    // phase 2 - wait to get an exclusive lock then release
    IExec->ObtainSemaphore(&lock);
    IExec->ReleaseSemaphore(&lock);

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
  // If the destructor has gotten past stage 1, the destroyed flag is set.
  // We must check this first and exit immediately if it is found to be set.
  assertAlive();

  if (IExec->AttemptSemaphore(&lock)) {
    // If we have obtained te semaphore, it might be that the destructor
    // is now midway having flagged the destruction and waiting for all
    // the other threads to release their locks again.
    if (destroyed) {
      IExec->ReleaseSemaphore(&lock);
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
  // If the destructor has gotten past stage 1, the destroyed flag is set.
  // We must check this first and exit immediately if it is found to be set.
  assertAlive();
  IExec->ObtainSemaphore(&lock);
  if (destroyed) {
    // If we have obtained te semaphore, it might be that the destructor
    // is now midway having flagged the destruction and waiting for all
    // the other threads to release their locks again.
    IExec->ReleaseSemaphore(&lock);
    THROW_NSX(Error, ObjectDestroyed());
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Thread::Lockable::tryReadOnlyLock()
{
  // If the destructor has gotten past stage 1, the destroyed flag is set.
  // We must check this first and exit immediately if it is found to be set.
  assertAlive();
  if (IExec->AttemptSemaphoreShared(&lock)) {
    // If we have obtained te semaphore, it might be that the destructor
    // is now midway having flagged the destruction and waiting for all
    // the other threads to release their locks again.
    if (destroyed) {
      IExec->ReleaseSemaphore(&lock);
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
  // If the destructor has gotten past stage 1, the destroyed flag is set.
  // We must check this first and exit immediately if it is found to be set.
  assertAlive();
  IExec->ObtainSemaphoreShared(&lock);
  if (destroyed) {
    // If we have obtained te semaphore, it might be that the destructor
    // is now midway having flagged the destruction and waiting for all
    // the other threads to release their locks again.
    IExec->ReleaseSemaphore(&lock);
    THROW_NSX(Error, ObjectDestroyed());
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 Thread::Lockable::pending()
{
  assertAlive();
  //return lock.ss_NestCount - lock.ss_QueueCount - 1;
  return lock.ss_QueueCount;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Thread::Lockable::freeLock()
{
  if (!destroyed) {
    IExec->ReleaseSemaphore(&lock);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 Thread::Lockable::active()
{
  assertAlive();
  return lock.ss_NestCount;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Thread* Thread::Lockable::getExclusiveOwner()
{
  assertAlive();
  if (lock.ss_Owner) {
    return Thread::threadForTask(lock.ss_Owner);
  }
  return 0;
}
