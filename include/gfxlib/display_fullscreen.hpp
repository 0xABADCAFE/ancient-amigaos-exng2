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

#ifndef _EXNG2_GFXLIB_DISPLAY_FULLSCREEN_HPP_
# define _EXNG2_GFXLIB_DISPLAY_FULLSCREEN_HPP_

#include <gfxlib/display.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Display::Unbuffered
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class Display::Unbuffered : public Display, private EXNGPrivate::OSScreen {
  DEFINE_MIN_RTTI

  public:
    const Properties* getProperties()               { return getDisplayProperties();  }
    void              setTitle(const char* title)   { setDisplayTitle(title, true);   }
    bool              isOpen()                      { return isAllocated();           }
    void              open(const Display::Properties* displayProperties);
    void              close();
    void              reopen();
    void              refresh();
    void              synchronize();

    void              setIndexedPalette(const Palette* pal) { setPalette(pal); }

    Surface*          getDrawSurface()              { return OSScreen::getDrawSurface();            }

    Thread::WakeEvent awaitInputEvents()            { return OSScreen::awaitInputEvents();          }
    void              processInputEvents()          { dispatchQueuedInput(getDisplayProperties());  }

    Unbuffered(uint32 displayMask, uint32 keyMask, uint32 mouseMask);
    ~Unbuffered();

  private:
    LOGGING_DEFINE_CLASSNAME
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Display::FlipBuffered : public Display, private EXNGPrivate::OSScreenBuffered {
  DEFINE_MIN_RTTI

  public:
    const Properties* getProperties()               { return getDisplayProperties();  }
    void              setTitle(const char* title)   { setDisplayTitle(title, true);   }
    bool              isOpen()                      { return isAllocated();           }
    void              open(const Display::Properties* displayProperties);
    void              close();
    void              reopen();
    void              refresh();
    void              synchronize();
    void              setIndexedPalette(const Palette* pal) { setPalette(pal); }
    Surface*          getDrawSurface()              { return OSScreenBuffered::getDrawSurface();    }

    Thread::WakeEvent awaitInputEvents()            { return OSScreenBuffered::awaitInputEvents();  }
    void              processInputEvents()          { dispatchQueuedInput(getDisplayProperties());  }

    // flipbuffered specifics
    typedef enum {
      DFB_DOUBLE_BUFFER = 2,
      DFB_TRIPLE_BUFFER = 3
    } BufferType;

    FlipBuffered(uint32 displayMask, uint32 keyMask, uint32 mouseMask, BufferType bt);
    ~FlipBuffered();

  private:
    LOGGING_DEFINE_CLASSNAME
};



#endif