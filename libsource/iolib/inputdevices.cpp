///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         iolib/inputdevices.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:
//  Comment(s):
//  Library:      IO
//  Created:      2006-10-08
//  Updated:      2006-10-08
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <xbase.hpp>
#include <iolib/inputdevices.hpp>

DECLARE_MIN_RTTI(HID::EventMask)
DECLARE_MIN_RTTI(HID::Mouse::Filter)
DECLARE_MIN_RTTI(HID::Mouse::Dispatcher)
DECLARE_MIN_RTTI(HID::Mouse::Observer)
DECLARE_MIN_RTTI(HID::Key::Filter)
DECLARE_MIN_RTTI(HID::Key::Dispatcher)
DECLARE_MIN_RTTI(HID::Key::Observer)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  EventMask
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 HID::EventMask::setMaskBits(uint32 f)
{
  uint32 oldMask = mask;
  mask = f;
  return mask^oldMask;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 HID::EventMask::toggleMaskBits(uint32 f)
{
  uint32 oldMask = mask;
  mask ^= f;
  return mask^oldMask;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 HID::EventMask::enableMaskBits(uint32 f)
{
  uint32 oldMask = mask;
  mask |= f;
  return mask^oldMask;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 HID::EventMask::disableMaskBits(uint32 f)
{
  uint32 oldMask = mask;
  mask &= (~f);
  return mask^oldMask;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Mouse::Filter
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 HID::Mouse::Filter::enableMouseEvents(uint32 mask)
{
  if (enableMaskBits(mask)) {
    applyMouseEventFilter(getMaskBits());
  }
  return getMaskBits();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 HID::Mouse::Filter::disableMouseEvents(uint32 mask)
{
  if (disableMaskBits(mask)) {
    applyMouseEventFilter(getMaskBits());
  }
  return getMaskBits();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Key::Filter
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 HID::Key::Filter::enableKeyEvents(uint32 mask)
{
  if (enableMaskBits(mask)) {
    applyKeyEventFilter(getMaskBits());
  }
  return getMaskBits();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 HID::Key::Filter::disableKeyEvents(uint32 mask)
{
  if (disableMaskBits(mask)) {
    applyKeyEventFilter(getMaskBits());
  }
  return getMaskBits();
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Mouse::Observer
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 HID::Mouse::Observer::nextId = 0;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

HID::Mouse::Observer::Observer(uint32 mask) : Mouse::Filter((mask & Mouse::ALL_EVENTS))
{
  id = nextId++;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

HID::Mouse::Observer::~Observer()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void HID::Mouse::Observer::applyMouseEventFilter(uint32 mask)
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Key::Observer
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 HID::Key::Observer::nextId = 0;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

HID::Key::Observer::Observer(uint32 mask) : HID::Key::Filter((mask & Key::ALL_EVENTS))
{
  id = nextId++;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

HID::Key::Observer::~Observer()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void HID::Key::Observer::applyKeyEventFilter(uint32 m)
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Mouse::Dispatcher
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace {
  typedef void (HID::Mouse::Observer::* ButOp)(const HID::Mouse::Dispatcher* d, HID::Mouse::Button b);
  typedef void (HID::Mouse::Observer::* MovOp)(const HID::Mouse::Dispatcher* d, sint16 x, sint16 y, sint16 dx, sint16 dy, uint32 keys);
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 HID::Mouse::Dispatcher::nextId = 0;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

HID::Mouse::Dispatcher::Dispatcher(uint32 mask) :
HID::Mouse::Filter((mask & HID::Mouse::ALL_EVENTS)), observers(),
buttons(0), lastX(0), lastY(0), lastSX(0), lastSY(0)
{
  id = nextId++;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

HID::Mouse::Dispatcher::~Dispatcher()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void HID::Mouse::Dispatcher::dispatchMouseKey(HID::Mouse::Button button, bool state)
{
  ButOp   butOp;
  uint32  event;
  if (state) {
    buttons |= button;
    event    = button;
    butOp    = &HID::Mouse::Observer::buttonPressed;
  } else {
    buttons &= ~button;
    event    = button<<5;
    butOp    = &HID::Mouse::Observer::buttonReleased;
  }

  if (checkEnabledMouseEvents(event)) {
    RefList<HID::Mouse::Observer>::Iterator itor(observers);
    for (HID::Mouse::Observer* p = itor.first(); p; p = itor.next()) {
      if (p->checkEnabledMouseEvents(button)) {
        (p->*butOp)(this, button);
      }
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void HID::Mouse::Dispatcher::dispatchMouseMove(sint16 x, sint16 xMin, sint16 xMax, sint16 y, sint16 yMin, sint16 yMax)
{
  // update the internal cursor states regardless of filtering
  sint16 dx = x-lastX;
  sint16 dy = y-lastY;
  lastX = x;
  lastY = y;
/*
      MOVE_LIMIT_LEFT   = 0x00100000,
      MOVE_LIMIT_RIGHT  = 0x00200000,
      MOVE_LIMIT_TOP    = 0x00400000,
      MOVE_LIMIT_BOTTOM = 0x00800000,
      MOVE_LIMIT_HORIZ  = MOVE_LIMIT_LEFT|MOVE_LIMIT_RIGHT,
      MOVE_LIMIT_VERT   = MOVE_LIMIT_TOP|MOVE_LIMIT_BOTTOM,
      MOVE_LIMIT_ALL    = MOVE_LIMIT_HORIZ|MOVE_LIMIT_VERT,
*/
  if (checkEnabledMouseEvents(MOVE_LIMIT_LEFT) && (x<xMin)) {
    x = xMin;
  }
  if (checkEnabledMouseEvents(MOVE_LIMIT_RIGHT) && (x>xMax)) {
    x = xMax;
  }
  if (checkEnabledMouseEvents(MOVE_LIMIT_TOP) && (y<yMin)) {
    y = yMin;
  }
  if (checkEnabledMouseEvents(MOVE_LIMIT_BOTTOM) && (y>yMax)) {
    y = yMax;
  }
  uint32 mode = buttons ? HID::Mouse::DRAG :
                          HID::Mouse::MOVE;

  MovOp movOp = buttons ? &HID::Mouse::Observer::drag :
                          &HID::Mouse::Observer::move;

  RefList<HID::Mouse::Observer>::Iterator itor(observers);
  for (HID::Mouse::Observer* p = itor.first(); p; p = itor.next()) {
    if (p->checkEnabledMouseEvents(mode)) {
      (p->*movOp)(this, x, y, dx, dy, buttons);
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void HID::Mouse::Dispatcher::dispatchMouseScroll(sint16 dx, sint16 dy)
{
  if (checkEnabledMouseEvents(HID::Mouse::SCROLL)) {
    RefList<HID::Mouse::Observer>::Iterator itor(observers);
    for (HID::Mouse::Observer* p = itor.first(); p; p = itor.next()) {
      if (p->checkEnabledMouseEvents(HID::Mouse::SCROLL)) {
        p->scroll(this, dx, dy);
      }
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Key::Dispatcher
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace {
  typedef void (HID::Key::Observer::* NPKOp)(const HID::Key::Dispatcher* d, HID::Key::CtrlKey key);
  typedef void (HID::Key::Observer::* PKOp)(const HID::Key::Dispatcher* d, sint32 ch);
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

HID::Key::Dispatcher::Dispatcher(uint32 mask) : HID::Key::Filter((mask & HID::Key::ALL_EVENTS)), observers()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

HID::Key::Dispatcher::~Dispatcher()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void HID::Key::Dispatcher::dispatchKeyNonPrintable(HID::Key::CtrlKey key, bool state)
{
  uint32 mode = state ? HID::Key::NON_PRINTABLE_PRESS :
                        HID::Key::NON_PRINTABLE_RELEASE;

  NPKOp keyOp = state ? &HID::Key::Observer::nonPrintablePressed :
                        &HID::Key::Observer::nonPrintableReleased;

  if (checkEnabledKeyEvents(mode)) {
    RefList<HID::Key::Observer>::Iterator itor(observers);
    for (HID::Key::Observer* p = itor.first(); p; p = itor.next()) {
      if (p->checkEnabledKeyEvents(mode)) {
        (p->*keyOp)(this, key);
      }
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void HID::Key::Dispatcher::dispatchKeyPrintable(sint32 ch, bool state)
{
  uint32 mode = state ? HID::Key::NON_PRINTABLE_PRESS :
                        HID::Key::NON_PRINTABLE_RELEASE;

  PKOp keyOp  = state ? &HID::Key::Observer::printablePressed :
                        &HID::Key::Observer::printableReleased;

  if (checkEnabledKeyEvents(mode)) {
    RefList<HID::Key::Observer>::Iterator itor(observers);
    for (HID::Key::Observer* p = itor.first(); p; p = itor.next()) {
      if (p->checkEnabledKeyEvents(mode)) {
        (p->*keyOp)(this, ch);
      }
    }
  }
}

