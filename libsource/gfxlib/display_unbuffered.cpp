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

#include <gfxlib/display_fullscreen.hpp>
#include <private/systemlib/error.hpp>
//#include <private/gfxlib/display_private.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Display::Unbuffered
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DECLARE_MIN_RTTI          (Display::Unbuffered)
LOGGING_DECLARE_CLASSNAME (Display::Unbuffered)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Display::Unbuffered::Unbuffered(uint32 displayMask, uint32 keyMask, uint32 mouseMask) :
  HostUI::Dispatcher(displayMask, keyMask, mouseMask),
  Display(),
  OSScreen()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Display::Unbuffered::~Unbuffered()
{
  if (isAllocated()) {
    closeDisplay();
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Display::Unbuffered::open(const Display::Properties* displayProperties)
{
  // if the display is already open and the passed instance is not the same
  // as the currently in use instance, throw an error
  if (isAllocated()) {
    if (displayProperties != getDisplayProperties()) {
      THROW_NSX(Error, ObjectStateViolation());
    }
    return;
  }
  if (!displayProperties) {
    THROW_NSX(Error, NullPointer());
  }
  if (openDisplay(displayProperties)==false) {
    THROW_NSX(Error, ResourceUnavailable(displayProperties->getName()));
  }
  bindSurface();
  applyEventFilters(getEnabledDisplayEvents(), getEnabledKeyEvents(), getEnabledMouseEvents());
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Display::Unbuffered::reopen()
{
  // already open?
  if (isAllocated()) {
    return;
  }
  // never opened?
  if (!getDisplayProperties()) {
    THROW_NSX(Error, ObjectStateViolation());
  }
  if (reopenDisplay()==false) {
    THROW_NSX(Error, ResourceUnavailable(getDisplayProperties()->getName()));
  }
  bindSurface();
  applyEventFilters(getEnabledDisplayEvents(), getEnabledKeyEvents(), getEnabledMouseEvents());
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Display::Unbuffered::close()
{
  if (isAllocated()) {
    discardEventQueue();
    closeDisplay();
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Display::Unbuffered::refresh()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Display::Unbuffered::synchronize()
{
  waitSync();
}

