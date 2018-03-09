///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         utilitylib/poll.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Polling classes
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

#ifndef _EXNG2_UTILITYLIB_POLL_HPP_
# define _EXNG2_UTILITYLIB_POLL_HPP_

# include <systemlib/reflist.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Pollable
//
//  Service for objects that can be polled. Pollable provides a polling interval, the meaning of which is dependent
//  upon the specific type of Poll to which the Pollable object is polled by
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class Pollable {
  DEFINE_MIN_RTTI

  private:
    uint32  polled;
    uint32  interval;

  public:
    uint32  getTimesPolled()      const;
    uint32  getInterval()         const;
    void    setInterval(uint32 n);


  protected:
    virtual void doPollAction() = 0;

  public:
    void poll();

  protected:
    Pollable(uint32 i);

  public:
    virtual ~Pollable() {}
};

inline Pollable::Pollable(uint32 i) : polled(0), interval(i)
{

}

inline uint32 Pollable::getTimesPolled() const
{
  return polled;
}

inline uint32 Pollable::getInterval() const
{
  return interval;
}

inline void Pollable::setInterval(uint32 i)
{
  interval = i;
}

inline void Pollable::poll()
{
  polled++;
  doPollAction();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Poll
//
//  Base class for different types of Polling implementations. By default, Provides the most basic form of polling
//  where each Pollable instance is invoked on the call to poll();
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Poll {
  DEFINE_MIN_RTTI

  protected:
    RefList<Pollable> jobs;

  public:
    void    add(Pollable* p);
    bool    remove(Pollable* p);
    virtual void poll();


  public:
    Poll();
    virtual ~Poll();
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  IterationPoll
//
//  Traverses list on each call to poll(), invoking poll() for each Pollable instance depending on their interval.
//  Eg, a Pollable instance with an interval of 1 would always be polled during traversal, a Pollable object with an
//  interval of 2 would be polled every second traversal, etc.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class IterationPoll : public Poll {
  DEFINE_MIN_RTTI

  private:
    uint32  iteration;

  public:
    void    poll();
    uint32  getIteration() const;

  public:
    IterationPoll();
    ~IterationPoll();
};

inline uint32 IterationPoll::getIteration() const
{
  return iteration;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  TimedPoll
//
//  Traverses list on each call to poll(), invoking poll() for each Pollable instance, interpeting the interval as
//  the minimum time period in milliseconds between successive polls. Timing is not precise, as objects are never
//  polled until poll() is invoked for the TimedPoll. It is assumed that this method will be called at least as
//  frequently as the shortest interval in the list.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

# include <systemlib/time.hpp>

class TimedPoll : public Poll {
  DEFINE_MIN_RTTI

  private:
    Time::MilliClock  timer;
    uint32            longest;
  public:
    void    poll();

  public:
    TimedPoll();
    ~TimedPoll();
};

#endif
