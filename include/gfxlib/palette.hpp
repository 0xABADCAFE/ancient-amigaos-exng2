///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         gfxlib/colour.hpp
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

#ifndef _EXNG2_GFXLIB_PALETTE_HPP_
# define _EXNG2_GFXLIB_PALETTE_HPP_

# include <gfxlib/pixel.hpp>
# include <gfxlib/colour.hpp>

class Palette {
  friend void Graphics::done();

  public:
    typedef enum {
      PAL_FAKERGB_666     = 0,  // 216/256 aka web safe
      PAL_FAKERGB_676,
      PAL_FAKERGB_775,          // 245/256
      PAL_FAKERGB_884,          // 256/256
      PAL_GREY,
      PAL_CUSTOM
    } Preset;

    void                  setPreset(Preset p);
    static const Palette* getPresetPalette(Preset p);
    Colour32&             operator[](size_t n)          { return data[n&255]; }
    Colour32              operator[](size_t n)  const   { return data[n&255]; }
    Colour32              index(size_t n)       const   { return data[n]; }
    Colour32*             getTable()                    { return data; }
    const Colour32*       getTable()            const   { return data; }

    void      scaleAlpha(float32 scf, sint8 ofs=0, uint8 min=0, uint8 max=255);
    void      scaleRed(float32 scf, sint8 ofs=0, uint8 min=0, uint8 max=255);
    void      scaleGreen(float32 scf, sint8 ofs=0, uint8 min=0, uint8 max=255);
    void      scaleBlue(float32 scf, sint8 ofs=0, uint8 min=0, uint8 max=255);

    size_t    findBestMatch(Colour32 c, bool igoreAlpha) const;



  public:
    Palette() {}
    Palette(Preset p) { setPreset(p); }
    ~Palette() {}

  private:
    static    void done();

    Colour32  data[256];
    static    Palette* presets[PAL_CUSTOM];
};


#endif
