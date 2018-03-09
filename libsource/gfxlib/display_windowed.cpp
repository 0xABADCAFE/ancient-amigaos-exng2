///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         gfxlib/palette.hpp
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

#include <gfxlib/display_windowed.hpp>
#include <private/systemlib/error.hpp>
//#include <private/gfxlib/display_private.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Display::Windowed
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DECLARE_MIN_RTTI          (Display::Windowed)
LOGGING_DECLARE_CLASSNAME (Display::Windowed)

Display::Windowed::Windowed(uint32 displayMask, uint32 keyMask, uint32 mouseMask, uint32 f, sint16 x, sint16 y) :
  HostUI::Dispatcher(displayMask, keyMask, mouseMask),
  Display(),
  OSWindowed(f & OSWindowed::WF_PUBLICMASK),
  winFrame(),
  winViewPort(),
  xPos(x),
  yPos(y)
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Display::Windowed::~Windowed()
{
  close();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 Display::Windowed::getWindowAttributes()
{
  return getFlags() & WF_PUBLICMASK;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 Display::Windowed::setWindowAttributes(uint32 attr)
{
  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const GfxRect& Display::Windowed::getViewPortRect()
{
  if (isAllocated()) {
    winViewPort.set(
      getViewLeft(),
      getViewTop(),
      getViewWidth(),
      getViewHeight()
    );
  }
  return winViewPort;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const GfxRect& Display::Windowed::getFrameRect()
{
  if (isAllocated()) {
    winFrame.set(
      getWinLeft(),
      getWinTop(),
      getWinWidth(),
      getWinHeight()
    );
  }
  return winFrame;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Display::Windowed::open(const Display::Properties* displayProperties)
{
  if (isAllocated()) {
    // TO DO - check to see if the passed properties are compatible with the ones
    // we are using
    THROW_NSX(Error, ObjectStateViolation());
  }

  if (!displayProperties) {
    THROW_NSX(Error, NullPointer());
  }

  if (!openDisplay(xPos, yPos, displayProperties->getWidth(), displayProperties->getHeight())) {
    THROW_NSX(Error, ResourceUnavailable(getDisplayProperties()->getName()));
  }

  xPos = getWinLeft();
  yPos = getWinTop();
  bindSurface();
  applyEventFilters(getEnabledDisplayEvents(), getEnabledKeyEvents(), getEnabledMouseEvents());
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Display::Windowed::open(sint16 w, sint16 h, uint32 d, uint32 opts)
{
  openWindow(xPos, yPos, w, h);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Display::Windowed::openWindow(sint16 x, sint16 y, sint16 w, sint16 h)
{
  if (isAllocated()) {
    // TO DO - check to see if the passed properties are compatible with the ones
    // we are using
    THROW_NSX(Error, ObjectStateViolation());
  }

  if (!openDisplay(x, y, w, h)) {
    THROW_NSX(Error, ResourceUnavailable("Windowed display"));
  }

  bindSurface();
  applyEventFilters(getEnabledDisplayEvents(), getEnabledKeyEvents(), getEnabledMouseEvents());
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Display::Windowed::reopen()
{
  if (isAllocated()) {
    return;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Display::Windowed::close()
{
  if (isAllocated()) {
    xPos = getWinLeft();
    yPos = getWinTop();
    discardEventQueue();
    closeDisplay();
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Display::Windowed::refresh()
{
  OSWindowed::refreshAll();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Display::Windowed::synchronize()
{
  waitSync();
}
