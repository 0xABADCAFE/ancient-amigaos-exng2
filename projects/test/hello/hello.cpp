#include <xbase.hpp>
#include <systemlib/cpu.hpp>
#include <systemlib/logger.hpp>
#include <systemlib/memory.hpp>
#include <systemlib/time.hpp>
#include <systemlib/machine_bitops.hpp>

#include <cstdlib>
#include <cstdio>
#include <time.h>

void naiveSwap16(void* dst, const void* src, size_t len)
{
  const uint16* s = (const uint16*)src;
  uint16*       d = (uint16*)dst;
  while (len--) {
    *d++ = Machine::swap16(*s++);
  }
}

void naiveSwap32(void* dst, const void* src, size_t len)
{
  const uint32* s = (const uint32*)src;
  uint32*       d = (uint32*)dst;
  while (len--) {
    *d++ = Machine::swap32(*s++);
  }
}

void naiveSwap64(void* dst, const void* src, size_t len)
{
  const uint64* s = (const uint64*)src;
  uint64*       d = (uint64*)dst;
  while (len--) {
    *d++ = Machine::swap64(*s++);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Main application
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class HelloWorld : public Application
{
  public:
    sint32  run();

  private:
    void    testProcessorClass();
    void    testMachineClass();
    void    testDatestampClass();

    void    testMemSwap();

    void    printDatestamp(const Time::Datestamp& ds);

    enum {
      BLOCK_SIZE  = 32*1024*1024
    };

    Time::MilliClock  timer;
    void*             memBlock;

  public:
    HelloWorld();
    ~HelloWorld();
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Application* Application::createInstance()
{
  return new HelloWorld();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Application::destroyInstance(Application* app)
{
  delete app;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

HelloWorld::HelloWorld()
{
  memBlock = Mem::alloc(BLOCK_SIZE);
  SystemLog::write(SystemLog::INFO, "Created HelloWorld\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

HelloWorld::~HelloWorld()
{
  Mem::free(memBlock);
  SystemLog::write(SystemLog::INFO,"Destroyed HelloWorld\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 HelloWorld::run()
{
  testProcessorClass();
  testMemSwap();
  //testMachineClass();
  //testDatestampClass();
  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void HelloWorld::testProcessorClass()
{
  std::printf(
    "Testing ProcessorInfo\n\tSystem reports %" XPF_U32 " available processors\n",
    Machine::ProcessorInfo::getProcessorCount()
  );
  for (uint32 i=0; i<Machine::ProcessorInfo::getProcessorCount(); i++) {
    std::printf(
      "\tProcessor [%" XPF_U32 "] : %s @ %g MHz\n",
      i,
      Machine::ProcessorInfo::getProcessorName(i),
      Machine::ProcessorInfo::getProcessorSpeed(i)
    );
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void HelloWorld::testMemSwap()
{
  float64     dataSize      = BLOCK_SIZE/(1024*1024);
  float64     elapsed       = 0;
  uint32      numWords      = 0;
  const char* testTemplate  = "Testing %d-bit byteswap on %" XPF_U32 " words (x4)\n";
  const char* resTemplate   = "Took %.6f s (%.2f MB/s) [total bandwidth]\n";

  void* src   = memBlock;
  void* dst   = ((uint8*)memBlock)+BLOCK_SIZE/2;

  std::printf("Testing Mem::swapX() routines\n");
  numWords    = BLOCK_SIZE/(2*sizeof(uint16));
  std::printf(testTemplate, 16, numWords);
  timer.set();
  Mem::swap16(dst, src, numWords);
  Mem::swap16(src, dst, numWords);
  Mem::swap16(dst, src, numWords);
  Mem::swap16(src, dst, numWords);
  elapsed = timer.elapsedFrac()*0.001;
  std::printf(resTemplate, elapsed, 4*dataSize/elapsed);

  numWords    = BLOCK_SIZE/(2*sizeof(uint32));
  std::printf(testTemplate, 32, numWords);
  timer.set();
  Mem::swap32(dst, src, numWords);
  Mem::swap32(src, dst, numWords);
  Mem::swap32(dst, src, numWords);
  Mem::swap32(src, dst, numWords);

  elapsed = timer.elapsedFrac()*0.001;
  std::printf(resTemplate, elapsed, 4*dataSize/elapsed);

  numWords    = BLOCK_SIZE/(2*sizeof(uint64));
  std::printf(testTemplate, 64, numWords);
  timer.set();
  Mem::swap64(dst, src, numWords);
  Mem::swap64(src, dst, numWords);
  Mem::swap64(dst, src, numWords);
  Mem::swap64(src, dst, numWords);
  elapsed = timer.elapsedFrac()*0.001;
  std::printf(resTemplate, elapsed, 4*dataSize/elapsed);

  std::printf("Testing naiveSwapX() routines\n");
  numWords    = BLOCK_SIZE/(2*sizeof(uint16));
  std::printf(testTemplate, 16, numWords);
  timer.set();
  naiveSwap16(dst, src, numWords);
  naiveSwap16(src, dst, numWords);
  naiveSwap16(dst, src, numWords);
  naiveSwap16(src, dst, numWords);
  elapsed = timer.elapsedFrac()*0.001;
  std::printf(resTemplate, elapsed, 4*dataSize/elapsed);

  numWords    = BLOCK_SIZE/(2*sizeof(uint32));
  std::printf(testTemplate, 32, numWords);
  timer.set();
  naiveSwap32(dst, src, numWords);
  naiveSwap32(src, dst, numWords);
  naiveSwap32(dst, src, numWords);
  naiveSwap32(src, dst, numWords);
  elapsed = timer.elapsedFrac()*0.001;
  std::printf(resTemplate, elapsed, 4*dataSize/elapsed);

  numWords    = BLOCK_SIZE/(2*sizeof(uint64));
  std::printf(testTemplate, 64, numWords);
  timer.set();
  naiveSwap64(dst, src, numWords);
  naiveSwap64(dst, src, numWords);
  naiveSwap64(dst, src, numWords);
  naiveSwap64(dst, src, numWords);
  elapsed = timer.elapsedFrac()*0.001;
  std::printf(resTemplate, elapsed, 4*dataSize/elapsed);
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void HelloWorld::testMachineClass()
{
  uint64 blk1[4] = { 0x0123456789ABCDEFULL, 0x0123456789ABCDEFULL, 0x0123456789ABCDEFULL, 0x0123456789ABCDEFULL};
  uint64 blk2[4] = { 0, 0, 0, 0};

  uint32 x = 0xAABBCCDD, y=0;
  const char* prt = "%08X -> %08X\n";

  y = Machine::swap32(x);
  std::printf(prt, (unsigned)x, (unsigned)y);

  y = Machine::rotLeft32(0, x);
  std::printf(prt, (unsigned)x, (unsigned)y);

  y = Machine::rotLeft32(4, x);
  std::printf(prt, (unsigned)x, (unsigned)y);

  y = Machine::rotLeft32(8, x);
  std::printf(prt, (unsigned)x, (unsigned)y);

  y = Machine::rotLeft32(12, x);
  std::printf(prt, (unsigned)x, (unsigned)y);

  y = Machine::rotLeft32(16, x);
  std::printf(prt, (unsigned)x, (unsigned)y);

  y = Machine::rotLeft32(20, x);
  std::printf(prt, (unsigned)x, (unsigned)y);

  y = Machine::rotLeft32(24, x);
  std::printf(prt, (unsigned)x, (unsigned)y);

  y = Machine::rotLeft32(28, x);
  std::printf(prt, (unsigned)x, (unsigned)y);

  y = Machine::rotLeft32(32, x);
  std::printf(prt, (unsigned)x, (unsigned)y);

  y = Machine::rotRight32(0, x);
  std::printf(prt, (unsigned)x, (unsigned)y);

  y = Machine::rotRight32(4, x);
  std::printf(prt, (unsigned)x, (unsigned)y);

  y = Machine::rotRight32(8, x);
  std::printf(prt, (unsigned)x, (unsigned)y);

  y = Machine::rotRight32(12, x);
  std::printf(prt, (unsigned)x, (unsigned)y);

  y = Machine::rotRight32(16, x);
  std::printf(prt, (unsigned)x, (unsigned)y);

  y = Machine::rotRight32(20, x);
  std::printf(prt, (unsigned)x, (unsigned)y);

  y = Machine::rotRight32(24, x);
  std::printf(prt, (unsigned)x, (unsigned)y);

  y = Machine::rotRight32(28, x);
  std::printf(prt, (unsigned)x, (unsigned)y);

  y = Machine::rotRight32(32,x);
  std::printf(prt, (unsigned)x, (unsigned)y);

  uint8* pB1 = (uint8*)blk1;
  uint8* pB2 = (uint8*)blk2;

  Mem::swap16(blk2, blk1, sizeof(blk1)/sizeof(uint16));
  for (int i=0; i<sizeof(blk1); i++) {
    std::printf("%02X ", pB1[i]);
  }
  std::printf("\n");
  for (int i=0; i<sizeof(blk2); i++) {
    std::printf("%02X ", pB2[i]);
  }
  std::printf("\n");


  Mem::swap32(blk2, blk1, sizeof(blk1)/sizeof(uint32));
  for (int i=0; i<sizeof(blk1); i++) {
    std::printf("%02X ", pB1[i]);
  }
  std::printf("\n");
  for (int i=0; i<sizeof(blk2); i++) {
    std::printf("%02X ", pB2[i]);
  }
  std::printf("\n");

  Mem::swap64(blk2, blk1, sizeof(blk1)/sizeof(uint64));
  for (int i=0; i<sizeof(blk1); i++) {
    std::printf("%02X ", pB1[i]);
  }
  std::printf("\n");
  for (int i=0; i<sizeof(blk2); i++) {
    std::printf("%02X ", pB2[i]);
  }
  std::printf("\n");

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void HelloWorld::testDatestampClass()
{
  Time::Datestamp ds0;
  Time::Datestamp ds1(ds0.year(), ds0.month(), ds0.day(), 0, 0, 0, 0, 0);
  Time::Datestamp ds2(ds0.year(), ds0.month(), ds0.day(), 1, 0, 0, 0, -60);

  std::printf("ds0: ");
  printDatestamp(ds0);
  std::printf("ds1: ");
  printDatestamp(ds1);
  std::printf("ds2: ");
  printDatestamp(ds2);

  std::printf("Testing: ds0<ds1 ");
  if (ds0<ds1) {
    std::puts("passed");
  } else {
    std::puts("failed");
  }

  std::printf("Testing: ds0<=ds1 ");
  if (ds0<ds1) {
    std::puts("passed");
  } else {
    std::puts("failed");
  }

  std::printf("Testing: ds0==ds1 ");
  if (ds0==ds1) {
    std::puts("passed");
  } else {
    std::puts("failed");
  }


  std::printf("Testing: ds1<ds2 ");
  if (ds1<ds2) {
    std::puts("passed");
  } else {
    std::puts("failed");
  }

  std::printf("Testing: ds1<=ds2 ");
  if (ds1<ds2) {
    std::puts("passed");
  } else {
    std::puts("failed");
  }

  std::printf("Testing: ds1==ds2 ");
  if (ds1==ds2) {
    std::puts("passed");
  } else {
    std::puts("failed");
  }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void HelloWorld::printDatestamp(const Time::Datestamp& date)
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
