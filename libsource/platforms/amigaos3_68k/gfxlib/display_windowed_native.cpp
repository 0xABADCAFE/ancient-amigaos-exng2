///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/amigaos3_68k/gfxlib/display_windowed_native.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:
//  Comment(s):
//  Library:      Graphics
//  Created:      2007-12-08
//  Updated:      2007-12-11
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <gfxlib/display.hpp>
#include <systemlib/memory.hpp>

#include <cstring>

namespace OSNative {
  extern "C" {
#   include <proto/graphics.h>
#   include <proto/cybergraphics.h>
#   include <clib/alib_protos.h>
  }
}

using namespace EXNGPrivate;
using namespace OSNative;

LOGGING_DECLARE_CLASSNAME(OSWindowed)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  OSWindowed
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

OSWindowed::OSWindowed(uint32 f) :
  OSDisplay(),
  mode(),
  flags(f)
{
  mode.setName("Windowed");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

OSWindowed::~OSWindowed()
{
  closeDisplay();
  if (drawSurface) {
    delete drawSurface;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool OSWindowed::openDisplay(sint16 x, sint16 y, sint16 w, sint16 h)
{
  uint32 wFlags = WFLG_REPORTMOUSE|WFLG_RMBTRAP|WFLG_ACTIVATE|
                  (flags & WF_MOVEABLE      ? WFLG_DRAGBAR : 0)                     |
                  (flags & WF_CLOSEABLE     ? WFLG_CLOSEGADGET : 0)                 |
                  (flags & WF_RESIZEABLE    ? WFLG_SIZEGADGET|WFLG_SIZEBRIGHT : 0)  |
                  (flags & WF_BORDERLESS    ? WFLG_BORDERLESS : 0)                  |
                  (flags & WF_NOSYSREFRESH  ? WFLG_SIMPLE_REFRESH|WFLG_NOCAREREFRESH : 0);
  const Display::Properties* wmProps;
  bool res = false;

  do {
    // obtain resources
    if ( !(screen  = lockHostDisplay()) ||
         !(wmProps = DisplayDatabase::getWindowedMode())
    ) {
      break;
    }

    // check requested dimensions are displayble
    if (w > wmProps->getWidth() || h > wmProps->getHeight()) {
      break;
    }

    // clamp position
    if (flags & WF_CENTRE_X) {
      x = (wmProps->getWidth() - w)>>1;
    }
    else {
      // clamp x to 0 ... screenWidth - w
      x = (x<0) ? 0 : ( ((x+w)>wmProps->getWidth()) ? wmProps->getWidth()-w : x);
    }
    if (flags & WF_CENTRE_Y) {
      y = (wmProps->getHeight() - h)>>1;
    }
    else {
      // clamp y to 0 ... screenHeight - h
      y = (y<0) ? 0 : ( ((y+h)>wmProps->getHeight()) ? wmProps->getHeight()-h : y);
    }

    // attempt to open display
    if ( (res = openWindowed(x, y, w, h, wFlags)) ) {
      setDisplayTitle(name, false);
      mode.cloneWindowProps(wmProps);
      mode.setDimension(w, h);
    }

  } while (0);

  // release screen if it was locked
  if (screen) {
    unlockHostDisplay(screen);
    if (!res) {
      screen = 0;
    }
  }
  return res;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool OSWindowed::reopenDisplay()
{
  return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void OSWindowed::closeDisplay()
{
  closeWindowed();
  screen = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void OSWindowed::refreshRegion(sint16 x, sint16 y, sint16 w, sint16 h)
{
  if (window) {
    // Refresh area must fit within the display
    if (x > mode.getWidth() || y > mode.getHeight() || (x+w) < 0 || (y+h) < 0)
      return;

    // Since coords can be negative, crop blit
    if (x<0)                    { w += x; x = 0;  }
    if ((x+w)>mode.getWidth())  { w = mode.getWidth() - x;  }
    if (y<0)                    { h += y; y = 0;  }
    if ((y+h)>mode.getHeight()) { h = mode.getHeight() - y; }

    // Do the blit
    ClipBlit(&rastPort, x, y, window->RPort, window->BorderLeft+x, window->BorderTop+y, w, h, 0xC0);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const Display::Properties* OSWindowed::getDisplayProperties()
{
  if (isAllocated()) {
    return &mode;
  }
  else {
    return DisplayDatabase::getWindowedMode();
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void OSWindowed::bindSurface()
{
  LOGGING_DECLARE_FUNCNAME(bindSurface)
  if (!drawSurface) {
    drawSurface = SurfaceProvider::createNewSurfaceLikeBitMap(window->RPort->BitMap, mode.getWidth(), mode.getHeight());
  }
  else {
    // reuse the old BitMap, if possible. Otherwise request an appropriately sized clone of the main ons
    if (
      !SurfaceProvider::checkCompatible(drawSurface,window->RPort->BitMap) ||
      drawSurface->getWidth()!=mode.getWidth() ||
      drawSurface->getHeight()!=mode.getHeight()
    ) {
      SurfaceProvider::releaseSurface(drawSurface);
      SurfaceProvider::cloneBitMapToSurface(drawSurface, window->RPort->BitMap, mode.getWidth(), mode.getHeight());
    };
  }
  SurfaceProvider::setWinUser(drawSurface, window);
  InitRastPort(&rastPort);
  rastPort.BitMap = SurfaceProvider::getSurfaceBitMap(drawSurface);
}

