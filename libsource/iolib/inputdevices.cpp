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

DECLARE_MIN_RTTI(EventMask)
DECLARE_MIN_RTTI(Mouse::Filter)
DECLARE_MIN_RTTI(Mouse::Dispatcher)
DECLARE_MIN_RTTI(Mouse::Observer)
DECLARE_MIN_RTTI(Key::Filter)
DECLARE_MIN_RTTI(Key::Dispatcher)
DECLARE_MIN_RTTI(Key::Observer)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  EventMask
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 EventMask::setMaskBits(uint32 f)
{
  uint32 oldMask = mask;
  mask = f;
  return mask^oldMask;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 EventMask::toggleMaskBits(uint32 f)
{
  uint32 oldMask = mask;
  mask ^= f;
  return mask^oldMask;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 EventMask::enableMaskBits(uint32 f)
{
  uint32 oldMask = mask;
  mask |= f;
  return mask^oldMask;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 EventMask::disableMaskBits(uint32 f)
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

uint32 Mouse::Filter::enableMouseEvents(uint32 mask)
{
  if (enableMaskBits(mask)) {
    applyMouseEventFilter(getMaskBits());
  }
  return getMaskBits();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 Mouse::Filter::disableMouseEvents(uint32 mask)
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

uint32 Key::Filter::enableKeyEvents(uint32 mask)
{
  if (enableMaskBits(mask)) {
    applyKeyEventFilter(getMaskBits());
  }
  return getMaskBits();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 Key::Filter::disableKeyEvents(uint32 mask)
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

uint32 Mouse::Observer::nextId = 0;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Mouse::Observer::Observer(uint32 mask) : Mouse::Filter((mask & Mouse::ALL_EVENTS))
{
  id = nextId++;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Mouse::Observer::~Observer()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Mouse::Observer::applyMouseEventFilter(uint32 mask)
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Key::Observer
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 Key::Observer::nextId = 0;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Key::Observer::Observer(uint32 mask) : Key::Filter((mask & Key::ALL_EVENTS))
{
  id = nextId++;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Key::Observer::~Observer()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Key::Observer::applyKeyEventFilter(uint32 m)
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Mouse::Dispatcher
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace {
  typedef void (Mouse::Observer::* ButOp)(const Mouse::Dispatcher* d, Mouse::Button b);
  typedef void (Mouse::Observer::* MovOp)(const Mouse::Dispatcher* d, sint16 x, sint16 y, sint16 dx, sint16 dy, uint32 keys);
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 Mouse::Dispatcher::nextId = 0;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Mouse::Dispatcher::Dispatcher(uint32 mask) :
Mouse::Filter((mask & Mouse::ALL_EVENTS)), observers(),
buttons(0), lastX(0), lastY(0), lastSX(0), lastSY(0)
{
  id = nextId++;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Mouse::Dispatcher::~Dispatcher()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Mouse::Dispatcher::dispatchMouseKey(Mouse::Button button, bool state)
{
  ButOp   butOp;
  uint32  event;
  if (state) {
    buttons |= button;
    event    = button;
    butOp    = &Mouse::Observer::buttonPressed;
  } else {
    buttons &= ~button;
    event    = button<<5;
    butOp    = &Mouse::Observer::buttonReleased;
  }

  if (checkEnabledMouseEvents(event)) {
    RefList<Mouse::Observer>::Iterator itor(observers);
    for (Mouse::Observer* p = itor.first(); p; p = itor.next()) {
      if (p->checkEnabledMouseEvents(button)) {
        (p->*butOp)(this, button);
      }
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Mouse::Dispatcher::dispatchMouseMove(sint16 x, sint16 xMin, sint16 xMax, sint16 y, sint16 yMin, sint16 yMax)
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
  uint32 mode = buttons ? Mouse::DRAG :
                          Mouse::MOVE;

  MovOp movOp = buttons ? &Mouse::Observer::drag :
                          &Mouse::Observer::move;

  RefList<Mouse::Observer>::Iterator itor(observers);
  for (Mouse::Observer* p = itor.first(); p; p = itor.next()) {
    if (p->checkEnabledMouseEvents(mode)) {
      (p->*movOp)(this, x, y, dx, dy, buttons);
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Mouse::Dispatcher::dispatchMouseScroll(sint16 dx, sint16 dy)
{
  if (checkEnabledMouseEvents(Mouse::SCROLL)) {
    RefList<Mouse::Observer>::Iterator itor(observers);
    for (Mouse::Observer* p = itor.first(); p; p = itor.next()) {
      if (p->checkEnabledMouseEvents(Mouse::SCROLL)) {
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
  typedef void (Key::Observer::* NPKOp)(const Key::Dispatcher* d, Key::CtrlKey key);
  typedef void (Key::Observer::* PKOp)(const Key::Dispatcher* d, sint32 ch);
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Key::Dispatcher::Dispatcher(uint32 mask) : Key::Filter((mask & Key::ALL_EVENTS)), observers()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Key::Dispatcher::~Dispatcher()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Key::Dispatcher::dispatchKeyNonPrintable(Key::CtrlKey key, bool state)
{
  uint32 mode = state ? Key::NON_PRINTABLE_PRESS :
                        Key::NON_PRINTABLE_RELEASE;

  NPKOp keyOp = state ? &Key::Observer::nonPrintablePressed :
                        &Key::Observer::nonPrintableReleased;

  if (checkEnabledKeyEvents(mode)) {
    RefList<Key::Observer>::Iterator itor(observers);
    for (Key::Observer* p = itor.first(); p; p = itor.next()) {
      if (p->checkEnabledKeyEvents(mode)) {
        (p->*keyOp)(this, key);
      }
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Key::Dispatcher::dispatchKeyPrintable(sint32 ch, bool state)
{
  uint32 mode = state ? Key::NON_PRINTABLE_PRESS :
                        Key::NON_PRINTABLE_RELEASE;

  PKOp keyOp  = state ? &Key::Observer::printablePressed :
                        &Key::Observer::printableReleased;

  if (checkEnabledKeyEvents(mode)) {
    RefList<Key::Observer>::Iterator itor(observers);
    for (Key::Observer* p = itor.first(); p; p = itor.next()) {
      if (p->checkEnabledKeyEvents(mode)) {
        (p->*keyOp)(this, ch);
      }
    }
  }
}

