#include <xbase.hpp>
#include <systemlib/time.hpp>
#include <cstdio>

void printDatestamp(FILE* f, const Time::Datestamp& date)
{
  std::fprintf(
    f,
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
