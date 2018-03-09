///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         systemlib/hwsignature.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Hardware signature constants, used for both identification and conditional compilation
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



#ifndef _EXNG2_SYSTEMLIB_HWSIGNATURE_HPP_
# define _EXNG2_SYSTEMLIB_HWSIGNATURE_HPP_

# define XA_ALIGNMASK    0x07 // Alignment Mask
# define XA_ALIGN8       0x00 // Byte Alignment
# define XA_ALIGN16      0x01 // Word Alignment
# define XA_ALIGN32      0x02 // DWord Alignment
# define XA_ALIGN64      0x03 // QWord Alignment
# define XA_ALIGN128     0x04 // 128-Bit Alignment
# define XA_ALIGN256     0x05 // 256-Bit Alignment
# define XA_ALIGN512     0x06 // 512-Bit Alignment
# define XA_ALIGN1K      0x07 // 1K-Bit Alignment
# define XA_PTRMASK      0x18 // Pointer Size Mask
# define XA_PTR32        0x00 // 32-Bit Pointers
# define XA_PTR64        0x08 // 64-Bit Pointers
# define XA_PTR96        0x10 // 96-Bit Pointers
# define XA_PTR128       0x18 // 128-Bit Pointers
# define XA_ENDIANMASK   0x20 // Endian Type Mask
# define XA_BIGENDIAN    0x00 // 0 = Motorola (more common)
# define XA_LITTLEENDIAN 0x20 // 1 = Intel (most popular :)
# define XA_NEGATIVEMASK 0x40 // Negative Format Mask
# define XA_TWOSCOMP     0x00 // 0 = 2's compliment (more common)
# define XA_ONESCOMP     0x40 // 1 = 1's compliment (very rare)

namespace Machine {
  enum {
    ALIGNMENT       = 0x07,
    ALIGNED_8       = 0x00,
    ALIGNED_16      = 0x01,
    ALIGNED_32      = 0x02,
    ALIGNED_64      = 0x03,
    ALIGNED_128     = 0x04,

    POINTERSIZE     = 0x18,
    PTRSIZE_32      = 0x00,
    PTRSIZE_64      = 0x08,

    ENDIANNESS      = 0x20,
    MSB_FIRST       = 0x00,
    LSB_FIRST       = 0x20,

    NEG_FORMAT      = 0x40,
    TWOS_COMP       = 0x00,
    ONES_COMP       = 0x40
  };

  typedef enum {
    WT_OTHER     = 0,
    WT_BIT       = 1,
    WT_BITFIELD  = 2,
    WT_BYTE      = 3,
    WT_WORD16    = 4,
    WT_WORD32    = 5,
    WT_WORD64    = 6,
    WT_WORD128   = 7
  } WordType;

};

#endif
