///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/amigaos3_68k/systemlib/machine_bitops_native.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  AmigaOS Specific implementation of systemlib internals
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

  template<typename T>
  inline T _rotLeft8(uint32 bits, T val)
  {
    if (__builtin_constant_p(bits)) {
      if (bits&7) {
        asm("rol.b %1, %0" : "=d"(val) : "I"(bits&7), "0"(val) : "cc");
      }
    } else {
      asm("rol.b %1, %0" : "=d"(val) : "d"(bits), "0"(val) : "cc");
    }
    return val;
  }

  template<typename T>
  inline T _rotLeft16(uint32 bits, T val)
  {
    if (__builtin_constant_p(bits)) {
      if (bits&15) {
        // only rotate when modulus 16 > 0
        if ((bits&15) < 9) {
          asm("rol.w %1, %0" : "=d"(val) : "I"(bits&15), "0"(val) : "cc");
        }
        else {
          // use opposite rotate for N > 8
          asm("ror.w %1, %0" : "=d"(val) : "I"(16-(bits&15)), "0"(val) : "cc");
        }
      }
    }
    else {
      asm("rol.w %1, %0" : "=d"(val) : "d"(bits), "0"(val) : "cc");
    }
    return val;
  }

  template<typename T>
  inline T  _rotRight8(uint32 bits, T val)
  {
    if (__builtin_constant_p(bits)) {
      if (bits&7) {
        // only rotate when modulus 8 > 0
        asm("ror.b %1, %0" : "=d"(val) : "I"(bits&7), "0"(val) : "cc");
      }
    }
    else {
      asm("ror.b %1, %0" : "=d"(val) : "d"(bits), "0"(val) : "cc");
    }
    return val;
  }

  template<typename T>
  inline T _rotRight16(uint32 bits, T val)
  {
    if (__builtin_constant_p(bits)) {
      if (bits&15) {
        // only rotate when modulus 16 > 0
        if ((bits&15) < 9) {
          asm("ror.w %1, %0" : "=d"(val) : "I"(bits&15), "0"(val) : "cc");
        }
        else {
          // use opposite rotate for N > 8
          asm("rol.w %1, %0" : "=d"(val) : "I"(16-(bits&15)), "0"(val) : "cc");
        }
      }
    }
    else {
      asm("ror.w %1, %0" : "=d"(val) : "d"(bits), "0"(val) : "cc");
    }
    return val;
  }


  inline uint16 swap16(uint16 val)
  {
    if (__builtin_constant_p(val)) {
      val = val<<8|val>>8;
    } else {
      asm(
        "rol.w #8, %0"
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
        "rol.w #8, %0\n\t"
        "swap %0\n\t"
        "rol.w #8, %0"
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
  #define _EXNG2_MACHINE_HAS_SWAP64

  // runtime known rotate
  inline uint32 rotLeft8_32(uint32 bits, uint32 val)  { return _rotLeft8<uint32>(bits, val); }
  inline uint16 rotLeft8_16(uint32 bits, uint16 val)  { return _rotLeft8<uint16>(bits, val); }
  inline uint8  rotLeft8(uint32 bits, uint8 val)      { return _rotLeft8<uint8>(bits, val); }
//   {
//     if (__builtin_constant_p(bits)) {
//       if (bits&7) {
//         asm("rol.b %1, %0" : "=d"(val) : "I"(bits&7), "0"(val) : "cc");
//       }
//     } else {
//       asm("rol.b %1, %0" : "=d"(val) : "d"(bits), "0"(val) : "cc");
//     }
//     return val;
//   }


  #define _EXNG2_MACHINE_HAS_ROL8

  inline uint32 rotLeft16_32(uint16 bits, uint32 val) { return _rotLeft16<uint32>(bits, val); }
  inline uint16 rotLeft16(uint32 bits, uint16 val)    { return _rotLeft16<uint16>(bits, val); }
//   {
//     if (__builtin_constant_p(bits)) {
//       if (bits&15) {
//         // only rotate when modulus 16 > 0
//         if ((bits&15) < 9) {
//           asm("rol.w %1, %0" : "=d"(val) : "I"(bits&15), "0"(val) : "cc");
//         }
//         else {
//           // use opposite rotate for N > 8
//           asm("ror.w %1, %0" : "=d"(val) : "I"(16-(bits&15)), "0"(val) : "cc");
//         }
//       }
//     }
//     else {
//       asm("rol.w %1, %0" : "=d"(val) : "d"(bits), "0"(val) : "cc");
//     }
//     return val;
//   }

  #define _EXNG2_MACHINE_HAS_ROL16

  inline uint32 rotLeft32(uint32 bits, uint32 val)
  {
    if (__builtin_constant_p(bits)) {
      if (bits&31) {
        // only rotate when modulus 32 > 0
        if ((bits&31) < 9) {
          asm("rol.l %1, %0" : "=d"(val) : "I"(bits&31), "0"(val) : "cc");
        }
        else if ((bits&31)==16) {
          asm("swap %0" : "=d"(val) : "0"(val) : "cc");
        }
        else if ((bits&31)>23) {
          // use opposite rotate for N > 23
          asm("ror.l %1, %0" : "=d"(val) : "I"(32-(bits&31)), "0"(val) : "cc");
        }
        else {
          // use register rotate for all intermediate sizes
          asm("rol.l %1, %0" : "=d"(val) : "d"(bits&31), "0"(val) : "cc");
        }
      }
    }
    else {
      asm("rol.l %1, %0" : "=d"(val) : "d"(bits), "0"(val) : "cc");
    }
    return val;
  }
  #define _EXNG2_MACHINE_HAS_ROL32

  inline uint32 rotRight8_32(uint32 bits, uint32 val) { return _rotRight8<uint32>(bits, val); }
  inline uint16 rotRight8_16(uint32 bits, uint16 val) { return _rotRight8<uint16>(bits, val); }
  inline uint8  rotRight8(uint32 bits, uint8 val)     { return _rotRight8<uint8>(bits, val);  }
//   {
//     if (__builtin_constant_p(bits)) {
//       if (bits&7) {
//         // only rotate when modulus 8 > 0
//         asm("ror.b %1, %0" : "=d"(val) : "I"(bits&7), "0"(val) : "cc");
//       }
//     }
//     else {
//       asm("ror.b %1, %0" : "=d"(val) : "d"(bits), "0"(val) : "cc");
//     }
//     return val;
//   }
  #define _EXNG2_MACHINE_HAS_ROR8

  inline uint32 rotRight16_32(uint32 bits, uint32 val)  { return _rotRight16<uint32>(bits, val); }
  inline uint16 rotRight16(uint32 bits, uint16 val)     { return _rotRight16<uint32>(bits, val); }
//   {
//     if (__builtin_constant_p(bits)) {
//       if (bits&15) {
//         // only rotate when modulus 16 > 0
//         if ((bits&15) < 9) {
//           asm("ror.w %1, %0" : "=d"(val) : "I"(bits&15), "0"(val) : "cc");
//         }
//         else {
//           // use opposite rotate for N > 8
//           asm("rol.w %1, %0" : "=d"(val) : "I"(16-(bits&15)), "0"(val) : "cc");
//         }
//       }
//     }
//     else {
//       asm("ror.w %1, %0" : "=d"(val) : "d"(bits), "0"(val) : "cc");
//     }
//     return val;
//   }
  #define _EXNG2_MACHINE_HAS_ROR16

  inline uint32 rotRight32(uint32 bits, uint32 val)
  {
    if (__builtin_constant_p(bits)) {
      if (bits&31) {
        // only rotate when modulus 32 > 0
        if ((bits&31) < 9) {
          asm("ror.l %1, %0" : "=d"(val) : "I"(bits&31), "0"(val) : "cc");
        }
        else if ((bits&31)==16) {
          asm("swap %0" : "=d"(val) : "0"(val) : "cc");
        }
        else if ((bits&31)>23) {
          // use opposite rotate for N > 23
          asm("rol.l %1, %0" : "=d"(val) : "I"(32-(bits&31)), "0"(val) : "cc");
        }
        else {
          // use register rotate for all intermediate sizes
          asm("ror.l %1, %0" : "=d"(val) : "d"(bits&31), "0"(val) : "cc");
        }
      }
    }
    else {
      asm("ror.r %1, %0" : "=d"(val) : "d"(bits), "0"(val) : "cc");
    }
    return val;
  }
  #define _EXNG2_MACHINE_HAS_ROR32

  inline sint32 mostSigBit32(uint32 val)
  {
    asm(
      "bfffo %0 {#0:#32}, %0" "\n\t"
      "neg.w %0"              "\n\t"
      "add.w #31,%0" : "=d"(val) : "0"(val) : "cc");
    return val;
  }
  #define _EXNG2_MACHINE_HAS_BFFFO

};

#endif
