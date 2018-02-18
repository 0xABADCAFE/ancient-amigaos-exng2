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
//                Karl Churchill, Serkan YAZICI
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

uint32 EventMask::toggleMaskBits(uint32 f)
{
	uint32 oldMask = mask;
	mask ^= f;
	return mask^oldMask;
}

uint32 EventMask::enableMaskBits(uint32 f)
{
	uint32 oldMask = mask;
	mask |= f;
	return mask^oldMask;
}

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

Mouse::Observer::Observer() : Mouse::Filter(Mouse::ALL_EVENTS)
{
	id = nextId++;
}

Mouse::Observer::Observer(uint32 mask) : Mouse::Filter((mask & Mouse::ALL_EVENTS))
{
	id = nextId++;
}

Mouse::Observer::~Observer()
{

}

void Mouse::Observer::applyMouseEventFilter(uint32 mask)
{

}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Key::Observer
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 Key::Observer::nextId = 0;

Key::Observer::Observer() : Key::Filter(Key::ALL_EVENTS)
{
	id = nextId++;
}

Key::Observer::Observer(uint32 mask) : Key::Filter((mask & Key::ALL_EVENTS))
{
	id = nextId++;
}

Key::Observer::~Observer()
{

}

void Key::Observer::applyKeyEventFilter(uint32 m)
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Mouse::Dispatcher
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 Mouse::Dispatcher::nextId = 0;

Mouse::Dispatcher::Dispatcher() :
Mouse::Filter(Mouse::ALL_EVENTS), observers(),
buttons(0), lastX(0), lastY(0), lastSX(0), lastSY(0)
{
	id = nextId++;
}

Mouse::Dispatcher::Dispatcher(uint32 mask) :
Mouse::Filter((mask & Mouse::ALL_EVENTS)), observers(),
buttons(0), lastX(0), lastY(0), lastSX(0), lastSY(0)
{
	id = nextId++;
}

Mouse::Dispatcher::~Dispatcher()
{

}

void Mouse::Dispatcher::dispatchMouseKey(Mouse::Button button, bool state)
{
	if (state) {
		// update button states regardless of dispatch
		buttons |= button;

		// pressed - check we are dispatching BUTTON_x_PRESSED and if so, iterate the observers
		// checking each one that is observing BUTTON_x_PRESSED and updating them accordingly.
		if (checkEnabledMouseEvents(button)) {
			RefListFwdIterator<Mouse::Observer> itor(observers);
			for (Mouse::Observer* p = itor.first(); p; p = itor.next()) {
				if (p->checkEnabledMouseEvents(button)) {
					p->buttonPressed(this, button);
				}
			}
		}
	}
	else {
		// update button states regardless of dispatch
		buttons &= ~button;

		// released
		uint32 event = button<<5;
		if (checkEnabledMouseEvents(event)) {
			RefListFwdIterator<Mouse::Observer> itor(observers);
			for (Mouse::Observer* p = itor.first(); p; p = itor.next()) {
				if (p->checkEnabledMouseEvents(event)) {
					p->buttonReleased(this, button);
				}
			}
		}
	}
}

void Mouse::Dispatcher::dispatchMouseMove(sint16 x, sint16 xMin, sint16 xMax, sint16 y, sint16 yMin, sint16 yMax)
{
	// update the internal cursor states regardless of filtering
	sint16 dx = x-lastX;
	sint16 dy = y-lastY;
	lastX = x;
	lastY = y;
	if (buttons) {
		// buttons are pressed, dragging context
		if (checkEnabledMouseEvents(Mouse::DRAG)) {
			RefListFwdIterator<Mouse::Observer> itor(observers);
			for (Mouse::Observer* p = itor.first(); p; p = itor.next()) {
				if (p->checkEnabledMouseEvents(Mouse::DRAG)) {
					p->drag(this, x, y, dx, dy, buttons);
				}
			}
		}
	}
	else {
		// normal movement
		if (checkEnabledMouseEvents(Mouse::MOVE)) {
			RefListFwdIterator<Mouse::Observer> itor(observers);
			for (Mouse::Observer* p = itor.first(); p; p = itor.next()) {
				if (p->checkEnabledMouseEvents(Mouse::MOVE)) {
					p->move(this, x, y, dx, dy);
				}
			}
		}
	}
}

void Mouse::Dispatcher::dispatchMouseScroll(sint16 dx, sint16 dy)
{
	if (checkEnabledMouseEvents(Mouse::SCROLL)) {
		RefListFwdIterator<Mouse::Observer> itor(observers);
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


Key::Dispatcher::Dispatcher() : Key::Filter(Key::ALL_EVENTS), observers()
{

}

Key::Dispatcher::Dispatcher(uint32 mask) : Key::Filter((mask & Key::ALL_EVENTS)), observers()
{

}

Key::Dispatcher::~Dispatcher()
{

}

void Key::Dispatcher::dispatchKeyNonPrintable(Key::CtrlKey key, bool state)
{
	if (state) {
		if (checkEnabledKeyEvents(Key::NON_PRINTABLE_PRESS)) {
			RefListFwdIterator<Key::Observer> itor(observers);
			for (Key::Observer* p = itor.first(); p; p = itor.next()) {
				if (p->checkEnabledKeyEvents(Key::NON_PRINTABLE_PRESS)) {
					p->nonPrintablePressed(this, key);
				}
			}
		}
	}
	else {
		if (checkEnabledKeyEvents(Key::NON_PRINTABLE_RELEASE)) {
			RefListFwdIterator<Key::Observer> itor(observers);
			for (Key::Observer* p = itor.first(); p; p = itor.next()) {
				if (p->checkEnabledKeyEvents(Key::NON_PRINTABLE_RELEASE)) {
					p->nonPrintableReleased(this, key);
				}
			}
		}
	}
}

void Key::Dispatcher::dispatchKeyPrintable(sint32 ch, bool state)
{
	if (state) {
		if (checkEnabledKeyEvents(Key::PRINTABLE_PRESS)) {
			RefListFwdIterator<Key::Observer> itor(observers);
			for (Key::Observer* p = itor.first(); p; p = itor.next()) {
				if (p->checkEnabledKeyEvents(Key::PRINTABLE_PRESS)) {
					p->printablePressed(this, ch);
				}
			}
		}
	}
	else {
		if (checkEnabledKeyEvents(Key::PRINTABLE_RELEASE)) {
			RefListFwdIterator<Key::Observer> itor(observers);
			for (Key::Observer* p = itor.first(); p; p = itor.next()) {
				if (p->checkEnabledKeyEvents(Key::PRINTABLE_RELEASE)) {
					p->printableReleased(this, ch);
				}
			}
		}
	}
}

