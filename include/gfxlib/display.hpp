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

#ifndef _EXNG2_GFXLIB_DISPLAY_HPP_
# define _EXNG2_GFXLIB_DISPLAY_HPP_

# include <iolib/inputdevices.hpp>
# include <gfxlib/gfx.hpp>
# include <gfxlib/pixel.hpp>
# include <gfxlib/palette.hpp>
# include <gfxlib/rects.hpp>

# include <utilitylib/referencelist.hpp>
# include <systemlib/thread.hpp>

# include <gfxlib/display_hostui.hpp>

namespace EXNGPrivate {
  class DisplayMode;
  class DisplayDatabase;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Display
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Display : virtual public HostUI::Dispatcher {
  DEFINE_MIN_RTTI
  LOGGING_DEFINE_CLASSNAME
  public:

    class Surface;
    class Properties;

    // fundamental display types
    class Unbuffered;
    class FlipBuffered;
    class Windowed;

    enum {
      WIDTH_MATCHES       = 0x00000000,
      WIDTH_AT_LEAST      = 0x00000001,
      WIDTH_AT_MOST       = 0x00000002,
      WIDTH_OPTIONS       = 0x00000003,

      HEIGHT_MATCHES      = 0x00000000,
      HEIGHT_AT_LEAST     = 0x00000010,
      HEIGHT_AT_MOST      = 0x00000020,
      HEIGHT_OPTIONS      = 0x00000030,

      DEPTH_MATCHES       = 0x00000000,
      DEPTH_AT_LEAST      = 0x00000100,
      DEPTH_AT_MOST       = 0x00000200,
      DEPTH_OPTIONS       = 0x00000300
    };

    virtual const Properties* getProperties()                                                       = 0;
    virtual void              setTitle(const char* title)                                           = 0;
    virtual bool              isOpen()                                                              = 0;
    virtual void              open(const Display::Properties* displayProperties)                    = 0;
    virtual void              close()                                                               = 0;
    virtual void              reopen()                                                              = 0;
    virtual void              refresh()                                                             = 0;
    virtual void              synchronize()                                                         = 0;

    virtual void              setIndexedPalette(const Palette* pal)                                 = 0;
    virtual Surface*          getDrawSurface()                                                      = 0;

    virtual void              open(sint16 w, sint16 h, uint32 d, uint32 opts);

    virtual Thread::WakeEvent awaitInputEvents()                                                    = 0;
    virtual void              processInputEvents()                                                  = 0;

    Display();
    virtual ~Display() {}

    static const Properties* findMode(sint16 w, sint16 h, uint32 d, uint32 options);
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Display::Properties
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Display::Properties : public GfxArea {
  friend class EXNGPrivate::DisplayMode;
  friend class EXNGPrivate::DisplayDatabase;
  public:

    float64       getHorizontalRefreshRatekHz() const;
    float64       getVerticalRefreshRateHz()    const;
    uint32        getUniqueId()                 const { return uniqueId; }
    uint32        getHorizPeriod()              const { return horizRefreshNanos; }
    uint32        getVertPeriod()               const { return vertRefreshMicros; }
    float32       getAspect()                   const { return aspect; }
    uint32        getDepth()                    const { return pixelDepth; }
    Pixel::FBType getFormat()                   const { return pixelHWType; }
    const char*   getName()                     const { return name; }

    static ConstRefList<Display::Properties>::Iterator  getAvailableModes();
    static const Display::Properties*                   getWindowedMode();

  private:
    // deny construction to client
    Properties() {}

    uint32        horizRefreshNanos;
    uint32        vertRefreshMicros;
    float32       aspect;
    uint32        uniqueId;
    uint32        pixelDepth;
    Pixel::FBType pixelHWType;
    char          name[32];

    static ConstRefList<Display::Properties>*  modeList;
};




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  include implementation mixins
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

# include <gfxlib/surface.hpp>
# include <private/gfxlib/display_private.hpp>

#endif