///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/linux_noarch/systemlib/lockable_native.cpp
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

//#include <systemlib/logger.hpp>
#include <cstdio>

using namespace EXNGPrivate;


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Lockable
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Thread::Lockable::Lockable() : destroyed(false)
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Thread::Lockable::~Lockable()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


bool Thread::Lockable::tryLock()
{
  return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Thread::Lockable::waitLock()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Thread::Lockable::tryReadOnlyLock()
{
  return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Thread::Lockable::waitReadOnlyLock()
{
  // If the destructor has gotten past stage 1, the destroyed flag is set.
  // We must check this first and exit immediately if it is found to be set.
  if (destroyed) {
    THROW_NSX(Error, ObjectDestroyed());
  }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 Thread::Lockable::pending()
{
  if (destroyed) {
    THROW_NSX(Error, ObjectDestroyed());
  }
  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Thread::Lockable::freeLock()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 Thread::Lockable::active()
{
  if (destroyed) {
    THROW_NSX(Error, ObjectDestroyed());
  }
  return 0;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Thread* Thread::Lockable::getExclusiveOwner()
{
  if (destroyed) {
    THROW_NSX(Error, ObjectDestroyed());
  }
  return 0;
}

