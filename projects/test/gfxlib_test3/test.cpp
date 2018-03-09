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

#include <gfxlib/draw.hpp>

namespace OSNative {
  #include <proto/dos.h>
}

using namespace EXNGPrivate;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  GraphicsTestApp
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class GraphicsTestApp : public Application, public HostUI::Observer
{
  private:
    Display::Display* display;
    Draw2D*           draw;
    uint32            depth;
    sint16            width;
    sint16            height;
    bool              quit;
  public:
    // Runnable
    sint32  run();


    // HostUI::Observer
    void displayClosed(const HostUI::Dispatcher* d);
    void displayMoved(const HostUI::Dispatcher* d);
    void displayResized(const HostUI::Dispatcher* d);
    void displayMinimized(const HostUI::Dispatcher* d);
    void displayFocus(const HostUI::Dispatcher* d);
    void displayBlur(const HostUI::Dispatcher* d);


    // Mouse::Observer
    void buttonPressed(const Mouse::Dispatcher* d, Mouse::Button b);
    void buttonReleased(const Mouse::Dispatcher* d, Mouse::Button b);
    //void scroll(const Mouse::Dispatcher* d, sint16 dx, sint16 dy);
    //void move(const Mouse::Dispatcher* d, sint16 x, sint16 y, sint16 dx, sint16 dy, uint32);
    void drag(const Mouse::Dispatcher* d, sint16 x, sint16 y, sint16 dx, sint16 dy, uint32 keys);

    // Key::Observer
    void nonPrintablePressed(const Key::Dispatcher* d, Key::CtrlKey code);
    //void nonPrintableReleased(const Key::Dispatcher* d, Key::CtrlKey code);
    void printablePressed(const Key::Dispatcher* d, sint32 ch);
    //void printableReleased(const Key::Dispatcher* d, sint32 ch);

  public:
    GraphicsTestApp();
    ~GraphicsTestApp();
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



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

GraphicsTestApp::GraphicsTestApp() : HostUI::Observer(HostUI::ALL_EVENTS, Key::PRESS, Mouse::ALL_EVENTS), display(0), quit(false)
{
  depth   = getArgInteger("-depth", 32, ARG_CASE_SENSITIVE);
  width   = getArgInteger("-width", 640, ARG_CASE_SENSITIVE);
  height  = getArgInteger("-height", 480, ARG_CASE_SENSITIVE);

  if (getArgSwitch("-window", ARG_CASE_SENSITIVE)) {
    std::printf("Windowed mode specified\n");
    display = new Display::Windowed(
      HostUI::ALL_EVENTS,
      Key::PRESS,
      Mouse::BUTTONS|Mouse::DRAG,
      Display::Windowed::DW_CLOSEABLE|
      Display::Windowed::DW_DEFAULT
    );
  }
  else {
    std::printf("Fullscreen mode\n");
    display = new Display::Unbuffered(
      HostUI::ALL_EVENTS,
      Key::PRESS,
      Mouse::BUTTONS|Mouse::DRAG
    );
  }
  display->addHostUIObserver(this);
  draw = Draw2D::createInstance();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

GraphicsTestApp::~GraphicsTestApp()
{
  delete draw;
  delete display;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Runnable interface implementation
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 GraphicsTestApp::run()
{
  quit = 0;
  try {
    display->setTitle("GraphicsTestApp");
    display->open(width, height, depth, Display::WIDTH_AT_LEAST|Display::HEIGHT_AT_LEAST|Display::DEPTH_AT_LEAST);

    if (depth<=8) {

      sint32 paletteType = getArgInteger("-pal", 0, ARG_CASE_SENSITIVE);
      display->setIndexedPalette(Palette::getPresetPalette((Palette::Preset)paletteType));
    }
    if (Display::Surface* canvas = display->getDrawSurface()) {

      draw->setCanvas(canvas);
      draw->begin();
      {
        draw->fillRect(0, 0, canvas->getWidth(), canvas->getHeight(), 0xFF999999);

        uint32 c=0xFF000000;

        for (sint16 i=0; i<=canvas->getHeight(); i+=4) {
          draw->drawLine(0, i, canvas->getWidth(), canvas->getHeight()-i, c);
          c += 0x00030000;
        }

        draw->setClip(64, 64, canvas->getWidth()-64, canvas->getHeight()-64);
        draw->fillRect(0, 0, canvas->getWidth(), canvas->getHeight(), 0xFF00007F);

        c=0xFF000000;
        for (sint16 i=0; i<=canvas->getWidth(); i+=4) {
          draw->drawLine(i, 0, canvas->getWidth()-i, canvas->getHeight(), c);
          c += 0x00000300;
        }

      }
      draw->end();

      display->refresh();
    }

    while (!quit) {
      //std::printf("Waiting for events\n");
      if (display->awaitInputEvents()==Thread::WAKE_SYSBREAK) {
        quit = true;
      } else {
        //std::printf("Processing events\n");
        display->processInputEvents();
      }
      //display->refresh();
    }

  }
  catch (Error::Resource &e) {
    std::printf("Caught unexpected %s [%s]\n", e.getClass(), e.getName());
  }
  catch (Error::Runtime &e) {
    std::printf("Caught unexpected %s\n", e.getClass());
  }

  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  HostUI::Observer interface implementation
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void GraphicsTestApp::displayClosed(const HostUI::Dispatcher* d)
{
  std::printf("HostUI::Observer::displayClosed(%p)\n", d);
}

void GraphicsTestApp::displayMoved(const HostUI::Dispatcher* d)
{
  std::printf("HostUI::Observer::displayMoved(%p)\n", d);
}

void GraphicsTestApp::displayResized(const HostUI::Dispatcher* d)
{
  std::printf("HostUI::Observer::displayResized(%p)\n", d);
}

void GraphicsTestApp::displayMinimized(const HostUI::Dispatcher* d)
{
  std::printf("HostUI::Observer::displayMinimized(%p)\n", d);
}

void GraphicsTestApp::displayFocus(const HostUI::Dispatcher* d)
{
  std::printf("HostUI::Observer::displayFocus(%p)\n", d);
}

void GraphicsTestApp::displayBlur(const HostUI::Dispatcher* d)
{
  std::printf("HostUI::Observer::displayBlur(%p)\n", d);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Mouse::Observer interface implementation
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void GraphicsTestApp::buttonPressed(const Mouse::Dispatcher* d, Mouse::Button b)
{
  std::printf(
    "Mouse::Observer::buttonPressed(%p, 0x%08X)\n",
    d,
    (unsigned)b
  );
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GraphicsTestApp::buttonReleased(const Mouse::Dispatcher* d, Mouse::Button b)
{
  std::printf(
    "Mouse::Observer::buttonReleased(%p, 0x%08X)\n",
    d,
    (unsigned)b
  );
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// void GraphicsTestApp::scroll(const Mouse::Dispatcher* d, sint16 dx, sint16 dy)
// {
//   std::printf("Mouse::Observer::scroll()\n");
// }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// void GraphicsTestApp::move(const Mouse::Dispatcher* d, sint16 x, sint16 y, sint16 dx, sint16 dy, uint32)
// {
//   std::printf(
//     "Mouse::Observer::move(%p, %" XPF_S16 ", %" XPF_S16 ", %" XPF_S16", %" XPF_S16 ")\n",
//     d,
//     x,
//     y,
//     dx,
//     dy
//   );
//
// }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GraphicsTestApp::drag(const Mouse::Dispatcher* d, sint16 x, sint16 y, sint16 dx, sint16 dy, uint32 keys)
{
  std::printf(
    "Mouse::Observer::drag(%p, %" XPF_S16 ", %" XPF_S16 ", %" XPF_S16", %" XPF_S16 ", 0x%08X)\n",
    d,
    x,
    y,
    dx,
    dy,
    (unsigned)keys
  );
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Key::Observer interface implementation
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GraphicsTestApp::nonPrintablePressed(const Key::Dispatcher* d, Key::CtrlKey code)
{
  switch(code) {
    case Key::F1:
      display->enableMouseEvents(Mouse::Dispatcher::MOVE_LIMIT_LEFT);
      break;
    case Key::F2:
      display->disableMouseEvents(Mouse::Dispatcher::MOVE_LIMIT_LEFT);
      break;
    case Key::F3:
      display->enableMouseEvents(Mouse::Dispatcher::MOVE_LIMIT_RIGHT);
      break;
    case Key::F4:
      display->disableMouseEvents(Mouse::Dispatcher::MOVE_LIMIT_RIGHT);
      break;
    case Key::F5:
      display->enableMouseEvents(Mouse::Dispatcher::MOVE_LIMIT_TOP);
      break;
    case Key::F6:
      display->disableMouseEvents(Mouse::Dispatcher::MOVE_LIMIT_TOP);
      break;
    case Key::F7:
      display->enableMouseEvents(Mouse::Dispatcher::MOVE_LIMIT_BOTTOM);
      break;
    case Key::F8:
      display->disableMouseEvents(Mouse::Dispatcher::MOVE_LIMIT_BOTTOM);
      break;
    case Key::F9:
      std::printf(
        "Mouse events mask = 0x%08X\n",
        (unsigned)display->getEnabledMouseEvents()
      );
      break;
    case Key::F10:
      if (const Display::Properties* p = display->getProperties()) {
        std::printf(
          "Got Host Display (before opening)\n"
          "Display Mode : %s\n"
          "Resolution   : %d x %d x %d\n"
          "Timing:      : %.2fkHz / %.2f Hz\n\n",
          p->getName(),
          (int)p->getWidth(),
          (int)p->getHeight(),
          (int)p->getDepth(),
          p->getHorizontalRefreshRatekHz(),
          p->getVerticalRefreshRateHz()
        );
      }
      break;
    default:
      std::printf("Key::Observer::nonPrintablePressed(%p, 0x%02X)\n", d, (unsigned)code);
      break;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// void GraphicsTestApp::nonPrintableReleased(const Key::Dispatcher* d, Key::CtrlKey code)
// {
//   std::printf("Key::Observer::nonPrintableReleased(%p, 0x%02X)\n", d, (unsigned)code);
// }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GraphicsTestApp::printablePressed(const Key::Dispatcher* d, sint32 ch)
{
  std::printf("Key::Observer::printablePressed(%p, '%c')\n", d, (int)ch);




  if (ch=='q' || ch=='Q') {
    quit = true;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// void GraphicsTestApp::printableReleased(const Key::Dispatcher* d, sint32 ch)
// {
//   std::printf("Key::Observer::printableReleased(%p, '%c')\n", d, (int)ch);
// }


