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

#ifndef _EXNG2_GFXLIB_GFX_NATIVE_HPP_
# define _EXNG2_GFXLIB_GFX_NATIVE_HPP_

namespace OSNative {
  extern "C" {
#   include <proto/intuition.h>
#   include <proto/graphics.h>
#   include <proto/cybergraphics.h>
  }
};

namespace EXNGPrivate {

  class GfxResource {
    public:
      static void init();
      static void done();

      static uint8  abstractToNative[];
      static uint8  nativeToAbstract[];

      LOGGING_DEFINE_CLASSNAME
  };

};

//#define EXNG2_GFXLIB_NATIVE_PIXEL_CONV_15
//#define EXNG2_GFXLIB_NATIVE_PIXEL_CONV_16
//#define EXNG2_GFXLIB_NATIVE_PIXEL_CONV_24
//#define EXNG2_GFXLIB_NATIVE_PIXEL_CONV_32


#endif