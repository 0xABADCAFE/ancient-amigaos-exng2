///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Test Application
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <xbase.hpp>
#include <gfxlib/gfx.hpp>
#include <gfxlib/display.hpp>
#include <cstdio>

namespace OSNative {
  #include <proto/dos.h>
}

using namespace EXNGPrivate;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class GraphicsTestApp : public Application
{
  private:
    static const char* formatNames[Pixel::CUSTOM_FB+1];

    void    describePixelLayout(const Pixel::Layout* p);

    void    printDisplayProperties();
    void    testFullscreenUnbuffered();
    void    testFullscreenBuffered();
    void    testWindowed();

    void    printGfxRect(const GfxRect& rect);

  public:
    sint32  run();

  public:
    GraphicsTestApp();
    ~GraphicsTestApp();
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const char* GraphicsTestApp::formatNames[] = {
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
  return new GraphicsTestApp();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Application::destroyInstance(Application* app)
{
  delete app;
  Graphics::done();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

GraphicsTestApp::GraphicsTestApp()
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

GraphicsTestApp::~GraphicsTestApp()
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 GraphicsTestApp::run()
{
  testWindowed();
  testFullscreenUnbuffered();
  testFullscreenBuffered();
  //printDisplayProperties();
  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GraphicsTestApp::printDisplayProperties()
{
  std::printf("Listing available display modes\n");
  const Display::Properties* p = Display::Properties::getWindowedMode();
  if (p) {
    std::printf(
      "Windowed mode available:\n"
      "Max Size       :  %d x %d\n"
      "Depth          :  %d [%s]\n"
      "Timing:        :  %.2fkHz / %.2f Hz\n",
      (int)p->getWidth(),
      (int)p->getHeight(),
      (int)p->getDepth(),
      formatNames[p->getFormat()],
      p->getHorizontalRefreshRatekHz(),
      p->getVerticalRefreshRateHz()
    );
    describePixelLayout(Pixel::getDescriptor(p->getFormat()));
    std::printf("\n------------------------\n");
  }
  else {
    std::puts("Windowed mode not available\n");
  }

  RefList<Display::Properties>::ConstIterator iterator = Display::Properties::getAvailableModes();
  for (p = iterator.first(); p; p = iterator.next()) {
    std::printf(
      "Display Mode   :  %s\n"
      "Resolution     :  %d x %d x %d [%s]\n"
      "Timing         :  %.2fkHz / %.2f Hz\n",
      p->getName(),
      (int)p->getWidth(),
      (int)p->getHeight(),
      (int)p->getDepth(),
      formatNames[p->getFormat()],
      p->getHorizontalRefreshRatekHz(),
      p->getVerticalRefreshRateHz()
    );
    describePixelLayout(Pixel::getDescriptor(p->getFormat()));
    std::printf("\n------------------------\n");
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GraphicsTestApp::testFullscreenUnbuffered()
{
  std::printf("Testing Display::Unbuffered\n");
  OSNative::Delay(25);

  Display::Unbuffered display;
  const Display::Properties* p = Display::findMode(640, 480, 32, 0);
  if (p) {
    try {
      display.open(p);

      Display::Surface* drawSurface = display.getDrawSurface();
      if (drawSurface) {
        for (uint32 i=0;i<0x00FFFFFF; i+=0x00010101) {
          drawSurface->clear(i);
          display.refresh();
          display.synchronize();
        }
      }

    }
    catch (Error::Runtime &e) {
      std::printf("Caught unexpected %s\n", e.getClass());
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GraphicsTestApp::testFullscreenBuffered()
{
  std::printf("Testing Display::FlibBuffered\n");
  OSNative::Delay(25);

  Display::FlipBuffered display(Display::FlipBuffered::DFB_DOUBLE_BUFFER);

  const Display::Properties* p = Display::findMode(640, 480, 32, 0);
  if (p) {
    try {
      display.open(p);

      Display::Surface* drawSurface = display.getDrawSurface();
      if (drawSurface) {
        for (uint32 i=0;i<0x00FFFFFF; i+=0x00010101) {
          drawSurface->clear(i);
          display.refresh();
          display.synchronize();
        }
      }

    }
    catch (Error::Runtime &e) {
      std::printf("Caught unexpected %s\n", e.getClass());
    }
  }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GraphicsTestApp::testWindowed()
{
  std::printf("Testing Display::Windowed\n");
  OSNative::Delay(25);

  Display::Windowed window;

  const Display::Properties* p = window.getProperties();
  if (p) {
    std::printf(
      "Got Host Display (before opening)\n"
      "Display Mode : %s\n"
      "Resolution   : %d x %d x %d [%s]\n"
      "Timing:      : %.2fkHz / %.2f Hz\n\n",
      p->getName(),
      (int)p->getWidth(),
      (int)p->getHeight(),
      (int)p->getDepth(),
      formatNames[p->getFormat()],
      p->getHorizontalRefreshRatekHz(),
      p->getVerticalRefreshRateHz()
    );
  }

  try {
    window.setTitle("Display::Windowed test instance - drag me a bit");
    window.open(0, 0, 640, 480);

    Display::Surface* drawSurface = window.getDrawSurface();
    if (drawSurface) {
      for (uint32 i=0;i<0x00FFFFFF; i+=0x00010101) {
        drawSurface->clear(i);
        window.refresh();
        window.synchronize();
      }
    }

    p = window.getProperties();
    if (p) {
      std::printf(
        "Got Host Display (after opening)\n"
        "Display Mode : %s\n"
        "Resolution   : %" XPF_S16 " x %" XPF_S16 " x %d [%s]\n"
        "Timing:      : %.2fkHz / %.2f Hz\n",
        p->getName(),
        p->getWidth(),
        p->getHeight(),
        (int)p->getDepth(),
        formatNames[p->getFormat()],
        p->getHorizontalRefreshRatekHz(),
        p->getVerticalRefreshRateHz()
      );



      std::puts("Window Geometry (in screen space)");
      printGfxRect(window.getFrameRect());
      std::puts("ViewPort Geometry (in screen space)");
      printGfxRect(window.getViewPortRect());

      OSNative::Delay(300);

      std::puts("Window Geometry (in screen space)");
      printGfxRect(window.getFrameRect());
      std::puts("ViewPort Geometry (in screen space)");
      printGfxRect(window.getViewPortRect());

    }


  }
  catch (Error::Runtime &e) {
    std::printf("Caught unexpected %s\n", e.getClass());
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GraphicsTestApp::printGfxRect(const GfxRect& rect)
{
  std::printf(
    "X:%" XPF_S16 ", Y:%" XPF_S16 "\n"
    "W:%" XPF_S16 ", H:%" XPF_S16 "\n",
    rect.getX(),
    rect.getY(),
    rect.getWidth(),
    rect.getHeight()
  );
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
sint32 GraphicsTestApp::run()
{
  std::puts("\nGraphics Test");
  printDisplayProperties();
  const Display::Properties* p = Display::findMode(640, 480, Pixel::BPP16, 0);
  if (p) {
    std::printf(
      "Display Mode : %s\n"
      "Resolution   : %d x %d x %d [%s]\n"
      "Timing:      : %.2fkHz / %.2f Hz\n\n",
      p->getName(),
      (int)p->getWidth(),
      (int)p->getHeight(),
      (int)p->getDepth(),
      formatNames[p->getFormat()],
      p->getHorizontalRefreshRatekHz(),
      p->getVerticalRefreshRateHz()
    );



    Display::FlipBuffered* screen = new Display::FlipBuffered(Display::FlipBuffered::DFB_DOUBLE_BUFFER);
    screen->setTitle("Test Display");

    screen->open(p);
    OSNative::Delay(200);
    for (int i=0; i<10; i++) {
      screen->refresh();
      OSNative::Delay(25);
    }
    OSNative::Delay(100);
    screen->close();
    OSNative::Delay(100);
    screen->reopen();
    OSNative::Delay(100);
    for (int i=0; i<10; i++) {
      screen->refresh();
      OSNative::Delay(25);
    }
    delete screen;
  }
  return 0;
}
*/

void GraphicsTestApp::describePixelLayout(const Pixel::Layout* pix)
{
  static const char* wordTypes[] = {
    "Unknown",
    "Bit",
    "Bitfield",
    "Byte",
    "Word16",
    "Word32",
    "Word64",
    "Word128"
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