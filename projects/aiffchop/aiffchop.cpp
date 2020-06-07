#include <xbase.hpp>
#include <systemlib/memory.hpp>
#include <systemlib/time.hpp>

#include <cstdlib>
#include <cstdio>
#include <time.h>

#include "pcmstream_aiff.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Main application
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class AIFFChop : public Application
{
  public:
    sint32  run();

    enum {
      BUFFER_SIZE = 1024
    };

  private:

    Time::MilliClock  timer;
    InputPCMStream*   source;
    sint16            buffer[BUFFER_SIZE];

  public:
    AIFFChop();
    ~AIFFChop();
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Application* Application::createInstance()
{
  return new AIFFChop();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Application::destroyInstance(Application* app)
{
  delete app;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

AIFFChop::AIFFChop() : source(0)
{
  source = new InputAIFF16();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

AIFFChop::~AIFFChop()
{
  delete source;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 AIFFChop::run()
{
  const char* sourceName = getArgString("-from", 0, ARG_CASE_SENSITIVE|ARG_MANDATORY);

  source->open(sourceName);
  std::printf(
    "Opened %s: Freq: %.f Hz %" XPF_S32 " channels\n",
    sourceName,
    source->getRecFreq(),
    source->getNumChannels()
  );

  size_t  zeroSpan  = 0;
  size_t  n         = 0;
  size_t  p         = 0;
  uint32  average   = 0;
  uint32  marks     = 0;
  bool    mark      = false;

  do {
    n = source->readCombine(buffer, BUFFER_SIZE/source->getNumChannels());
    for (size_t j=0; j<n; j++) {
      if (!(average = (average>>1) + (uint32)(buffer[j]*buffer[j]))) {
        zeroSpan++;
      }
      else {
        zeroSpan = 0;
        mark     = true;
      }
      if (zeroSpan > 32 && mark) {
        std::printf("Mark %" XPF_U32 " %zd\n", ++marks, p);
        mark = false;
      }
      ++p;
    }

  } while (n>0);


  return 0;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
