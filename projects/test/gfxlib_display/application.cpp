///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Test Application
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <xbase.hpp>
#include <gfxlib/gfx.hpp>
#include <gfxlib/display_windowed.hpp>
#include <gfxlib/display_fullscreen.hpp>
#include <cstdio>

namespace OSNative {
  #include <proto/dos.h>
}

using namespace EXNGPrivate;
using HID::Mouse;
using HID::Key;

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
  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GraphicsTestApp::testFullscreenUnbuffered()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GraphicsTestApp::testFullscreenBuffered()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GraphicsTestApp::testWindowed()
{
  Display::Windowed window (
    HostUI::ALL_EVENTS,
    Key::PRESS,
    Mouse::BUTTONS|Mouse::DRAG,
    Display::Windowed::DW_CLOSEABLE|
    Display::Windowed::DW_DEFAULT
  );

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

  //window.setFlags(OSWindowed::WF_CENTRE_X|OSWindowed::WF_CENTRE_Y|OSWindowed::WF_MOVEABLE);

  try {
    window.setTitle("Display::Windowed test instance - drag me a bit");
    window.openWindow(0, 0, 640, 480);
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