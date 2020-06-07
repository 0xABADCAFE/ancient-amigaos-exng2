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

LOGGING_DECLARE_CLASSNAME(ImageBuffer)


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

Palette* ImageBuffer::getPalette()
{
  assertAllocated();
  return palette;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void* ImageBuffer::lockData()
{
  LOGGING_DECLARE_FUNCNAME(lockData)

  assertAllocated();

  #ifdef EXNG2_BUILD_LOGGED
  SystemLog::write(
    SystemLog::INFO,
    "%s::%s - aquired lock\n",
    loggingClassName, loggingFuncName
  );
  #endif

  return data;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void  ImageBuffer::unlockData()
{
  LOGGING_DECLARE_FUNCNAME(unlockData)

  #ifdef EXNG2_BUILD_LOGGED
  SystemLog::write(
    SystemLog::INFO,
    "%s::%s - releasing lock\n",
    loggingClassName, loggingFuncName
  );
  #endif

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void  ImageBuffer::clear(Colour32 c)
{
  LOGGING_DECLARE_FUNCNAME(clear)

  #ifdef EXNG2_BUILD_LOGGED
  SystemLog::write(
    SystemLog::INFO,
    "%s::%s - clearing to %08" XPF_U32 "\n",
    loggingClassName, loggingFuncName, c.getMachineRep()
  );
  #endif

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void  ImageBuffer::create(sint16 w, sint16 h, const Pixel::Layout* d, Palette* p, uint32 options)
{
  LOGGING_DECLARE_FUNCNAME(create)

  assertFree();
  if (!d) {
    THROW_NSX(Error, NullPointer());
  } else if (w<1 || h<1) {
    THROW_NSX(Error, InvalidValue());
  }



  // check to see if the palette needs cloning. May throw Mem::Exhausted on first attempt

  if (options & (IB_CLONE_PALETTE|IB_CREATE_PALETTE)) {
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

  width   = w;
  height  = h;

  #ifdef EXNG2_BUILD_LOGGED
  SystemLog::write(
    SystemLog::INFO,
    "%s::%s - created data @ %p, descriptor @%p, palette @ %p [w:%" XPF_S16 ", h:%" XPF_S16 ", f:%d]\n",
    loggingClassName, loggingFuncName, data, descriptor, palette, width, height, format
  );
  #endif
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void  ImageBuffer::create(sint16 w, sint16 h, Pixel::FBType f, Palette* p, uint32 options)
{
  LOGGING_DECLARE_FUNCNAME(clear)

  // jump into descriptor based call
  create(w, h, Pixel::getDescriptor(f), p, (options & ~IB_CLONE_DESCRIPTOR));
  format = f;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void  ImageBuffer::destroy()
{
  LOGGING_DECLARE_FUNCNAME(destroy)

  if (data) {

    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::INFO,
      "%s::%s - destroying data at %p\n",
      loggingClassName, loggingFuncName, data
    );
    #endif

    Mem::free(data);
    data = 0;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ImageBuffer::createOwnPalette(const Palette* p)
{
  LOGGING_DECLARE_FUNCNAME(createOwnPalette)

  // create own palette if it doesn't exist. If we have been passed a reference,
  // clone it.

  if (
    !ownPalette &&
    !(ownPalette = p ? new (std::nothrow) Palette(*p) : // copy construct
                       new (std::nothrow) Palette())    // vanilla construct
  ) {
    THROW_NSX(Mem, Exhausted(sizeof(Palette)));
  }
  else if (p) {
    *ownPalette = *p; // vanilla clone
  }

  #ifdef EXNG2_BUILD_LOGGED
  SystemLog::write(
    SystemLog::INFO,
    "%s::%s - ownPalette @ %p\n",
    loggingClassName, loggingFuncName, ownPalette
  );
  #endif
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ImageBuffer::createOwnDescriptor(const Pixel::Layout* d)
{
  LOGGING_DECLARE_FUNCNAME(createOwnDescriptor)

  if (!ownDescriptor && !(ownDescriptor = new(std::nothrow) Pixel::Layout(*d))) {
    THROW_NSX(Mem, Exhausted(sizeof(Pixel::Layout)));
  } else {
    *ownDescriptor = *d;
  }

  #ifdef EXNG2_BUILD_LOGGED
  SystemLog::write(
    SystemLog::INFO,
    "%s::%s - ownDesrciptor @ %p\n",
    loggingClassName, loggingFuncName, ownPalette
  );
  #endif
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ImageBuffer::ImageBuffer() : AbstractPixelMap(), data(0), ownPalette(0), ownDescriptor(0),
                             palette(0), descriptor(0), format(Pixel::LUT_8), flags(0)
{
  #ifdef EXNG2_BUILD_LOGGED
  SystemLog::write(
    SystemLog::INFO,
    "%s::%s - instance created\n",
    loggingClassName, loggingClassName
  );
  #endif
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ImageBuffer::~ImageBuffer()
{
  destroy();
  delete ownPalette;
  delete ownDescriptor;
  #ifdef EXNG2_BUILD_LOGGED
  SystemLog::write(
    SystemLog::INFO,
    "%s::~%s - instance destroyed\n",
    loggingClassName, loggingClassName
  );
  #endif
}

