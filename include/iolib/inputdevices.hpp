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

#ifndef _EXNG2_IOLIB_INPUT_DEVICES_HPP_
# define _EXNG2_IOLIB_INPUT_DEVICES_HPP_

# include <xbase.hpp>
# include <systemlib/error.hpp>
# include <utilitylib/referencelist.hpp>

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

namespace HID {

  class EventMask {
    DEFINE_MIN_RTTI
    private:
      uint32 mask;

    protected:
      uint32 getMaskBits()            const { return mask; }
      uint32 checkMaskBits(uint32 f)  const { return mask & f; }
      uint32 setMaskBits(uint32 f);
      uint32 toggleMaskBits(uint32 f);
      uint32 enableMaskBits(uint32 f);
      uint32 disableMaskBits(uint32 f);

    protected:
      EventMask(uint32 m) : mask(m) { }
  };

  class Key;
  class Mouse;
}

#include <iolib/inputmouse.hpp>
#include <iolib/inputkeyboard.hpp>
#include <iolib/inputdevices_native.hpp>


#endif
