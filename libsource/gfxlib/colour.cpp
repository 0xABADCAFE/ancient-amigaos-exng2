///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         gfxlib/colour.cpp
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

#include <gfxlib/colour.hpp>


////////////////////////////////////////////////////////////////////////////////
//
//  Colour
//
////////////////////////////////////////////////////////////////////////////////

Colour32& Colour32::blendReplaceAlpha(Colour32 c)
{
  uint16 alpha    = c.chan[ARGB_A];
  uint16 invAlpha = 255-alpha;
  chan[ARGB_R]    = ((alpha*c.chan[ARGB_R])+(invAlpha*chan[ARGB_R]))>>8;
  chan[ARGB_G]    = ((alpha*c.chan[ARGB_G])+(invAlpha*chan[ARGB_G]))>>8;
  chan[ARGB_B]    = ((alpha*c.chan[ARGB_B])+(invAlpha*chan[ARGB_B]))>>8;
  return *this;
}

Colour32& Colour32::blendSumAlpha(Colour32 c)
{
  uint16 alpha  = c.chan[ARGB_A];
  chan[ARGB_R]  += ((alpha*chan[ARGB_R])>>8);
  chan[ARGB_G]  += ((alpha*chan[ARGB_G])>>8);
  chan[ARGB_B]  += ((alpha*chan[ARGB_B])>>8);
  return *this;
}

Colour32& Colour32::blendSumSaturateAlpha(Colour32 c)
{
  uint16 alpha    = c.chan[ARGB_A];
  uint16 tmp      = chan[ARGB_R] + ((alpha*c.chan[ARGB_R])>>8);
  chan[ARGB_R]    = tmp>255 ? 255 : tmp;
  tmp             = chan[ARGB_G] + ((alpha*c.chan[ARGB_G])>>8);
  chan[ARGB_G]    = tmp>255 ? 255 : tmp;
  tmp             = chan[ARGB_B] + ((alpha*c.chan[ARGB_B])>>8);
  chan[ARGB_B]    = tmp>255 ? 255 : tmp;
  return *this;
}

Colour32& Colour32::blendMultiplyAlpha(Colour32 c)
{
  uint32 alpha    = c.chan[ARGB_A];
  uint32 invAlpha = (255-alpha)<<8;
  chan[ARGB_R]    = ((alpha*chan[ARGB_R]*c.chan[ARGB_R])+(invAlpha*chan[ARGB_R]))>>16;
  chan[ARGB_G]    = ((alpha*chan[ARGB_G]*c.chan[ARGB_G])+(invAlpha*chan[ARGB_G]))>>16;
  chan[ARGB_B]    = ((alpha*chan[ARGB_B]*c.chan[ARGB_B])+(invAlpha*chan[ARGB_B]))>>16;
  return *this;
}

Colour32 Colour32::interpolate(Colour32 c1, Colour32 c2, float32 frac)
{
  union {
    uint32 argb;
    uint8  chan[4];
  } tmp;
  float32 inv = 1.0f-frac;
  tmp.chan[ARGB_A] = (uint8) (c1.chan[ARGB_A]*frac + c2.chan[ARGB_A]*inv);
  tmp.chan[ARGB_R] = (uint8) (c1.chan[ARGB_R]*frac + c2.chan[ARGB_R]*inv);
  tmp.chan[ARGB_G] = (uint8) (c1.chan[ARGB_G]*frac + c2.chan[ARGB_G]*inv);
  tmp.chan[ARGB_B] = (uint8) (c1.chan[ARGB_B]*frac + c2.chan[ARGB_B]*inv);
  return Colour32(tmp.argb);
}

/*
uint32 Colour32::getPixelRep(const Pixel::Descriptor *p) const
{
  // Generates a value representing the colour expressed as a pixel defined by
  // the PixelDescriptor. This method is completely generic and assumes nothing
  // about the pixel format. For standard pixel formats, there are individually
  // optimised routines.

  ruint32 ret = 0;

  rfloat32 sf = (1.0/255.0); // this 'normalizes' our colour channel value
  if (p->getBitsAlpha()) {
    ret = (uint32)(sf*((uint16)chan[ARGB_A]*(uint16)p->getMaxAlpha()))<<p->getShiftAlpha();
  }
  ret |= (uint32)(sf*((uint16)chan[ARGB_R]*(uint16)p->getMaxRed()))<<p->getShiftRed();
  ret |= (uint32)(sf*((uint16)chan[ARGB_G]*(uint16)p->getMaxGreen()))<<p->getShiftGreen();
  ret |= (uint32)(sf*((uint16)chan[ARGB_B]*(uint16)p->getMaxBlue()))<<p->getShiftBlue();

  if (p->isSwapped()) {
    // handle byteswapping if required
    if (p->getSize()==2) {
      return (ret>>8 | ret<<8) & 0x0000FFFF;
    } else if (p->getSize()==4) {
      return ret<<24 | ((ret<<16)&0x00FF0000) | ((ret>>16)&0x0000FF00) | ret>>24;
    }
  }
  return ret;
}

////////////////////////////////////////////////////////////////////////////////

void Colour32::setFromPixel(const Pixel::Descriptor *p, uint32 data)
{
  // Converts a pixel value into a Colour using the specified PixelDescriptor.
  // This method is completely generic and assumes nothing
  // about the pixel format. For standard pixel formats, there are individually
  // optimised routines.

  if (p->isSwapped()) {
    // handle byteswapping if required
    if (p->getSize()==2) {
      data = (data<<8 | data>>8) & 0x0000FFFF;
    } else if (p->getSize()==4) {
      data = data<<24 | ((data<<16)&0x00FF0000) | ((data>>16)&0x0000FF00) | data>>24;
    }
  }

  argb = 0; // quickly zero colour representation

  // For each channel, isolate the bits using getMask...()
  // Convert masked range to integer using getShift...()
  // Scale by 255 and divide through by getMax...() to get the 0..255 range used by Colour

  // Note : is floating point scaling better for this?

  if ((data & p->getMaskAlpha())!=0) {
    alpha() = (uint8)((255UL*(data & p->getMaskAlpha())>>p->getShiftAlpha())/p->getMaxAlpha());
  }
  if (data & p->getMaskRed()!=0) {
    red() = (uint8)((255UL*(data & p->getMaskRed())>>p->getShiftRed())/p->getMaxRed());
  }
  if (data & p->getMaskGreen()!=0) {
    green() = (uint8)((255UL*(data & p->getMaskGreen())>>p->getShiftGreen())/p->getMaxGreen());
  }
  if (data & p->getMaskBlue()!=0) {
    blue() = (uint8)((255UL*(data & p->getMaskBlue())>>p->getShiftBlue())/p->getMaxBlue());
  }
}
*/
