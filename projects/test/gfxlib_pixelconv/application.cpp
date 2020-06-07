///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Test Application
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <xbase.hpp>
#include <systemlib/memory.hpp>
#include <systemlib/time.hpp>
#include <gfxlib/gfx.hpp>
#include <gfxlib/pixel.hpp>

#include <cstdlib>
#include <cstdio>

#include <private/gfxlib/pixel_15bit.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  GraphicsTestApp
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class PixConvTestApp : public Application
{
  private:
    enum {
      TEST_W = 16,
      TEST_H = 16
    };

    void* data1;
    void* data2;

    void printBuffer8(void* buffer, int x, int y, int w, int h);
    void printBuffer16(void* buffer, int x, int y, int w, int h);
    void printBuffer24(void* buffer, int x, int y, int w, int h);
    void printBuffer32(void* buffer, int x, int y, int w, int h);

  public:
    // Runnable
    sint32  run();

  public:
    PixConvTestApp();
    ~PixConvTestApp();
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Application* Application::createInstance()
{
  Graphics::init();
  return new PixConvTestApp();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Application::destroyInstance(Application* app)
{
  delete app;
  Graphics::done();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

PixConvTestApp::PixConvTestApp() : data1(0), data2(0)
{
  data1 = Mem::alloc(TEST_W*TEST_H*sizeof(uint32));
  data2 = Mem::alloc(TEST_W*TEST_H*sizeof(uint32));
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

PixConvTestApp::~PixConvTestApp()
{
  Mem::free(data2);
  Mem::free(data1);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Runnable interface implementation
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 PixConvTestApp::run()
{
  Mem::set32(data1, 0x001177FF, TEST_W*TEST_H);
  Mem::set32(data2, 0xAABBCCDD, TEST_W*TEST_H);

  printf("Before\n");
  printBuffer16(data1, 0, 0, TEST_W, TEST_H);
  convSwap16(data1, data2, 8, 8, TEST_W-8, TEST_W-8);
  printf("\nAfter\n");
  printBuffer16(data1, 0, 0, TEST_W, TEST_H);

  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PixConvTestApp::printBuffer8(void* buffer, int x, int y, int w, int h)
{
  uint8* p = (uint8*) buffer;
  p = p + (y*TEST_W)+x;
  y = TEST_W-w;
  while (h--) {
    x = w;
    while (x--) {
      printf("%02X ", (unsigned) *p++);
    }
    printf("\n");
    p += y;
  }
}

void PixConvTestApp::printBuffer16(void* buffer, int x, int y, int w, int h)
{
  uint16* p = (uint16*) buffer;
  p = p + (y*TEST_W)+x;
  y = TEST_W-w;
  while (h--) {
    x = w;
    while (x--) {
      printf("%04X ", (unsigned) *p++);
    }
    printf("\n");
    p += y;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PixConvTestApp::printBuffer24(void* buffer, int x, int y, int w, int h)
{
  uint8* p = (uint8*) buffer;
  p = p + ((y*TEST_W)+x)*3;
  y = (TEST_W-w)*3;
  while (h--) {
    x = w;
    while (x--) {
      printf("%02X%02X%02X ", (unsigned) p[0], (unsigned) p[1], (unsigned) p[2]);
      p+=3;
    }
    printf("\n");
    p += y;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void PixConvTestApp::printBuffer32(void* buffer, int x, int y, int w, int h)
{
  uint32* p = (uint32*) buffer;
  p = p + (y*TEST_W)+x;
  y = TEST_W-w;
  while (h--) {
    x = w;
    while (x--) {
      printf("%08X ", (unsigned) *p++);
    }
    printf("\n");
    p += y;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
