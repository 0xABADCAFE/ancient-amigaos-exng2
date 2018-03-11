///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/linux_x86/systemlib/base.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Linux x86 (32-bit) Specific implementation of systemlib internals
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

#ifndef _EXTROPIA_SYSTEMLIB_BASE_NATIVE_HPP
# define _EXTROPIA_SYSTEMLIB_BASE_NATIVE_HPP

////////////////////////////////////////////////////////////////////////////////
//
//  ARCHITECTURE DEFINITION
//
////////////////////////////////////////////////////////////////////////////////

# ifdef __LP64__
#   error Compilation target mismatch. Attempt to compile 32-bit library with 64-bit compiler mode
# endif

# define X_ARCHITECTURE     "Intel x86 (32-bit)"
# define X_PLATFORM         "Linux"
# define X_ALIGNMENT        XA_ALIGN32
# define X_PTRSIZE          XA_PTR32
# define X_ENDIAN           XA_LITTLEENDIAN
# define X_NEGATIVE         XA_TWOSCOMP
# define X_FPU_IEEE754

# ifndef _LC_TRASH
#   define _LC_TRASH
# endif

namespace Machine {
  enum {
    SIGNATURE = TWOS_COMP|LSB_FIRST|PTRSIZE_32|ALIGNED_32
  };
};

namespace EXNGPrivate {

};

////////////////////////////////////////////////////////////////////////////////
//
//  TYPES
//
////////////////////////////////////////////////////////////////////////////////

// 32-bit gcc target
// long long is 64-bit
// long is 32-bit
// int  is 32-bit

typedef unsigned char       uint8;
typedef unsigned short      uint16;
typedef unsigned long       uint32;
typedef unsigned long long  uint64;
typedef signed char         sint8;
typedef signed short        sint16;
typedef signed long         sint32;
typedef signed long long    sint64;
typedef float               float32;
typedef double              float64;
typedef float               floatF;

// printf family templates
# define XPF_S8  "hhd"
# define XPF_S16 "hd"
# define XPF_S32 "ld"
# define XPF_S64 "lld"
# define XPF_U8  "hhu"
# define XPF_U16 "hu"
# define XPF_U32 "lu"
# define XPF_U64 "llu"

# define ruint8       register uint8
# define ruint16      register uint16
# define ruint32      register uint32
# define ruint64      register uint64
# define rsint8       register sint8
# define rsint16      register sint16
# define rsint32      register sint32
# define rsint64      register sint64
# define rbool        register bool
# define rfloat32     register float32
# define rfloat64     register float64
# define rfloatF      register floatF
# define rsize_t      register size_t

////////////////////////////////////////////////////////////////////////////////
//
//  OTHER MACROS
//
////////////////////////////////////////////////////////////////////////////////

# define  ALIGN_STACK_STRUCT_32(T, name)                      \
          uint8 __ass32##name[sizeof(T)+3];                   \
          T &name = *( (T*)((uint32)(__ass32##name+3)&~3) );

# define  ALIGN_STACK_STRUCT_64(T, name)                      \
          uint8 __ass64##name[sizeof(T)+7];                   \
          T &name = *( (T*)((uint32)(__ass64##name+7)&~7) );

# define  ALIGN_STACK_STRUCT_CACHELINE(T, name)               \
          uint8 __assCh##name[sizeof(T)+31]                  \
          T &name = *( (T*)((uint32)(__assCh##name+15)&~31);

# define  ALIGN_STACK_BLOCK_32(T,name,num)                    \
          uint8 __assb32##name[3+((num)*sizeof(T))];          \
          T *name = (T*)((uint32)(__assb32##name+3) & ~3);

# define  ALIGN_STACK_BLOCK_64(T,name,num)                    \
          uint8 __assb64##name[7+((num)*sizeof(T))];          \
          T *name = (T*)((uint32)(__assb64##name+7) & ~7);

# define  ALIGN_STACK_BLOCK_CACHELINE(T,name,num)             \
          uint8 __assb32##name[31+((num)*sizeof(T))];           \
          T *name = (T*)((uint32)(__assb32##name+7) & ~31);

# define ALIGNSTACKOBJ32(T, name) uint8 __a32##name[sizeof(T)+3]; \
          T &name = *( (T*)((uint32)(__a32##name+3) & ~3) );

# define ALIGNSTACKOBJ64(T, name) uint8 __a64##name[sizeof(T)+7]; \
          T &name = *( (T*)((uint32)(__a64##name+7) & ~7) );


# define ALIGNSTACKBLOCK32(T,name,num) uint8 __ba32##name[3+((num)*sizeof(T))]; \
          T *name = (T*)((uint32)(__ba32##name+3) & ~3);

# define ALIGNSTACKBLOCK64(T,name,num) uint8 __ba64##name[7+((num)*sizeof(T))]; \
          T *name = (T*)((uint32)(__ba64##name+7) & ~7);

#endif
