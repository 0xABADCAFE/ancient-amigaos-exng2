///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         utilitylib/poll.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Poll classes
//  Comment(s):
//  Library:      utility
//  Created:      2007-04-07
//  Updated:      2007-04-07
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <xbase.hpp>
#include <utilitylib/poll.hpp>
#include <private/systemlib/error.hpp>

DECLARE_MIN_RTTI(Pollable)
DECLARE_MIN_RTTI(Poll)
DECLARE_MIN_RTTI(IterationPoll)
DECLARE_MIN_RTTI(TimedPoll)

Poll::Poll() : jobs()
{

}

Poll::~Poll()
{

}

void Poll::add(Pollable* p)
{
  jobs.pushBack(p);
}

bool Poll::remove(Pollable* p)
{
  return jobs.remove(p);
}

void Poll::poll()
{
  RefList<Pollable>::Iterator iterator(jobs);
  for (Pollable* p = iterator.first(); p; p = iterator.next()) {
    p->poll();
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

IterationPoll::IterationPoll() : Poll(), iteration(0)
{

}

IterationPoll::~IterationPoll()
{

}

void IterationPoll::poll()
{
  ++iteration;
  RefList<Pollable>::Iterator iterator(jobs);
  for (Pollable* p = iterator.first(); p; p = iterator.next()) {
    uint32 i = p->getInterval();
    if (i<2 || (iteration%i)==0) {
      p->poll();
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TimedPoll::TimedPoll() : Poll(), timer(), longest(0)
{
  timer.set();
}

TimedPoll::~TimedPoll()
{

}

void TimedPoll::poll()
{
  // We measure the interval since the last call to poll()
  // poll an instance if its interval is less than the
  // currently measured interval. An instance with an interval
  // of 2 ms will therefore always be polled if on average we
  // are calling this method at least once every 2ms.

  // We als keep an accumulated interval that  measures how long
  // it has been since all the objects were polled.
  // We test each instance against this to ensure that we
  // don't exclude instances that have polling intervals that
  // are longer than the average interval between polls.

  uint32                      interval = timer.elapsed();
  RefList<Pollable>::Iterator iterator(jobs);
  bool                        skipped = false;

  for (Pollable* p = iterator.first(); p; p = iterator.next()) {
    uint32 i = p->getInterval();
    if (i<=interval || i<=longest) {
      p->poll();
    } else {
      skipped = true;
    }
  }
  if (skipped) {
    longest += interval;
  } else {
    longest = 0;
  }
  timer.set();
}
