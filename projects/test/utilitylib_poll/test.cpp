
#include <xbase.hpp>
#include <utilitylib/poll.hpp>
#include <cstdio>

class DummyJob : public Pollable {

  private:
    static uint32 nextId;
    uint32 id;

  protected:
    void doPollAction();

  public:
    DummyJob(uint32 i);
    ~DummyJob();

};

uint32 DummyJob::nextId = 0;

DummyJob::DummyJob(uint32 i) : Pollable(i), id(++nextId)
{
  std::printf("Created DummyJob %lu with interval %lu\n", id, i);
}

DummyJob::~DummyJob()
{
  std::printf("Destroyed DummyJob %lu\n", id);
}

void DummyJob::doPollAction()
{
  std::printf(
    "DummyJob %lu polled (%lu)\n",
    id,
    getTimesPolled()
  );
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class PollTestApp : public Application
{
  private:
    DummyJob*       jobs[4];
    Poll*           simplePoller;
    IterationPoll*  iterationPoller;

    void testPoll();
    void testIterationPoll();

  public:
    sint32 run();

  public:
    PollTestApp();
    ~PollTestApp();
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Application* Application::createInstance()
{
  return new PollTestApp();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Application::destroyInstance(Application* app)
{
  delete app;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

PollTestApp::PollTestApp()
{
  simplePoller    = new Poll();
  iterationPoller = new IterationPoll();

  for (int i=0; i<4; i++) {
    DummyJob* job = new DummyJob((i+1));
    jobs[i] = job;
    simplePoller->add(job);
    iterationPoller->add(job);
  }
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

PollTestApp::~PollTestApp()
{
  delete iterationPoller;
  delete simplePoller;
  for (int i=0; i<4; i++) {
    delete jobs[i];
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 PollTestApp::run()
{
  //testPoll();
  testIterationPoll();
  return 0;
}

void PollTestApp::testPoll()
{
  std::printf("\nTesting Poll\n");

  for (int i=0; i<4; i++) {
    std::printf("\nIteration %d...\n\n", i);
    simplePoller->poll();
  }
}

void PollTestApp::testIterationPoll()
{
  std::printf("\nTesting IterationPoll\n");

  for (int i=1; i<33; i++) {
    std::printf("\nIteration %d...\n\n", i);
    iterationPoller->poll();
  }
}

