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

#include <gfxlib/display.hpp>
#include <private/systemlib/error.hpp>
#include <private/gfxlib/display_private.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Display
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


DECLARE_MIN_RTTI(Display)
LOGGING_DECLARE_CLASSNAME(Display)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Display::Display()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const Display::Properties* Display::findMode(sint16 w, sint16 h, uint32 d, uint32 options)
{
  LOGGING_DECLARE_FUNCNAME(findMode)

  const Display::Properties* best = 0;

  ConstRefList<Display::Properties>::Iterator iterator = Display::Properties::getAvailableModes();

  for (const Display::Properties* p = iterator.first(); p; p = iterator.next()) {
    if (p->getWidth() == w && p->getHeight() == h && p->getDepth() == d) {
      best = p;

      #ifdef EXNG2_BUILD_LOGGED
      SystemLog::write(
        SystemLog::INFO, "%s::%s found exact match [%s]\n",
        loggingClassName, loggingFuncName,
        p->getName()
      );
      #endif

      break;
    }
  }

  if (!best && options!=0) {
    sint32 bestScore  = 0x7FFFFFFF;
    sint32 score      = 0;
    sint32 tmp        = 0;
    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::INFO, "%s::%s no exact match found, testing alternatives\n",
      loggingClassName, loggingFuncName
    );
    #endif
    for (const Display::Properties* p = iterator.first(); p; p = iterator.next()) {
//       #ifdef EXNG2_BUILD_LOGGED
//       SystemLog::write(
//         SystemLog::INFO, "\tMode: %s\n",
//         p->getName()
//       );
//       #endif

      // check width
      switch(options & Display::WIDTH_OPTIONS) {
        case Display::WIDTH_AT_LEAST:
          if (p->getWidth()<w) {
//             #ifdef EXNG2_BUILD_LOGGED
//             SystemLog::write(
//               SystemLog::INFO, "\tfailed WIDTH_AT_LEAST %" XPF_S16 "\n",
//               w
//             );
//             #endif
            continue;
          }
          break;

        case Display::WIDTH_AT_MOST:
          if (p->getWidth()>w) {
//             #ifdef EXNG2_BUILD_LOGGED
//             SystemLog::write(
//               SystemLog::INFO, "\tfailed WIDTH_AT_MOST %" XPF_S16 "\n",
//               w
//             );
//             #endif
            continue;
          }
          break;

        default:
          if (p->getWidth()!=w) {
//             #ifdef EXNG2_BUILD_LOGGED
//             SystemLog::write(
//               SystemLog::INFO, "\tfailed WIDTH_MATCHES %" XPF_S16 "\n",
//               w
//             );
//             #endif
            continue;
          }
          break;
      }

      // check height
      switch (options & Display::HEIGHT_OPTIONS) {
        case Display::HEIGHT_AT_LEAST:
          if (p->getHeight()<h) {
//             #ifdef EXNG2_BUILD_LOGGED
//             SystemLog::write(
//               SystemLog::INFO, "\tfailed HEIGHT_AT_LEAST %" XPF_S16 "\n",
//               h
//             );
//             #endif
            continue;
          }
          break;

        case Display::HEIGHT_AT_MOST:
          if (p->getHeight()>h) {
//             #ifdef EXNG2_BUILD_LOGGED
//             SystemLog::write(
//               SystemLog::INFO, "\tfailed HEIGHT_AT_MOST %" XPF_S16 "\n",
//               h
//             );
//             #endif
            continue;
          }
          break;

        default:
          if (p->getHeight()!=h) {
//             #ifdef EXNG2_BUILD_LOGGED
//             SystemLog::write(
//               SystemLog::INFO, "\tfailed HEIGHT_MATCHES %" XPF_S16 "\n",
//               h
//             );
//             #endif
            continue;
          }
          break;
      }

      // check depth
      switch (options & Display::DEPTH_OPTIONS) {
        case Display::DEPTH_AT_LEAST:
          if (p->getDepth()<d) {
//             #ifdef EXNG2_BUILD_LOGGED
//             SystemLog::write(
//               SystemLog::INFO, "\tfailed DEPTH_AT_LEAST %" XPF_U32 "\n",
//               d
//             );
//             #endif
            continue;
          }
          break;

        case Display::DEPTH_AT_MOST:
          if (p->getDepth()>d) {
//             #ifdef EXNG2_BUILD_LOGGED
//             SystemLog::write(
//               SystemLog::INFO, "\tfailed DEPTH_AT_MOST %" XPF_U32 "\n",
//               d
//             );
//             #endif
            continue;
          }
          break;

        default:
          if (p->getDepth()!=d) {
//             #ifdef EXNG2_BUILD_LOGGED
//             SystemLog::write(
//               SystemLog::INFO, "\tfailed DEPTH_MATCHES %" XPF_U32 "\n",
//               d
//             );
//             #endif
            continue;
          }
          break;
      }

      tmp    = w-p->getWidth();
      tmp   *= tmp;
      score  = tmp;
      tmp    = h-p->getHeight();
      tmp   *= tmp;
      score += tmp;
      tmp    = d-p->getDepth();
      tmp   *= tmp;
      score += tmp;
//       #ifdef EXNG2_BUILD_LOGGED
//       SystemLog::write(
//         SystemLog::INFO, "\tpassed %" XPF_S32 "\n",
//         score
//       );
//       #endif
      if (score < bestScore) {
        best = p;
        bestScore = score;
      }
    }

    #ifdef EXNG2_BUILD_LOGGED
    if (best) {
      SystemLog::write(
        SystemLog::INFO, "%s::%s found best fit match [%s]\n",
        loggingClassName, loggingFuncName,
        best->getName()
      );
    } else {
      SystemLog::write(
        SystemLog::WARNING, "%s::%s couldn't find suitable match\n",
        loggingClassName, loggingFuncName
      );
    }
    #endif

  }
  return best;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Display::open(sint16 w, sint16 h, uint32 d, uint32 opts)
{
  const Display::Properties* match = findMode(w, h, d, opts);
  if (match) {
    open(match);
  } else {
    THROW_NSX(Error, ResourceUnavailable("Display"));
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  HostUI::Filter
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DECLARE_MIN_RTTI(HostUI::Filter)
DECLARE_MIN_RTTI(HostUI::Observer)
DECLARE_MIN_RTTI(HostUI::Dispatcher)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 HostUI::Filter::enableDisplayEvents(uint32 mask)
{
  if (enableMaskBits(mask)) {
    applyDisplayEventFilter(getMaskBits());
  }
  return getMaskBits();
}

uint32 HostUI::Filter::disableDisplayEvents(uint32 mask)
{
  if (disableMaskBits(mask)) {
    applyDisplayEventFilter(getMaskBits());
  }
  return getMaskBits();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

HostUI::Observer::Observer(uint32 mask, uint32 keyMask, uint32 mouseMask) :
  HostUI::Filter(mask),
  HID::Key::Observer(keyMask),
  HID::Mouse::Observer(mouseMask)
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

HostUI::Observer::~Observer()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void HostUI::Observer::applyDisplayEventFilter(uint32)
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

HostUI::Dispatcher::Dispatcher(uint32 mask, uint32 keyMask, uint32 mouseMask) :
  HostUI::Filter(mask),
  HID::Key::Dispatcher(keyMask),
  HID::Mouse::Dispatcher(mouseMask)
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

HostUI::Dispatcher::~Dispatcher()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void HostUI::Dispatcher::addHostUIObserver(HostUI::Observer* o)
{
  addKeyObserver(o);
  addMouseObserver(o);
  observers.pushBack(o);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool HostUI::Dispatcher::removeHostUIObserver(HostUI::Observer* o)
{
  removeKeyObserver(o);
  removeMouseObserver(o);
  return observers.remove(o);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
  enum {
    HUI_CLOSE     = 0x00000001,
    HUI_MOVE      = 0x00000002,
    HUI_RESIZE    = 0x00000004,
    HUI_MINIMIZE  = 0x00000008,
    ALL_EVENTS    = 0x0000000F
  };
*/
void HostUI::Dispatcher::dispatchClosed()
{
  if (checkEnabledDisplayEvents(HostUI::HUI_CLOSE)) {
    RefList<HostUI::Observer>::Iterator itor(observers);
    for (HostUI::Observer* p = itor.first(); p; p = itor.next()) {
      if (p->checkEnabledDisplayEvents(HostUI::HUI_CLOSE)) {
        p->displayClosed(this);
      }
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void HostUI::Dispatcher::dispatchMoved()
{
  if (checkEnabledDisplayEvents(HostUI::HUI_MOVE)) {
    RefList<HostUI::Observer>::Iterator itor(observers);
    for (HostUI::Observer* p = itor.first(); p; p = itor.next()) {
      if (p->checkEnabledDisplayEvents(HostUI::HUI_MOVE)) {
        p->displayMoved(this);
      }
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void HostUI::Dispatcher::dispatchResized()
{
  if (checkEnabledDisplayEvents(HostUI::HUI_RESIZE)) {
    RefList<HostUI::Observer>::Iterator itor(observers);
    for (HostUI::Observer* p = itor.first(); p; p = itor.next()) {
      if (p->checkEnabledDisplayEvents(HostUI::HUI_RESIZE)) {
        p->displayResized(this);
      }
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void HostUI::Dispatcher::dispatchMinimized()
{
  if (checkEnabledDisplayEvents(HostUI::HUI_MINIMIZE)) {
    RefList<HostUI::Observer>::Iterator itor(observers);
    for (HostUI::Observer* p = itor.first(); p; p = itor.next()) {
      if (p->checkEnabledDisplayEvents(HostUI::HUI_MINIMIZE)) {
        p->displayMinimized(this);
      }
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void HostUI::Dispatcher::dispatchFocus()
{
  if (checkEnabledDisplayEvents(HostUI::HUI_FOCUS)) {
    RefList<HostUI::Observer>::Iterator itor(observers);
    for (HostUI::Observer* p = itor.first(); p; p = itor.next()) {
      if (p->checkEnabledDisplayEvents(HostUI::HUI_FOCUS)) {
        p->displayFocus(this);
      }
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void HostUI::Dispatcher::dispatchBlur()
{
  if (checkEnabledDisplayEvents(HostUI::HUI_BLUR)) {
    RefList<HostUI::Observer>::Iterator itor(observers);
    for (HostUI::Observer* p = itor.first(); p; p = itor.next()) {
      if (p->checkEnabledDisplayEvents(HostUI::HUI_BLUR)) {
        p->displayBlur(this);
      }
    }
  }
}

// HID::Key::Observer
void HostUI::Observer::nonPrintablePressed(const HID::Key::Dispatcher* d, HID::Key::CtrlKey code)
{

}

void HostUI::Observer::nonPrintableReleased(const HID::Key::Dispatcher* d, HID::Key::CtrlKey code)
{

}

void HostUI::Observer::printablePressed(const HID::Key::Dispatcher* d, sint32 ch)
{

}

void HostUI::Observer::printableReleased(const HID::Key::Dispatcher* d, sint32 ch)
{

}

// HID::Mouse::Observer
void HostUI::Observer::buttonPressed(const HID::Mouse::Dispatcher* d, HID::Mouse::Button b)
{

}

void HostUI::Observer::buttonReleased(const HID::Mouse::Dispatcher* d, HID::Mouse::Button b)
{

}

void HostUI::Observer::scroll(const HID::Mouse::Dispatcher* d, sint16 dx, sint16 dy)
{

}

void HostUI::Observer::move(const HID::Mouse::Dispatcher* d, sint16 x, sint16 y, sint16 dx, sint16 dy, uint32)
{

}

void HostUI::Observer::drag(const HID::Mouse::Dispatcher* d, sint16 x, sint16 y, sint16 dx, sint16 dy, uint32 keys)
{

}

void HostUI::Observer::displayClosed(const HostUI::Dispatcher* d)
{

}

void HostUI::Observer::displayMoved(const HostUI::Dispatcher* d)
{

}

void HostUI::Observer::displayResized(const HostUI::Dispatcher* d)
{

}

void HostUI::Observer::displayMinimized(const HostUI::Dispatcher* d)
{

}

void HostUI::Observer::displayFocus(const HostUI::Dispatcher* d)
{

}

void HostUI::Observer::displayBlur(const HostUI::Dispatcher* d)
{

}

