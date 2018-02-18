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
//                Karl Churchill, Serkan YAZICI
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _EXNG2_IOLIB_INPUT_DEVICES_HPP_
#	define _EXNG2_IOLIB_INPUT_DEVICES_HPP_

#	include <xbase.hpp>
#	include <systemlib/error.hpp>
#	include <systemlib/reflist.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  EventMask
//
//  Defines a simple flag based filtering system utilised by both Dispatchers and Observers
//
//  toggle/enable/disable return the xor'd flags that where affected. Hence, if no bits were changed, the return
//  will be zero.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class EventMask {
	DEFINE_MIN_RTTI
	private:
		uint32 mask;

	protected:
		uint32 getMaskBits()						const { return mask; }
		uint32 checkMaskBits(uint32 f)	const { return mask & f; }
		uint32 setMaskBits(uint32 f);
		uint32 toggleMaskBits(uint32 f);
		uint32 enableMaskBits(uint32 f);
		uint32 disableMaskBits(uint32 f);

	protected:
		EventMask(uint32 m) : mask(m) { }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Mouse
//
//  Specification for mouse based input device
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Mouse {
	public:
		// mouse button enumerations
		typedef enum {
			BUTTON_1		= 0x00000001,
			BUTTON_2		= 0x00000002,
			BUTTON_3		= 0x00000004,
			BUTTON_4		= 0x00000008,
			BUTTON_5		= 0x00000010,

			// common aliases
			LEFT				= BUTTON_1,
			CENTRE			= BUTTON_2,
			RIGHT				= BUTTON_3
		} Button;

		// mouse event filter types
		enum {
			// individual filters. Button filters match Button bitfield definition
			BUTTON_1_PRESS		= BUTTON_1,
			BUTTON_2_PRESS		= BUTTON_2,
			BUTTON_3_PRESS		= BUTTON_3,
			BUTTON_4_PRESS		= BUTTON_4,
			BUTTON_5_PRESS		= BUTTON_5,
			BUTTON_1_RELEASE	= (BUTTON_1<<5),
			BUTTON_2_RELEASE	= (BUTTON_2<<5),
			BUTTON_3_RELEASE	= (BUTTON_3<<5),
			BUTTON_4_RELEASE	= (BUTTON_4<<5),
			BUTTON_5_RELEASE	= (BUTTON_5<<5),
			MOVE							= 0x00010000,
			DRAG							= 0x00020000,
			SCROLL						= 0x00040000,

			// common aliases
			LEFT_PRESS				= BUTTON_1_PRESS,
			CENTRE_PRESS			= BUTTON_2_PRESS,
			RIGHT_PRESS				= BUTTON_3_PRESS,
			LEFT_RELEASE			= BUTTON_1_RELEASE,
			CENTRE_RELEASE		= BUTTON_2_RELEASE,
			RIGHT_RELEASE			= BUTTON_3_RELEASE,

			// compound filters
			PRESS						= BUTTON_1_PRESS|BUTTON_2_PRESS|BUTTON_3_PRESS|BUTTON_4_PRESS|BUTTON_5_PRESS,
			RELEASE					= BUTTON_1_RELEASE|BUTTON_2_RELEASE|BUTTON_3_RELEASE|BUTTON_4_RELEASE|BUTTON_5_RELEASE,
			ALL_EVENTS			= PRESS|RELEASE|MOVE|DRAG|SCROLL
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

class Mouse::Filter : protected EventMask {
	DEFINE_MIN_RTTI
	public:
		uint32	enableMouseEvents(uint32 mask);
		uint32	disableMouseEvents(uint32 mask);
		uint32	getEnabledMouseEvents()								const	{ return getMaskBits(); }
		uint32	checkEnabledMouseEvents(uint32 mask)	const	{ return checkMaskBits(mask); }
	protected:
		virtual	void applyMouseEventFilter(uint32 m) = 0;
		Filter(uint32 m) : EventMask(m) { }
};


class Mouse::Observer : public Mouse::Filter {
	DEFINE_MIN_RTTI
	private:
		static uint32 nextId;
		uint32 id;

	public:
		virtual void buttonPressed(const Mouse::Dispatcher* d, Mouse::Button b)																= 0;
		virtual void buttonReleased(const Mouse::Dispatcher* d, Mouse::Button b)															= 0;
		virtual void scroll(const Mouse::Dispatcher* d, sint16 dx, sint16 dy)																	= 0;
		virtual void move(const Mouse::Dispatcher* d, sint16 x, sint16 y, sint16 dx, sint16 dy)								= 0;
		virtual void drag(const Mouse::Dispatcher* d, sint16 x, sint16 y, sint16 dx, sint16 dy, uint32 keys)	= 0;

	protected:
		virtual void applyMouseEventFilter(uint32 mask);
		uint32 getId() const { return id; }

		Observer();
		Observer(uint32 mask);

	public:
		virtual ~Observer();
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Mouse::Dispatcher
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Mouse::Dispatcher : public Mouse::Filter {
	DEFINE_MIN_RTTI
	private:
		static uint32 nextId;
		RefList<Mouse::Observer> observers;
		uint32 id;

		// mouse state
		uint32	buttons;
		sint16	lastX, lastY;
		sint16	lastSX, lastSY;

	public:
		bool		addObserver(Mouse::Observer* o)							{ return observers.pushBack(o); }
		bool		removeObserver(Mouse::Observer* o)					{ return observers.remove(o);		}
		bool		hasObserver(Mouse::Observer* o)							{ return observers.contains(o); }

	protected:
		void		dispatchMouseMove(sint16 x, sint16 xMin, sint16 xMax, sint16 y, sint16 yMin, sint16 yMax);
		void		dispatchMouseKey(Mouse::Button button, bool state);
		void		dispatchMouseScroll(sint16 dx, sint16 dy);

		Dispatcher();
		Dispatcher(uint32 mask);

	public:
		virtual ~Dispatcher();
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Key
//
//  Specification for keyboard based input device
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Key {
	public:
		typedef enum {
			UNASSIGNABLE = 0,
			SPACE,
			BACKSP,
			TAB,
			ENTER,
			ESC,
			DEL,
			UP,
			DOWN,
			RIGHT,
			LEFT,
			F1,	F2,	F3,	F4,	F5,	F6,	F7,	F8,	F9,	F10, F11, F12,
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
			NON_PRINTABLE_PRESS			= 0x00000001,
			PRINTABLE_PRESS					= 0x00000002,
			NON_PRINTABLE_RELEASE		= 0x00000004,
			PRINTABLE_RELEASE				= 0x00000008,
			PRESS										= NON_PRINTABLE_PRESS|PRINTABLE_PRESS,
			RELEASE									= NON_PRINTABLE_RELEASE|PRINTABLE_RELEASE,
			ALL_EVENTS							= PRESS|RELEASE
		};

		// participants
		class Filter;
		class Observer;
		class Dispatcher;
};

class Key::Filter : protected EventMask {
	DEFINE_MIN_RTTI
	public:
		uint32	enableKeyEvents(uint32 mask);
		uint32	disableKeyEvents(uint32 mask);
		uint32	getEnabledKeyEvents()								const	{ return getMaskBits(); }
		uint32	checkEnabledKeyEvents(uint32 mask)	const	{ return checkMaskBits(mask); }
	protected:
		Filter(uint32 m) : EventMask(m) { }
		virtual void applyKeyEventFilter(uint32 mask) = 0;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Key::Observer
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Key::Observer : public Key::Filter {
	DEFINE_MIN_RTTI
	private:
		static uint32 nextId;
		uint32 id;
	public:
		virtual void nonPrintablePressed(const Key::Dispatcher* d, Key::CtrlKey code)		= 0;
		virtual void nonPrintableReleased(const Key::Dispatcher* d, Key::CtrlKey code)	= 0;
		virtual void printablePressed(const Key::Dispatcher* d, sint32 ch)							= 0;
		virtual void printableReleased(const Key::Dispatcher* d, sint32 ch)							= 0;

	protected:
		uint32 getId() const { return id; }
		virtual void applyKeyEventFilter(uint32 mask);
		Observer();
		Observer(uint32 mask);

	public:
		virtual ~Observer();
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Key::Dispatcher
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Key::Dispatcher : public Key::Filter {
	DEFINE_MIN_RTTI
	private:
		static uint32 nextId;
		RefList<Key::Observer> observers;
		uint32 id;

	public:
		bool		addObserver(Key::Observer* o)							{ return observers.pushBack(o); }
		bool		removeObserver(Key::Observer* o)					{ return observers.remove(o);		}
		bool		hasObserver(Key::Observer* o)							{ return observers.contains(o); }

	protected:
		void		dispatchKeyNonPrintable(Key::CtrlKey code, bool state);
		void		dispatchKeyPrintable(sint32 ch, bool state);

		Dispatcher();
		Dispatcher(uint32 mask);

	public:
		virtual ~Dispatcher();
};


#endif
