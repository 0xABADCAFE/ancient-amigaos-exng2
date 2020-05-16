///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         gfxlib/pixel_convert.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Conversion table
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

#include <private/gfxlib/pixel_15bit.hpp>
#include <private/gfxlib/pixel_16bit.hpp>
#include <private/gfxlib/pixel_24bit.hpp>
#include <private/gfxlib/pixel_32bit.hpp>


namespace {
  void nopRGB(PIXCONV_ARGS)   {}
  void nopIdx(PIXCONV_ARGS2)  {}
};

#define convXGY_555B_To_XGY_555B convCopy16
#define convXGY_555B_To_XGY_555L convSwap16
#define convXGY_555L_To_XGY_555B convSwap16
#define convXGY_555L_To_XGY_555L convCopy16

#define convXGY_565B_To_XGY_565B convCopy16
#define convXGY_565B_To_XGY_565L convSwap16
#define convXGY_565L_To_XGY_565B convSwap16
#define convXGY_565L_To_XGY_565L convCopy16

#define convXGY_888_To_XGY_888   convCopy24

#define convAXGY_8888_To_AXGY_8888   convCopy32
#define convAXGY_8888_To_YGXA_8888   convSwap32

#define convXGYA_8888_To_XGYA_8888   convCopy32
#define convXGYA_8888_To_AYGX_8888   convSwap32


Pixel::ConvertRGB Pixel::convertRGB[Pixel::CUSTOM_FB-1][Pixel::CUSTOM_FB-1] = {
  // RGB_555B
  {
    convXGY_555B_To_XGY_555B,   // RGB_555B
    convXGY_555B_To_YGX_555B,   // BGR_555B
    convXGY_555B_To_XGY_555L,   // RGB_555L
    convXGY_555B_To_YGX_555L,   // BGR_555L
    convXGY_555B_To_XGY_565B,   // RGB_565B
    convXGY_555B_To_YGX_565B,   // BGR_565B
    convXGY_555B_To_XGY_565L,   // RGB_565L
    convXGY_555B_To_YGX_565L,   // BGR_565L
    convXGY_555B_To_XGY_888,    // RGB_888
    convXGY_555B_To_YGX_888,    // BGR_888
    convXGY_555B_To_AXGY_8888,  // ARGB_8888
    convXGY_555B_To_AYGX_8888,  // ABGR_8888
    convXGY_555B_To_YGXA_8888,  // BGRA_8888
    convXGY_555B_To_XGYA_8888   // RGBA_8888
  },
  // BGR_555B
  {
    convXGY_555B_To_YGX_555B,   // RGB_555B
    convXGY_555B_To_XGY_555B,   // BGR_555B
    convXGY_555B_To_YGX_555L,   // RGB_555L
    convXGY_555B_To_XGY_555L,   // BGR_555L
    convXGY_555B_To_YGX_565B,   // RGB_565B
    convXGY_555B_To_XGY_565B,   // BGR_565B
    convXGY_555B_To_YGX_565L,   // RGB_565L
    convXGY_555B_To_XGY_565L,   // BGR_565L
    convXGY_555B_To_YGX_888,    // RGB_888
    convXGY_555B_To_XGY_888,    // BGR_888
    convXGY_555B_To_AYGX_8888,  // ARGB_8888
    convXGY_555B_To_AXGY_8888,  // ABGR_8888
    convXGY_555B_To_XGYA_8888,  // BGRA_8888
    convXGY_555B_To_YGXA_8888   // RGBA_8888
  },
  // RGB_555L
  {
    convXGY_555L_To_XGY_555B,   // RGB_555B
    convXGY_555L_To_YGX_555B,   // BGR_555B
    convXGY_555L_To_XGY_555L,   // RGB_555L
    convXGY_555L_To_YGX_555L,   // BGR_555L
    convXGY_555L_To_XGY_565B,   // RGB_565B
    convXGY_555L_To_YGX_565B,   // BGR_565B
    convXGY_555L_To_XGY_565L,   // RGB_565L
    convXGY_555L_To_YGX_565L,   // BGR_565L
    convXGY_555L_To_XGY_888,    // RGB_888
    convXGY_555L_To_YGX_888,    // BGR_888
    convXGY_555L_To_AXGY_8888,  // ARGB_8888
    convXGY_555L_To_AYGX_8888,  // ABGR_8888
    convXGY_555L_To_YGXA_8888,  // BGRA_8888
    convXGY_555L_To_XGYA_8888   // RGBA_8888
  },
  // BGR_555L
  {
    convXGY_555L_To_YGX_555B,   // RGB_555B
    convXGY_555L_To_XGY_555B,   // BGR_555B
    convXGY_555L_To_YGX_555L,   // RGB_555L
    convXGY_555L_To_XGY_555L,   // BGR_555L
    convXGY_555L_To_YGX_565B,   // RGB_565B
    convXGY_555L_To_XGY_565B,   // BGR_565B
    convXGY_555L_To_YGX_565L,   // RGB_565L
    convXGY_555L_To_XGY_565L,   // BGR_565L
    convXGY_555L_To_YGX_888,    // RGB_888
    convXGY_555L_To_XGY_888,    // BGR_888
    convXGY_555L_To_AYGX_8888,  // ARGB_8888
    convXGY_555L_To_AXGY_8888,  // ABGR_8888
    convXGY_555L_To_XGYA_8888,  // BGRA_8888
    convXGY_555L_To_YGXA_8888   // RGBA_8888
  },
  // RGB_565B
  {
    convXGY_565B_To_XGY_555B,   // RGB_555B
    convXGY_565B_To_YGX_555B,   // BGR_555B
    convXGY_565B_To_XGY_555L,   // RGB_555L
    convXGY_565B_To_YGX_555L,   // BGR_555L
    convXGY_565B_To_XGY_565B,   // RGB_565B
    convXGY_565B_To_YGX_565B,   // BGR_565B
    convXGY_565B_To_XGY_565L,   // RGB_565L
    convXGY_565B_To_YGX_565L,   // BGR_565L
    convXGY_565B_To_XGY_888,    // RGB_888
    convXGY_565B_To_YGX_888,    // BGR_888
    convXGY_565B_To_AXGY_8888,  // ARGB_8888
    convXGY_565B_To_AYGX_8888,  // ABGR_8888
    convXGY_565B_To_YGXA_8888,  // BGRA_8888
    convXGY_565B_To_XGYA_8888   // RGBA_8888
  },
  // BGR_565B
  {
    convXGY_565B_To_YGX_555B,   // RGB_555B
    convXGY_565B_To_XGY_555B,   // BGR_555B
    convXGY_565B_To_YGX_555L,   // RGB_555L
    convXGY_565B_To_XGY_555L,   // BGR_555L
    convXGY_565B_To_YGX_565B,   // RGB_565B
    convXGY_565B_To_XGY_565B,   // BGR_565B
    convXGY_565B_To_YGX_565L,   // RGB_565L
    convXGY_565B_To_XGY_565L,   // BGR_565L
    convXGY_565B_To_YGX_888,    // RGB_888
    convXGY_565B_To_XGY_888,    // BGR_888
    convXGY_565B_To_AYGX_8888,  // ARGB_8888
    convXGY_565B_To_AXGY_8888,  // ABGR_8888
    convXGY_565B_To_XGYA_8888,  // BGRA_8888
    convXGY_565B_To_YGXA_8888   // RGBA_8888
  },
  // RGB_565L
  {
    convXGY_565L_To_XGY_555B,   // RGB_555B
    convXGY_565L_To_YGX_555B,   // BGR_555B
    convXGY_565L_To_XGY_555L,   // RGB_555L
    convXGY_565L_To_YGX_555L,   // BGR_555L
    convXGY_565L_To_XGY_565B,   // RGB_565B
    convXGY_565L_To_YGX_565B,   // BGR_565B
    convXGY_565L_To_XGY_565L,   // RGB_565L
    convXGY_565L_To_YGX_565L,   // BGR_565L
    convXGY_565L_To_XGY_888,    // RGB_888
    convXGY_565L_To_YGX_888,    // BGR_888
    convXGY_565L_To_AXGY_8888,  // ARGB_8888
    convXGY_565L_To_AYGX_8888,  // ABGR_8888
    convXGY_565L_To_YGXA_8888,  // BGRA_8888
    convXGY_565L_To_XGYA_8888   // RGBA_8888
  },
  // BGR_565L
  {
    convXGY_565L_To_YGX_555B,   // RGB_555B
    convXGY_565L_To_XGY_555B,   // BGR_555B
    convXGY_565L_To_YGX_555L,   // RGB_555L
    convXGY_565L_To_XGY_555L,   // BGR_555L
    convXGY_565L_To_YGX_565B,   // RGB_565B
    convXGY_565L_To_XGY_565B,   // BGR_565B
    convXGY_565L_To_YGX_565L,   // RGB_565L
    convXGY_565L_To_XGY_565L,   // BGR_565L
    convXGY_565L_To_YGX_888,    // RGB_888
    convXGY_565L_To_XGY_888,    // BGR_888
    convXGY_565L_To_AYGX_8888,  // ARGB_8888
    convXGY_565L_To_AXGY_8888,  // ABGR_8888
    convXGY_565L_To_XGYA_8888,  // BGRA_8888
    convXGY_565L_To_YGXA_8888   // RGBA_8888
  },
  // RGB_888
  {
    convXGY_888_To_XGY_555B,    //   RGB_555B
    convXGY_888_To_YGX_555B,    //   BGR_555B
    convXGY_888_To_XGY_555L,    //   RGB_555L
    convXGY_888_To_YGX_555L,    //   BGR_555L
    convXGY_888_To_XGY_565B,    //   RGB_565B
    convXGY_888_To_YGX_565B,    //   BGR_565B
    convXGY_888_To_XGY_565L,    //   RGB_565L
    convXGY_888_To_YGX_565L,    //   BGR_565L
    convXGY_888_To_XGY_888,     //   RGB_888
    convXGY_888_To_YGX_888,     //   BGR_888
    convXGY_888_To_AXGY_8888,   //   ARGB_8888
    convXGY_888_To_AYGX_8888,   //   ABGR_8888
    convXGY_888_To_YGXA_8888,   //   BGRA_8888
    convXGY_888_To_XGYA_8888    //   RGBA_8888
  },
  // BGR_888
  {
    convXGY_888_To_YGX_555B,    //   RGB_555B
    convXGY_888_To_XGY_555B,    //   BGR_555B
    convXGY_888_To_YGX_555L,    //   RGB_555L
    convXGY_888_To_XGY_555L,    //   BGR_555L
    convXGY_888_To_YGX_565B,    //   RGB_565B
    convXGY_888_To_XGY_565B,    //   BGR_565B
    convXGY_888_To_YGX_565L,    //   RGB_565L
    convXGY_888_To_XGY_565L,    //   BGR_565L
    convXGY_888_To_YGX_888,     //   RGB_888
    convXGY_888_To_XGY_888,     //   BGR_888
    convXGY_888_To_AYGX_8888,   //   ARGB_8888
    convXGY_888_To_AXGY_8888,   //   ABGR_8888
    convXGY_888_To_XGYA_8888,   //   BGRA_8888
    convXGY_888_To_YGXA_8888    //   RGBA_8888
  },
  // ARGB_8888
  {
    convAXGY_8888_To_XGY_555B,   // RGB_555B
    convAXGY_8888_To_YGX_555B,   // BGR_555B
    convAXGY_8888_To_XGY_555L,   // RGB_555L
    convAXGY_8888_To_YGX_555L,   // BGR_555L
    convAXGY_8888_To_XGY_565B,   // RGB_565B
    convAXGY_8888_To_YGX_565B,   // BGR_565B
    convAXGY_8888_To_XGY_565L,   // RGB_565L
    convAXGY_8888_To_YGX_565L,   // BGR_565L
    convAXGY_8888_To_XGY_888,    // RGB_888
    convAXGY_8888_To_YGX_888,    // BGR_888
    convAXGY_8888_To_AXGY_8888,  // ARGB_8888
    convAXGY_8888_To_AYGX_8888,  // ABGR_8888
    convAXGY_8888_To_YGXA_8888,  // BGRA_8888
    convAXGY_8888_To_XGYA_8888   // RGBA_8888
  },
  // ABGR_8888
  {
    convAXGY_8888_To_YGX_555B,   // RGB_555B
    convAXGY_8888_To_XGY_555B,   // BGR_555B
    convAXGY_8888_To_YGX_555L,   // RGB_555L
    convAXGY_8888_To_XGY_555L,   // BGR_555L
    convAXGY_8888_To_YGX_565B,   // RGB_565B
    convAXGY_8888_To_XGY_565B,   // BGR_565B
    convAXGY_8888_To_YGX_565L,   // RGB_565L
    convAXGY_8888_To_XGY_565L,   // BGR_565L
    convAXGY_8888_To_YGX_888,    // RGB_888
    convAXGY_8888_To_XGY_888,    // BGR_888
    convAXGY_8888_To_AYGX_8888,  // ARGB_8888
    convAXGY_8888_To_AXGY_8888,  // ABGR_8888
    convAXGY_8888_To_XGYA_8888,  // BGRA_8888
    convAXGY_8888_To_YGXA_8888   // RGBA_8888
  },
  // BGRA_8888
  {
    convXGYA_8888_To_YGX_555B,   // RGB_555B
    convXGYA_8888_To_XGY_555B,   // BGR_555B
    convXGYA_8888_To_YGX_555L,   // RGB_555L
    convXGYA_8888_To_XGY_555L,   // BGR_555L
    convXGYA_8888_To_YGX_565B,   // RGB_565B
    convXGYA_8888_To_XGY_565B,   // BGR_565B
    convXGYA_8888_To_YGX_565L,   // RGB_565L
    convXGYA_8888_To_XGY_565L,   // BGR_565L
    convXGYA_8888_To_YGX_888,    // RGB_888
    convXGYA_8888_To_XGY_888,    // BGR_888
    convXGYA_8888_To_AYGX_8888,  // ARGB_8888
    convXGYA_8888_To_AXGY_8888,  // ABGR_8888
    convXGYA_8888_To_XGYA_8888,  // BGRA_8888
    convXGYA_8888_To_YGXA_8888   // RGBA_8888
  },
  // RGBA_8888
  {
    convXGYA_8888_To_XGY_555B,   // RGB_555B
    convXGYA_8888_To_YGX_555B,   // BGR_555B
    convXGYA_8888_To_XGY_555L,   // RGB_555L
    convXGYA_8888_To_YGX_555L,   // BGR_555L
    convXGYA_8888_To_XGY_565B,   // RGB_565B
    convXGYA_8888_To_YGX_565B,   // BGR_565B
    convXGYA_8888_To_XGY_565L,   // RGB_565L
    convXGYA_8888_To_YGX_565L,   // BGR_565L
    convXGYA_8888_To_XGY_888,    // RGB_888
    convXGYA_8888_To_YGX_888,    // BGR_888
    convXGYA_8888_To_AXGY_8888,  // ARGB_8888
    convXGYA_8888_To_AYGX_8888,  // ABGR_8888
    convXGYA_8888_To_YGXA_8888,  // BGRA_8888
    convXGYA_8888_To_XGYA_8888   // RGBA_8888
  }
};

Pixel::ConvertIdx Pixel::convertIdx2RGB[Pixel::CUSTOM_FB-1] = {
  nopIdx,  //   RGB_555B
  nopIdx,  //   BGR_555B
  nopIdx,  //   RGB_555L
  nopIdx,  //   BGR_555L
  nopIdx,  //   RGB_565B
  nopIdx,  //   BGR_565B
  nopIdx,  //   RGB_565L
  nopIdx,  //   BGR_565L
  nopIdx,  //   RGB_888
  nopIdx,  //   BGR_888
  nopIdx,  //   ARGB_8888
  nopIdx,  //   ABGR_8888
  nopIdx,  //   BGRA_8888
  nopIdx   //   RGBA_8888
};



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

