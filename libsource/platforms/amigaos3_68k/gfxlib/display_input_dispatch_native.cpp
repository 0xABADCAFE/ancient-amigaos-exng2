///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/amigaos3_68k/gfxlib/display_native.hpp
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
#include <systemlib/logger.hpp>
#include <cstring>

namespace OSNative {
  extern "C" {
#   include <proto/graphics.h>
#   include <proto/cybergraphics.h>
#   include <clib/alib_protos.h>
#   include <proto/keymap.h>
#   include <proto/dos.h>
  }
}

using namespace EXNGPrivate;
using namespace OSNative;

namespace {
  // helper code for intuition -> HID::Key::Dispatcher stuff
/*
  0x00,  //   UNASSIGNABLE = 0,
  0x41,  //   BACKSP,
  0x42,  //   TAB,
  0x44,  //   ENTER,
  0x45,  //   ESC,
  0x46,  //   DEL,
  0x4C,  //   UP,
  0x4D,  //   DOWN,
  0x4E,  //   RIGHT,
  0x4F,  //   LEFT,
  0x50,  //   F1,
  0x51,  //   F2,
  0x52,  //   F3,
  0x53,  //   F4,
  0x54,  //   F5,
  0x55,  //   F6,
  0x56,  //   F7,
  0x57,  //   F8,
  0x58,  //   F9,
  0x59,  //   F10,
  0x66,  //   F11,
  0x67,  //   F12,
  0x60,  //   SHIFTL,
  0x61,  //   SHIFTR,
  0x62,  //   CAPSL,
  0x63,  //   CTRL,
  0x64,  //   ALTL,
  0x65,  //   ALTR,
  0x0F,  //   NP_0,
  0x1D,  //   NP_1,
  0x1E,  //   NP_2,
  0x1F,  //   NP_3,
  0x2D,  //   NP_4,
  0x2E,  //   NP_5,
  0x2F,  //   NP_6,
  0x3D,  //   NP_7,
  0x3E,  //   NP_8,
  0x3F,  //   NP_9,
  0x00,  //   NP_INS,
  0x00,  //   NP_END,
  0x46,  //   NP_DEL,
  0x3C,  //   NP_PNT,
  0x43,  //   NP_ENT,
  0x4A,  //   NP_MINUS,
  0x5E,  //   NP_PLUS,
*/
  uint8 nonPrinting[] = {
    HID::Key::NP_0,      0x0F,
    HID::Key::NP_1,      0x1D,
    HID::Key::NP_2,      0x1E,
    HID::Key::NP_3,      0x1F,
    HID::Key::NP_4,      0x2D,
    HID::Key::NP_5,      0x2E,
    HID::Key::NP_6,      0x2F,
    HID::Key::NP_PNT,    0x3C,
    HID::Key::NP_7,      0x3D,
    HID::Key::NP_8,      0x3E,
    HID::Key::NP_9,      0x3F,
    HID::Key::BACKSP,    0x41,
    HID::Key::TAB,       0x42,
    HID::Key::NP_ENT,    0x43,
    HID::Key::ENTER,     0x44,
    HID::Key::ESC,       0x45,
    HID::Key::DEL,       0x46,
    HID::Key::NP_MINUS,  0x4A,
    HID::Key::UP,        0x4C,
    HID::Key::DOWN,      0x4D,
    HID::Key::RIGHT,     0x4E,
    HID::Key::LEFT,      0x4F,
    HID::Key::F1,        0x50,
    HID::Key::F2,        0x51,
    HID::Key::F3,        0x52,
    HID::Key::F4,        0x53,
    HID::Key::F5,        0x54,
    HID::Key::F6,        0x55,
    HID::Key::F7,        0x56,
    HID::Key::F8,        0x57,
    HID::Key::F9,        0x58,
    HID::Key::F10,       0x59,
    HID::Key::NP_PLUS,   0x5E,
    HID::Key::SHIFTL,    0x60,
    HID::Key::SHIFTR,    0x61,
    HID::Key::CAPSL,     0x62,
    HID::Key::CTRL,      0x63,
    HID::Key::ALTL,      0x64,
    HID::Key::ALTR,      0x65,
    HID::Key::F11,       0x66,
    HID::Key::F12,       0x67
  };

  int         openCount   = 0;
  uint8*      nonPrintMap = 0;
  const char* keyMapLib   = "keymap.library";


  sint32 mapCharacter(IntuiMessage* m)
  {
    //SystemLog::write(SystemLog::INFO, "IntuiMessage->Code = %d\n", (int)m->Code);

    uint32 rawCode = m->Code & 0x7F;

    if (rawCode > 0x40) {
      return 0;
    }
    else {
      InputEvent  inputEvent = {
        0,
        IECLASS_RAWKEY,
        0,
        rawCode,
        m->Qualifier,
        0,
        0,
        { 0, 0 }
      };
      inputEvent.ie_EventAddress = *((uint8**)(m->IAddress));
      char mapped[2] = "";
      MapRawKey(&inputEvent, mapped, 2, 0);
      return (sint32)mapped[0];
    }
  }
};

Library*  KeyMapBase = 0;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Input handling resources
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void OSDisplay::initDispatcher()
{
  LOGGING_DECLARE_FUNCNAME(initDispatcher)

  if (!openCount) {
    if ( !(KeyMapBase = OpenLibrary(keyMapLib, 37)) ) {
      THROW_NSX(Error, ResourceUnavailable(keyMapLib));
    }
    nonPrintMap = Mem::alloc<uint8>(128);
    Mem::set(nonPrintMap, HID::Key::UNASSIGNABLE, 128);
    for (int i=0; i<sizeof(nonPrinting); i+=2) {
      nonPrintMap[nonPrinting[i+1]] = nonPrinting[i];
    }

    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::WARNING, "%s::%s - initialised, nonPrintMap at %p\n",
      loggingClassName, loggingFuncName, nonPrintMap
    );
    #endif
  }
  ++openCount;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void OSDisplay::finalizeDispatcher()
{
  if (--openCount == 0) {
    if (nonPrintMap) {
      Mem::free(nonPrintMap);
      nonPrintMap = 0;
    }
    if (KeyMapBase) {
      CloseLibrary(KeyMapBase);
      KeyMapBase = 0;
    }
  }
  else if (openCount<0) {
    openCount = 0;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    typedef enum {
      WAKE_TIMEOUT  = 0,  // sleep ended normally
      WAKE_WAKE     = 1,  // sleep interrupted by wake call
      WAKE_STOP     = 2,  // sleep interrupted by stop call
      WAKE_SHUTDOWN = 3,  // sleep interrupted by thread termination (destructor invoked)
      WAKE_SYSBREAK = 4,  // sleep interrupted by system break
      WAKE_USER     = 5,  // sleep interrupted by user defined event
      WAKE_DISPOSED = 6,  // returned when sleep request is disposed
      WAKE_UNKNOWN  = 7   // sleep interrupted by unknown source
    } WakeEvent;
*/
Thread::WakeEvent OSDisplay::awaitInputEvents()
{
  uint32 eventSignal = 1UL<<window->UserPort->mp_SigBit;
  uint32 gotSignals  = Wait(eventSignal|SIGBREAKF_CTRL_C);

  if (gotSignals & eventSignal) {
    return Thread::WAKE_TIMEOUT;
  }
  if (gotSignals & SIGBREAKF_CTRL_C) {
    return Thread::WAKE_SYSBREAK;
  }
  return Thread::WAKE_UNKNOWN;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// bool OSDisplay::inputQueued()
// {
//   return false;
// }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void OSDisplay::dispatchQueuedInput(const GfxArea* area)
{
  union {
    Message* msg;
    IntuiMessage* iMsg;
  };
  sint32 ch = 0;


  while ( (msg = GetMsg(window->UserPort)) ) {
    switch (iMsg->Class) {
      case IDCMP_RAWKEY:
        if ( (ch = mapCharacter(iMsg)) ) {
          dispatchKeyPrintable(
            ch,
            ((iMsg->Code & 0x80UL)==0)
          );
        }
        else {
          dispatchKeyNonPrintable(
            (HID::Key::CtrlKey) nonPrintMap[(iMsg->Code & 0x7FUL)],
            ((iMsg->Code & 0x80UL)==0)
          );
        }
        break;

      case IDCMP_MOUSEBUTTONS:
        switch(iMsg->Code) {
          case SELECTDOWN:  dispatchMouseKey(HID::Mouse::LEFT, true);    break;
          case MIDDLEDOWN:  dispatchMouseKey(HID::Mouse::CENTRE, true);  break;
          case MENUDOWN:    dispatchMouseKey(HID::Mouse::RIGHT, true);   break;
          case SELECTUP:    dispatchMouseKey(HID::Mouse::LEFT, false);   break;
          case MIDDLEUP:    dispatchMouseKey(HID::Mouse::CENTRE, false); break;
          case MENUUP:      dispatchMouseKey(HID::Mouse::RIGHT, false);  break;
        }
        break;

      case IDCMP_MOUSEMOVE:
        dispatchMouseMove(
          iMsg->MouseX-window->BorderLeft, 0, area->getWidth()-1,
          iMsg->MouseY-window->BorderTop,  0, area->getHeight()-1
        );
        break;

      case IDCMP_ACTIVEWINDOW:
        dispatchFocus();
        break;

      case IDCMP_INACTIVEWINDOW:
        dispatchBlur();
        break;

      case IDCMP_CLOSEWINDOW:
        dispatchClosed();
        break;

      default:
        break;
    }
    ReplyMsg(msg);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void OSDisplay::discardEventQueue()
{
  Message* msg;
  while ( (msg = GetMsg(window->UserPort)) ) {
    ReplyMsg(msg);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void OSDisplay::applyEventFilters(uint32 disp, uint32 key, uint32 mouse)
{
  if (window) {
    uint32 winIDCMPFlags  =   (disp & HostUI::HUI_CLOSE)  ? IDCMP_CLOSEWINDOW     : 0;
    winIDCMPFlags         |=  (disp & HostUI::HUI_FOCUS)  ? IDCMP_ACTIVEWINDOW    : 0;
    winIDCMPFlags         |=  (disp & HostUI::HUI_BLUR)   ? IDCMP_INACTIVEWINDOW  : 0;
    winIDCMPFlags         |=  (mouse & HID::Mouse::BUTTONS)    ? IDCMP_MOUSEBUTTONS    : 0;
    winIDCMPFlags         |=  (mouse & HID::Mouse::MOVEMENT)   ? IDCMP_MOUSEMOVE       : 0;
    winIDCMPFlags         |=  (key & HID::Key::ALL_EVENTS)     ? IDCMP_RAWKEY          : 0;
    SystemLog::write(
      SystemLog::INFO,
      "HostUI::0x%08X, HID::Key::0x%08X, HID::Mouse::0x%08X -> IDCMP 0x%08X\n",
      (unsigned)disp,
      (unsigned)key,
      (unsigned)mouse,
      (unsigned)winIDCMPFlags
    );
    ModifyIDCMP(window, winIDCMPFlags);
    SetMouseQueue(window, 4);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void OSDisplay::applyDisplayEventFilter(uint32 mask)
{
  applyEventFilters(mask, getEnabledKeyEvents(), getEnabledMouseEvents());
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void OSDisplay::applyMouseEventFilter(uint32 mask)
{
  applyEventFilters(getEnabledDisplayEvents(), getEnabledKeyEvents(), mask);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void OSDisplay::applyKeyEventFilter(uint32 mask)
{
  applyEventFilters(getEnabledDisplayEvents(), mask, getEnabledMouseEvents());
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

