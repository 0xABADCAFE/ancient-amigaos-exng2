///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         private/gfxlib/display_private.hpp
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

#ifndef _EXNG2_GFXLIB_DISPLAY_PRIVATE_HPP_
# define _EXNG2_GFXLIB_DISPLAY_PRIVATE_HPP_

namespace EXNGPrivate {

  class DisplayMode : public Display::Properties {
    public:
      void setUniqueId(uint32 id);
      void setTiming(uint32 h, uint32 v);
      void setDimension(sint16 width, sint16 height);
      void setAspect(float32 a);
      void setFormat(Pixel::FBType f, Pixel::FBDepth d=Pixel::BPP0);
      void setName(const char* title);

      void cloneWindowProps(const Display::Properties* p)
      {
        horizRefreshNanos = p->horizRefreshNanos;
        vertRefreshMicros = p->vertRefreshMicros;
        aspect            = p->aspect;
        uniqueId          = p->uniqueId;
        pixelDepth        = p->pixelDepth;
        pixelHWType       = p->pixelHWType;
      }

    public:
      DisplayMode() : Display::Properties() {}
  };

  class DisplayDatabase {
    public:
      static const  Display::Properties*  getWindowedMode();
      static bool   createDatabase();
      static void   freeDatabase();

    private:
      static bool   allocPropertyNodes(size_t n);
      static void   freePropertyNodes();

      static DisplayMode* availableModes;
      static size_t       numModes;

      LOGGING_DEFINE_CLASSNAME
  };
};

#include <gfxlib/display_native.hpp>

#endif
