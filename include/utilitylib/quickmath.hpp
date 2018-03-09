///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         utilitylib/quickmath.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Quick math estimation
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

#ifndef _EXNG2_UTILITYLIB_QUICKMATH_HPP_
# define _EXNG2_UTILITYLIB_QUICKMATH_HPP_

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  QMath
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class QMath {

  public:
    typedef union {
      float32 f;
      sint32  s;
      uint32  u;
    } ieee32;

    typedef union {
      float64 f;
      sint64  s;
      uint64  u;
    } ieee64;

  public:
    static float32 fabs(float32 x)
    {
      ieee32 u;
      u.f = x;
      u.u &= 0x7FFFFFFF;
      return u.f;
    }

    static float32 sinEstimate(float32 x);
    static float32 cosEstimate(float32 x);
    static float32 tanEstimate(float32 x);


    static float32 repSqrtEstimate(float32 x)
    {
      ieee32 u;
      u.f = x;
      float32 xHalf = 0.5f * x;
      u.s = 0x5f3759df - (u.s>>1);
      x = u.f;
      x *= (1.5f-xHalf*x*x);
      return x;
    }

    static float32 repSqrtEstimate2(float32 x)
    {
      ieee32 u;
      u.f = x;
      float32 xHalf = 0.5f * x;
      u.s = 0x5f3759df - (u.s>>1);
      x = u.f;
      x *= (1.5f-xHalf*x*x);
      x *= (1.5f-xHalf*x*x);
      return x;
    }

    static float32 sqrtEstimate(float32 x)
    {
      return x*repSqrtEstimate(x);
    }

    static float32 sqrtEstimate2(float32 x)
    {
      return x*repSqrtEstimate2(x);
    }
};

#endif
