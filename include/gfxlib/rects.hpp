///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         gfxlib/display.hpp
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

#ifndef _EXNG2_GFXLIB_RECTS_HPP_
# define _EXNG2_GFXLIB_RECTS_HPP_

# include <xbase.hpp>

class GfxArea {
  public:
    sint16 getWidth()   const { return width; }
    sint16 getHeight()  const { return height; }

    GfxArea()                                         {}
    GfxArea(sint16 w, sint16 h) : width(w), height(h) {}

  protected:
    sint16 width;
    sint16 height;

};

class GfxRect : public GfxArea {
  public:
    sint16 getX()       const { return left; }
    sint16 getY()       const { return top; }
    sint16 getX2()      const { return left+width-1; }
    sint16 getY2()      const { return top+height-1; }

    sint16 getLeft()    const { return left; }
    sint16 getTop()     const { return top; }
    sint16 getRight()   const { return left+width-1; }
    sint16 getBottom()  const { return top+height-1; }

    GfxRect()                                                                         {}
    GfxRect(sint16 x, sint16 y, sint16 w, sint16 h) : GfxArea(w, h), left(x), top(y)  {}

  protected:
    sint16 left;
    sint16 top;
};

class GfxAreaMutable : public GfxArea {
  public:
    void  setWidth(sint16 w)      { width = w; }
    void  setHeight(sint16 h)     { height = h; }
    void  set(sint16 w, sint16 h) { width = w; height = h; }

    GfxAreaMutable() : GfxArea() {}
    GfxAreaMutable(sint16 w, sint16 h) : GfxArea(w, h) {}

};

class GfxRectMutable : public GfxRect {
  public:
    void  setWidth(sint16 w)  { width = w; }
    void  setHeight(sint16 h) { height = h; }
    void  setLeft(sint16 l)   { left = l; }
    void  setTop(sint16 t)    { top = t; }

    void  set(sint16 x, sint16 y, sint16 w, sint16 h)
    {
      left    = x;
      top     = y;
      width   = w;
      height  = h;
    }

    GfxRectMutable() : GfxRect() {}
    GfxRectMutable(sint16 x, sint16 y, sint16 w, sint16 h) : GfxRect(x, y, w, h) {}
};

#endif
