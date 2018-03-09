///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         gfxlib/draw.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Graphics resource
//  Comment(s):
//  Library:      Gfx
//  Created:      2009-11-01
//  Updated:      2009-11-01
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _EXNG2_GFXLIB_DRAW_HPP_
# define _EXNG2_GFXLIB_DRAW_HPP_

# include <gfxlib/gfx.hpp>
# include <gfxlib/display.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Draw
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define S16_XY   sint16 x1, sint16 y1
#define S16_2XY  sint16 x1, sint16 y1, sint16 x2, sint16 y2
#define S16_3XY  sint16 x1, sint16 y1, sint16 x2, sint16 y2, sint16 x3, sint16 y3

class Draw2D {

  DEFINE_MIN_RTTI

  public:
    typedef enum {
      DRAW_LINE               = 0,
      DRAW_LINE_GRAD,
//       DRAW_TRIANGLE,
//       DRAW_TRIANGLE_GRAD,
//       DRAW_RECTANGLE,
//       DRAW_RECTANGLE_GRAD,
      FILL_TRIANGLE,
      FILL_TRIANGLE_GRAD,
      FILL_RECTANGLE,
      FILL_RECTANGLE_GRAD,
      _MAX_CAPABILITIES
    } Capability;

    typedef enum {
      UNSUPPORTED = 0,    // no support at all
      PARTIAL,            // partial support (usually with 'general' queries)
      SLOW,               // feature implemented but may be slow, however
      SUPPORTED,          // feature is implemented sufficiently for normal use
      ACCELERATED         // wheee!
    } Support;

    enum {
      DEF_STROKE  = 0xFF000000,
      DEF_FILL    = 0xFFFFFFFF,
      DEF_CLEAR   = 0xFFCCCCCC
    };

    virtual Support             supports(Capability feature)    = 0;
    virtual void                setCanvas(Display::Surface* s)  = 0;
    virtual Display::Surface*   getCanvas()                     = 0;

    virtual void                setClip(S16_2XY)                = 0;

    void                        setClip(const GfxRect& rect)
    {
      setClip(rect.getLeft(), rect.getTop(), rect.getRight(), rect.getBottom());
    }

    virtual void                setStrokeColour(Colour32 c)     = 0;
    virtual void                setFlatFillColour(Colour32 c)   = 0;
    virtual void                setClearColour(Colour32 c)      = 0;

    virtual Colour32            getStrokeColour()               = 0;
    virtual Colour32            getFlatFillColour()             = 0;
    virtual Colour32            getClearColour()                = 0;


    virtual void                begin()                         = 0;
    virtual void                end()                           = 0;

    // Line rendering
    virtual void    drawLine(S16_2XY)                                                         { }
    virtual void    drawLine(S16_2XY, Colour32 c)                                             { }
    virtual void    drawLineGrad(S16_2XY, Colour32 c1, Colour32 c2)                           { }

    virtual void    drawLines(size_t num, const sint16* data)                                 { }


//     virtual void    drawLines(size_t num, sint16* data)                                       { }
//     virtual void    drawLinesConnected(size_t num, sint16* data)                              { }
//     virtual void    drawLinesClosed(size_t num, sint16* data)                                 { }
//
//     virtual void    drawLines(size_t num, sint16* data, Colour32 c)                           { }
//     virtual void    drawLines(size_t num, sint16* data, Colour32* c)                          { }
//     virtual void    drawLinesGrad(size_t num, sint16* data, Colour32* c)                      { }
//
//     // Triangles Outline
//     virtual void    drawTri(S16_3XY);
//     virtual void    drawTri(S16_3XY, Colour32 c);
//     virtual void    drawTriGrad(S16_3XY, Colour32 c1, Colour32 c2, Colour32 c3)               { }

    // Triangles Solid
    virtual void    fillTri(S16_3XY)                                                          { }
    virtual void    fillTri(S16_3XY, Colour32 c)                                              { }
    virtual void    fillTriGrad(S16_3XY, Colour32 c1, Colour32 c2, Colour32 c3)               { }

    // Rectangles Outline
//     virtual void    drawRect(S16_2XY);
//     virtual void    drawRect(S16_2XY, Colour32 c);
//     virtual void    drawRectGradH(S16_2XY, Colour32 c1, Colour32 c2)                          { }
//     virtual void    drawRectGradV(S16_2XY, Colour32 c1, Colour32 c2)                          { }
//     virtual void    drawRectGrad(S16_2XY, Colour32 c1, Colour32 c2, Colour32 c3, Colour32 c4) { }
//
//     void            drawRect(const GfxRect& rect)
//     {
//       drawRect(rect.getLeft(), rect.getTop(), rect.getRight(), rect.getBottom());
//     }
//
//     void            drawRect(const GfxRect& rect, Colour32 c)
//     {
//       drawRect(rect.getLeft(), rect.getTop(), rect.getRight(), rect.getBottom(), c);
//     }
//
//     void            drawRectGradH(const GfxRect& rect, Colour32 c1, Colour32 c2)
//     {
//       drawRectGradH(rect.getLeft(), rect.getTop(), rect.getRight(), rect.getBottom(), c1, c2);
//     }
//
//     void            drawRectGradV(const GfxRect& rect, Colour32 c1, Colour32 c2)
//     {
//       drawRectGradV(rect.getLeft(), rect.getTop(), rect.getRight(), rect.getBottom(), c1, c2);
//     }
//
//     void            drawRectGrad(const GfxRect& rect, Colour32 c1, Colour32 c2, Colour32 c3, Colour32 c4)
//     {
//       drawRectGrad(rect.getLeft(), rect.getTop(), rect.getRight(), rect.getBottom(), c1, c2, c3, c4);
//     }


    // Rectangles Solid
    virtual void    eraseRect(S16_2XY)                                                        { }
    virtual void    fillRect(S16_2XY)                                                         { }
    virtual void    fillRect(S16_2XY, Colour32 c)                                             { }
    virtual void    fillRectGradH(S16_2XY, Colour32 c1, Colour32 c2)                          { }
    virtual void    fillRectGradV(S16_2XY, Colour32 c1, Colour32 c2)                          { }
    virtual void    fillRectGrad(S16_2XY, Colour32 c1, Colour32 c2, Colour32 c3, Colour32 c4) { }

    void            eraseRect(const GfxRect& rect)
    {
      eraseRect(rect.getLeft(), rect.getTop(), rect.getRight(), rect.getBottom());
    }

    void            fillRect(const GfxRect& rect)
    {
      fillRect(rect.getLeft(), rect.getTop(), rect.getRight(), rect.getBottom());
    }

    void            fillRect(const GfxRect& rect, Colour32 c)
    {
      fillRect(rect.getLeft(), rect.getTop(), rect.getRight(), rect.getBottom(), c);
    }

    void            fillRectGradH(const GfxRect& rect, Colour32 c1, Colour32 c2)
    {
      fillRectGradH(rect.getLeft(), rect.getTop(), rect.getRight(), rect.getBottom(), c1, c2);
    }

    void            fillRectGradV(const GfxRect& rect, Colour32 c1, Colour32 c2)
    {
      fillRectGradV(rect.getLeft(), rect.getTop(), rect.getRight(), rect.getBottom(), c1, c2);
    }

    void            fillRectGrad(const GfxRect& rect, Colour32 c1, Colour32 c2, Colour32 c3, Colour32 c4)
    {
      fillRectGrad(rect.getLeft(), rect.getTop(), rect.getRight(), rect.getBottom(), c1, c2, c3, c4);
    }
    virtual void    dumpInfo()                                                                { }

    virtual ~Draw2D() {};

    static Draw2D*  createInstance();

  protected:

    bool  clipLineSegment(sint16* coords, const sint16* bounds);
    void  clip2ComponentGradient(Colour32* colour, sint16 len, sint16 ofsStart, sint16 ofsEnd);

    Draw2D() {}

};


#endif
