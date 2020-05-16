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

#include <gfxlib/gfxapplication.hpp>
#include <private/systemlib/error.hpp>
#include <private/gfxlib/display_private.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Display
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


DECLARE_MIN_RTTI(AppDisplay)
DECLARE_MIN_RTTI(AppDisplay::Unbuffered)
DECLARE_MIN_RTTI(AppDisplay::FlipBuffered)
DECLARE_MIN_RTTI(AppDisplay::Windowed)

AppDisplay::AppDisplay(uint32 keyMask, uint32 mouseMask) :
  HID::Key::Dispatcher(keyMask),
  HID::Mouse::Dispatcher(mouseMask)
{

}

AppDisplay::Unbuffered::Unbuffered(uint32 keyMask, uint32 mouseMask) :
  AppDisplay::AppDisplay(keyMask, mouseMask),
  Display::Unbuffered()
{

}

AppDisplay::FlipBuffered::FlipBuffered(uint32 keyMask, uint32 mouseMask, BufferType bt) :
  AppDisplay::AppDisplay(keyMask, mouseMask),
  Display::FlipBuffered(bt)
{

}

AppDisplay::Windowed::Windowed(uint32 keyMask, uint32 mouseMask, uint32 attr, sint16 x, sint16 y) :
  AppDisplay::AppDisplay(keyMask, mouseMask),
  Display::Windowed(attr, x, y)
{

}

