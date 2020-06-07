///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         gfxlib/pixel.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Pixel definitions
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

#ifndef _EXNG2_GFXLIB_PIXEL_HPP_
# define _EXNG2_GFXLIB_PIXEL_HPP_

# include <gfxlib/gfx.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Pixel
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace EXNGPrivate {
  class GfxResource;
}

class Pixel {

  public:
    typedef enum {
      INVALID_FMT = -1,
      LUT_8       = 0,  // 8-bit
      RGB_555B    = 1,  // 15-bit, RGB    5:5:5, big endian
      BGR_555B    = 2,  // 15-bit, BGR    5:5:5, big endian
      RGB_555L    = 3,  // 15-bit, RGB    5:5:5, little endian
      BGR_555L    = 4,  // 15-bit, BGR    5:5:5, little endian
      RGB_565B    = 5,  // 16-bit, RGB    5:6:5, big endian
      BGR_565B    = 6,  // 16-bit, BGR    5:6:5, big endian
      RGB_565L    = 7,  // 16-bit, RGB    5:6:5, little endian
      BGR_565L    = 8,  // 16-bit, BGR    5:6:5, little endian
      RGB_888     = 9,  // 24-bit, RGB    8:8:8, byte packed
      BGR_888     = 10, // 24-bit, BGR    8:8:8, byte packed
      ARGB_8888   = 11,
      ABGR_8888   = 12,
      BGRA_8888   = 13,
      RGBA_8888   = 14,

      CUSTOM_FB   = 15, // Other format, requires Layout
    } FBType;

    typedef enum {
      BPP0    = 0,
      BPP8    = 8,
      BPP15   = 15,
      BPP16   = 16,
      BPP24   = 24,
      BPP32   = 32
    } FBDepth;

    class Layout {
      friend class Pixel;

      friend bool operator==(const Layout& a, const Layout& b);
      friend bool operator!=(const Layout& a, const Layout& b);

      public:

        typedef enum {
          // RGB/RGBA
          RED        = 0,
          GREEN      = 1,
          BLUE       = 2,
          ALPHA      = 3,

          // CYM / CYMK
          CYAN       = 4,
          YELLOW     = 5,
          MAGENTA    = 6,
          BLACK      = 7,

          // HSV / HSL
          HUE        = 8,
          SATURATION = 9,
          VALUE      = 10,
          LUMINANCE  = 11,

          // other
          CUSTOM_0    = 12,
          CUSTOM_1    = 13,
          CUSTOM_2    = 14,
          CUSTOM_3    = 15,

          // Other oddities
          INDEX      = 10,
          INTENSITY  = 10,
          DEF_MAX    = 15
        } Component;

        enum {
          HAS_RED         = 0x00000001,
          HAS_GREEN       = 0x00000002,
          HAS_BLUE        = 0x00000004,
          HAS_ALPHA       = 0x00000008,
          HAS_CYAN        = 0x00000010,
          HAS_YELLOW      = 0x00000020,
          HAS_MAGENTA     = 0x00000040,
          HAS_BLACK       = 0x00000080,
          HAS_HUE         = 0x00000100,
          HAS_SATURATION  = 0x00000200,
          HAS_VALUE       = 0x00000400,
          HAS_LUMINANCE   = 0x00000800,
          HAS_CUSTOM_0    = 0x00001000,
          HAS_CUSTOM_1    = 0x00002000,
          HAS_CUSTOM_2    = 0x00004000,
          HAS_CUSTOM_3    = 0x00008000,
          IS_BYTESWAPPED  = 0x00010000,
          IS_FLOAT_FORMAT = 0x00020000,
          IS_DISPLAYABLE  = 0x00040000,
          MASK_CHAN_SPEC  = 0x0000FFFF,
          MASK_USER_SET   = IS_BYTESWAPPED|IS_FLOAT_FORMAT,
        };

        static uint32 packCP(uint8 a, uint8 b=0, uint8 c=0, uint8 d=0)
        {
          return d<<24|c<<16|b<<8|a;
        }

        static uint32 packBP(uint32 flags, Machine::ElemType e, uint8 n)
        {
          return (flags&MASK_USER_SET)|e<<8|n;
        }

        uint32            getNumComponents()              const { return props[2]; }
        size_t            getAccessSize()                 const { return props[3]; }
        Machine::ElemType getAccessType()                 const { return (Machine::ElemType)props[1]; }
        Machine::ElemType getComponentAccessType()        const { return (Machine::ElemType)props[0]; }

        uint32            getWidth(Component c)           const { return width[getIdxComp(c)]; }
        uint32            getPosition(Component c)        const { return pos[getIdxComp(c)]; }

        uint32            getMask(Component c)            const;
        uint32            getMax(Component c)             const;

        Component         getComponentType(uint32 ch)     const;
        uint32            getComponentWidth(uint32 ch)    const;
        uint32            getComponentPosition(uint32 ch) const;
        uint32            getComponentNumBits(uint32 ch)  const;
        uint32            getComponentMask(uint32 ch)     const;
        uint32            getComponentMax(uint32 ch)      const;

        uint32            getFlags(uint32 mask)           const { return flags & mask; }

        bool              compare(const Layout& layout) const;

        // constructor for bitfield-based formats.
        // These are restricted to a maximum of 32-bits
        // Wider formats require the use of elemental types
        Layout(
          uint32            bProps,
          uint32            compDef,
          uint32            fldWidth,
          uint32            fldPos
        );

        // constructor for element-based formats
        Layout(
          uint32            bProps,
          uint32            compDef
        );
      private:
        enum {
          MIN_CHANNELS    = 1,
          MAX_CHANNELS    = 4,
        };



        uint32  getIdxComp(Component c) const;

        uint32  computeMax(uint32 ch)   const;
        uint32  computeMask(uint32 ch)  const;

        void    initCompMap(size_t n, uint32 compDef);
        void    initBitfield(uint32 fldW, uint32 fldP, uint8 t, uint8 s);
        void    initElemental(size_t elemSize);

        uint32  flags;      // lower 16-bits specify available components
        uint32  compMap;    // maps component to channel number
/*
        uint8   compType;
        uint8   wordType;
        uint8   compNum;    // values are 1 - 4
        uint8   sizeBytes;
*/
        union {
          uint32  props_u32;
          uint8   props[4];
        };

        union {
          uint32  comp_u32;
          uint8   comp[4];  // values are Component enum
        };

        union {
          uint32  width_u32;
          uint8   width[4];  // values in bits or bytes depending on type
        };

        union {
          uint32  pos_u32;
          uint8   pos[4];  // values in bits or bytes depending on type
        };

      private:
        LOGGING_DEFINE_CLASSNAME
    };


    static FBType   getPrefferedFormat(uint32 depth);
    static Layout*  getDescriptor(FBType type)
    {
      return &fbTypeLayout[type];
    }

  private:
    // although values are specified as 32-bit unsigned, system specific limits apply
    #define PIXCONV_ARGS  void* dst, const void* src, uint32 w, uint32 h, uint32 dstMod, uint32 srcMod
    #define PIXCONV_ARGS2 void* dst, const void* src, const uint32* sPal, uint32 w, uint32 h, uint32 dstMod, uint32 srcMod

    typedef void (*ConvertRGB)(PIXCONV_ARGS);
    typedef void (*ConvertIdx)(PIXCONV_ARGS2);

    static ConvertRGB convertRGB[CUSTOM_FB-1][CUSTOM_FB-1];
    static ConvertIdx convertIdx2RGB[CUSTOM_FB-1];

    static uint8    fbPrefFormats [6]; // preferred formats for depth
    static Layout   fbTypeLayout  [Pixel::CUSTOM_FB];
};

inline bool operator!=(const Pixel::Layout& a, const Pixel::Layout &b)
{
  return !(a==b);
}


#endif
