///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         gfxlib/pixel_15bit.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Range bound integer class
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

#include <gfxlib/pixel.hpp>
#include <systemlib/memory.hpp>
#include <systemlib/machine_bitops.hpp>

//#define PIXCONV_ARGS void* dst, const void* src, uint16 w, uint16 h, uint16 dstSpan, uint16 srcSpan

void Pixel::copy16(PIXCONV_ARGS)
{
  if (srcSpan==dstSpan==w) {
    Mem::copy(dst, src, (w*h)<<1);
  }
  else {
    register uint16* s = (uint16*)src;
    register uint16* d = (uint16*)dst;
    w<<=1;
    while (h--) {
      Mem::copy(s, d, w);
      s += srcSpan;
      d += dstSpan;
    }
  }
}

void Pixel::swap16(PIXCONV_ARGS)
{
  if (srcSpan==dstSpan==w) {
    Mem::swap16(dst, src, w*h);
  }
  else {
    register uint16* s = (uint16*)src;
    register uint16* d = (uint16*)dst;
    w<<=1;
    while (h--) {
      Mem::swap16(s, d, w);
      s += srcSpan;
      d += dstSpan;
    }
  }
}

void Pixel::convXGY_555B_To_YGX_555B(PIXCONV_ARGS)
{
/*
  move.w  \1,     \2    ;// 2.w = -------- -------- Nxxxxxgg gggyyyyy
  lsl.b   #2,     \2    ;// 2.w = -------- -------- Nxxxxxgg gyyyyy00
  rol.w   #8,     \2    ;// 2.w = -------- -------- gyyyyy00 Nxxxxxgg
  lsr.b   #2,     \2    ;// 2.w = -------- -------- gyyyyy00 00Nxxxxx
  and.w   #$7C1F,   \2    ;// 2.w = -------- -------- 0yyyyy00 000xxxxx
  and.w   #$83E0,   \1    ;// 1.w = -------- -------- N00000gg ggg00000
  or.w    \2,     \1    ;// 1.w = -------- -------- Nyyyyygg gggxxxxx
*/

  // T                B T B
  register uint16* s = (uint16*)src;
  register uint16* d = (uint16*)dst;
  srcSpan -= w;
  dstSpan -= w;
  while (h--) {
    while (w--) {

    }
  }
}

void Pixel::convXGY_555B_To_YGX_555L(PIXCONV_ARGS)
{
  // T B              B T
}

void Pixel::convXGY_555L_To_YGX_555B(PIXCONV_ARGS)
{
  // B T              T B
}

void Pixel::convXGY_555L_To_YGX_555L(PIXCONV_ARGS)
{
  // B T B            T
}

// 15 -> 16
void Pixel::convXGY_555B_To_XGY_565B(PIXCONV_ARGS)
{
  // X                B X B
}

void Pixel::convXGY_555B_To_XGY_565L(PIXCONV_ARGS)
{
  // X B              B X
}

void Pixel::convXGY_555L_To_XGY_565B(PIXCONV_ARGS)
{
  // B X              X B
}

void Pixel::convXGY_555L_To_XGY_565L(PIXCONV_ARGS)
{
  // B X B            X
}

void Pixel::convXGY_555B_To_YGX_565B(PIXCONV_ARGS)
{
  // T X              B X T B
}

void Pixel::convXGY_555B_To_YGX_565L(PIXCONV_ARGS)
{
  // T X B            B X T
}

void Pixel::convXGY_555L_To_YGX_565B(PIXCONV_ARGS)
{
  // B T X            T X B
}

void Pixel::convXGY_555L_To_YGX_565L(PIXCONV_ARGS)
{
  // B T X B          T X
}

// 15 -> 24
void Pixel::convXGY_555B_To_XGY_888(PIXCONV_ARGS)
{
   // X                B X
}

void Pixel::convXGY_555L_To_XGY_888(PIXCONV_ARGS)
{
   // B X              X
}

void Pixel::convXGY_555B_To_YGX_888(PIXCONV_ARGS)
{
   // T X              B T X
}

void Pixel::convXGY_555L_To_YGX_888(PIXCONV_ARGS)
{
   // B T X            X T
}

// 15 -> 32
void Pixel::convXGY_555B_To_AXGY_8888(PIXCONV_ARGS)
{
  // X
}

void Pixel::convXGY_555B_To_AYGX_8888(PIXCONV_ARGS)
{
  // T X
}

void Pixel::convXGY_555B_To_YGXA_8888(PIXCONV_ARGS)
{
   // B T
}

void Pixel::convXGY_555B_To_XGYA_8888(PIXCONV_ARGS)
{
  // X
}

void Pixel::convXGY_555L_To_AXGY_8888(PIXCONV_ARGS)
{
  // B X
}

void Pixel::convXGY_555L_To_AYGX_8888(PIXCONV_ARGS)
{
  // B T X
}

void Pixel::convXGY_555L_To_YGXA_8888(PIXCONV_ARGS)
{
  // B T X
}

void Pixel::convXGY_555L_To_XGYA_8888(PIXCONV_ARGS)
{
  // B X
}

