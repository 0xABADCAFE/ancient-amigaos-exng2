///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         gfxlib/palette.hpp
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

#include <gfxlib/display.hpp>
#include <private/systemlib/error.hpp>
#include <private/gfxlib/display_private.hpp>
#include <systemlib/memory.hpp>
#include <cstring>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Display::Properties
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ConstRefList<Display::Properties>* Display::Properties::modeList   = 0;

float64 Display::Properties::getHorizontalRefreshRatekHz() const
{
  return 1000000.0 / (float64)horizRefreshNanos;
}

float64 Display::Properties::getVerticalRefreshRateHz() const
{
  return 1000000.0 / (float64)vertRefreshMicros;
}

ConstRefList<Display::Properties>::Iterator Display::Properties::getAvailableModes()
{
  if (!modeList) {
    THROW_NSX(Error, NullPointer());
  }
  return ConstRefList<Display::Properties>::Iterator(*modeList);
}

const Display::Properties* Display::Properties::getWindowedMode()
{
  return EXNGPrivate::DisplayDatabase::getWindowedMode();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  EXNGPrivate::DisplayMode
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void EXNGPrivate::DisplayMode::setUniqueId(uint32 id)
{
  uniqueId = id;
}

void EXNGPrivate::DisplayMode::setTiming(uint32 h, uint32 v)
{
  horizRefreshNanos = h;
  vertRefreshMicros = v;
}

void EXNGPrivate::DisplayMode::setDimension(sint16 w, sint16 h)
{
  width = w;
  height = h;
  aspect = ((float32)h/(float32)w)/0.75;
}

void EXNGPrivate::DisplayMode::setAspect(float32 a)
{
  aspect = a;
}

void EXNGPrivate::DisplayMode::setFormat(Pixel::FBType f, Pixel::FBDepth d)
{
  pixelHWType = f;
  if (d==Pixel::BPP0) {
    switch (f) {
      case Pixel::LUT_8:      d = Pixel::BPP8; break;
      case Pixel::RGB_555B:
      case Pixel::BGR_555B:
      case Pixel::RGB_555L:
      case Pixel::BGR_555L:   d = Pixel::BPP15; break;
      case Pixel::RGB_565B:
      case Pixel::BGR_565B:
      case Pixel::RGB_565L:
      case Pixel::BGR_565L:   d = Pixel::BPP16; break;
      case Pixel::RGB_888:
      case Pixel::BGR_888:    d = Pixel::BPP24; break;
      case Pixel::ARGB_8888:
      case Pixel::ABGR_8888:
      case Pixel::RGBA_8888:
      case Pixel::BGRA_8888:  d = Pixel::BPP32; break;
      default: break;
    }
  }
  pixelDepth = d;
}

void EXNGPrivate::DisplayMode::setName(const char* title)
{
  std::strncpy(name, title, sizeof(name)-1);
}

////////////////////////////////////////////////////////////////////////////////
//
//  DisplayDatabase
//
////////////////////////////////////////////////////////////////////////////////

EXNGPrivate::DisplayMode* EXNGPrivate::DisplayDatabase::availableModes  = 0;
size_t                    EXNGPrivate::DisplayDatabase::numModes        = 0;

bool EXNGPrivate::DisplayDatabase::allocPropertyNodes(size_t n)
{
  if (!availableModes)  {
    //void* p = Mem::alloc(n*sizeof(EXNGPrivate::DisplayMode), true);
    EXNGPrivate::DisplayMode* p = Mem::alloc<EXNGPrivate::DisplayMode>(n, Mem::NO_THROW);
    if (p) {
      numModes        = n;
      availableModes  = p;//(EXNGPrivate::DisplayMode*)p;
    }
    else {
      numModes = 0;
      return false;
    }
  }

  return true;
}

////////////////////////////////////////////////////////////////////////////////

void EXNGPrivate::DisplayDatabase::freePropertyNodes()
{
  if (availableModes) {
    Mem::free(availableModes);
  }
  availableModes  = 0;
  numModes        = 0;
}

