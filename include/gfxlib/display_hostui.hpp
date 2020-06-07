///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         gfxlib/display.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Display classes
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

#ifndef _EXNG2_GFXLIB_DISPLAY_HOST_UI_HPP_
# define _EXNG2_GFXLIB_DISPLAY_HOST_UI_HPP_

namespace HostUI {
  class Filter;
  class Observer;
  class Dispatcher;

  enum {
    NO_EVENTS     = 0,
    HUI_CLOSE     = 0x00000001,
    HUI_MOVE      = 0x00000002,
    HUI_RESIZE    = 0x00000004,
    HUI_MINIMIZE  = 0x00000008,
    HUI_FOCUS     = 0x00000010,
    HUI_BLUR      = 0x00000020,
    ALL_EVENTS    = 0x0000003F
  };
};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Display::Filter
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class HostUI::Filter : protected HID::EventMask {
  DEFINE_MIN_RTTI
  public:
    uint32  enableDisplayEvents(uint32 mask);
    uint32  disableDisplayEvents(uint32 mask);
    uint32  getEnabledDisplayEvents()               const { return getMaskBits(); }
    uint32  checkEnabledDisplayEvents(uint32 mask)  const { return checkMaskBits(mask); }
  protected:
    Filter(uint32 m) : EventMask(m) { }
    virtual void applyDisplayEventFilter(uint32 mask) = 0;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Display::Observer
//
//  Intersection of Key and Mouse Observers with additional methods for display specific events
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class HostUI::Observer : public HostUI::Filter, public HID::Key::Observer, public HID::Mouse::Observer {
  DEFINE_MIN_RTTI
  private:
    static uint32 nextId;
    uint32 id;
  public:
    // HID::Key::Observer
    void nonPrintablePressed(const HID::Key::Dispatcher* d, HID::Key::CtrlKey code);
    void nonPrintableReleased(const HID::Key::Dispatcher* d, HID::Key::CtrlKey code);
    void printablePressed(const HID::Key::Dispatcher* d, sint32 ch);
    void printableReleased(const HID::Key::Dispatcher* d, sint32 ch);

    // HID::Mouse::Observer
    void buttonPressed(const HID::Mouse::Dispatcher* d, HID::Mouse::Button b);
    void buttonReleased(const HID::Mouse::Dispatcher* d, HID::Mouse::Button b);
    void scroll(const HID::Mouse::Dispatcher* d, sint16 dx, sint16 dy);
    void move(const HID::Mouse::Dispatcher* d, sint16 x, sint16 y, sint16 dx, sint16 dy, uint32);
    void drag(const HID::Mouse::Dispatcher* d, sint16 x, sint16 y, sint16 dx, sint16 dy, uint32 keys);

    virtual void displayClosed(const HostUI::Dispatcher* d);
    virtual void displayMoved(const HostUI::Dispatcher* d);
    virtual void displayResized(const HostUI::Dispatcher* d);
    virtual void displayMinimized(const HostUI::Dispatcher* d);
    virtual void displayFocus(const HostUI::Dispatcher* d);
    virtual void displayBlur(const HostUI::Dispatcher* d);
  protected:
    uint32 getId() const { return id; }
/*
    virtual void applyKeyEventFilter(uint32 mask);
    virtual void applyMouseEventFilter(uint32 mask);
*/
    virtual void applyDisplayEventFilter(uint32 mask);
    Observer(uint32 mask, uint32 keyMask, uint32 mouseMask);

  public:
    virtual ~Observer();
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Display::Dispatcher
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class HostUI::Dispatcher : public HostUI::Filter, public HID::Key::Dispatcher, public HID::Mouse::Dispatcher {
  DEFINE_MIN_RTTI
  private:
    static uint32 nextId;
    RefList<HostUI::Observer> observers;
    uint32 id;

  public:

//     HID::Key::Dispatcher
//     void    addKeyObserver(HID::Key::Observer* o)
//     bool    removeKeyObserver(HID::Key::Observer* o)
//     bool    hasKeyObserver(HID::Key::Observer* o)
//
//     HID::Mouse::Dispatcher
//     void    addMouseObserver(HID::Mouse::Observer* o)
//     bool    removeMouseObserver(HID::Mouse::Observer* o)
//     bool    hasMouseObserver(HID::Mouse::Observer* o)

    void    addHostUIObserver(HostUI::Observer* o);
    bool    removeHostUIObserver(HostUI::Observer* o);
    bool    hasHostUIObserver(HostUI::Observer* o)           { return observers.contains(o); }

  protected:

//     HID::Key::Dispatcher
//     void    dispatchKeyNonPrintable(HID::Key::CtrlKey code, bool state);
//     void    dispatchKeyPrintable(sint32 ch, bool state);
//
//     HID::Mouse::Dispatcher
//     void    dispatchMouseMove(sint16 x, sint16 xMin, sint16 xMax, sint16 y, sint16 yMin, sint16 yMax);
//     void    dispatchMouseKey(HID::Mouse::Button button, bool state);
//     void    dispatchMouseScroll(sint16 dx, sint16 dy);

    void    dispatchClosed();
    void    dispatchMoved();
    void    dispatchResized();
    void    dispatchMinimized();
    void    dispatchFocus();
    void    dispatchBlur();

    Dispatcher(uint32 mask=HostUI::NO_EVENTS, uint32 keyMask=HID::Key::ALL_EVENTS, uint32 mouseMask=HID::Mouse::NO_EVENTS);

  public:
    virtual ~Dispatcher();
};

#endif