///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/linux_noarch/systemlib/machine_native.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:
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


#ifndef _EXNG2_SYSTEMLIB_MACHINE_NATIVE_HPP_
# define _EXNG2_SYSTEMLIB_MACHINE_NATIVE_HPP_

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Machine
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Machine {

#ifndef _EXNG2_MACHINE_HAS_SWAP16
  inline uint16 swap16(uint16 val)
  {
    return val>>8|val<<8;
  }
#endif

#ifndef _EXNG2_MACHINE_HAS_SWAP32
  inline uint32 swap32(uint32 val)
  {
    val = val<<16 | val>>16;
    return ((val&0x00FF00FF)<<8) | ((val&0xFF00FF00)>>8);
  }
#endif

#ifndef _EXNG2_MACHINE_HAS_SWAP64
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
    }
    else {
      union { uint64 u64; uint32 u32[2]; };
      u64 = val;
      uint32 msw  = swap32(u32[0]);
      u32[0]      = swap32(u32[1]);
      u32[1]      = msw;
      return u64;
    }
  }
#endif

  // runtime known rotate

#ifndef _EXNG2_MACHINE_HAS_ROL8
  inline uint8  rotLeft8(uint32 bits, uint8 val)
  {
    bits &= 7;
    return val<<bits | val>>(8-bits);
  }
#endif

#ifndef _EXNG2_MACHINE_HAS_ROL16
  inline uint16 rotLeft16(uint32 bits, uint16 val)
  {
    bits &= 15;
    return val<<bits | val>>(16-bits);
  }
#endif

#ifndef _EXNG2_MACHINE_HAS_ROL32
  inline uint32 rotLeft32(uint32 bits, uint32 val)
  {
    bits &= 31;
    return val<<bits | val>>(32-bits);
  }
#endif

#ifndef _EXNG2_MACHINE_HAS_ROR8
  inline uint8  rotRight8(uint32 bits, uint8 val)
  {
    bits &= 7;
    return val>>bits | val<<(8-bits);
  }
#endif

#ifndef _EXNG2_MACHINE_HAS_ROR16
  inline uint16 rotRight16(uint32 bits, uint16 val)
  {
    bits &= 15;
    return val>>bits | val<<(16-bits);
  }
#endif

#ifndef _EXNG2_MACHINE_HAS_ROR32
  inline uint32 rotRight32(uint32 bits, uint32 val)
  {
    bits &= 31;
    return val>>bits | val<<(32-bits);
  }
#endif


#ifndef _EXNG2_MACHINE_HAS_BFFFO
  inline sint32 mostSigBit32(uint32 val)
  {
    sint32 i = 31;
    do {
      if (val&(1<<i)) {
        break;
      }
      --i;
    } while (i>=0);
    return i;
  }
#endif
}


#endif
