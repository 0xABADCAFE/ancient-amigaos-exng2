#include <xbase.hpp>
#include <systemlib/cpu.hpp>
#include <systemlib/logger.hpp>
#include <systemlib/memory.hpp>
#include <systemlib/time.hpp>
//#include <systemlib/machine_bitops.hpp>

#include <cstdlib>
#include <cstdio>
#include <time.h>

#include "maps.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Main application
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class Main : public Application
{
  public:
    sint32  run();

  private:

    Time::MilliClock  timer;


  public:
    Main();
    ~Main();
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Application* Application::createInstance()
{
  return new Main();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Application::destroyInstance(Application* app)
{
  delete app;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Main::Main()
{
  SystemLog::write(SystemLog::INFO, "Created Main\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Main::~Main()
{
  SystemLog::write(SystemLog::INFO,"Destroyed Main\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 Main::run()
{
  LinearMap     linear;
  SubPatch16Map subpatch;

  float64       elapsed;

  uint32        max = linear.getSize()-1;

  printf("Testing linear %" XPF_U32 " x %" XPF_U32 "\n", linear.getSize(), linear.getSize());

  timer.set();
  for (uint32 y = 1; y < max; y++) {
    for (uint32 x = 1; x < max; x++) {
      uint32 val = linear.point(x, y)<<2;
      val       += (linear.point(x-1, y) +
                   linear.point(x+1, y) +
                   linear.point(x, y-1) +
                   linear.point(x, y+1))<<1;
      val       += (linear.point(x-1, y-1) +
                   linear.point(x+1, y-1) +
                   linear.point(x-1, y+1) +
                   linear.point(x+1, y+1));
      linear.point(x, y) = val>>4;
    }
  }
  elapsed = timer.elapsedFrac();

  printf("Elapsed time: %.3f ms\n", elapsed);

  max = subpatch.getSize()-1;

  printf("Testing subpatched %" XPF_U32 " x %" XPF_U32 "\n", subpatch.getSize(), subpatch.getSize());

  timer.set();
  for (uint32 y = 0; y < max; y++) {
    for (uint32 x = 0; x < max; x++) {
      uint32 val = subpatch.point(x, y)<<2;
      val       += (subpatch.point(x-1, y) +
                   subpatch.point(x+1, y) +
                   subpatch.point(x, y-1) +
                   subpatch.point(x, y+1))<<1;
      val       += (subpatch.point(x-1, y-1) +
                   subpatch.point(x+1, y-1) +
                   subpatch.point(x-1, y+1) +
                   subpatch.point(x+1, y+1));
      subpatch.point(x, y) = val>>4;
    }
  }
  elapsed = timer.elapsedFrac();

  printf("Elapsed time: %.3f ms\n", elapsed);

  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
