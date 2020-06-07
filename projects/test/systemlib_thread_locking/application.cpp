///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         projects/test/thread.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Thread class test
//  Comment(s):
//  Created:      2007-03-18
//  Updated:      2007-03-18
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <xbase.hpp>
#include <systemlib/logger.hpp>
#include <systemlib/thread.hpp>
#include <private/systemlib/error.hpp>
#include <cstdlib>
#include <cstdio>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Lockable item
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Doobrey : public Thread::Lockable {
  public:
    Doobrey() : Lockable() {}
    ~Doobrey() {}
};

namespace {
  Doobrey* volatile   doobrey = 0;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  UserThread - basic extension of Thread. The alternative method is to bind a standard Thread to a Runnable instance
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class UserThread : public Thread {
  public:
    static volatile bool waitForLock;

    UserThread(uint32 ival, uint16 x, uint16 y, uint16 w, uint16 h);
    ~UserThread();

  protected:
    sint32  run();

  private:
    std::FILE*  output;
    uint32      interval;
    char        console[128];

};

volatile bool UserThread::waitForLock = false;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

UserThread::UserThread(uint32 ival, uint16 x, uint16 y, uint16 w, uint16 h) : Thread(PRI_NORMAL, 4096), interval(ival)
{
  std::sprintf(
    console,
    "CON:%" XPF_U16 "/%" XPF_U16 "/%" XPF_U16 "/%" XPF_U16 "/%s/CLOSE/WAIT",
    x, y, w, h,
    getResourceName()
  );
  output = std::fopen(console, "w");
  std::fprintf(output, "[console open]\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

UserThread::~UserThread()
{
  if (hasStarted()) {
    stop();
  }
  if (output) {
    std::fclose(output);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 UserThread::run()
{
  uint32  attemptsMade       = 0;
  uint32  attemptsSucceeded  = 0;

  bool hasLock = false;
  std::fprintf(output, "Hello World from %s, polling at %" XPF_U32 "\n", getResourceName(), interval);
  while (!stopRequested()) {

    if (!hasLock) {
      ++attemptsMade;
      if (doobrey) {
        try {
          if (waitForLock) {
            std::fprintf(output, "I'm about to waitLock() the Doobrey...\n");
            doobrey->waitLock();
            hasLock = true;
            ++attemptsSucceeded;
            std::fprintf(output, "Now it's mine for %" XPF_U32 "ms\n", interval);
          }
          else {
            std::fprintf(output, "I'm about to tryLock() the Doobrey...");
            if (hasLock = doobrey->tryLock()) {
              ++attemptsSucceeded;
              std::fprintf(output, "I win :) It's mine for %" XPF_U32 "ms now\n", interval);
            }
            else {
              std::fprintf(output, "I failed :( Maybe next time?\n");
            }
          }
        }
        catch (Error::Runtime& e) {
          std::fprintf(output, "I caught a %s when trying to lock Doobrey\n", e.getClass());
        }
      }
    } else {
      if (doobrey) {
        std::fprintf(output, "Doobrey Info: pending=%" XPF_S32 ", active=%" XPF_S32 "\n", doobrey->pending(), doobrey->active());
        doobrey->freeLock();
        std::fprintf(output, "I relinquished the Doobrey\n");
        hasLock = false;
      }
    }
    std::fprintf(output, "...");
    switch (suspend(interval, SLEEP_IGNORE_UNKNOWN|SLEEP_DISPOSE_TIMEOUT)) {
      case Thread::WAKE_TIMEOUT:
        std::fprintf(output, "\n");
        break;
      case Thread::WAKE_WAKE:
        std::fprintf(output, "[interrupted by wake()]\n");
        break;
      case Thread::WAKE_STOP:
        std::fprintf(output, "[interrupted by stop()]\n");
        break;
      case Thread::WAKE_SYSBREAK:
        std::fprintf(output, "[interrupted by system break]\n");
        break;
      case Thread::WAKE_USER:
        std::fprintf(output, "[interrupted by user signal]\n");
        break;
      case Thread::WAKE_SHUTDOWN:
        std::fprintf(output, "[interrupted by ~Thread()]\n");
        break;
      case Thread::WAKE_UNKNOWN:
        std::fprintf(output, "[interrupted by unknown]\n");
        break;
      default:
        break;
    }
    //std::fflush(output);
  }

  if (hasLock) {
    if (doobrey) {
      try {
        doobrey->freeLock();
        std::fprintf(output, "I relinquished the doobrey on exit\n");
      }
      catch (Error::Runtime& e) {
        std::fprintf(output, "Exception %s when trying to unlock doobrey on exit\n", e.getClass());
      }
    }
  }
  hasLock = false;

  std::fprintf(
    output,
    "\nMade %" XPF_U32 " attempts of which %" XPF_U32 " succeeded\n",
    attemptsMade,
    attemptsSucceeded
  );

  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Main Application
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ThreadTestApp : public Application
{
  public:
    sint32  run();

  public:
    ThreadTestApp();
    ~ThreadTestApp();

  private:
    UserThread* thread[4];
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Application* Application::createInstance()
{
  return new ThreadTestApp();
}

void Application::destroyInstance(Application* app)
{
  delete app;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ThreadTestApp::ThreadTestApp() : thread()
{
  int     i   = 0;
  uint32  ivl = 500;
  for (uint16 y=24; y<480; y+=240) {
    for (uint16 x=24; x<640; x+=320) {
      thread[i++] = new UserThread(ivl, x, y, 320, 240);
      ivl += 100;
    }
  }

  SystemLog::write(SystemLog::INFO, "Created ThreadTestApp\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ThreadTestApp::~ThreadTestApp()
{
  Time::Interval t = Thread::getCurrent()->getUptime();
  std::printf(
    "Main Program Uptime:%3lu days %02lu hours %02lu mins %02lu secs %03lu millis\n",
    t.days(), t.hours(), t.mins(), t.secs(), t.millisecs()
  );

  for (int i=0; i<4; i++) {
    delete thread[i];
  }

  SystemLog::write(SystemLog::INFO,"Destroyed ThreadTestApp\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 ThreadTestApp::run()
{
  bool help = true;
  bool quit = false;
  while (!quit) {

    if (help) {
      std::puts(
        "Choose method\n"
        "1) Start all threads\n"
        "2) Stop all threads\n"
        "3) Create Doobrey - threads each try to lock Doobrey for their specific interval\n"
        "4) Destroy Doobrey\n"
        "5) Set all threads to tryLock() mode (only when no Doobrey currently exists)\n"
        "6) Set all threads to waitLock() mode (only when no Doobrey currently exists)\n"
        "Q) Quit"
      );
    }

    help = false;
    try {
      switch (std::getchar()) {
        case '1':
          std::puts("Starting threads...");
          for (int i=0; i<4; i++) {
            thread[i]->start();
          }
          break;
        case '2':
          std::puts("Stopping threads...");
          for (int i=0; i<4; i++) {
            thread[i]->stop();
          }
          break;

        case '3':
          if (!doobrey) {
            doobrey = new Doobrey();
            std::puts("Created Doobrey");
          }
          break;

        case '4':
          if (doobrey) {
            delete doobrey;
            doobrey = 0;
            std::puts("Destroyed Doobrey");
          }
          break;

        case '5':
          if (!doobrey) {
            std::puts("Setting mode to tryLock()...");
            UserThread::waitForLock = false;
          }
          break;

        case '6':
          if (!doobrey) {
            std::puts("Setting mode to waitLock()...");
            UserThread::waitForLock = true;
          }
          break;

        case 'h':
        case 'H':
          help = true;
          break;
        case 'q':
        case 'Q':
          quit = true;
          break;

        default:
          break;
      }
    }
    catch (Error::Runtime& e) {
      std::printf("Unable to complete operation, caught %s\n", e.getClass());
    }
    catch(...) {
      std::printf("Unable to complete operation, caught an exception\n");
    }
  }
  std::puts("Bye!");
  return 0;
}

