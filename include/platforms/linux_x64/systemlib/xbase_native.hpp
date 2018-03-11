///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/linux_x64/systemlib/base.hpp
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

#ifndef _EXTROPIA_SYSTEMLIB_BASE_NATIVE_HPP
# define _EXTROPIA_SYSTEMLIB_BASE_NATIVE_HPP

# ifndef __LP64__
#   error Compilation target mismatch. Attempt to compile 64-bit library with 32-bit compiler mode
# endif

# ifndef E_OK
#   define E_OK 0
# endif

////////////////////////////////////////////////////////////////////////////////
//
//  ARCHITECTURE DEFINITION
//
////////////////////////////////////////////////////////////////////////////////

# define X_ARCHITECTURE     "Intel x64 (64-bit)"
# define X_PLATFORM         "Linux"
# define X_ALIGNMENT        XA_ALIGN64
# define X_PTRSIZE          XA_PTR64
# define X_ENDIAN           XA_LITTLEENDIAN
# define X_NEGATIVE         XA_TWOSCOMP
# define X_FPU_IEEE754

# ifndef _LC_TRASH
#   define _LC_TRASH
# endif

namespace Machine {
  enum {
    SIGNATURE = TWOS_COMP|LSB_FIRST|PTRSIZE_64|ALIGNED_64
  };
};

namespace EXNGPrivate {

};

////////////////////////////////////////////////////////////////////////////////
//
//  TYPES
//
////////////////////////////////////////////////////////////////////////////////

// 64-bit gcc target
// long long is 64-bit
// long is 64-bit
// int  is 32-bit

typedef signed char         sint8;
typedef signed short int    sint16;
typedef signed int          sint32;
typedef signed long int     sint64;
typedef unsigned char       uint8;
typedef unsigned short int  uint16;
typedef unsigned int        uint32;
typedef unsigned long int   uint64;
typedef float               float32;
typedef double              float64;

// printf family templates
# define XPF_S8  "hhd"
# define XPF_S16 "hd"
# define XPF_S32 "d"
# define XPF_S64 "ld"
# define XPF_U8  "hhu"
# define XPF_U16 "hu"
# define XPF_U32 "u"
# define XPF_U64 "lu"

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
          T &name = *( (T*)((uint32)(__ass32##name+3) & ~3) );

# define  ALIGN_STACK_STRUCT_64(T, name)                      \
          uint8 __ass64##name[sizeof(T)+7];                   \
          T &name = *( (T*)((uint32)(__ass64##name+7) & ~7) );

# define  ALIGN_STACK_STRUCT_CACHELINE(T, name)               \
          uint8 __assCh##name[sizeof(T)+63];                  \
          T &name = *( (T*)((uint32)(__assCh##name+15) & ~63) );

# define  ALIGN_STACK_BLOCK_32(T,name,num)                    \
          uint8 __assb32##name[3+((num)*sizeof(T))];          \
          T *name = (T*)((uint32)(__assb32##name+3) & ~3);

# define  ALIGN_STACK_BLOCK_64(T,name,num)                    \
          uint8 __assb64##name[7+((num)*sizeof(T))];          \
          T *name = (T*)((uint32)(__assb64##name+7) & ~7);

# define  ALIGN_STACK_BLOCK_CACHELINE(T,name,num)             \
          uint8 __assb32##name[63+((num)*sizeof(T))];         \
          T *name = (T*)((uint32)(__assb32##name+7) & ~63);

# define ALIGNSTACKOBJ32(T, name) uint8 __a32##name[sizeof(T)+3]; \
          T &name = *( (T*)((uint32)(__a32##name+3)&~3) );

# define ALIGNSTACKOBJ64(T, name) uint8 __a64##name[sizeof(T)+7]; \
          T &name = *( (T*)((uint32)(__a64##name+7)&~7) );


# define ALIGNSTACKBLOCK32(T,name,num) uint8 __ba32##name[3+((num)*sizeof(T))]; \
          T *name = (T*)((uint32)(__ba32##name+3) & ~3);

# define ALIGNSTACKBLOCK64(T,name,num) uint8 __ba64##name[7+((num)*sizeof(T))]; \
          T *name = (T*)((uint32)(__ba64##name+7) & ~7);


#endif
