///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Test Application
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <xbase.hpp>
#include <systemlib/memory.hpp>
#include <systemlib/time.hpp>
#include <gfxlib/gfx.hpp>
#include <gfxlib/pixelmap.hpp>
#include <iolib/streamio.hpp>
#include <cstdlib>
#include <cstdio>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  GraphicsTestApp
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class TestApp : public Application
{
  private:
    static const char* formatNames[Pixel::CUSTOM_FB+1];
    ImageBuffer* ib;

    void    describePixelLayout(const Pixel::Layout* p);

  public:
    // Runnable
    sint32  run();


  public:
    TestApp();
    ~TestApp();
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const char* TestApp::formatNames[] = {
  "LUT_8",
  "RGB_555B",  // 15-bit, RGB    5:5:5, big endian
  "BGR_555B",  // 15-bit, BGR    5:5:5, big endian
  "RGB_555L",  // 15-bit, RGB    5:5:5, little endian
  "BGR_555L",  // 15-bit, BGR    5:5:5, little endian
  "RGB_565B",  // 16-bit, RGB    5:6:5, big endian
  "BGR_565B",  // 16-bit, BGR    5:6:5, big endian
  "RGB_565L",  // 16-bit, RGB    5:6:5, little endian
  "BGR_566L",  // 16-bit, BGR    5:6:5, little endian
  "RGB_888",  // 24-bit, RGB    8:8:8, byte packed
  "BGR_888", // 24-bit, BGR    8:8:8, byte packed
  "ARGB_8888",
  "ABGR_8888",
  "BGRA_8888",
  "RGBA_8888",
  "CUSTOM_FB", // Other format, requires Layout
};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Application* Application::createInstance()
{
  Graphics::init();
  return new TestApp();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Application::destroyInstance(Application* app)
{
  delete app;
  Graphics::done();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TestApp::TestApp() : ib(0)
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TestApp::~TestApp()
{
  delete ib;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Runnable interface implementation
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 TestApp::run()
{
  const char* imageFile = getArgString("-img", 0, ARG_MANDATORY|ARG_CASE_SENSITIVE);
  ib = ImageLoader::loadImage(imageFile, false);

  std::printf(
    "ImageBuffer instance located at %p width %" XPF_S16 ", height: %" XPF_S16 "\n",
    ib,
    ib->getWidth(),
    ib->getHeight()
  );
  describePixelLayout(ib->getDescriptor());

//  uint8* data = (uint8*)ib->lockData();
//   for (sint16 i=0; i<ib->getWidth(); i++) {
//     std::printf("%02X ", data[i]);
//   }
//   ib->unlockData();

  std::printf("Writing PPM\n");
  IO::Stream::Out outputStream;

  outputStream.open("ram:test.ppm", IO::Stream::MODE_WRITE);
  outputStream.writeText(
    "P6\n%" XPF_S16 "\n%" XPF_S16 "\n255\n",
    ib->getWidth(),
    ib->getHeight()
  );

  uint8* data = (uint8*)ib->lockData();

  size_t accessSize = ib->getDescriptor()->getAccessSize();
  if (accessSize==1) {
    uint8*  d = data;
    uint32* c = (uint32*)ib->getPalette()->getTable();
    sint32  n = ib->getWidth()*ib->getHeight();
    while (n--) {
      outputStream.writeBytes(
        ((uint8*)(&c[*d++]))+1,
        3
      );
    }
  }
  else if (accessSize==3) {
    outputStream.writeBytes(
      data,
      ib->getWidth()*ib->getHeight()*3
    );
  }
  else if (accessSize==4) {
    uint8*  d = data+1;
    sint32  n = ib->getWidth()*ib->getHeight();

    while (n--) {
      outputStream.writeBytes(
        d,
        3
      );
      d+=4;
    }

  }
  ib->unlockData();

  outputStream.close();


  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void TestApp::describePixelLayout(const Pixel::Layout* pix)
{
  static const char* wordTypes[] = {
    "Unknown",
    "Bit",
    "Unsigned Bitfield",
    "Signed Bitfield",
    "Unsigned Byte",
    "Signed Byte",
    "Unsigned 16-bit Word",
    "Signed 16-bit Word",
    "Float 16-bit Word (half precision)",
    "Unsigned 32-bit Word",
    "Signed 32-bit Word",
    "Float 32-bit Word",
    "Unsigned 64-bit Word",
    "Signed 64-bit Word",
    "Float 64-bit Word (double precision)",
    "Unsigned 128-bit Word",
    "Signed 128-bit Word",
    "Float 128-bit Word (quad precision)"
  };

  static const char* componentNames[] = {
    "Red",
    "Green",
    "Blue",
    "Alpha",
    "Cyan",
    "Yellow",
    "Magenta",
    "Black",
    "Hue",
    "Saturation",
    "Value",
    "Luminance",
    "Custom_0",
    "Custom_1",
    "Custom_2",
    "Custom_3"
  };

  std::printf(
    "Pixel Layout\n"
    "Total size     :  %u bytes\n"
    "Access Type    :  %s%s%s\n"
    "Component Type :  %s\n"
    "Num Components :  %u\n",
    (unsigned)pix->getAccessSize(),
    wordTypes[pix->getAccessType()],
    pix->getFlags(Pixel::Layout::IS_FLOAT_FORMAT) ? " float" : "",
    pix->getFlags(Pixel::Layout::IS_BYTESWAPPED) ? " byteswapped" : "",
    wordTypes[pix->getComponentAccessType()],
    (unsigned)pix->getNumComponents()
  );

  for (uint32 i=0; i<pix->getNumComponents(); i++) {
    std::printf(
      "[%12s] : %2u : %2u Range:0-%u [%08X]\n",
      componentNames[pix->getComponentType(i)],
      (unsigned)pix->getComponentWidth(i),
      (unsigned)pix->getComponentPosition(i),
      (unsigned)pix->getComponentMax(i),
      (unsigned)pix->getComponentMask(i)
    );
  }

}

