///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         gfxlib/pixelmap.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Display classes
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

#ifndef _EXNG2_GFXLIB_PIXELMAP_HPP_
# define _EXNG2_GFXLIB_PIXELMAP_HPP_

# include <gfxlib/rects.hpp>
# include <gfxlib/palette.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  AbstractPixelMap
//
//  Parent interface for pixel based resources
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class AbstractPixelMap : public GfxArea {
  DEFINE_MIN_RTTI
  public:

    // inspectors
/*
    GfxArea
    sint16 getWidth()   const { return width; }
    sint16 getHeight()  const { return height; }
*/
    virtual const Pixel::Layout*  getDescriptor() const = 0;
    virtual Pixel::FBType         getFormat()     const = 0;

    // modifiers
    virtual void* lockData()                            = 0;
    virtual void  unlockData()                          = 0;
    virtual void  clear(Colour32 c)                     = 0;

    ~AbstractPixelMap() {};
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  ImageBuffer
//
//  Simple implementation of AbstractPixelMap
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class ImageBuffer : public AbstractPixelMap {
  DEFINE_MIN_RTTI

  public:
    enum {
      IB_CLONE_PALETTE    = 0x00000001,
      IB_CLONE_DESCRIPTOR = 0x00000002,
      IB_CREATE_PALETTE   = 0x00000004
    };

    // inspectors
    const Pixel::Layout*  getDescriptor() const;
    Pixel::FBType         getFormat()     const;


    // modifiers
    void*     lockData();
    void      unlockData();
    void      clear(Colour32 c);
    Palette*  getPalette(); // returned palette is mutable
    void      setPalette(Palette* p, uint32 options);
    void      create(sint16 w, sint16 h, const Pixel::Layout* d, Palette* p=0, uint32 options=0);
    void      create(sint16 w, sint16 h, Pixel::FBType f, Palette* p=0, uint32 options=0);
    void      destroy();


    ImageBuffer();
    virtual ~ImageBuffer();

  private:
    enum {
      IB_OWN_DATA     = 0x80000001,
      IB_LOCKED       = 0x00000002
    };

    void assertAllocated()  const { if (!data) THROW_NSX(Error, ObjectStateViolation()); }
    void assertFree()       const { if (data) THROW_NSX(Error, ObjectStateViolation()); }

    void createOwnPalette(const Palette* p);
    void createOwnDescriptor(const Pixel::Layout* d);


    void*                 data;
    Palette*              ownPalette;
    Pixel::Layout*        ownDescriptor;
    Palette*              palette;
    const Pixel::Layout*  descriptor;
    Pixel::FBType         format;
    uint32                flags;

    LOGGING_DEFINE_CLASSNAME

};

class ImageLoader {
  public:
    static ImageBuffer* loadImage(const char* name, bool aligned=true);

  private:
    LOGGING_DEFINE_CLASSNAME
};

#endif
