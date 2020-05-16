///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         gfxlib/pixel_15bit.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  pixel conversion
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

#ifndef _EXNG2_GFXLIB_PIXEL15BIT_HPP_
# define _EXNG2_GFXLIB_PIXEL15BIT_HPP_

extern "C" {
  void convCopy16(PIXCONV_ARGS);
  void convSwap16(PIXCONV_ARGS);

  // 15 -> 15                                   // Big Endian Host  Little Endian Host
  void convXGY_555B_To_YGX_555B(PIXCONV_ARGS);  // T                B T B
  void convXGY_555B_To_YGX_555L(PIXCONV_ARGS);  // T B              B T
  void convXGY_555L_To_YGX_555B(PIXCONV_ARGS);  // B T              T B
  void convXGY_555L_To_YGX_555L(PIXCONV_ARGS);  // B T B            T

  // 15 -> 16
  void convXGY_555B_To_XGY_565B(PIXCONV_ARGS);  // X                B X B
  void convXGY_555B_To_XGY_565L(PIXCONV_ARGS);  // X B              B X
  void convXGY_555L_To_XGY_565B(PIXCONV_ARGS);  // B X              X B
  void convXGY_555L_To_XGY_565L(PIXCONV_ARGS);  // B X B            X

  void convXGY_555B_To_YGX_565B(PIXCONV_ARGS);  // T X              B X T B
  void convXGY_555B_To_YGX_565L(PIXCONV_ARGS);  // T X B            B X T
  void convXGY_555L_To_YGX_565B(PIXCONV_ARGS);  // B T X            T X B
  void convXGY_555L_To_YGX_565L(PIXCONV_ARGS);  // B T X B          T X

  // 15 -> 24
  void convXGY_555B_To_XGY_888(PIXCONV_ARGS);   // X                B X
  void convXGY_555L_To_XGY_888(PIXCONV_ARGS);   // B X              X
  void convXGY_555B_To_YGX_888(PIXCONV_ARGS);   // T X              B T X
  void convXGY_555L_To_YGX_888(PIXCONV_ARGS);   // B T X            X T

  // 15 -> 32
  void convXGY_555B_To_AXGY_8888(PIXCONV_ARGS); // X
  void convXGY_555B_To_AYGX_8888(PIXCONV_ARGS); // T X
  void convXGY_555B_To_YGXA_8888(PIXCONV_ARGS); // B T
  void convXGY_555B_To_XGYA_8888(PIXCONV_ARGS); // X
  void convXGY_555L_To_AXGY_8888(PIXCONV_ARGS); // B X
  void convXGY_555L_To_AYGX_8888(PIXCONV_ARGS); // B T X
  void convXGY_555L_To_YGXA_8888(PIXCONV_ARGS); // B T X
  void convXGY_555L_To_XGYA_8888(PIXCONV_ARGS); // B X
}

#endif
