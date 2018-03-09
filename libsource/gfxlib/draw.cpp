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

# include <gfxlib/gfx.hpp>
# include <gfxlib/draw.hpp>

DECLARE_MIN_RTTI(Draw2D)

// void Draw2D::drawTri(S16_3XY)
// {
//   drawLine(x1,y1,x2,y2);
//   drawLine(x2,y2,x3,y3);
//   drawLine(x3,y3,x1,y1);
// }
//
// void Draw2D::drawTri(S16_3XY, Colour32 c)
// {
//   drawLine(x1,y1,x2,y2,c);
//   drawLine(x2,y2,x3,y3,c);
//   drawLine(x3,y3,x1,y1,c);
// }
//
// void Draw2D::drawRect(S16_2XY)
// {
//   drawLine(x1,y1,x2,y1);
//   drawLine(x1,y2,x2,y2);
//   drawLine(x1,y1,x1,y2);
//   drawLine(x2,y1,x2,y2);
// }
//
// void Draw2D::drawRect(S16_2XY, Colour32 c)
// {
//   drawLine(x1,y1,x2,y1,c);
//   drawLine(x1,y2,x2,y2,c);
//   drawLine(x1,y1,x1,y2,c);
//   drawLine(x2,y1,x2,y2,c);
// }

#define X1 coords[0]
#define Y1 coords[1]
#define X2 coords[2]
#define Y2 coords[3]
#define MINX bounds[0]
#define MINY bounds[1]
#define MAXX bounds[2]
#define MAXY bounds[3]
/*
    public void liang_barsky(int x1, int y1, int x2, int y2, int xmin, int ymin, int xmax, int ymax)
    {
        double deltaX, deltaY, p, q;
        double u1 = 0.0, u2 = 1.0;
        double r;

        deltaX = (x2 - x1);
        deltaY = (y2 - y1);

        double pPart[] = {-1 * deltaX, deltaX, -1 * deltaY, deltaY};
        double qPart[] = {x1 - xmin, xmax - x1, y1 - ymin, ymax - y1};

        boolean accept = true;

        for( int i = 0; i < 4; i ++ )
        {
            p = pPart[ i ];
            q = qPart[ i ];

            if( p == 0 && q < 0 )
            {
                accept = false;
                break;
            }

            r = q / p;

            if( p < 0 )
            {
                u1 =Math.max(u1, r);
            }

            if( p > 0 )
            {
                u2 = Math.min(u2, r);
            }

            if( u1 > u2 )
            {
                accept = false;
                break;
            }
            //System.out.println(u1 +" " + u2);

        }
        if(accept)
        {
            if( u2 < 1 )
            {
                x2 = (int)(x1 + u2 * deltaX);
                y2 = (int)(y1 + u2 * deltaY);
            }
            if( u1 > 0)
            {
                x1 = (int)(x1 + u1 * deltaX);
                y1 = (int)(y1 + u1 * deltaY);
            }

            set(x1, y1, x2, y2);
        }
        else
        {
            set(-1, -1, -1, -1);
        }
    }

*/

bool Draw2D::clipLineSegment(sint16* coords, const sint16* bounds)
{
  //return true;

  // liang barsky method
  float32 deltaX, deltaY, p, q;
  float32 u1 = 0.0, u2 = 1.0;
  float32 r;

  deltaX = (X2 - X1);
  deltaY = (Y2 - Y1);

  // left edge, right edge, bottom edge and top edge checking

  float32 pPart[] = {-deltaX, deltaX, -deltaY, deltaY};
  float32 qPart[] = {X1 - MINX, MAXX - X1, Y1 - MINY, MAXY - Y1};

  bool accept = true;

  for (int i=0; i<4; i++) {
    p = pPart[i];
    q = qPart[i];

    if (p==0 && q<0) {
      accept = false;
      break;
    }
    r = q / p;
    if (p<0 && r>u1) {
      u1 = r;
    }
    if (p>0 && r<u2) {
      u2 = r;
    }

    if (u1>u2) {
      accept = false;
      break;
    }
  }
  if (accept) {
    if (u2<1) {
      X2 = (sint16)(X1 + u2 * deltaX);
      Y2 = (sint16)(0.5f+Y1 + u2 * deltaY);
    }
    if (u1>0) {
      X1 = (sint16)(X1 + u1 * deltaX);
      Y1 = (sint16)(0.5f+Y1 + u1 * deltaY);
    }
  }
  return accept;
}
