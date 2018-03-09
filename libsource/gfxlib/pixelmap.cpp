///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         gfxlib/pixelmap.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:
//  Comment(s):
//  Library:      gfxlib
//  Created:      2006-10-08
//  Updated:      2006-10-08
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <gfxlib/pixelmap.hpp>
#include <systemlib/memory.hpp>
#include <new>

DECLARE_MIN_RTTI(AbstractPixelMap)
DECLARE_MIN_RTTI(ImageBuffer)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const Pixel::Layout* ImageBuffer::getDescriptor() const
{
  assertAllocated();
  return descriptor;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Pixel::FBType ImageBuffer::getFormat() const
{
  assertAllocated();
  return format;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Palette* ImageBuffer::getPalette() const
{
  assertAllocated();
  return palette;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void* ImageBuffer::lockData()
{
  assertAllocated();
  return data;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void  ImageBuffer::unlockData()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void  ImageBuffer::clear(Colour32 c)
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void  ImageBuffer::create(sint16 w, sint16 h, const Pixel::Layout* d, Palette* p, uint32 options)
{
  assertFree();
  if (!d) {
    THROW_NSX(Error, NullPointer());
  } else if (w<1 || h<1) {
    THROW_NSX(Error, InvalidValue());
  }

  // check to see if the palette needs cloning. May throw Mem::Exhausted on first attempt
  if (options & IB_CLONE_PALETTE) {
    createOwnPalette(p);
    palette = ownPalette;
  } else {
    palette = p;
  }

  // check to see if the descriptor needs cloning. May throw Mem::Exhausted on first attempt
  if (options & IB_CLONE_DESCRIPTOR) {
    createOwnDescriptor(d);
    descriptor = ownDescriptor;
  } else {
    descriptor = d;
  }

  // allocate the needed storage. May throw Mem::Exhausted
  data    = Mem::alloc( w*h*d->getAccessSize() );
  format  = Pixel::CUSTOM_FB;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void  ImageBuffer::create(sint16 w, sint16 h, Pixel::FBType f, Palette* p, uint32 options)
{
  // jump into descriptor based call
  create(w, h, Pixel::getDescriptor(f), p, (options & ~IB_CLONE_DESCRIPTOR));
  format = f;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void  ImageBuffer::destroy()
{
  if (data) {
    Mem::free(data);
    data = 0;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ImageBuffer::createOwnPalette(const Palette* p)
{
  if (!p) {
    THROW_NSX(Error, NullPointer());
  }
  if (!ownPalette && !(ownPalette = new(std::nothrow) Palette(*p))) {
    THROW_NSX(Mem, Exhausted(sizeof(Palette)));
  } else {
    *ownPalette = *p;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ImageBuffer::createOwnDescriptor(const Pixel::Layout* d)
{
  if (!ownDescriptor && !(ownDescriptor = new(std::nothrow) Pixel::Layout(*d))) {
    THROW_NSX(Mem, Exhausted(sizeof(Pixel::Layout)));
  } else {
    *ownDescriptor = *d;
  }
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ImageBuffer::ImageBuffer() : AbstractPixelMap(), data(0), ownPalette(0), ownDescriptor(0),
                             palette(0), descriptor(0), format(Pixel::LUT_8), flags(0)
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ImageBuffer::~ImageBuffer()
{
  destroy();
  delete ownPalette;
  delete ownDescriptor;
}

