///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         iolib/input.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Input devices
//  Comment(s):
//  Library:      IO
//  Created:      2007-05-13
//  Updated:      2007-05-13
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _EXNG2_IOLIB_INPUT_KEYBOARD_HPP_
# define _EXNG2_IOLIB_INPUT_KEYBOARD_HPP_

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Key
//
//  Specification for keyboard based input device
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class HID::Key {
  public:
    typedef enum {
      UNASSIGNABLE = 0,
      BACKSP,
      TAB,
      ENTER,
      ESC,
      DEL,
      UP,
      DOWN,
      RIGHT,
      LEFT,
      F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
      SHIFTL, SHIFTR,
      CAPSL,
      CTRL,
      ALTL, ALTR,
      NP_0, NP_1, NP_2, NP_3, NP_4, NP_5, NP_6, NP_7, NP_8, NP_9,
      NP_INS,
      NP_END,
      NP_DEL,
      NP_PNT,
      NP_ENT,
      NP_MINUS,
      NP_PLUS,
      NUM_NPKEYS
    } CtrlKey;

    // keyboard event filters
    enum {
      NO_EVENTS               = 0,
      NON_PRINTABLE_PRESS     = 0x00000001,
      PRINTABLE_PRESS         = 0x00000002,
      NON_PRINTABLE_RELEASE   = 0x00000004,
      PRINTABLE_RELEASE       = 0x00000008,
      PRESS                   = NON_PRINTABLE_PRESS|PRINTABLE_PRESS,
      RELEASE                 = NON_PRINTABLE_RELEASE|PRINTABLE_RELEASE,
      ALL_EVENTS              = PRESS|RELEASE
    };

    // participants
    class Filter;
    class Observer;
    class Dispatcher;
};

class HID::Key::Filter : protected EventMask {
  DEFINE_MIN_RTTI
  public:
    uint32  enableKeyEvents(uint32 mask);
    uint32  disableKeyEvents(uint32 mask);
    uint32  getEnabledKeyEvents()               const { return getMaskBits(); }
    uint32  checkEnabledKeyEvents(uint32 mask)  const { return checkMaskBits(mask); }
  protected:
    Filter(uint32 m) : EventMask(m) { }
    virtual void applyKeyEventFilter(uint32 mask) = 0;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Key::Observer
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class HID::Key::Observer : public Key::Filter {
  DEFINE_MIN_RTTI
  private:
    static uint32 nextId;
    uint32 id;
  public:
    virtual void nonPrintablePressed(const Key::Dispatcher* d, Key::CtrlKey code)   = 0;
    virtual void nonPrintableReleased(const Key::Dispatcher* d, Key::CtrlKey code)  = 0;
    virtual void printablePressed(const Key::Dispatcher* d, sint32 ch)              = 0;
    virtual void printableReleased(const Key::Dispatcher* d, sint32 ch)             = 0;

  protected:
    uint32 getId() const { return id; }
    virtual void applyKeyEventFilter(uint32 mask);
    Observer(uint32 mask=Key::ALL_EVENTS);

  public:
    virtual ~Observer();
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Key::Dispatcher
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class HID::Key::Dispatcher : public Key::Filter {
  DEFINE_MIN_RTTI
  private:
    static uint32 nextId;
    RefList<Key::Observer> observers;
    uint32 id;

  public:
    void    addKeyObserver(Key::Observer* o)            { observers.pushBack(o); }
    bool    removeKeyObserver(Key::Observer* o)         { return observers.remove(o);   }
    bool    hasKeyObserver(Key::Observer* o)            { return observers.contains(o); }

  protected:
    void    dispatchKeyNonPrintable(Key::CtrlKey code, bool state);
    void    dispatchKeyPrintable(sint32 ch, bool state);

    Dispatcher(uint32 mask=Key::ALL_EVENTS);

  public:
    virtual ~Dispatcher();
};

#endif
