///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         gfxlib/pixel_32bit.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Conversions from 8888 pixel
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

#ifndef EXNG2_GFXLIB_NATIVE_PIXEL_CONV_32

#include <systemlib/memory.hpp>
#include <systemlib/machine_bitops.hpp>

namespace {

  inline uint16 shrink15A(uint32 pix)
  {
    // AXGY -> XGY
    return ((pix>>3)&0x001F) | ((pix>>6)&0x03e0) | ((pix>>9)&0x7c00);
  }

  inline uint16 shrink15B(uint32 pix)
  {
    // AXGY -> YGX
    pix = Machine::swap32(pix)>>8;
    return ((pix>>3)&0x001F) | ((pix>>6)&0x03e0) | ((pix>>9)&0x7c00);
  }

  inline uint16 shrink15C(uint32 pix)
  {
    // XGYA -> XGY
    pix >>=8;
    return ((pix>>3)&0x001F) | ((pix>>6)&0x03e0) | ((pix>>9)&0x7c00);
  }

  inline uint16 shrink15D(uint32 pix)
  {
    // XGYA -> YGX
    pix = Machine::swap32(pix);
    return ((pix>>3)&0x001F) | ((pix>>6)&0x03e0) | ((pix>>9)&0x7c00);
  }

  inline uint16 shrink16A(uint32 pix)
  {
    // AXGY -> XGY
    return ((pix>>3)&0x001F) | ((pix>>5)&0x07e0) | ((pix>>8)&0x7c00);
  }

  inline uint16 shrink16B(uint32 pix)
  {
    // AXGY -> YGX
    pix = Machine::swap32(pix)>>8;
    return ((pix>>3)&0x001F) | ((pix>>5)&0x07e0) | ((pix>>8)&0x7c00);
  }

  inline uint16 shrink16C(uint32 pix)
  {
    // XGYA -> XGY
    pix >>=8;
    return ((pix>>3)&0x001F) | ((pix>>5)&0x07e0) | ((pix>>8)&0x7c00);
  }

  inline uint16 shrink16D(uint32 pix)
  {
    // XGYA -> YGX
    pix = Machine::swap32(pix);
    return ((pix>>3)&0x001F) | ((pix>>5)&0x07e0) | ((pix>>8)&0x7c00);
  }


};

#if X_ENDIAN == XA_BIGENDIAN

// 32 -> 15
# define _AXGY32_TO_XGY15B(d, s) *d++ = shrink15A(*s++)
# define _AXGY32_TO_XGY15L(d, s) *d++ = Machine::swap16(shrink15A(*s++))
# define _AXGY32_TO_YGX15B(d, s) *d++ = shrink15B(*s++)
# define _AXGY32_TO_YGX15L(d, s) *d++ = Machine::swap16(shrink15B(*s++))
# define _XGYA32_TO_XGY15B(d, s) *d++ = shrink15C(*s++)
# define _XGYA32_TO_XGY15L(d, s) *d++ = Machine::swap16(shrink15C(*s++))
# define _XGYA32_TO_YGX15B(d, s) *d++ = shrink15D(*s++)
# define _XGYA32_TO_YGX15L(d, s) *d++ = Machine::swap16(shrink15D(*s++))

// 32 -> 16
# define _AXGY32_TO_XGY16B(d, s) *d++ = shrink16A(*s++)
# define _AXGY32_TO_XGY16L(d, s) *d++ = Machine::swap16(shrink16A(*s++))
# define _AXGY32_TO_YGX16B(d, s) *d++ = shrink16B(*s++)
# define _AXGY32_TO_YGX16L(d, s) *d++ = Machine::swap16(shrink16B(*s++))
# define _XGYA32_TO_XGY16B(d, s) *d++ = shrink16C(*s++)
# define _XGYA32_TO_XGY16L(d, s) *d++ = Machine::swap16(shrink16C(*s++))
# define _XGYA32_TO_YGX16B(d, s) *d++ = shrink16D(*s++)
# define _XGYA32_TO_YGX16L(d, s) *d++ = Machine::swap16(shrink16D(*s++))

// 32 -> 24
# define _AXGY32_TO_XGY24(d, s)     { uint32 p = *s++; *d++ = (p>>16)&0xFF; *d++ = (p>>8)&0xFF;  *d++ = p&0xFF; }
# define _AXGY32_TO_YGX24(d, s)     { uint32 p = *s++; *d++ = p&0xFF;       *d++ = (p>>8)&0xFF;  *d++ = (p>>16)&0xFF; }
# define _XGYA32_TO_XGY24(d, s)     { uint32 p = *s++; *d++ = (p>>24)&0xFF; *d++ = (p>>16)&0xFF; *d++ = (p>>8)&0xFF; }
# define _XGYA32_TO_YGX24(d, s)     { uint32 p = *s++; *d++ = (p>>8)&0xFF;  *d++ = (p>>16)&0xFF; *d++ = (p>>24)&0xFF; }

// 32 -> 32
# define _AXGY32_TO_AYGX32(d, s) *d++ = Machine::rotRight32(8, Machine::swap32(*s++))
# define _AXGY32_TO_XGYA32(d, s) *d++ = Machine::rotLeft32(8, *s++)
# define _XGYA32_TO_AXGY32(d, s) *d++ = Machine::rotRight32(8, *s++)
# define _XGYA32_TO_YGXA32(d, s) *d++ = Machine::rotLeft32(8, Machine::swap32(*s++))

#else

// 32 -> 15
# define _AXGY32_TO_XGY15B(d, s) *d++ = Machine::swap16(shrink15D(*s++))
# define _AXGY32_TO_XGY15L(d, s) *d++ = shrink15A(*s++)
# define _AXGY32_TO_YGX15B(d, s) *d++ = Machine::swap16(shrink15C(*s++))
# define _AXGY32_TO_YGX15L(d, s) *d++ = shrink15B(*s++)
# define _XGYA32_TO_XGY15B(d, s) *d++ = Machine::swap16(shrink15B(*s++))
# define _XGYA32_TO_XGY15L(d, s) *d++ = shrink15C(*s++)
# define _XGYA32_TO_YGX15B(d, s) *d++ = Machine::swap16(shrink15A(*s++))
# define _XGYA32_TO_YGX15L(d, s) *d++ = shrink15D(*s++))

// 32 -> 16
# define _AXGY32_TO_XGY16B(d, s) *d++ = Machine::swap16(shrink15D(*s++))
# define _AXGY32_TO_XGY16L(d, s) *d++ = shrink15A(*s++)
# define _AXGY32_TO_YGX16B(d, s) *d++ = Machine::swap16(shrink15C(*s++))
# define _AXGY32_TO_YGX16L(d, s) *d++ = shrink15B(*s++)
# define _XGYA32_TO_XGY16B(d, s) *d++ = Machine::swap16(shrink15B(*s++))
# define _XGYA32_TO_XGY16L(d, s) *d++ = shrink15C(*s++)
# define _XGYA32_TO_YGX16B(d, s) *d++ = Machine::swap16(shrink15A(*s++))
# define _XGYA32_TO_YGX16L(d, s) *d++ = shrink15D(*s++))

// 32 -> 24
# define _AXGY32_TO_XGY24(d, s)     { uint32 p = *s++; *d++ = (p>>16)&0xFF; *d++ = (p>>8)&0xFF;  *d++ = p&0xFF; }
# define _AXGY32_TO_YGX24(d, s)     { uint32 p = *s++; *d++ = p&0xFF;       *d++ = (p>>8)&0xFF;  *d++ = (p>>16)&0xFF; }
# define _XGYA32_TO_XGY24(d, s)     { uint32 p = *s++; *d++ = (p>>24)&0xFF; *d++ = (p>>16)&0xFF; *d++ = (p>>8)&0xFF; }
# define _XGYA32_TO_YGX24(d, s)     { uint32 p = *s++; *d++ = (p>>8)&0xFF;  *d++ = (p>>16)&0xFF; *d++ = (p>>24)&0xFF; }

// 32 -> 32
# define _AXGY32_TO_AYGX32(d, s) *d++ = Machine::rotRight32(8, Machine::swap32(*s++))
# define _AXGY32_TO_XGYA32(d, s) *d++ = Machine::rotLeft32(8, *s++)
# define _XGYA32_TO_AXGY32(d, s) *d++ = Machine::rotRight32(8, *s++)
# define _XGYA32_TO_YGXA32(d, s) *d++ = Machine::rotLeft32(8, Machine::swap32(*s++))

#endif

//#define PIXCONV_ARGS void* dst, const void* src, uint16 w, uint16 h, uint16 dstMod, uint16 srcMod

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 32 -> 15
extern "C" void convAXGY_8888_To_XGY_555B(PIXCONV_ARGS)
{
  register uint32* s = (uint32*)src;
  register uint16* d = (uint16*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _AXGY32_TO_XGY15B(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convAXGY_8888_To_XGY_555L(PIXCONV_ARGS)
{
  register uint32* s = (uint32*)src;
  register uint16* d = (uint16*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _AXGY32_TO_XGY15L(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convAXGY_8888_To_YGX_555B(PIXCONV_ARGS)
{
  register uint32* s = (uint32*)src;
  register uint16* d = (uint16*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _AXGY32_TO_YGX15B(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convAXGY_8888_To_YGX_555L(PIXCONV_ARGS)
{
  register uint32* s = (uint32*)src;
  register uint16* d = (uint16*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _AXGY32_TO_YGX15L(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convXGYA_8888_To_XGY_555B(PIXCONV_ARGS)
{
  register uint32* s = (uint32*)src;
  register uint16* d = (uint16*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGYA32_TO_XGY15B(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convXGYA_8888_To_XGY_555L(PIXCONV_ARGS)
{
  register uint32* s = (uint32*)src;
  register uint16* d = (uint16*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGYA32_TO_XGY15L(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convXGYA_8888_To_YGX_555B(PIXCONV_ARGS)
{
  register uint32* s = (uint32*)src;
  register uint16* d = (uint16*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGYA32_TO_YGX15B(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convXGYA_8888_To_YGX_555L(PIXCONV_ARGS)
{
  register uint32* s = (uint32*)src;
  register uint16* d = (uint16*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGYA32_TO_YGX15L(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



// 32 -> 16
extern "C" void convAXGY_8888_To_XGY_565B(PIXCONV_ARGS)
{
  register uint32* s = (uint32*)src;
  register uint16* d = (uint16*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _AXGY32_TO_XGY16B(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convAXGY_8888_To_XGY_565L(PIXCONV_ARGS)
{
  register uint32* s = (uint32*)src;
  register uint16* d = (uint16*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _AXGY32_TO_XGY16L(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convAXGY_8888_To_YGX_565B(PIXCONV_ARGS)
{
  register uint32* s = (uint32*)src;
  register uint16* d = (uint16*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _AXGY32_TO_YGX16B(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convAXGY_8888_To_YGX_565L(PIXCONV_ARGS)
{
  register uint32* s = (uint32*)src;
  register uint16* d = (uint16*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _AXGY32_TO_YGX16L(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convXGYA_8888_To_XGY_565B(PIXCONV_ARGS)
{
  register uint32* s = (uint32*)src;
  register uint16* d = (uint16*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGYA32_TO_XGY16B(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convXGYA_8888_To_XGY_565L(PIXCONV_ARGS)
{
  register uint32* s = (uint32*)src;
  register uint16* d = (uint16*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGYA32_TO_XGY16L(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convXGYA_8888_To_YGX_565B(PIXCONV_ARGS)
{
  register uint32* s = (uint32*)src;
  register uint16* d = (uint16*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGYA32_TO_YGX16B(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convXGYA_8888_To_YGX_565L(PIXCONV_ARGS)
{
  register uint32* s = (uint32*)src;
  register uint16* d = (uint16*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGYA32_TO_YGX16L(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// 32 -> 24

extern "C" void convAXGY_8888_To_XGY_888(PIXCONV_ARGS)
{
  register uint32* s = (uint32*)src;
  register uint8*  d = (uint8*)dst;

  dstMod *= 3;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _AXGY32_TO_XGY24(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convAXGY_8888_To_YGX_888(PIXCONV_ARGS)
{
  register uint32* s = (uint32*)src;
  register uint8*  d = (uint8*)dst;

  dstMod *= 3;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _AXGY32_TO_YGX24(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convXGYA_8888_To_XGY_888(PIXCONV_ARGS)
{
  register uint32* s = (uint32*)src;
  register uint8*  d = (uint8*)dst;

  dstMod *= 3;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGYA32_TO_XGY24(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convXGYA_8888_To_YGX_888(PIXCONV_ARGS)
{
  register uint32* s = (uint32*)src;
  register uint8*  d = (uint8*)dst;

  dstMod *= 3;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGYA32_TO_YGX24(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// 32 -> 32
extern "C" void copy32(PIXCONV_ARGS)
{
  if (srcMod==dstMod==w) {
    Mem::copy(dst, src, (w*h)<<2);
  }
  else {
    register uint32* s = (uint32*)src;
    register uint32* d = (uint32*)dst;

    srcMod += w;
    dstMod += w;

    w<<=2;
    while (h--) {
      Mem::copy(s, d, w);
      s += srcMod;
      d += dstMod;
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void swap32(PIXCONV_ARGS)
{
  if (srcMod==dstMod==w) {
    Mem::swap32(dst, src, w*h);
  }
  else {
    register uint32* s = (uint32*)src;
    register uint32* d = (uint32*)dst;

    srcMod += w;
    dstMod += w;

    w<<=2;
    while (h--) {
      Mem::swap32(s, d, w);
      s += srcMod;
      d += dstMod;
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convAXGY_8888_To_AYGX_8888(PIXCONV_ARGS)
{
  register uint32* s = (uint32*)src;
  register uint32* d = (uint32*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _AXGY32_TO_AYGX32(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convAXGY_8888_To_XGYA_8888(PIXCONV_ARGS)
{
  register uint32* s = (uint32*)src;
  register uint32* d = (uint32*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _AXGY32_TO_XGYA32(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convXGYA_8888_To_AXGY_8888(PIXCONV_ARGS)
{
  register uint32* s = (uint32*)src;
  register uint32* d = (uint32*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGYA32_TO_AXGY32(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" void convXGYA_8888_To_YGXA_8888(PIXCONV_ARGS)
{
  register uint32* s = (uint32*)src;
  register uint32* d = (uint32*)dst;

  while (h--) {
    uint32 w2 = w;
    while (w2--) {
      _XGYA32_TO_YGXA32(d, s);
    }
    s += srcMod;
    d += dstMod;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif
