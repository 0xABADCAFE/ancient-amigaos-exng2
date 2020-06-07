#include <xbase.hpp>
#include <systemlib/cpu.hpp>
#include <systemlib/logger.hpp>
#include <systemlib/memory.hpp>
#include <systemlib/time.hpp>
#include <systemlib/machine_bitops.hpp>

#include <cstdlib>
#include <cstdio>

void naiveSwap16(void* dst, const void* src, size_t len);
void naiveSwap32(void* dst, const void* src, size_t len);
void naiveSwap64(void* dst, const void* src, size_t len);

extern "C" {
  void set32_move16(void *dst, uint32 val, size_t len);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Main application
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class MachineTestApplication : public Application
{
  public:
    sint32  run();

  private:
    void    testProcessorInfo();
    void    testMachineBitOps();
    void    testMemoryBlockSet();
    void    testMemoryBlockSwap();

    void    test040Set();

    enum {
      BLOCK_SIZE  = 32*1024*1024
    };

    Time::MilliClock  timer;
    void*             memBlock;

  public:
    MachineTestApplication();
    ~MachineTestApplication();
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Application* Application::createInstance()
{
  return new MachineTestApplication();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Application::destroyInstance(Application* app)
{
  delete app;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

MachineTestApplication::MachineTestApplication()
{
  memBlock = Mem::alloc(BLOCK_SIZE+1024);
  printf("memBlock allocated at %p\n", memBlock);
  SystemLog::write(SystemLog::INFO, "Created MachineTestApplication\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

MachineTestApplication::~MachineTestApplication()
{
  Mem::free(memBlock);
  SystemLog::write(SystemLog::INFO,"Destroyed MachineTestApplication\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 MachineTestApplication::run()
{
  if (getNumArgs()<=1) {
    std::printf(
      "Usage: %s [-cpu] [-bit] [-set] [-swap]\n"
      "-cpu : report processor information\n"
      "-bit : verify bit operations\n"
      "-set : benchmark memory setting throughput\n"
      "-swap: benchmark memory swapping throughput\n",
      getArg(0)
    );
  }

  if (getArgSwitch("-cpu", ARG_CASE_SENSITIVE)) {
    testProcessorInfo();
  }

  if (getArgSwitch("-bit", ARG_CASE_SENSITIVE)) {
    testMachineBitOps();
  }

  if (getArgSwitch("-set", ARG_CASE_SENSITIVE)) {
    testMemoryBlockSet();
  }

  if (getArgSwitch("-set040", ARG_CASE_SENSITIVE)) {
    test040Set();
  }


  if (getArgSwitch("-swap", ARG_CASE_SENSITIVE)) {
    testMemoryBlockSwap();
  }

  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MachineTestApplication::testProcessorInfo()
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

void MachineTestApplication::testMemoryBlockSet()
{
  float64     dataSize      = BLOCK_SIZE/(1024*1024);
  float64     elapsed       = 0;
  uint32      numWords      = 0;
  const char* testTemplate  = "Testing %d-bit set on %" XPF_U32 " words (x4)\n";
  const char* resTemplate   = "Took %.6f s (%.2f MB/s) [total bandwidth]\n\n";

  std::printf("Testing Mem::setX() routines\n");

  numWords    = BLOCK_SIZE;
  std::printf(testTemplate, 8, numWords);
  timer.set();
  Mem::set(memBlock, 0xFF, numWords);
  Mem::set(memBlock, 0x00, numWords);
  Mem::set(memBlock, 0xFF, numWords);
  Mem::set(memBlock, 0x00, numWords);
  elapsed = timer.elapsedFrac()*0.001;
  std::printf(resTemplate, elapsed, 4*dataSize/elapsed);

  numWords    = BLOCK_SIZE/sizeof(uint16);
  std::printf(testTemplate, 16, numWords);
  timer.set();
  Mem::set16(memBlock, 0x137F, numWords);
  Mem::set16(memBlock, 0xF731, numWords);
  Mem::set16(memBlock, 0x137F, numWords);
  Mem::set16(memBlock, 0xF731, numWords);
  elapsed = timer.elapsedFrac()*0.001;
  std::printf(resTemplate, elapsed, 4*dataSize/elapsed);

  numWords    = BLOCK_SIZE/sizeof(uint32);
  std::printf(testTemplate, 32, numWords);
  timer.set();
  Mem::set32(memBlock, 0xF73108CE, numWords);
  Mem::set32(memBlock, 0x08CEF731, numWords);
  Mem::set32(memBlock, 0xF73108CE, numWords);
  Mem::set32(memBlock, 0x08CEF731, numWords);
  elapsed = timer.elapsedFrac()*0.001;
  std::printf(resTemplate, elapsed, 4*dataSize/elapsed);

  numWords    = BLOCK_SIZE/sizeof(uint64);
  std::printf(testTemplate, 64, numWords);
  timer.set();
  Mem::set64(memBlock, 0x0011223344556677ULL, numWords);
  Mem::set64(memBlock, 0x7766554433221100ULL, numWords);
  Mem::set64(memBlock, 0x0011223344556677ULL, numWords);
  Mem::set64(memBlock, 0x7766554433221100ULL, numWords);
  elapsed = timer.elapsedFrac()*0.001;
  std::printf(resTemplate, elapsed, 4*dataSize/elapsed);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MachineTestApplication::test040Set()
{
  float64     dataSize      = BLOCK_SIZE/(1024*1024);
  float64     elapsed       = 0;
  uint32      numWords      = 0;
  const char* testTemplate  = "Testing %d-bit set on %" XPF_U32 " words (x4)\n";
  const char* resTemplate   = "Took %.6f s (%.2f MB/s) [total bandwidth]\n\n";

  std::printf("Testing setX_move16() routines\n");
  numWords    = BLOCK_SIZE/sizeof(uint32);

  Mem::set32(memBlock, 0xDEADBEEF, numWords+256);

  std::printf(testTemplate, 32, numWords);
  timer.set();
  set32_move16(memBlock, 0x01234567, numWords);
  set32_move16(memBlock, 0x76543210, numWords);
  set32_move16(memBlock, 0x01234567, numWords);
  set32_move16(memBlock, 0x76543210, numWords);
  elapsed = timer.elapsedFrac()*0.001;
  std::printf(resTemplate, elapsed, 4*dataSize/elapsed);
//   std::printf("0x%08X | 0x%08X | 0x%08X\n",
//     *((uint32*)memBlock),
//     *(((uint32*)memBlock)+numWords-1),
//     *(((uint32*)memBlock)+numWords)
//   );
  uint32* p = ((uint32*)memBlock)+numWords-8;
  for (int i=-8; i<8; i++) {
    std::printf(
      "%2d : 0x%08X\n",
      i,
      (unsigned)(*p++)
    );
  }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MachineTestApplication::testMemoryBlockSwap()
{
  float64     dataSize      = BLOCK_SIZE/(1024*1024);
  float64     elapsed       = 0;
  uint32      numWords      = 0;
  const char* testTemplate  = "Testing %d-bit byteswap on %" XPF_U32 " words (x4)\n";
  const char* resTemplate   = "Took %.6f s (%.2f MB/s) [total bandwidth]\n\n";

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


void MachineTestApplication::testMachineBitOps()
{
  const char* prt32 = "%10s #%2d %08X -> %08X\n";
  const char* prt16 = "%10s #%2d %04X -> %04X\n";
  const char* prt8  = "%10s #%2d %02X -> %02X\n";

  uint32 src32 = 0xAABBCCDD, dst32=0;
  uint16 src16 = 0xABCD,     dst16=0;
  uint8  src8  = 0xF0,       dst8=0;

  std::printf("Testing Machine rotate/swap routines with constant literal size\n");

  // these should generate optimal sequences of inlined asm
  dst8  = Machine::rotLeft8(0, src8);     std::printf(prt8, "rol8", 0, (unsigned)src8, (unsigned)dst8);
  dst8  = Machine::rotLeft8(2, src8);     std::printf(prt8, "rol8", 2, (unsigned)src8, (unsigned)dst8);
  dst8  = Machine::rotLeft8(4, src8);     std::printf(prt8, "rol8", 4, (unsigned)src8, (unsigned)dst8);
  dst8  = Machine::rotLeft8(6, src8);     std::printf(prt8, "rol8", 6, (unsigned)src8, (unsigned)dst8);
  dst8  = Machine::rotLeft8(8, src8);     std::printf(prt8, "rol8", 8, (unsigned)src8, (unsigned)dst8);
  dst8  = Machine::rotRight8(0, src8);    std::printf(prt8, "ror8", 0, (unsigned)src8, (unsigned)dst8);
  dst8  = Machine::rotRight8(2, src8);    std::printf(prt8, "ror8", 2, (unsigned)src8, (unsigned)dst8);
  dst8  = Machine::rotRight8(4, src8);    std::printf(prt8, "ror8", 4, (unsigned)src8, (unsigned)dst8);
  dst8  = Machine::rotRight8(6, src8);    std::printf(prt8, "ror8", 6, (unsigned)src8, (unsigned)dst8);
  dst8  = Machine::rotRight8(8, src8);    std::printf(prt8, "ror8", 8, (unsigned)src8, (unsigned)dst8);

  dst16 = Machine::swap16(src16);         std::printf(prt16, "swap", 16, (unsigned)src16, (unsigned)dst16);
  dst16 = Machine::rotLeft16(0, src16);   std::printf(prt16, "rol16", 0, (unsigned)src16, (unsigned)dst16);
  dst16 = Machine::rotLeft16(4, src16);   std::printf(prt16, "rol16", 4, (unsigned)src16, (unsigned)dst16);
  dst16 = Machine::rotLeft16(8, src16);   std::printf(prt16, "rol16", 8, (unsigned)src16, (unsigned)dst16);
  dst16 = Machine::rotLeft16(12, src16);  std::printf(prt16, "rol16", 12, (unsigned)src16, (unsigned)dst16);
  dst16 = Machine::rotLeft16(16, src16);  std::printf(prt16, "rol16", 16, (unsigned)src16, (unsigned)dst16);
  dst16 = Machine::rotRight16(0, src16);  std::printf(prt16, "ror16", 0, (unsigned)src16, (unsigned)dst16);
  dst16 = Machine::rotRight16(4, src16);  std::printf(prt16, "ror16", 4, (unsigned)src16, (unsigned)dst16);
  dst16 = Machine::rotRight16(8, src16);  std::printf(prt16, "ror16", 8, (unsigned)src16, (unsigned)dst16);
  dst16 = Machine::rotRight16(12, src16); std::printf(prt16, "ror16", 12, (unsigned)src16, (unsigned)dst16);
  dst16 = Machine::rotRight16(16, src16); std::printf(prt16, "ror16", 16, (unsigned)src16, (unsigned)dst16);

  dst32 = Machine::swap32(src32);         std::printf(prt32, "swap", 32, (unsigned)src32, (unsigned)dst32);
  dst32 = Machine::rotLeft32(0, src32);   std::printf(prt32, "rol32", 0, (unsigned)src32, (unsigned)dst32);
  dst32 = Machine::rotLeft32(4, src32);   std::printf(prt32, "rol32", 4, (unsigned)src32, (unsigned)dst32);
  dst32 = Machine::rotLeft32(8, src32);   std::printf(prt32, "rol32", 8, (unsigned)src32, (unsigned)dst32);
  dst32 = Machine::rotLeft32(12, src32);  std::printf(prt32, "rol32", 12, (unsigned)src32, (unsigned)dst32);
  dst32 = Machine::rotLeft32(16, src32);  std::printf(prt32, "rol32", 16, (unsigned)src32, (unsigned)dst32);
  dst32 = Machine::rotLeft32(20, src32);  std::printf(prt32, "rol32", 20, (unsigned)src32, (unsigned)dst32);
  dst32 = Machine::rotLeft32(24, src32);  std::printf(prt32, "rol32", 24, (unsigned)src32, (unsigned)dst32);
  dst32 = Machine::rotLeft32(28, src32);  std::printf(prt32, "rol32", 28, (unsigned)src32, (unsigned)dst32);
  dst32 = Machine::rotLeft32(32, src32);  std::printf(prt32, "rol32", 32, (unsigned)src32, (unsigned)dst32);
  dst32 = Machine::rotRight32(0, src32);  std::printf(prt32, "ror32", 0, (unsigned)src32, (unsigned)dst32);
  dst32 = Machine::rotRight32(4, src32);  std::printf(prt32, "rol32", 4, (unsigned)src32, (unsigned)dst32);
  dst32 = Machine::rotRight32(8, src32);  std::printf(prt32, "rol32", 8, (unsigned)src32, (unsigned)dst32);
  dst32 = Machine::rotRight32(12, src32); std::printf(prt32, "rol32", 12, (unsigned)src32, (unsigned)dst32);
  dst32 = Machine::rotRight32(16, src32); std::printf(prt32, "rol32", 16, (unsigned)src32, (unsigned)dst32);
  dst32 = Machine::rotRight32(20, src32); std::printf(prt32, "rol32", 20, (unsigned)src32, (unsigned)dst32);
  dst32 = Machine::rotRight32(24, src32); std::printf(prt32, "rol32", 24, (unsigned)src32, (unsigned)dst32);
  dst32 = Machine::rotRight32(28, src32); std::printf(prt32, "rol32", 28, (unsigned)src32, (unsigned)dst32);
  dst32 = Machine::rotRight32(32,src32);  std::printf(prt32, "rol32", 32, (unsigned)src32, (unsigned)dst32);

  std::printf("Testing Machine rotate routines with variable size\n");

  volatile int i;

  for (i=0; i<=8; i+=2) {
    dst8 = Machine::rotLeft8(i, src8);
    std::printf(prt8, "rol8", i, (unsigned)src8, (unsigned)dst8);
  }

  for (i=0; i<=8; i+=2) {
    dst8 = Machine::rotRight8(i, src8);
    std::printf(prt8, "ror8", i, (unsigned)src8, (unsigned)dst8);
  }

  for (i=0; i<=16; i+=4) {
    dst16 = Machine::rotLeft16(i, src16);
    std::printf(prt16, "rol16", i, (unsigned)src16, (unsigned)dst16);
  }

  for (i=0; i<=16; i+=4) {
    dst16 = Machine::rotRight16(i, src16);
    std::printf(prt16, "ror16", i, (unsigned)src16, (unsigned)dst16);
  }

  for (i=0; i<=32; i+=4) {
    dst32 = Machine::rotLeft32(i, src32);
    std::printf(prt16, "rol32", i, (unsigned)src32, (unsigned)dst32);
  }

  for (i=0; i<=32; i+=4) {
    dst32 = Machine::rotRight32(i, src32);
    std::printf(prt16, "ror32", i, (unsigned)src32, (unsigned)dst32);
  }

  std::printf("Testing Machine MSB\n");
  for (uint32 j=1; j<=32; j++) {
    src32 = ((1<<j)-1);
    dst32 = Machine::mostSigBit32(src32);
    std::printf("MSB: %08X -> %u\n", (unsigned)src32, (unsigned)dst32);
  }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


