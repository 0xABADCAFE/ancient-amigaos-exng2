#include <xbase.hpp>
#include <systemlib/logger.hpp>
#include <systemlib/time.hpp>

#include <cstdlib>
#include <cstdio>
#include <ctime>


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Main application
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class DateTestApplication : public Application
{
  public:
    sint32  run();

    void    printDatestamp(const Time::Datestamp& ds);

  public:
    DateTestApplication();
    ~DateTestApplication();
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Application* Application::createInstance()
{
  return new DateTestApplication();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Application::destroyInstance(Application* app)
{
  delete app;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DateTestApplication::DateTestApplication()
{
  SystemLog::write(SystemLog::INFO, "Created DateTestApplication\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DateTestApplication::~DateTestApplication()
{
  SystemLog::write(SystemLog::INFO,"Destroyed DateTestApplication\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 DateTestApplication::run()
{
  Time::Datestamp ds0;
  Time::Datestamp ds1(ds0.year(), ds0.month(), ds0.day(), 0, 0, 0, 0, 0);
  Time::Datestamp ds2(ds0.year(), ds0.month(), ds0.day(), 1, 0, 0, 0, -60);

  Time::Interval interval(100);

  const char* testing = "Testing: %s %s\n";
  const char* passed  = "passed";
  const char* failed  = "failed";

  std::printf("ds0: ");
  printDatestamp(ds0);
  std::printf("ds1: ");
  printDatestamp(ds1);
  std::printf("ds2: ");
  printDatestamp(ds2);

  std::printf(testing, "ds0.leapYear()", ds0.leapYear() ? passed : failed);
  std::printf(testing, "ds0<ds1 ",       ds0<ds1        ? passed : failed);
  std::printf(testing, "ds0<=ds1",       ds0<=ds1       ? passed : failed);
  std::printf(testing, "ds0==ds1",       ds0==ds1       ? passed : failed);
  std::printf(testing, "ds0>=ds1",       ds0>=ds1       ? passed : failed);
  std::printf(testing, "ds0>ds1 ",       ds0>ds1        ? passed : failed);

  std::printf(testing, "ds0<ds2 ",       ds0<ds2        ? passed : failed);
  std::printf(testing, "ds0<=ds2",       ds0<=ds2       ? passed : failed);
  std::printf(testing, "ds0==ds2",       ds0==ds2       ? passed : failed);
  std::printf(testing, "ds0>=ds2",       ds0>=ds2       ? passed : failed);
  std::printf(testing, "ds0>ds2",        ds0>ds2        ? passed : failed);

  std::printf(testing, "ds1<ds2 ",       ds1<ds2        ? passed : failed);
  std::printf(testing, "ds1<=ds2",       ds1<=ds2       ? passed : failed);
  std::printf(testing, "ds1==ds2",       ds1==ds2       ? passed : failed);
  std::printf(testing, "ds1>=ds2",       ds1>=ds2       ? passed : failed);
  std::printf(testing, "ds1>ds2 ",       ds1>ds2        ? passed : failed);

  std::printf("Testing ds1 += interval\n");

  for (int i=0; i<20; i++) {
    printDatestamp(ds1);
    ds1 += interval;
  }

  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DateTestApplication::printDatestamp(const Time::Datestamp& date)
{
  std::printf(
    "%04" XPF_S32 "-%02" XPF_S32 "-%02" XPF_S32
    " %02" XPF_S32 ":%02" XPF_S32 ":%02" XPF_S32 ".%03" XPF_S32
    "%+" XPF_S32 ":%02" XPF_S32 "\n",
    date.year(),
    date.month(),
    date.day(),
    date.hour(),
    date.min(),
    date.sec(),
    date.millisec(),
    date.tzHour(),
    date.tzMin()
  );
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
