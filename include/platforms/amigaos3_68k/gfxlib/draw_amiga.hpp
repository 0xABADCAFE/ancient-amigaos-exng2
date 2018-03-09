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

#ifndef _EXNG2_GFXLIB_GFX_DRAW_AMIGA_HPP_
# define _EXNG2_GFXLIB_GFX_DRAW_AMIGA_HPP_

#include <gfxlib/gfx.hpp>
#include <gfxlib/draw.hpp>
#include <systemlib/memory.hpp>
#include <systemlib/error.hpp>
#include <systemlib/logger.hpp>

namespace OSNative {
  extern "C" {

  }
};

using namespace EXNGPrivate;
using namespace OSNative;

template <class T> inline T clamp(T v, T min, T max)
{
  return v<min ? min : v>max ? max: v;
}

class Draw2DAmiga : public Draw2D, private EXNGPrivate::SurfaceUser {

  DEFINE_MIN_RTTI
  LOGGING_DEFINE_CLASSNAME

  private:
    static uint8 rgbCapabilities[_MAX_CAPABILITIES];
    static uint8 idxCapabilities[_MAX_CAPABILITIES];

    enum {
      USING_INDEXED     = 0x00000001
    };

    Display::Surface*   canvas;
    ViewPort*           view;
    uint32              flags;
    sint32              lockCount;
    Colour32            stroke,   fill,     clear;

    sint16              strokePen,  fillPen,  clearPen, tempPen, lastAPen, lastBPen;

    sint16              clipRect[4];

    RastPort            rastPort;

    uint8*              capabilities;

    void                setRGBCapabilities()  { capabilities = rgbCapabilities; }
    void                setIdxCapabilities()  { capabilities = idxCapabilities; }

    void                allocPens();
    void                releasePens();

    // Common pen-level drawing methods when in RGB mode
    void                setPenRGB(Colour32 c, sint16 pen);

    uint32              getBestPen(Colour32 c);

    void        drawLineRGB(const sint16* coords, sint16 pen);
//     void        drawTriRGB(sint16 pen, S16_3XY);
//     void        drawRectRGB(sint16 pen, S16_2XY);
    void        fillRectRGB(sint16 pen, S16_2XY);

    // choose best pen 'on the fly' methods when in 8-bit mode
    void        drawLineIdx(const sint16* coords, Colour32 c);
//     void        drawTriIdx(Colour32 c, S16_3XY);
//     void        drawRectIdx(Colour32 c, S16_2XY);
    void        fillRectIdx(Colour32 c, S16_2XY);



  public:
    Draw2DAmiga();
    ~Draw2DAmiga();

    Support             supports(Capability feature)
    {
      return (Support)capabilities[feature];
    }

    void                setCanvas(Display::Surface* s);
    Display::Surface*   getCanvas()         { return canvas; }

    void                setClip(S16_2XY);

    void                setStrokeColour(Colour32 c);
    void                setFlatFillColour(Colour32 c);
    void                setClearColour(Colour32 c);
    Colour32            getStrokeColour()   { return stroke;   }
    Colour32            getFlatFillColour() { return fill;     }
    Colour32            getClearColour()    { return clear;    }

    void                begin();
    void                end();

    // Line rendering
    void    drawLine(S16_2XY);
    void    drawLine(S16_2XY, Colour32 c);

    // Triangles Outline
//     void    drawTri(S16_3XY);
//     void    drawTri(S16_3XY, Colour32 c);

    // Triangles Solid
    void    fillTri(S16_3XY);
    void    fillTri(S16_3XY, Colour32 c);

    // Rectangles Outline
//     void    drawRect(S16_2XY);
//     void    drawRect(S16_2XY, Colour32 c);

    // Rectangles Solid
    void    eraseRect(S16_2XY);
    void    fillRect(S16_2XY);
    void    fillRect(S16_2XY, Colour32 c);

};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif
