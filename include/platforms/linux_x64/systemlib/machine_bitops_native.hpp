///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/linux_x64/systemlib/machine_bitops_native.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Linux 64-bit Specific implementation of systemlib internals
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

#ifndef _EXNG2_SYSTEMLIB_BITOPS_NATIVE_HPP
# define _EXNG2_SYSTEMLIB_BITOPS_NATIVE_HPP

////////////////////////////////////////////////////////////////////////////////
//
//  Native bit operations
//
////////////////////////////////////////////////////////////////////////////////

namespace Machine {

  inline uint16 swap16(uint16 val)
  {
    if (__builtin_constant_p(val)) {
      val = val<<8|val>>8;
    } else {
      asm(
        "rorw $8, %w0"
        : "=d"(val)
        : "0"(val)
        : "cc"
      );
    }
    return val;
  }
  #define _EXNG2_MACHINE_HAS_SWAP16

  inline uint32 swap32(uint32 val)
  {
    if (__builtin_constant_p(val)) {
      val = val<<16 | val>>16;
      val = ((val&0x00FF00FF)<<8) | ((val&0xFF00FF00)>>8);
    } else {
      asm(
        "bswap %0"
        : "=d"(val)
        : "0"(val)
        : "cc"
      );
    }
    return val;
  }
  #define _EXNG2_MACHINE_HAS_SWAP32

  inline uint64 swap64(uint64 val)
  {
    if (__builtin_constant_p(val)) {
      return  (((val & 0xff00000000000000ull) >> 56)
            | ((val & 0x00ff000000000000ull) >> 40)
            | ((val & 0x0000ff0000000000ull) >> 24)
            | ((val & 0x000000ff00000000ull) >> 8)
            | ((val & 0x00000000ff000000ull) << 8)
            | ((val & 0x0000000000ff0000ull) << 24)
            | ((val & 0x000000000000ff00ull) << 40)
            | ((val & 0x00000000000000ffull) << 56));
    } else {
      asm(
        "bswap %q0"
        : "=d"(val)
        : "0"(val)
        : "cc"
      );
    }
    return val;
  }
  #define _EXNG2_MACHINE_HAS_SWAP64

};

#endif
