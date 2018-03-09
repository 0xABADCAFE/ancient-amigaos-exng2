///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         gfxlib/display.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Display classes
//  Comment(s):
//  Library:      System
//  Created:      2006-10-08
//  Updated:      2006-10-08
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _EXNG2_GFXLIB_DISPLAY_NATIVE_HPP_
# define _EXNG2_GFXLIB_DISPLAY_NATIVE_HPP_

namespace OSNative {
  extern "C" {
#   include <proto/intuition.h>
#   include <proto/graphics.h>
#   include <proto/cybergraphics.h>
  }
}

namespace EXNGPrivate {

  class DisplayDatabase;

  class OSDisplay : virtual public HostUI::Dispatcher, protected SurfaceProvider {
    friend class DisplayDatabase;
    public:
      enum {
        MAX_TITLE_LENGTH = 255
      };

      virtual ~OSDisplay();

    protected:
      struct AmigaPalette {
        uint32 info;
        struct Entry {
          uint32 red, green, blue;
        } data[256];
        uint32 terminator;
/*
        void setGrey();
        void setRGB666();
        void setRGB676();
        void setRGB775();
        void setRGB884();
*/
        void setCustom(const Palette* p);

        AmigaPalette() : info(256UL<<16), terminator(0) {}
      } __attribute__(( aligned(4), __packed__ ));

      static OSNative::Screen*  lockHostDisplay();
      static void               unlockHostDisplay(OSNative::Screen*);
      Display::Surface*         getDrawSurface()
      {
        return drawSurface;
      }
      void              setPalette(const Palette* pal);

      void              waitSync();

      bool              openFullscreen(uint32 id);
      bool              openWindowed(sint16 x, sint16 y, sint16 w, sint16 h, uint32 f);

      void              closeFullscreen();
      void              closeWindowed();

      void              setDisplayTitle(const char* title, bool fullScreen);
      bool              isAllocated() { return (screen!=0) && (window!=0); }

      // Input handling resources
      Thread::WakeEvent awaitInputEvents();
      //bool            inputQueued();
      void              dispatchQueuedInput(const GfxArea* area);
      void              discardEventQueue();
      // inputdevices gubbins
      void              applyMouseEventFilter(uint32 mask);
      void              applyKeyEventFilter(uint32 mask);
      void              applyDisplayEventFilter(uint32 mask);
      void              applyEventFilters(uint32 disp, uint32 key, uint32 mouse);

      OSDisplay();

      Display::Surface* drawSurface;
      OSNative::Screen* screen;
      OSNative::Window* window;
      const Palette*    palette;
      AmigaPalette*     viewPalette;

      char name[MAX_TITLE_LENGTH+1];

    private:
      static  void    initDispatcher();
      static  void    finalizeDispatcher();
      static  uint32  hostLockCount;

      LOGGING_DEFINE_CLASSNAME
  };

  ////////////////////////////////////////////////////////////////////////////////

  class OSWindowed : public OSDisplay {
    private:
      DisplayMode         mode;
      uint32              flags;
      OSNative::RastPort  rastPort;

    protected:
      enum {
        WF_PUBLICMASK     = 0x0000FFFF,
        WF_PRIVATEMASK    = 0xFFFF0000,
        WF_CENTRE_X       = 0x00000001,
        WF_CENTRE_Y       = 0x00000002,
        WF_CLOSEABLE      = 0x00000004,
        WF_MOVEABLE       = 0x00000008,
        WF_RESIZEABLE     = 0x00000010,
        WF_BORDERLESS     = 0x00000020,
        WF_HOST_FOUND     = 0x00010000,
        WF_NOSYSREFRESH   = 0x00020000,
        WF_REOPENED       = 0x00040000,
      };

      void      setFlags(uint32 f)  { flags |= f; }
      void      clrFlags(uint32 f)  { flags &= ~f; }
      uint32    getFlags() const    { return flags; }

      bool              openDisplay(sint16 x, sint16 y, sint16 w, sint16 h);
      bool              reopenDisplay();
      void              closeDisplay();
      void              refreshAll() {
        if (window) {
          OSNative::ClipBlit(&rastPort, 0, 0, window->RPort, window->BorderLeft, window->BorderTop,
                             mode.getWidth(), mode.getHeight(), 0xC0);
        }
      }
      void              refreshRegion(sint16 x, sint16 y, sint16 w, sint16 h);
      void              bindSurface();

      // window position/geometry
      sint16    getWinLeft()      const { return window->LeftEdge; }
      sint16    getWinTop()       const { return window->TopEdge; }
      sint16    getWinWidth()     const { return window->Width; }
      sint16    getWinHeight()    const { return window->Height; }

      // Decorator dimensions
      sint16    getBorderLeft()   const { return window->BorderLeft; }
      sint16    getBorderRight()  const { return window->BorderRight; }
      sint16    getBorderTop()    const { return window->BorderTop; }
      sint16    getBorderBottom() const { return window->BorderBottom; }

      // Viewport dimensions
      sint16    getViewLeft()   const { return window->LeftEdge + window->BorderLeft; }
      sint16    getViewTop()    const { return window->TopEdge + window->BorderTop; }
      sint16    getViewWidth()  const { return window->Width - window->BorderLeft - window->BorderRight; }
      sint16    getViewHeight() const { return window->Height - window->BorderTop - window->BorderBottom; }

      const Display::Properties* getDisplayProperties();

    public:
      OSWindowed(uint32 f=WF_MOVEABLE);

    public:
      ~OSWindowed();

    private:
      LOGGING_DEFINE_CLASSNAME
  };

  ////////////////////////////////////////////////////////////////////////////////

  class OSScreen : public OSDisplay {
    private:
      const Display::Properties*  properties;

    protected:
      bool                openDisplay(const Display::Properties* p);
      bool                reopenDisplay();
      void                closeDisplay();
      void                bindSurface();

      const Display::Properties* getDisplayProperties() { return properties; }

      OSScreen();

    public:
      ~OSScreen();

    private:
      LOGGING_DEFINE_CLASSNAME
  };

  ////////////////////////////////////////////////////////////////////////////////

  class OSScreenBuffered : public OSScreen {
    private:
      OSNative::MsgPort*        vidSafePort;  // safe to use bitmap
      OSNative::MsgPort*        vidDispPort;  // frame has been displayed
      OSNative::ScreenBuffer*   buffer[3];    // up to triple buffering
      sint16                    drawBuffer;
      uint16                    flags;

      enum {
        SBF_TRIPLE_BUFFER = 0x0001,
        SBF_CLONE_BUFFER  = 0x0002,
        SBF_VID_SAFE      = 0x0004,
        SBF_VID_DISP      = 0x0008,
        SBF_PORT_ERROR    = 0x8000
      };

      bool      allocatePorts();
      void      freePorts();
      bool      allocateBuffers();
      void      freeBuffers();

    protected:
      void              bindSurface();
      bool              setTripleBuffered(bool state);
      bool              getTripleBuffered();

      bool              openDisplay(const Display::Properties* p);
      bool              reopenDisplay();
      void              closeDisplay();
      void              flipBuffers();

      OSScreenBuffered(bool triple);

    public:
      ~OSScreenBuffered();

    private:
      LOGGING_DEFINE_CLASSNAME
  };


  inline bool OSScreenBuffered::getTripleBuffered()
  {
    return flags & SBF_TRIPLE_BUFFER;
  }

};


#endif
