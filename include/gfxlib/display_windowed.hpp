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

#ifndef _EXNG2_GFXLIB_DISPLAY_WINDOWED_HPP_
# define _EXNG2_GFXLIB_DISPLAY_WINDOWED_HPP_

#include <gfxlib/display.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Display::Windowed
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Display::Windowed : public Display, private EXNGPrivate::OSWindowed {
  DEFINE_MIN_RTTI

  public:
    const Properties* getProperties()             { return getDisplayProperties();  }
    void              setTitle(const char* title) { setDisplayTitle(title, false);  }
    bool              isOpen()                    { return isAllocated();           }
    void              open(const Display::Properties* displayProperties);
    void              open(sint16 w, sint16 h, uint32 d, uint32 opts);
    void              close();
    void              reopen();
    void              refresh();
    void              synchronize();
    void              setIndexedPalette(const Palette* pal) { /* do nothing */  }
    Surface*          getDrawSurface()            { return OSWindowed::getDrawSurface(); }

    Thread::WakeEvent awaitInputEvents()          { return OSWindowed::awaitInputEvents(); }
    void              processInputEvents()        { dispatchQueuedInput(getDisplayProperties()); }

    void              openWindow(sint16 x, sint16 y, sint16 w, sint16 y); // renamed so as not to be confused with virtual open() method

    // windowed specifics
    enum {
      DW_CENTRED_HORIZONTAL = 0x00000001,
      DW_CENTRED_VERTICAL   = 0x00000002,
      DW_CENTRED            = 0x00000003,
      DW_CLOSEABLE          = 0x00000004,
      DW_MOVEABLE           = 0x00000008,
      DW_RESIZEABLE         = 0x00000010,
      DW_BORDERLESS         = 0x00000020,
      DW_DEFAULT            = DW_CENTRED|DW_MOVEABLE
    };

    uint32            getWindowAttributes();
    uint32            setWindowAttributes(uint32 a);

    void              setScreenPosition(sint16 x, sint16 y);

    const GfxRect&    getViewPortRect();
    const GfxRect&    getFrameRect();

    void              refresh(sint16 left, sint16 top, sint16 width, sint16 height);
    void              refresh(const GfxRect& rectangle)
    {
      refresh(
        rectangle.getLeft(),
        rectangle.getTop(),
        rectangle.getWidth(),
        rectangle.getHeight()
      );
    }

    Windowed(uint32 displayMask, uint32 keyMask, uint32 mouseMask, uint32 attr=DW_DEFAULT, sint16 x=0, sint16 y=0);
    ~Windowed();

  private:
    GfxRectMutable    winFrame;
    GfxRectMutable    winViewPort;
    sint16            xPos;
    sint16            yPos;
    LOGGING_DEFINE_CLASSNAME
};



#endif