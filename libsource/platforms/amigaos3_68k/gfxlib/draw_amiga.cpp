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

#include <gfxlib/draw_amiga.hpp>

DECLARE_MIN_RTTI(Draw2DAmiga);
LOGGING_DECLARE_CLASSNAME(Draw2DAmiga);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint8 Draw2DAmiga::rgbCapabilities[Draw2D::_MAX_CAPABILITIES] = {
  Draw2D::SUPPORTED,  //DRAW_LINE,
  Draw2D::SUPPORTED,  //DRAW_LINE_GRAD,
//   Draw2D::SUPPORTED,  //DRAW_TRIANGLE,
//   Draw2D::SUPPORTED,  //DRAW_TRIANGLE_GRAD,
//   Draw2D::SUPPORTED,  //DRAW_RECTANGLE,
//   Draw2D::SUPPORTED,  //DRAW_RECTANGLE_GRAD,
  Draw2D::SUPPORTED,  //FILL_TRIANGLE,
  Draw2D::SUPPORTED,  //FILL_TRIANGLE_GRAD,
  Draw2D::SUPPORTED,  //FILL_RECTANGLE.
  Draw2D::SUPPORTED,  //FILL_RECTANGLE_GRAD
};

uint8 Draw2DAmiga::idxCapabilities[Draw2D::_MAX_CAPABILITIES] = {
  Draw2D::SUPPORTED,    //DRAW_LINE,
  Draw2D::UNSUPPORTED,  //DRAW_LINE_GRAD,
//   Draw2D::SUPPORTED,    //DRAW_TRIANGLE,
//   Draw2D::UNSUPPORTED,  //DRAW_TRIANGLE_GRAD,
//   Draw2D::SUPPORTED,    //DRAW_RECTANGLE,
//   Draw2D::UNSUPPORTED,  //DRAW_RECTANGLE_GRAD,
  Draw2D::SUPPORTED,    //FILL_TRIANGLE,
  Draw2D::UNSUPPORTED,  //FILL_TRIANGLE_GRAD,
  Draw2D::SUPPORTED,    //FILL_RECTANGLE.
  Draw2D::UNSUPPORTED,  //FILL_RECTANGLE_GRAD
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
    Display::Surface*   canvas;
    ViewPort*           view;
    uint32              flags;
    Colour32            stroke,     fill,     clear;

    GfxRectMutable      clipRect;
    sint16              clipRect[3], clipRect[2];

    sint16              strokePen,  fillPen,  clearPen, tempPen, lastAPen, lastBPen;
*/

#define MINX bounds[0]
#define MINY bounds[1]
#define MAXX bounds[2]
#define MAXY bounds[3]

Draw2DAmiga::Draw2DAmiga() :
  canvas(0),
  view(0),
  flags(0),
  lockCount(0),
  stroke(Draw2D::DEF_STROKE), fill(Draw2D::DEF_FILL), clear(Draw2D::DEF_CLEAR),
  strokePen(-1),  fillPen(-1),  clearPen(-1), tempPen(-1), lastAPen(-1), lastBPen(-1),
  capabilities(idxCapabilities)
{
  InitRastPort(&rastPort);
  Mem::zero(clipRect, sizeof(clipRect));
}

Draw2DAmiga::~Draw2DAmiga()
{
  releasePens();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Draw2DAmiga::allocPens()
{
  LOGGING_DECLARE_FUNCNAME(allocPens)

  // Allocate pens exclusively, setting desired colours at same time
  if (!(flags & USING_INDEXED)) {
    strokePen = ObtainPen(
      view->ColorMap, (uint32)-1,
      stroke.red()<<24,
      stroke.green()<<24,
      stroke.blue()<<24,
      PEN_EXCLUSIVE
    );

    fillPen   = ObtainPen(
      view->ColorMap, (uint32)-1,
      fill.red()<<24,
      fill.green()<<24,
      fill.blue()<<24,
      PEN_EXCLUSIVE
    );

    clearPen  = ObtainPen(
      view->ColorMap, (uint32)-1,
      clear.red()<<24,
      clear.green()<<24,
      clear.blue()<<24,
      PEN_EXCLUSIVE
    );

    tempPen   = ObtainPen(
      view->ColorMap, (uint32)-1,
      0,
      0,
      0,
      PEN_EXCLUSIVE
    );
      #ifdef EXNG2_BUILD_LOGGED
      SystemLog::write(
        SystemLog::INFO,
        "%s::%s - obtained pens (%" XPF_S16 ", %" XPF_S16 ", %" XPF_S16 ", %" XPF_S16 ")\n",
        loggingClassName, loggingFuncName,
        strokePen, fillPen, clearPen, tempPen
      );
      #endif
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Draw2DAmiga::releasePens()
{
  if (view) {
    if (strokePen >= 0) {
      ReleasePen(view->ColorMap, strokePen);
      strokePen = -1;
    }
    if (fillPen >= 0) {
      ReleasePen(view->ColorMap, fillPen);
      fillPen = -1;
    }
    if (clearPen >= 0) {
      ReleasePen(view->ColorMap, clearPen);
      clearPen = -1;
    }
    if (tempPen >= 0) {
      ReleasePen(view->ColorMap, tempPen);
      tempPen = -1;
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 Draw2DAmiga::getBestPen(Colour32 c)
{
  LOGGING_DECLARE_FUNCNAME(getBestPen)

  uint32 pen = 0xFF;

  const Palette* pal = canvas->getIndexedPalette();

  if (!pal) {
    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::WARNING,
      "%s::%s - Surface does not have a Palette instance attached\n",
      loggingClassName, loggingFuncName,
      (unsigned)pen,
      (unsigned)c.red(),
      (unsigned)c.green(),
      (unsigned)c.blue()
    );
    #endif
    return pen;
  }
  else {
    pen = pal->findBestMatch(c, true);
  }

  Colour32 c2 = (*pal)[pen];

  #ifdef EXNG2_BUILD_LOGGED
  SystemLog::write(
    SystemLog::INFO,
    "%s::%s - got pen %08X [%02X %02X %02X] for colour %02X %02X %02X\n",
    loggingClassName, loggingFuncName,
    (unsigned)pen,

    (unsigned)c2.red(),
    (unsigned)c2.green(),
    (unsigned)c2.blue(),

    (unsigned)c.red(),
    (unsigned)c.green(),
    (unsigned)c.blue()
  );
  #endif
  return pen;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Draw2DAmiga::setPenRGB(Colour32 c, sint16 pen)
{
  // according to docs, this is faster than SetRGB32, even for 1 colour...
  uint32 rgb32tab[] = {
    1UL<<16|(pen&255),
    (uint32)(c.red())<<24,
    (uint32)(c.green())<<24,
    (uint32)(c.blue())<<24,
    0
  };
  LoadRGB32(view, rgb32tab);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Draw2DAmiga::setCanvas(Display::Surface* s)
{
  LOGGING_DECLARE_FUNCNAME(setCanvas)

  if (lockCount) {
    THROW_NSX(Error, ObjectStateViolation());
  }

/*
      static OSNative::BitMap*  getSurfaceBitMap(Display::Surface* s)                                     { return s->bitMap; }
      static OSNative::Window*  getWinUser(Display::Surface* s)                                           { return s->winUser; }
      static bool checkCompatible(Display::Surface* s, OSNative::BitMap* b);
*/
  if (!s) {
    THROW_NSX(Error, NullPointer());
  }
  if (s!=canvas) {
    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::INFO,
      "%s::%s - using Surface at %p\n",
      loggingClassName, loggingFuncName, s
    );
    #endif

    BitMap*   bMap   = 0;
    ViewPort* nView  = 0;
    if (!s->isAllocated() || s->getDepth()<8) {
      THROW_NSX(Error, ObjectStateViolation());
    }
    if (
      !(bMap = getSurfaceBitMap(s)) || !getWinUser(s) ||
      !(nView = &(getWinUser(s)->WScreen->ViewPort))
    ) {
      THROW_NSX(Error, ObjectStateViolation());
    }

    if (s->getDepth()==8) {

      #ifdef EXNG2_BUILD_LOGGED
      SystemLog::write(
        SystemLog::INFO,
        "%s::%s - Surface is indexed colour mode\n",
        loggingClassName, loggingFuncName
      );
      #endif

      flags = USING_INDEXED;
      setIdxCapabilities();
    } else {

      #ifdef EXNG2_BUILD_LOGGED
      SystemLog::write(
        SystemLog::INFO,
        "%s::%s - Surface is direct colour mode\n",
        loggingClassName, loggingFuncName
      );
      #endif

      flags = 0;
      setRGBCapabilities();
    }



    // If new surface dimension is different reset clip area to new
    // canvas size
    if (s->getWidth() != canvas->getWidth() || s->getHeight() != canvas->getHeight()) {
      clipRect[0] = 0;
      clipRect[1] = 0;
      clipRect[2] = s->getWidth()-1;
      clipRect[3] = s->getHeight()-1;
    }

    // Assign the new canvas and update RastPort
    canvas          = s;
    rastPort.BitMap = bMap;

    // Check if new canvas' window handle referenes a different ColorMap
    if (nView != view) {

      #ifdef EXNG2_BUILD_LOGGED
      SystemLog::write(
        SystemLog::INFO,
        "%s::%s - assigning ViewPort at %p\n",
        loggingClassName, loggingFuncName, nView
      );
      #endif

      view = nView;
      releasePens();
      allocPens();
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Draw2DAmiga::setClip(S16_2XY)
{
  LOGGING_DECLARE_FUNCNAME(setClip)

  x1 = clamp<sint16>(x1, 0, canvas->getWidth()-1);
  x2 = clamp<sint16>(x2, x1, canvas->getWidth()-1);
  if (x2 == x1) {
    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::WARNING,
      "%s::%s - clip area clamp (%" XPF_S16 ", %" XPF_S16 ", %" XPF_S16 ", %" XPF_S16 ")\n",
      loggingClassName, loggingFuncName,
      x1, y1, x2, y2
    );
    #endif
    THROW_NSX(Error, Range());
  }
  y1 = clamp<sint16>(y1, 0, canvas->getHeight()-1);
  y2 = clamp<sint16>(y2, y1, canvas->getHeight()-1);
  if (y2 == y1) {
    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::WARNING,
      "%s::%s - clip area clamp (%" XPF_S16 ", %" XPF_S16 ", %" XPF_S16 ", %" XPF_S16 ")\n",
      loggingClassName, loggingFuncName,
      x1, y1, x2, y2
    );
    #endif
    THROW_NSX(Error, Range());
  }

  clipRect[0] = x1;
  clipRect[1] = y1;
  clipRect[2] = x2;
  clipRect[3] = y2;

  #ifdef EXNG2_BUILD_LOGGED
  SystemLog::write(
    SystemLog::INFO,
    "%s::%s - clip area set (%" XPF_S16 ", %" XPF_S16 ", %" XPF_S16 ", %" XPF_S16 ")\n",
    loggingClassName, loggingFuncName,
    x1, y1, x2, y2
  );
  #endif

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Draw2DAmiga::setStrokeColour(Colour32 c)
{
  if (stroke != c) {
    setPenRGB(c, strokePen);
    stroke = c;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Draw2DAmiga::setFlatFillColour(Colour32 c)
{
  if (fill != c) {
    setPenRGB(c, fillPen);
    fill = c;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Draw2DAmiga::setClearColour(Colour32 c)
{
  if (clear != c) {
    setPenRGB(c, clearPen);
    clear = c;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Draw2DAmiga::begin()
{
  ++lockCount;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Draw2DAmiga::end()
{
  if (lockCount>0) {
    --lockCount;
  }
  else {
    THROW_NSX(Error, ObjectStateViolation());
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Draw2D* Draw2D::createInstance()
{
  return new Draw2DAmiga();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

