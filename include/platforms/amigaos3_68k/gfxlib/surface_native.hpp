///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         gfxlib/surface_native.hpp
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

#ifndef _EXNG2_GFXLIB_SURFACE_NATIVE_HPP_
# define _EXNG2_GFXLIB_SURFACE_NATIVE_HPP_

namespace EXNGPrivate {
  class SurfaceProvider;
  class SurfaceUser;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Display::Surface
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class Display::Surface : public AbstractPixelMap {
  friend class EXNGPrivate::SurfaceProvider;
  friend class EXNGPrivate::SurfaceUser;
  private:
    OSNative::Window* winUser;  // this handle is used by AmigaOS Draw2D implementation
    OSNative::BitMap* bitMap;
    const Palette*    palette;
    void*             gfxAddr;
    void*             lockAddr;
    uint32            properties;
    sint16            hwWidth;  // Hardware rounded width
    sint16            hwHeight; // Hardware rounded height
    sint16            modulus;  // Row modulus for direct access
    sint16            depth;
    Pixel::FBType     pixFormat;
    void              queryBitMap();
    void              init();
    void              allocateBitMap(OSNative::BitMap* clone, sint16 w, sint16 h);
    void              releaseBitMap();
    void              assertAllocated()  const;
    void              assertFree()       const;

    Surface(OSNative::BitMap* bmp, uint32 flags, sint16 w, sint16 h);

    static Surface*           createFromBitMap(OSNative::BitMap* bmp);
    static Surface*           createLikeBitMap(OSNative::BitMap* bmp, sint16 w, sint16 h);
    static void               assertRTG(OSNative::BitMap* b);
    static OSNative::BitMap*  createBitMap(OSNative::BitMap* clone, sint16 w, sint16 h);


  protected:

    enum {
      SP_OWN_BITMAP = 0x00000001, // internally allocated BitMap
      SP_EXT_BITMAP = 0x00000002, // externally provided BitMap
      SP_LINEAR_MEM = 0x00000004,
    };

    static void       blitCopy(
      Surface* dst,
      sint16 x1, sint16 y1,
      Surface* src,
      sint16 x2, sint16 y2,
      sint16 w, sint16 h
    );

  public:
    const Palette*        getIndexedPalette() const { return palette; }

    const Pixel::Layout*  getDescriptor() const;

    bool                  isAllocated()   const { return (bitMap != 0); }
    bool                  isLinear()      const { return ((properties & SP_LINEAR_MEM) != 0); }
    Pixel::FBType         getFormat()     const { return pixFormat; }
    sint32                getDepth()      const { return depth; }   // in bits
    sint32                getModulus()    const { return modulus; } // in pixel units

    sint32                getHWWidth()    const { return hwWidth; }
    sint32                getHWHeight()   const { return hwHeight; }

    // Elemental draw access
    void*                 lockData();
    void                  unlockData();
    void                  clear(Colour32 c);
    //sint32  putImageBuffer(ImageBuffer* img, S_CRD1, S_CRD2, S_WH);
    void                  putSurface(
      Surface* other,
      sint16 x1, sint16 y1,
      sint16 x2, sint16 y2,
      sint16 w, sint16 h
    ) {
      return blitCopy(this, x1, y1, other, x2, y2, w, h);
    }

  public:
    // User creation of new surfaces via factory only
    static Surface* create(Surface* clone, sint16 w, sint16 h);
    ~Surface()  { releaseBitMap(); }

    LOGGING_DEFINE_CLASSNAME

};

namespace EXNGPrivate {

  class SurfaceUser {
    protected:
      static OSNative::BitMap*  getSurfaceBitMap(Display::Surface* s)                                     { return s->bitMap; }
      static OSNative::Window*  getWinUser(Display::Surface* s)                                           { return s->winUser; }
      static bool checkCompatible(Display::Surface* s, OSNative::BitMap* b);
  };

  class SurfaceProvider : public SurfaceUser {
    protected:
      static void     releaseSurface(Display::Surface* s)                                                 { s->releaseBitMap(); }
      static void     cloneBitMapToSurface(Display::Surface* s, OSNative::BitMap* b, sint16 w, sint16 h)  { s->allocateBitMap(b, w, h); }
      static void     assignBitMapToSurface(Display::Surface* s, OSNative::BitMap* b);
      static void     assignBitMapToSurfaceQuick(Display::Surface* s, OSNative::BitMap* b)                { s->bitMap = b; }
      static void     setWinUser(Display::Surface* s, OSNative::Window* w)                                { s->winUser = w; }
      static void     setSurfacePalette(Display::Surface* s, const Palette* pal)                          { s->palette = pal; }

      static Display::Surface*  createNewSurfaceFromBitMap(OSNative::BitMap* b)
      {
        return Display::Surface::createFromBitMap(b);
      }
      static Display::Surface*  createNewSurfaceLikeBitMap(OSNative::BitMap* b, sint16 w, sint16 h)
      {
        return Display::Surface::createLikeBitMap(b, w, h);
      }


  };

};


#endif
