
#include <xbase.hpp>
#include <systemlib/time.hpp>
#include <utilitylib/quickmath.hpp>
#include <cstdio>
#include <cmath>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class QuickMathTestApp : public Application
{
  public:
    sint32 run();

  public:
    QuickMathTestApp();
    ~QuickMathTestApp();
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Application* Application::createInstance()
{
  return new QuickMathTestApp();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Application::destroyInstance(Application* app)
{
  delete app;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

QuickMathTestApp::QuickMathTestApp()
{

}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

QuickMathTestApp::~QuickMathTestApp()
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static float32 repSqrt(float32 x)
{
  return 1.0f/std::sqrt(x);
}

sint32 QuickMathTestApp::run()
{
  Time::MilliClock timer;

  std::printf("Testing repSqrt()\n");
  float64 ms  = 0.0f;
  float32 res = 0.0f;
  float32 s   = 0.1f;
  float32 f   = 0.1f;
  timer.set();
  for (sint32 i=0; i<100000; i++) {
    res += repSqrt(f); f+= s;
    res += repSqrt(f); f+= s;
    res += repSqrt(f); f+= s;
    res += repSqrt(f); f+= s;
    res += repSqrt(f); f+= s;
    res += repSqrt(f); f+= s;
    res += repSqrt(f); f+= s;
    res += repSqrt(f); f+= s;
    res += repSqrt(f); f+= s;
    res += repSqrt(f); f+= s;
  }
  ms = timer.elapsedFrac();
  std::printf("Took %.3f ms [res : %.6f]\n", ms, res);

  std::printf("Testing sqrt()\n");
  res = 0.0f;
  f   = 0.1f;
  timer.set();
  for (sint32 i=0; i<100000; i++) {
    res += std::sqrt(f); f+= s;
    res += std::sqrt(f); f+= s;
    res += std::sqrt(f); f+= s;
    res += std::sqrt(f); f+= s;
    res += std::sqrt(f); f+= s;
    res += std::sqrt(f); f+= s;
    res += std::sqrt(f); f+= s;
    res += std::sqrt(f); f+= s;
    res += std::sqrt(f); f+= s;
    res += std::sqrt(f); f+= s;
  }
  ms = timer.elapsedFrac();
  std::printf("Took %.3f ms [res : %.6f]\n", ms, res);


  std::printf("Testing QMath::repSqrtEstimate()\n");
  res = 0.0f;
  f   = 0.1f;
  timer.set();
  for (sint32 i=0; i<100000; i++) {
    res += QMath::repSqrtEstimate(f); f+= s;
    res += QMath::repSqrtEstimate(f); f+= s;
    res += QMath::repSqrtEstimate(f); f+= s;
    res += QMath::repSqrtEstimate(f); f+= s;
    res += QMath::repSqrtEstimate(f); f+= s;
    res += QMath::repSqrtEstimate(f); f+= s;
    res += QMath::repSqrtEstimate(f); f+= s;
    res += QMath::repSqrtEstimate(f); f+= s;
    res += QMath::repSqrtEstimate(f); f+= s;
    res += QMath::repSqrtEstimate(f); f+= s;
  }
  ms = timer.elapsedFrac();
  std::printf("Took %.3f ms [res : %.6f]\n", ms, res);

  std::printf("Testing QMath::sqrtEstimate()\n");
  res = 0.0f;
  f   = 0.1f;
  timer.set();
  for (sint32 i=0; i<100000; i++) {
    res += QMath::sqrtEstimate(f); f+= s;
    res += QMath::sqrtEstimate(f); f+= s;
    res += QMath::sqrtEstimate(f); f+= s;
    res += QMath::sqrtEstimate(f); f+= s;
    res += QMath::sqrtEstimate(f); f+= s;
    res += QMath::sqrtEstimate(f); f+= s;
    res += QMath::sqrtEstimate(f); f+= s;
    res += QMath::sqrtEstimate(f); f+= s;
    res += QMath::sqrtEstimate(f); f+= s;
    res += QMath::sqrtEstimate(f); f+= s;
  }
  ms = timer.elapsedFrac();
  std::printf("Took %.3f ms [res : %.6f]\n", ms, res);

  std::printf("Testing QMath::repSqrtEstimate2()\n");
  res = 0.0f;
  f   = 0.1f;
  timer.set();
  for (sint32 i=0; i<100000; i++) {
    res += QMath::repSqrtEstimate2(f); f+= s;
    res += QMath::repSqrtEstimate2(f); f+= s;
    res += QMath::repSqrtEstimate2(f); f+= s;
    res += QMath::repSqrtEstimate2(f); f+= s;
    res += QMath::repSqrtEstimate2(f); f+= s;
    res += QMath::repSqrtEstimate2(f); f+= s;
    res += QMath::repSqrtEstimate2(f); f+= s;
    res += QMath::repSqrtEstimate2(f); f+= s;
    res += QMath::repSqrtEstimate2(f); f+= s;
    res += QMath::repSqrtEstimate2(f); f+= s;
  }
  ms = timer.elapsedFrac();
  std::printf("Took %.3f ms [res : %.6f]\n", ms, res);

  std::printf("Testing QMath::sqrtEstimate2()\n");
  res = 0.0f;
  f   = 0.1f;
  timer.set();
  for (sint32 i=0; i<100000; i++) {
    res += QMath::sqrtEstimate2(f); f+= s;
    res += QMath::sqrtEstimate2(f); f+= s;
    res += QMath::sqrtEstimate2(f); f+= s;
    res += QMath::sqrtEstimate2(f); f+= s;
    res += QMath::sqrtEstimate2(f); f+= s;
    res += QMath::sqrtEstimate2(f); f+= s;
    res += QMath::sqrtEstimate2(f); f+= s;
    res += QMath::sqrtEstimate2(f); f+= s;
    res += QMath::sqrtEstimate2(f); f+= s;
    res += QMath::sqrtEstimate2(f); f+= s;
  }
  ms = timer.elapsedFrac();
  std::printf("Took %.3f ms [res : %.6f]\n", ms, res);

  return 0;
}

