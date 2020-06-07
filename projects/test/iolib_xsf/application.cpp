#include <xbase.hpp>
#include <systemlib/cpu.hpp>
#include <systemlib/logger.hpp>
#include <iolib/xsfio.hpp>
#include <cstdio>


void printDatestamp(const Time::Datestamp& date)
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
//
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class XSFTestApp : public Application, XSF::Stream::User
{
  public:
    sint32 run();

  public:
    XSFTestApp();
    ~XSFTestApp();

  private:
    void testWrite();
    void testRead1();
    void testRead2();


    struct TestInfo {
      const char* filename;
      uint32      signature;
    };
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Application* Application::createInstance()
{
  return new XSFTestApp();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Application::destroyInstance(Application* app)
{
  delete app;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

XSFTestApp::XSFTestApp()
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

XSFTestApp::~XSFTestApp()
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 XSFTestApp::run()
{
  testWrite();
  testRead1();
  testRead2();

  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void XSFTestApp::testWrite()
{
  uint64 dummy[] = { 0xABADCAFEDEADF00DULL, 0x0011223344556677ULL };

  TestInfo machines[] = {
    {"32be", Machine::ALIGNED_32|Machine::PTRSIZE_32|Machine::MSB_FIRST|Machine::TWOS_COMP},
    {"64be", Machine::ALIGNED_64|Machine::PTRSIZE_64|Machine::MSB_FIRST|Machine::TWOS_COMP},
    {"32le", Machine::ALIGNED_32|Machine::PTRSIZE_32|Machine::LSB_FIRST|Machine::TWOS_COMP},
    {"64le", Machine::ALIGNED_64|Machine::PTRSIZE_64|Machine::LSB_FIRST|Machine::TWOS_COMP},
  };

  char buffer[32];


  XSF::Stream::Out out;

  for (int i=0; i<sizeof(machines)/sizeof(TestInfo); i++) {
    std::printf("Creating test_%s.xsf\n", machines[i].filename);
    std::sprintf(buffer, "test_%s.xsf", machines[i].filename);
    out.open(buffer, "Test", 1, 0, machines[i].signature, 2048);
    write8(&out, dummy, sizeof(dummy));
    write16(&out, dummy, sizeof(dummy)/sizeof(uint16));
    write32(&out, dummy, sizeof(dummy)/sizeof(uint32));
    write64(&out, dummy, sizeof(dummy)/sizeof(uint64));
    out.close();
  }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void XSFTestApp::testRead1()
{
  const char* files[] = {
    "32be",
    "64be",
    "32le",
    "64be"
  };
  char buffer[32];

  XSF::Stream::In in;

  for (int i=0; i<sizeof(files)/sizeof(char*); i++) {
    std::printf("Opening test_%s.xsf\n", files[i]);
    std::sprintf(buffer, "test_%s.xsf", files[i]);
    in.open(buffer, 2048);

    std::printf(
      "XSF     Version: %d.%d\n"
      "Payload Version: %d.%d\n",
      (int)in.getHeader().getXSFVersion(),
      (int)in.getHeader().getXSFRevision(),
      (int)in.getHeader().getPayloadVersion(),
      (int)in.getHeader().getPayloadRevision()
    );

    std::printf(
      "Created        : "
    );
    printDatestamp(in.getHeader().getDateCreated());

    in.close();
  }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void XSFTestApp::testRead2()
{

}


