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

#ifndef _EXNG2_IOLIB_INPUT_MOUSE_HPP_
# define _EXNG2_IOLIB_INPUT_MOUSE_HPP_

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Mouse
//
//  Specification for mouse based input device
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class HID::Mouse {
  public:
    // mouse button enumerations
    typedef enum {
      BUTTON_1    = 0x00000001,
      BUTTON_2    = 0x00000002,
      BUTTON_3    = 0x00000004,
      BUTTON_4    = 0x00000008,
      BUTTON_5    = 0x00000010,

      // common aliases
      LEFT        = BUTTON_1,
      CENTRE      = BUTTON_2,
      RIGHT       = BUTTON_3
    } Button;

    // mouse event filter types
    enum {
      NO_EVENTS         = 0,

      // individual filters. Button filters match Button bitfield definition
      BUTTON_1_PRESS    = BUTTON_1,
      BUTTON_2_PRESS    = BUTTON_2,
      BUTTON_3_PRESS    = BUTTON_3,
      BUTTON_4_PRESS    = BUTTON_4,
      BUTTON_5_PRESS    = BUTTON_5,
      BUTTON_1_RELEASE  = (BUTTON_1<<5),
      BUTTON_2_RELEASE  = (BUTTON_2<<5),
      BUTTON_3_RELEASE  = (BUTTON_3<<5),
      BUTTON_4_RELEASE  = (BUTTON_4<<5),
      BUTTON_5_RELEASE  = (BUTTON_5<<5),
      MOVE              = 0x00010000,
      DRAG              = 0x00020000,
      SCROLL            = 0x00040000,


      // common aliases
      LEFT_PRESS        = BUTTON_1_PRESS,
      CENTRE_PRESS      = BUTTON_2_PRESS,
      RIGHT_PRESS       = BUTTON_3_PRESS,
      LEFT_RELEASE      = BUTTON_1_RELEASE,
      CENTRE_RELEASE    = BUTTON_2_RELEASE,
      RIGHT_RELEASE     = BUTTON_3_RELEASE,

      // compound filters
      PRESS             = BUTTON_1_PRESS|BUTTON_2_PRESS|BUTTON_3_PRESS|BUTTON_4_PRESS|BUTTON_5_PRESS,
      RELEASE           = BUTTON_1_RELEASE|BUTTON_2_RELEASE|BUTTON_3_RELEASE|BUTTON_4_RELEASE|BUTTON_5_RELEASE,
      BUTTONS           = PRESS|RELEASE,
      MOVEMENT          = MOVE|DRAG,
      ALL_EVENTS        = PRESS|RELEASE|MOVE|DRAG|SCROLL
    };

    // participants
    class Filter;
    class Observer;
    class Dispatcher;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Mouse::Observer
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class HID::Mouse::Filter : protected EventMask {
  DEFINE_MIN_RTTI
  public:
    uint32  enableMouseEvents(uint32 mask);
    uint32  disableMouseEvents(uint32 mask);
    uint32  getEnabledMouseEvents()               const { return getMaskBits(); }
    uint32  checkEnabledMouseEvents(uint32 mask)  const { return checkMaskBits(mask); }
  protected:
    virtual void applyMouseEventFilter(uint32 m) = 0;
    Filter(uint32 m) : EventMask(m) { }
};


class HID::Mouse::Observer : public Mouse::Filter {
  DEFINE_MIN_RTTI
  private:
    static uint32 nextId;
    uint32 id;

  public:
    virtual void buttonPressed(const Mouse::Dispatcher* d, Mouse::Button b)                               = 0;
    virtual void buttonReleased(const Mouse::Dispatcher* d, Mouse::Button b)                              = 0;
    virtual void scroll(const Mouse::Dispatcher* d, sint16 dx, sint16 dy)                                 = 0;
    virtual void move(const Mouse::Dispatcher* d, sint16 x, sint16 y, sint16 dx, sint16 dy, uint32)       = 0;
    virtual void drag(const Mouse::Dispatcher* d, sint16 x, sint16 y, sint16 dx, sint16 dy, uint32 keys)  = 0;

  protected:
    virtual void applyMouseEventFilter(uint32 mask);
    uint32 getId() const { return id; }

    Observer(uint32 mask=Mouse::ALL_EVENTS);

  public:
    virtual ~Observer();
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Mouse::Dispatcher
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class HID::Mouse::Dispatcher : public Mouse::Filter {
  DEFINE_MIN_RTTI
  private:
    static uint32 nextId;
    RefList<Mouse::Observer> observers;
    uint32 id;

    // mouse state
    uint32  buttons;
    sint16  lastX, lastY;
    sint16  lastSX, lastSY;

  public:
    enum {
      // additional filters for dispatcher only
      MOVE_LIMIT_LEFT   = 0x00100000,
      MOVE_LIMIT_RIGHT  = 0x00200000,
      MOVE_LIMIT_TOP    = 0x00400000,
      MOVE_LIMIT_BOTTOM = 0x00800000,
      MOVE_LIMIT_HORIZ  = MOVE_LIMIT_LEFT|MOVE_LIMIT_RIGHT,
      MOVE_LIMIT_VERT   = MOVE_LIMIT_TOP|MOVE_LIMIT_BOTTOM,
      MOVE_LIMIT_ALL    = MOVE_LIMIT_HORIZ|MOVE_LIMIT_VERT,
    };
    void    addMouseObserver(Mouse::Observer* o)            { observers.pushBack(o); }
    bool    removeMouseObserver(Mouse::Observer* o)         { return observers.remove(o);   }
    bool    hasMouseObserver(Mouse::Observer* o)            { return observers.contains(o); }

  protected:
    void    dispatchMouseMove(sint16 x, sint16 xMin, sint16 xMax, sint16 y, sint16 yMin, sint16 yMax);
    void    dispatchMouseKey(Mouse::Button button, bool state);
    void    dispatchMouseScroll(sint16 dx, sint16 dy);

    Dispatcher(uint32 mask=Mouse::ALL_EVENTS);

  public:
    virtual ~Dispatcher();
};

#endif
