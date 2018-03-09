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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Draw2DAmiga::drawLineRGB(const sint16* coords, sint16 pen)
{
  // method assumes caller has clipped the ordinates
  if (pen != lastAPen) {
    SetAPen(&rastPort, pen);
    lastAPen = pen;
  }
  Move(&rastPort, coords[0], coords[1]);
  Draw(&rastPort, coords[2], coords[3]);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// void Draw2DAmiga::drawTriRGB(sint16 pen, S16_3XY)
// {
//   sint16 coords[] = {x1, y1, x2, y2};
//   if (pen!=lastAPen) {
//     SetAPen(&rastPort, pen);
//   }
//   if (clipLineSegment(coords, clipRect)) {
//     Move(&rastPort, coords[0], coords[1]);
//     Draw(&rastPort, coords[2], coords[3]);
//   }
//   coords[0] = x2; coords[1] = y2; coords[2] = x3; coords[3] = y3;
//   if (clipLineSegment(coords, clipRect)) {
//     Move(&rastPort, coords[0], coords[1]);
//     Draw(&rastPort, coords[2], coords[3]);
//   }
//   coords[0] = x3; coords[1] = y3; coords[2] = x1; coords[3] = y1;
//   if (clipLineSegment(coords, clipRect)) {
//     Move(&rastPort, coords[0], coords[1]);
//     Draw(&rastPort, coords[2], coords[3]);
//   }
// }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// void Draw2DAmiga::drawRectRGB(sint16 pen, S16_2XY)
// {
//   // First clamp the values to the clip extent
//   if (pen != lastAPen) {
//     SetAPen(&rastPort, pen);
//     lastAPen = pen;
//   }
//   sint16 tx1 = clamp<sint16>(x1, clipRect[0], clipRect[2]);
//   sint16 tx2 = clamp<sint16>(x2, clipRect[0], clipRect[2]);
//   sint16 ty1 = clamp<sint16>(y1, clipRect[1], clipRect[3]);
//   sint16 ty2 = clamp<sint16>(y2, clipRect[1], clipRect[3]);
//   // top line
//   if ((y1 >= clipRect[1]) && (y1 <= clipRect[3])) {
//     Move(&rastPort, tx1, y1);
//     Draw(&rastPort, tx2, y1);
//   }
//   // bottom line
//   if ((y2 >= clipRect[1]) && (y2 <= clipRect[3])) {
//     Move(&rastPort, tx1, y2);
//     Draw(&rastPort, tx2, y2);
//   }
//   // left line
//   if ((x1 >= clipRect[0]) && (x1 <= clipRect[2])) {
//     Move(&rastPort, x1, ty1);
//     Draw(&rastPort, x1, ty2);
//   }
//   // right line
//   if ((x2 >= clipRect[0]) && (x2 <= clipRect[2])) {
//     Move(&rastPort, x2, ty1);
//     Draw(&rastPort, x2, ty2);
//   }
// }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Draw2DAmiga::fillRectRGB(sint16 pen, S16_2XY)
{
  x1 = clamp<sint16>(x1, clipRect[0], clipRect[2]);
  x2 = clamp<sint16>(x2, clipRect[0], clipRect[2]);
  y1 = clamp<sint16>(y1, clipRect[1], clipRect[3]);
  y2 = clamp<sint16>(y2, clipRect[1], clipRect[3]);
  if (pen != lastAPen) {
    SetAPen(&rastPort, pen);
    lastAPen = pen;
  }
  RectFill(&rastPort, x1, y1, x2, y2);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// choose best pen 'on the fly' methods when in 8-bit mode
void Draw2DAmiga::drawLineIdx(const sint16* coords, Colour32 c)
{
  // method assumes caller has clipped the ordinates
  uint32 pen = getBestPen(c);
  SetAPen(&rastPort, pen);
  Move(&rastPort, coords[0], coords[1]);
  Draw(&rastPort, coords[2], coords[3]);
  ReleasePen(view->ColorMap, pen);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// void Draw2DAmiga::drawTriIdx(Colour32 c, S16_3XY)
// {
//   uint32 pen = getBestPen(c);
//   SetAPen(&rastPort, pen);
//   sint16 coords[] = {x1, y1, x2, y2};
//   if (clipLineSegment(coords, clipRect)) {
//     Move(&rastPort, coords[0], coords[1]);
//     Draw(&rastPort, coords[2], coords[3]);
//   }
//   coords[0] = x2; coords[1] = y2; coords[2] = x3; coords[3] = y3;
//   if (clipLineSegment(coords, clipRect)) {
//     Move(&rastPort, coords[0], coords[1]);
//     Draw(&rastPort, coords[2], coords[3]);
//   }
//   coords[0] = x3; coords[1] = y3; coords[2] = x1; coords[3] = y1;
//   if (clipLineSegment(coords, clipRect)) {
//     Move(&rastPort, coords[0], coords[1]);
//     Draw(&rastPort, coords[2], coords[3]);
//   }
//   ReleasePen(view->ColorMap, pen);
// }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// void Draw2DAmiga::drawRectIdx(Colour32 c, S16_2XY)
// {
//   uint32 pen = getBestPen(c);
//   SetAPen(&rastPort, pen);
//
//   sint16 tx1 = clamp<sint16>(x1, clipRect[0], clipRect[2]);
//   sint16 tx2 = clamp<sint16>(x2, clipRect[0], clipRect[2]);
//   sint16 ty1 = clamp<sint16>(y1, clipRect[1], clipRect[3]);
//   sint16 ty2 = clamp<sint16>(y2, clipRect[1], clipRect[3]);
//   // top line
//   if ((y1 >= clipRect[1]) && (y1 <= clipRect[3])) {
//     Move(&rastPort, tx1, y1);
//     Draw(&rastPort, tx2, y1);
//   }
//   // bottom line
//   if ((y2 >= clipRect[1]) && (y2 <= clipRect[3])) {
//     Move(&rastPort, tx1, y2);
//     Draw(&rastPort, tx2, y2);
//   }
//   // left line
//   if ((x1 >= clipRect[0]) && (x1 <= clipRect[2])) {
//     Move(&rastPort, x1, ty1);
//     Draw(&rastPort, x1, ty2);
//   }
//   // right line
//   if ((x2 >= clipRect[0]) && (x2 <= clipRect[2])) {
//     Move(&rastPort, x2, ty1);
//     Draw(&rastPort, x2, ty2);
//   }
//
//   ReleasePen(view->ColorMap, pen);
// }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Draw2DAmiga::fillRectIdx(Colour32 c, S16_2XY)
{
  x1 = clamp<sint16>(x1, clipRect[0], clipRect[2]);
  x2 = clamp<sint16>(x2, clipRect[0], clipRect[2]);
  y1 = clamp<sint16>(y1, clipRect[1], clipRect[3]);
  y2 = clamp<sint16>(y2, clipRect[1], clipRect[3]);

  uint32 pen = getBestPen(c);
  SetAPen(&rastPort, pen);
  RectFill(&rastPort, x1, y1, x2, y2);
  ReleasePen(view->ColorMap, pen);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Line rendering
void Draw2DAmiga::drawLine(S16_2XY)
{
/*
    ((x1 < clipRect[0]) && (x2 < clipRect[0])) ||
    ((y1 < clipRect[1]) && (y2 < clipRect[1])) ||
    ((x1 > clipRect[2]) && (x2 > clipRect[2])) ||
    ((y1 > clipRect[3]) && (y2 > clipRect[3]))
*/
  sint16 coords[] = {x1, y1, x2, y2};
  if (Draw2D::clipLineSegment(coords, clipRect)) {
    if (flags & USING_INDEXED) {
      drawLineIdx(coords, stroke);
    }
    else {
      drawLineRGB(coords, strokePen);
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Draw2DAmiga::drawLine(S16_2XY, Colour32 c)
{
  sint16 coords[] = {x1, y1, x2, y2};

  if (Draw2D::clipLineSegment(coords, clipRect)) {
    if (flags & USING_INDEXED) {
      drawLineIdx(coords, c);
    }
    else {
      setPenRGB(c, tempPen);
      drawLineRGB(coords, tempPen);
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Triangles Outline
// void Draw2DAmiga::drawTri(S16_3XY)
// {
//   if (flags & USING_INDEXED) {
//     drawTriIdx(stroke, x1, y1, x2, y2, x3, y3);
//   }
//   else {
//     drawTriRGB(strokePen, x1, y1, x2, y2, x3, y3);
//   }
// }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// void Draw2DAmiga::drawTri(S16_3XY, Colour32 c)
// {
//   if (flags & USING_INDEXED) {
//     drawTriIdx(c, x1, y1, x2, y2, x3, y3);
//   }
//   else {
//     setPenRGB(c, tempPen);
//     drawTriRGB(tempPen, x1, y1, x2, y2, x3, y3);
//   }
// }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Triangles Solid
void Draw2DAmiga::fillTri(S16_3XY)
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Draw2DAmiga::fillTri(S16_3XY, Colour32 c)
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Rectangles Outline
// void Draw2DAmiga::drawRect(S16_2XY)
// {
//   if (flags & USING_INDEXED) {
//     drawRectIdx(stroke, x1, y1, x2, y2);
//   }
//   else {
//     drawRectRGB(strokePen, x1, y1, x2, y2);
//   }
// }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// void Draw2DAmiga::drawRect(S16_2XY, Colour32 c)
// {
//   if (flags & USING_INDEXED) {
//     drawRectIdx(c, x1, y1, x2, y2);
//   }
//   else {
//     setPenRGB(c, tempPen);
//     drawRectRGB(tempPen, x1, y1, x2, y2);
//   }
// }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Rectangles Solid
void Draw2DAmiga::eraseRect(S16_2XY)
{

  if (flags & USING_INDEXED) {
    fillRectIdx(clear, x1, y1, x2, y2);
  }
  else {
    fillRectRGB(clearPen, x1, y1, x2, y2);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Draw2DAmiga::fillRect(S16_2XY)
{
  if (flags & USING_INDEXED) {
    fillRectIdx(fill, x1, y1, x2, y2);
  }
  else {
    fillRectRGB(fillPen, x1, y1, x2, y2);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Draw2DAmiga::fillRect(S16_2XY, Colour32 c)
{
  if (flags & USING_INDEXED) {
    fillRectIdx(c, x1, y1, x2, y2);
  }
  else {
    setPenRGB(c, tempPen);
    fillRectRGB(tempPen, x1, y1, x2, y2);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




