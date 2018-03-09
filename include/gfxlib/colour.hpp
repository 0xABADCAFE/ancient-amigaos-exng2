///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         gfxlib/colour.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Colour classes
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

#ifndef _EXNG2_GFXLIB_COLOUR_HPP_
# define _EXNG2_GFXLIB_COLOUR_HPP_

# include <xbase.hpp>

# if (X_ENDIAN == XA_BIGENDIAN)
#   define ARGB_A 0
#   define ARGB_R 1
#   define ARGB_G 2
#   define ARGB_B 3
#   define COMP_0 0
#   define COMP_1 1
#   define COMP_2 2
#   define COMP_3 3
# else
#   define ARGB_A 3
#   define ARGB_R 2
#   define ARGB_G 1
#   define ARGB_B 0
#   define COMP_0 3
#   define COMP_1 2
#   define COMP_2 1
#   define COMP_3 0
# endif

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Colour8888 {
  protected:
    union {
      uint32  u32;
      uint8   u8[4];
    };
};

class ColourARGB_8888;
class ColourABGR_8888;
class ColourRGBA_8888;
class ColourBGRA_8888;

class ColourARGB_8888 : public Colour8888 {

  friend bool operator==(const ColourARGB_8888&, const ColourARGB_8888&);
  friend bool operator==(const ColourARGB_8888&, const ColourABGR_8888&);
  friend bool operator==(const ColourARGB_8888&, const ColourRGBA_8888&);
  friend bool operator==(const ColourARGB_8888&, const ColourBGRA_8888&);
  friend bool operator!=(const ColourARGB_8888&, const ColourARGB_8888&);
  friend bool operator!=(const ColourARGB_8888&, const ColourABGR_8888&);
  friend bool operator!=(const ColourARGB_8888&, const ColourRGBA_8888&);
  friend bool operator!=(const ColourARGB_8888&, const ColourBGRA_8888&);

  public:
    ColourARGB_8888(uint32 c=0xFF000000)  { u32 = c; }

    uint8&  alpha()                       { return u8[COMP_0]; }
    uint8&  red()                         { return u8[COMP_1]; }
    uint8&  green()                       { return u8[COMP_2]; }
    uint8&  blue()                        { return u8[COMP_3]; }

    uint32  alpha()                       const { return u8[COMP_0]; }
    uint32  red()                         const { return u8[COMP_1]; }
    uint32  green()                       const { return u8[COMP_2]; }
    uint32  blue()                        const { return u8[COMP_3]; }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ColourABGR_8888 : public Colour8888 {

  friend bool operator==(const ColourABGR_8888&, const ColourARGB_8888&);
  friend bool operator==(const ColourABGR_8888&, const ColourABGR_8888&);
  friend bool operator==(const ColourABGR_8888&, const ColourRGBA_8888&);
  friend bool operator==(const ColourABGR_8888&, const ColourBGRA_8888&);
  friend bool operator!=(const ColourABGR_8888&, const ColourARGB_8888&);
  friend bool operator!=(const ColourABGR_8888&, const ColourABGR_8888&);
  friend bool operator!=(const ColourABGR_8888&, const ColourRGBA_8888&);
  friend bool operator!=(const ColourABGR_8888&, const ColourBGRA_8888&);

  public:
    ColourABGR_8888(uint32 c=0xFF000000)  { u32 = c; }

    uint8&  alpha()                       { return u8[COMP_0]; }
    uint8&  red()                         { return u8[COMP_3]; }
    uint8&  green()                       { return u8[COMP_2]; }
    uint8&  blue()                        { return u8[COMP_1]; }

    uint32  alpha()                       const { return u8[COMP_0]; }
    uint32  red()                         const { return u8[COMP_3]; }
    uint32  green()                       const { return u8[COMP_2]; }
    uint32  blue()                        const { return u8[COMP_1]; }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ColourRGBA_8888 : public Colour8888 {

  friend bool operator==(const ColourRGBA_8888&, const ColourARGB_8888&);
  friend bool operator==(const ColourRGBA_8888&, const ColourABGR_8888&);
  friend bool operator==(const ColourRGBA_8888&, const ColourRGBA_8888&);
  friend bool operator==(const ColourRGBA_8888&, const ColourBGRA_8888&);
  friend bool operator!=(const ColourRGBA_8888&, const ColourARGB_8888&);
  friend bool operator!=(const ColourRGBA_8888&, const ColourABGR_8888&);
  friend bool operator!=(const ColourRGBA_8888&, const ColourRGBA_8888&);
  friend bool operator!=(const ColourRGBA_8888&, const ColourBGRA_8888&);

  public:
    ColourRGBA_8888(uint32 c=0x000000FF)  { u32 = c; }

    uint8&  alpha()                       { return u8[COMP_3]; }
    uint8&  red()                         { return u8[COMP_2]; }
    uint8&  green()                       { return u8[COMP_1]; }
    uint8&  blue()                        { return u8[COMP_0]; }

    uint32  alpha()                       const { return u8[COMP_3]; }
    uint32  red()                         const { return u8[COMP_2]; }
    uint32  green()                       const { return u8[COMP_1]; }
    uint32  blue()                        const { return u8[COMP_0]; }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ColourBGRA_8888 : public Colour8888 {

  friend bool operator==(const ColourBGRA_8888&, const ColourARGB_8888&);
  friend bool operator==(const ColourBGRA_8888&, const ColourABGR_8888&);
  friend bool operator==(const ColourBGRA_8888&, const ColourRGBA_8888&);
  friend bool operator==(const ColourBGRA_8888&, const ColourBGRA_8888&);
  friend bool operator!=(const ColourBGRA_8888&, const ColourARGB_8888&);
  friend bool operator!=(const ColourBGRA_8888&, const ColourABGR_8888&);
  friend bool operator!=(const ColourBGRA_8888&, const ColourRGBA_8888&);
  friend bool operator!=(const ColourBGRA_8888&, const ColourBGRA_8888&);

  public:
    ColourBGRA_8888(uint32 c=0x000000FF)  { u32 = c; }

    uint8&  alpha()                       { return u8[COMP_3]; }
    uint8&  red()                         { return u8[COMP_1]; }
    uint8&  green()                       { return u8[COMP_2]; }
    uint8&  blue()                        { return u8[COMP_0]; }

    uint32  alpha()                       const { return u8[COMP_3]; }
    uint32  red()                         const { return u8[COMP_1]; }
    uint32  green()                       const { return u8[COMP_2]; }
    uint32  blue()                        const { return u8[COMP_0]; }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Colour32 {
  friend bool operator==(const Colour32&, const Colour32&);
  friend bool operator!=(const Colour32&, const Colour32&);
  private:
    union {
      uint32 argb;
      uint8  chan[4];
      sint32 i;
    };

  public:
    enum {
      BALANCE_RED   = 77,
      BALANCE_GREEN = 150,
      BALANCE_BLUE  = 28
    };

    Colour32(uint32 c=0xFF000000)       { argb = c; }
    uint8&  alpha()                     { return chan[ARGB_A]; }
    uint8&  red()                       { return chan[ARGB_R]; }
    uint8&  green()                     { return chan[ARGB_G]; }
    uint8&  blue()                      { return chan[ARGB_B]; }

    uint32  alpha()                     const { return chan[ARGB_A]; }
    uint32  red()                       const { return chan[ARGB_R]; }
    uint32  green()                     const { return chan[ARGB_G]; }
    uint32  blue()                      const { return chan[ARGB_B]; }

    uint32  getMachineRep()             const { return argb; }

    Colour32& blendSum(Colour32 c)
    {
      chan[ARGB_R] += c.chan[ARGB_R];
      chan[ARGB_G] += c.chan[ARGB_G];
      chan[ARGB_B] += c.chan[ARGB_B];
      return *this;
    }

    Colour32& blendSumSaturate(Colour32 c)
    {
      uint16 tmp      = chan[ARGB_R] + c.chan[ARGB_R];
      chan[ARGB_R]    = tmp>255 ? 255 : tmp;
      tmp             = chan[ARGB_G] + c.chan[ARGB_G];
      chan[ARGB_G]    = tmp>255 ? 255 : tmp;
      tmp             = chan[ARGB_B] + c.chan[ARGB_B];
      chan[ARGB_B]    = tmp>255 ? 255 : tmp;
      return *this;
    }

    Colour32& blendReplaceAlpha(Colour32 c);
    Colour32& blendSumAlpha(Colour32 c);
    Colour32& blendSumSaturateAlpha(Colour32 c);
    Colour32& blendMultiplyAlpha(Colour32 c);

    static Colour32 interpolate(Colour32 c1, Colour32 c2, float32 frac);

};


inline bool operator==(const Colour32& a, const Colour32& b) {
  return a.argb == b.argb;
}

inline bool operator!=(const Colour32& a, const Colour32& b) {
  return a.argb != b.argb;
}

#endif
