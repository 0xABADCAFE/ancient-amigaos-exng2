///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         gfxlib/pixel_15bit.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Conversions from 555 pixel
//  Comment(s):
//  Library:      Graphics
//  Created:      2006-10-08
//  Updated:      2006-10-08
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <gfxlib/pixel.hpp>

#ifndef EXNG2_GFXLIB_NATIVE_PIXEL_CONV_15

#include <systemlib/memory.hpp>
#include <systemlib/machine_bitops.hpp>

namespace {

  inline uint16 rotate15(uint16 pix)
  {
    uint16 tmp = Machine::rotRight8_16(2,Machine::swap16(Machine::rotLeft8_16(2, pix))) & 0x7C1F;
    pix &= 0x87E0;
    return pix | tmp;
  }

  inline uint16 expand16(uint16 pix)
  {
    uint16 tmp = (pix<<1)&0xFFC0;
    pix &= 0x001F;
    return pix | tmp;
  }

  inline uint32 expand32A(uint16 pix)
  {
    return ((pix&0x7C00)<<9|(pix&0x03E0)<<6|(pix&0x001F)<<3);
  }

  inline uint32 expand32B(uint32 pix)
  {
    return ((pix&0x7C00)>>7|(pix&0x03E0)<<6|(pix&0x001F)<<19);
  }

  inline uint32 expand32C(uint16 pix)
  {
    return ((pix&0x7C00)<<17|(pix&0x03E0)<<14|(pix&0x001F)<<11);
  }

  inline uint32 expand32D(uint32 pix)
  {
    return ((pix&0x7C00)<<1|(pix&0x03E0)<<14|(pix&0x001F)<<27);
  }

};


#if X_ENDIAN == XA_BIGENDIAN

// 15 -> 15 transforms
# define _XGY15B_TO_YGX15B(d, s)    *d++ = rotate15(*s++)
# define _XGY15B_TO_YGX15L(d, s)    *d++ = Machine::swap16(rotate15(*s++))
# define _XGY15L_TO_YGX15B(d, s)    *d++ = rotate15(Machine::swap16(*s++))
# define _XGY15L_TO_YGX15L(d, s)    *d++ = Machine::swap16(rotate15(Machine::swap16(*s++)))

// 16 -> 16 transforms
# define _XGY15B_TO_XGY16B(d, s)    *d++ = expand16(*s++)
# define _XGY15B_TO_XGY16L(d, s)    *d++ = Machine::swap16(expand16(*s++))
# define _XGY15B_TO_YGX16B(d, s)    *d++ = expand16(rotate15(*s++))
# define _XGY15B_TO_YGX16L(d, s)    *d++ = Machine::swap16(expand16(rotate15(*s++)))
# define _XGY15L_TO_XGY16B(d, s)    *d++ = expand16(Machine::swap16(*s++))
# define _XGY15L_TO_XGY16L(d, s)    *d++ = Machine::swap16(expand16(Machine::swap16(*s++)))
# define _XGY15L_TO_YGX16B(d, s)    *d++ = expand16(rotate15(Machine::swap16(*s++)))
# define _XGY15L_TO_YGX16L(d, s)    *d++ = Machine::swap16(expand16(rotate15(Machine::swap16(*s++))))

// 15 -> 24 transforms
# define _XGY15B_TO_XGY24(d, s)     { uint16 p = *s++;                  *d++ = (p>>7)&0xF8; *d++ = (p>>2)&0xF8; *d++ = (p<<3)&0xF8; }
# define _XGY15B_TO_YGX24(d, s)     { uint16 p = *s++;                  *d++ = (p<<3)&0xF8; *d++ = (p>>2)&0xF8; *d++ = (p>>7)&0xF8; }
# define _XGY15L_TO_XGY24(d, s)     { uint16 p = Machine::swap16(*s++); *d++ = (p>>7)&0xF8; *d++ = (p>>2)&0xF8; *d++ = (p<<3)&0xF8; }
# define _XGY15L_TO_YGX24(d, s)     { uint16 p = Machine::swap16(*s++); *d++ = (p<<3)&0xF8; *d++ = (p>>2)&0xF8; *d++ = (p>>7)&0xF8; }

// 15 -> 32 transforms

# define _XGY15B_TO_AXGY32(d, s) *d++ = expand32A(*s++)
# define _XGY15B_TO_AYGX32(d, s) *d++ = expand32B(*s++)
# define _XGY15B_TO_XGYA32(d, s) *d++ = expand32C(*s++)
# define _XGY15B_TO_YGXA32(d, s) *d++ = expand32D(*s++)
# define _XGY15L_TO_AXGY32(d, s) *d++ = expand32A(Machine::swap16(*s++))
# define _XGY15L_TO_AYGX32(d, s) *d++ = expand32B(Machine::swap16(*s++))
# define _XGY15L_TO_XGYA32(d, s) *d++ = expand32C(Machine::swap16(*s++))
# define _XGY15L_TO_YGXA32(d, s) *d++ = expand32D(Machine::swap16(*s++))

#else

// 15 -> 15 transforms
# define _XGY15B_TO_YGX15B(d, s)  *d++ = Machine::swap16(rotate15(Machine::swap16(*s++)))
# define _XGY15B_TO_YGX15L(d, s)  *d++ = rotate15(Machine::swap16(*s++))
# define _XGY15L_TO_YGX15B(d, s)  *d++ = Machine::swap16(rotate15(*s++))
# define _XGY15L_TO_YGX15L(d, s)  *d++ = rotate15(*s++)

// 15 -> 16 transforms
# define _XGY15B_TO_XGY16B(d, s)  *d++ = Machine::swap16(expand16(Machine::swap16(*s++)))
# define _XGY15B_TO_XGY16L(d, s)  *d++ = expand16(Machine::swap16(*s++))
# define _XGY15B_TO_YGX16B(d, s)  *d++ = Machine::swap16(expand16(rotate15(Machine::swap16(*s++))))
# define _XGY15B_TO_YGX16L(d, s)  *d++ = expand16(rotate15(Machine::swap16(*s++)))
# define _XGY15L_TO_XGY16B(d, s)  *d++ = Machine::swap16(expand16(*s++))
# define _XGY15L_TO_XGY16L(d, s)  *d++ = expand16(*s++)
# define _XGY15L_TO_YGX16B(d, s)  *d++ = Machine::swap16(expand16(rotate15(*s++)))
# define _XGY15L_TO_YGX16L(d, s)  *d++ = expand16(rotate15(*s++))

// 15 -> 24 transforms
# define _XGY15B_TO_XGY24(d, s)     { uint16 p = Machine::swap16(*s++); *d++ = (p>>7)&0xF8; *d++ = (p>>2)&0xF8; *d++ = (p<<3)&0xF8; }
# define _XGY15B_TO_YGX24(d, s)     { uint16 p = Machine::swap16(*s++); *d++ = (p<<3)&0xF8; *d++ = (p>>2)&0xF8; *d++ = (p>>7)&0xF8; }
# define _XGY15L_TO_XGY24(d, s)     { uint16 p = *s++;                  *d++ = (p>>7)&0xF8; *d++ = (p>>2)&0xF8; *d++ = (p<<3)&0xF8; }
# define _XGY15L_TO_YGX24(d, s)     { uint16 p = *s++;                  *d++ = (p<<3)&0xF8; *d++ = (p>>2)&0xF8; *d++ = (p>>7)&0xF8; }

// 15 -> 32 transforms

# define _XGY15B_TO_AXGY32(d, s) *d++ = expand32D(Machine::swap16(*s++))
# define _XGY15B_TO_AYGX32(d, s) *d++ = expand32C(Machine::swap16(*s++))
# define _XGY15B_TO_XGYA32(d, s) *d++ = expand32B(Machine::swap16(*s++))
# define _XGY15B_TO_YGXA32(d, s) *d++ = expand32A(Machine::swap16(*s++))
# define _XGY15L_TO_AXGY32(d, s) *d++ = expand32D(*s++)
# define _XGY15L_TO_AYGX32(d, s) *d++ = expand32C(*s++)
# define _XGY15L_TO_XGYA32(d, s) *d++ = expand32B(*s++)
# define _XGY15L_TO_YGXA32(d, s) *d++ = expand32A(*s++)
#endif

//#define PIXCONV_ARGS void* dst, const void* src, uint16 w, uint16 h, uint16 dstMod, uint16 srcMod

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convCopy16(PIXCONV_ARGS)
{
  if (!(srcMod|dstMod)) {
    Mem::copy(dst, src, (w*h)<<1);
  }
  else {
    register uint16* s = (uint16*)src;
    register uint16* d = (uint16*)dst;

    srcMod += w;
    dstMod += w;

    w <<= 1;
    while (h--) {
      Mem::copy(s, d, w);
      s += srcMod;
      d += dstMod;
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convSwap16(PIXCONV_ARGS)
{
  if (!(srcMod|dstMod)) {
    Mem::swap16(dst, src, w*h);
  }
  else {
    register uint16* s = (uint16*)src;
    register uint16* d = (uint16*)dst;

    srcMod += w;
    dstMod += w;

    w <<= 1;
    while (h--) {
      Mem::swap16(s, d, w);
      s += srcMod;
      d += dstMod;
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convXGY_555B_To_YGX_555B(PIXCONV_ARGS)
{
  register uint16* s = (uint16*)src;
  register uint16* d = (uint16*)dst;

  while (h--) {
    while (w--) {
      _XGY15B_TO_YGX15B(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convXGY_555B_To_YGX_555L(PIXCONV_ARGS)
{
  // T B              B T
  register uint16* s = (uint16*)src;
  register uint16* d = (uint16*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGY15B_TO_YGX15L(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convXGY_555L_To_YGX_555B(PIXCONV_ARGS)
{
  // B T              T B
  register uint16* s = (uint16*)src;
  register uint16* d = (uint16*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGY15L_TO_YGX15B(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convXGY_555L_To_YGX_555L(PIXCONV_ARGS)
{
  // B T B            T
  register uint16* s = (uint16*)src;
  register uint16* d = (uint16*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGY15L_TO_YGX15L(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 15 -> 16
extern "C" void convXGY_555B_To_XGY_565B(PIXCONV_ARGS)
{
  // X                B X B
  register uint16* s = (uint16*)src;
  register uint16* d = (uint16*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGY15B_TO_XGY16B(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convXGY_555B_To_XGY_565L(PIXCONV_ARGS)
{
  // X B              B X
  register uint16* s = (uint16*)src;
  register uint16* d = (uint16*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGY15B_TO_XGY16L(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convXGY_555L_To_XGY_565B(PIXCONV_ARGS)
{
  // B X              X B
  register uint16* s = (uint16*)src;
  register uint16* d = (uint16*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGY15L_TO_XGY16B(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convXGY_555L_To_XGY_565L(PIXCONV_ARGS)
{
  // B X B            X
  register uint16* s = (uint16*)src;
  register uint16* d = (uint16*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGY15L_TO_XGY16L(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convXGY_555B_To_YGX_565B(PIXCONV_ARGS)
{
  // T X              B X T B
  register uint16* s = (uint16*)src;
  register uint16* d = (uint16*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGY15B_TO_YGX16B(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convXGY_555B_To_YGX_565L(PIXCONV_ARGS)
{
  // T X B            B X T
  register uint16* s = (uint16*)src;
  register uint16* d = (uint16*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGY15B_TO_YGX16L(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convXGY_555L_To_YGX_565B(PIXCONV_ARGS)
{
  // B T X            T X B
  register uint16* s = (uint16*)src;
  register uint16* d = (uint16*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGY15L_TO_YGX16B(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convXGY_555L_To_YGX_565L(PIXCONV_ARGS)
{
  // B T X B          T X
  register uint16* s = (uint16*)src;
  register uint16* d = (uint16*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGY15L_TO_YGX16L(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 15 -> 24
extern "C" void convXGY_555B_To_XGY_888(PIXCONV_ARGS)
{
  // this implementation sucks.
  register uint16* s = (uint16*)src;
  register uint8*  d = (uint8*)dst;

  dstMod *= 3;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGY15B_TO_XGY24(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convXGY_555L_To_XGY_888(PIXCONV_ARGS)
{
  // this implementation sucks.
  register uint16* s = (uint16*)src;
  register uint8*  d = (uint8*)dst;

  dstMod *= 3;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGY15L_TO_XGY24(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convXGY_555B_To_YGX_888(PIXCONV_ARGS)
{
  // this implementation sucks.
  register uint16* s = (uint16*)src;
  register uint8*  d = (uint8*)dst;

  dstMod *= 3;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGY15B_TO_YGX24(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convXGY_555L_To_YGX_888(PIXCONV_ARGS)
{
  // this implementation sucks.
  register uint16* s = (uint16*)src;
  register uint8*  d = (uint8*)dst;

  dstMod *= 3;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGY15L_TO_YGX24(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 15 -> 32
extern "C" void convXGY_555B_To_AXGY_8888(PIXCONV_ARGS)
{
  // X
  register uint16* s = (uint16*)src;
  register uint32* d = (uint32*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGY15B_TO_AXGY32(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convXGY_555B_To_AYGX_8888(PIXCONV_ARGS)
{
  // T X
  register uint16* s = (uint16*)src;
  register uint32* d = (uint32*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGY15B_TO_AYGX32(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convXGY_555B_To_YGXA_8888(PIXCONV_ARGS)
{
   // B T
  register uint16* s = (uint16*)src;
  register uint32* d = (uint32*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGY15B_TO_YGXA32(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convXGY_555B_To_XGYA_8888(PIXCONV_ARGS)
{
  // X
  register uint16* s = (uint16*)src;
  register uint32* d = (uint32*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGY15B_TO_XGYA32(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convXGY_555L_To_AXGY_8888(PIXCONV_ARGS)
{
  // B X
  register uint16* s = (uint16*)src;
  register uint32* d = (uint32*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGY15L_TO_AXGY32(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convXGY_555L_To_AYGX_8888(PIXCONV_ARGS)
{
  // B T X
  register uint16* s = (uint16*)src;
  register uint32* d = (uint32*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGY15L_TO_AYGX32(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convXGY_555L_To_YGXA_8888(PIXCONV_ARGS)
{
  // B T X
  register uint16* s = (uint16*)src;
  register uint32* d = (uint32*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGY15L_TO_YGXA32(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convXGY_555L_To_XGYA_8888(PIXCONV_ARGS)
{
  // B X
  register uint16* s = (uint16*)src;
  register uint32* d = (uint32*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGY15L_TO_XGYA32(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif
