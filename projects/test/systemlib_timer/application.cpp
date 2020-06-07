///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         projects/blank_project/application.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Application wireframe
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
#include <systemlib/time.hpp>
#include <systemlib/thread.hpp>
//#include <systemlib/logger.hpp>
//#include <iolib/streamio.hpp>
#include <cstdio>


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Main Application
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class MainApplication : public Application
{
  public:
    sint32  run();

  public:
    MainApplication();
    ~MainApplication();

  private:
    Time::MilliClock  timer;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Application* Application::createInstance()
{
  return new MainApplication();
}

void Application::destroyInstance(Application* app)
{
  delete app;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

MainApplication::MainApplication()
{
  //SystemLog::write(SystemLog::INFO, "Created MainApplication\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

MainApplication::~MainApplication()
{
  //SystemLog::write(SystemLog::INFO,"Destroyed MainApplication\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 MainApplication::run()
{
  timer.set();

  union {
    OSNative::EClockVal time1;
    uint64 time1_u64;
  };

  union {
    OSNative::EClockVal time2;
    uint64 time2_u64;
  };

  uint32 rate1 = OSNative::ReadEClock(&time1);

  Thread::sleep(1000, Thread::SLEEP_DISPOSE_TIMEOUT);

  uint32 rate2 = OSNative::ReadEClock(&time2);

  uint64 dt = time2_u64-time1_u64;

  std::printf(
    "time1 = { %" XPF_U32 ", %" XPF_U32 " } [%" XPF_U64 "] @ %" XPF_U32 "Hz\n"
    "time2 = { %" XPF_U32 ", %" XPF_U32 " } [%" XPF_U64 "] @ %" XPF_U32 "Hz\n"
    "diff %" XPF_U64 "\n",
    time1.ev_hi, time1.ev_lo, time1_u64, rate1,
    time2.ev_hi, time2.ev_lo, time2_u64, rate2,
    dt
  );



  float64 t = timer.elapsedFrac();

  std::printf("Elapsed %f ms\n", t);

  return 0;
}


