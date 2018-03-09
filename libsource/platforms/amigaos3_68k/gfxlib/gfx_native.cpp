///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         gfxlib/colour.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Range bound integer class
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

#include <gfxlib/gfx.hpp>
#include <gfxlib/pixel.hpp>
#include <gfxlib/display.hpp>
#include <systemlib/error.hpp>
#include <systemlib/logger.hpp>

namespace OSNative {
  extern "C" {
#   include <cybergraphics/cybergraphics.h>
  }
};

using namespace EXNGPrivate;
using namespace OSNative;

Library*          CyberGfxBase  = 0;
struct GfxBase*   GfxBase       = 0;

uint8 GfxResource::abstractToNative[Pixel::CUSTOM_FB] = {
  // Maps abstract hardware types to CGX native types
  PIXFMT_LUT8,      // LUT_8
  PIXFMT_RGB15,     // RGB_555B
  PIXFMT_BGR15,     // BGR_555B
  PIXFMT_RGB15PC,   // RGB_555L
  PIXFMT_BGR15PC,   // BGR_555L
  PIXFMT_RGB16,     // RGB_565B
  PIXFMT_BGR16,     // BGR_565L
  PIXFMT_RGB16PC,   // RGB_565L
  PIXFMT_BGR16PC,   // BGR_565L
  PIXFMT_RGB24,     // RGB_24
  PIXFMT_BGR24,     // BGR_24
  PIXFMT_ARGB32,    // ARGB_8888
  PIXFMT_ARGB32,    // ABGR_8888 - unsupported in cgx?
  PIXFMT_BGRA32,    // BGRA_8888
  PIXFMT_RGBA32     // RGBA_8888
};

uint8 GfxResource::nativeToAbstract[1+PIXFMT_RGBA32] = {
  // Maps CGX native types to the abstract hardware types
  Pixel::LUT_8,       // PIXFMT_LUT8    (0UL)
  Pixel::RGB_555B,    // PIXFMT_RGB15   (1UL)
  Pixel::BGR_555B,    // PIXFMT_BGR15   (2UL)
  Pixel::RGB_555L,    // PIXFMT_RGB15PC (3UL)
  Pixel::BGR_555L,    // PIXFMT_BGR15PC (4UL)
  Pixel::RGB_565B,    // PIXFMT_RGB16   (5UL)
  Pixel::BGR_565B,    // PIXFMT_BGR16   (6UL)
  Pixel::RGB_565L,    // PIXFMT_RGB16PC (7UL)
  Pixel::BGR_565L,    // PIXFMT_BGR16PC (8UL)
  Pixel::RGB_888,      // PIXFMT_RGB24   (9UL)
  Pixel::BGR_888,      // PIXFMT_BGR24   (10UL)
  Pixel::ARGB_8888,   // PIXFMT_ARGB32  (11UL)
  Pixel::BGRA_8888,   // PIXFMT_BGRA32  (12UL)
  Pixel::RGBA_8888    // PIXFMT_RGBA32  (13UL)
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LOGGING_DECLARE_CLASSNAME(GfxResource)

void GfxResource::init()
{
  LOGGING_DECLARE_FUNCNAME(init)

  if (!(::GfxBase = (struct GfxBase*)OpenLibrary("graphics.library",39))) {
    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::ERROR, "%s::%s failed to open graphics.library v39+\n",
      loggingClassName, loggingFuncName
    );
    #endif
    done();
    THROW_NSX(Error, ResourceVersion("graphics.library v39+"));
  }
  if (!(::CyberGfxBase = OpenLibrary("cybergraphics.library", 41))) {
    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::ERROR, "%s::%s failed to open cybergraphics.library v41+\n",
      loggingClassName, loggingFuncName
    );
    #endif
    done();
    THROW_NSX(Error, ResourceUnavailable("cybergraphics.library v41+"));
  }

  if (!DisplayDatabase::createDatabase()) {
    done();
    THROW_NSX(Error, ResourceUnavailable("display database"));
  }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GfxResource::done()
{
  LOGGING_DECLARE_FUNCNAME(done)

  DisplayDatabase::freeDatabase();

  if (::CyberGfxBase) {
    CloseLibrary(::CyberGfxBase);
    ::CyberGfxBase = 0;
  }
  if (::GfxBase) {
    CloseLibrary((Library*)::GfxBase);
    ::GfxBase = 0;
  }

  #ifdef EXNG2_BUILD_LOGGED
  SystemLog::write(
    SystemLog::INFO, "%s::%s freed resources\n",
    loggingClassName, loggingFuncName
  );
  #endif
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

