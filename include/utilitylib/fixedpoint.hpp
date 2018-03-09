///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         utilitylib/fixedpoint.hpp
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

#ifndef _EXNG2_UTILITYLIB_FIXEDPOINT_HPP_
# define _EXNG2_SYSTEMLIB_FIXEDPOINT_HPP_

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  RangedInt
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

# if X_ENDIAN == XA_BIG_ENDIAN
#   define FIX16_PART_INT   0
#   define FIX16_PART_FRAC  1
# else
#   define FIX16_PART_INT   1
#   define FIX16_PART_FRAC  0
# endif

class Fix1616 {
  private:
    union {
      sint32 val32;
      sint16 val16[2];
    };
  public:
    Fix1616()         : val(0)      { }
    Fix1616(int i)
    {
      val16[FIX16_PART_INT]   = i;
      val16[FIX16_PART_FRAC]  = 0;
    }

    Fix1616 operator=(int i)
    {
      val16[FIX16_PART_INT]   = i;
      val16[FIX16_PART_FRAC]  = 0;
      return *this;
    }

    Fix1616 operator++()  // ++prefix
    {
      val32 += (1<<16);
      return *this;
    }

    Fix1616 operator++(int) // postfix++;
    {
      Fix1616 tmp(*this);
      val32 += (1<<16);
      return tmp;
    }

    Fix1616 operator--()  // --prefix
    {
      val32 -= (1<<16);
    }

    Fix1616 operator--(int) // postfix--
    {
      Fix1616 tmp(*this);
      val32 -= (1<<16);
      return tmp;
    }

    Fix1616 operator+=(Fix1616 f)
    {
      val32 += f.val32;
      return *this;
    }

    Fix1616 operator-=(Fix1616 f)
    {
      val32 -= f.val32;
      return *this;
    }

    Fix1616 operator*=(Fix1616 f)
    {
      sint64 t = (sint64)val32 * (sint64)f.val32;
      val32 = (sint32)(t>>32);
      return *this;
    }

    Fix1616 operator/=(Fix1616 f)
    {

    }
};

/*
template <class T, int min, int max> class RangedInt {
  private:
    T val;
  public: // Construtor
    RangedInt() : val(min)      { }
    RangedInt(int i)            { (i>min)?((i<max)?(val=i):(val=max)):(val=min); }
    void operator=(int i)       { (i>min)?((i<max)?(val=i):(val=max)):(val=min); }
  public: // Operators
    operator T()                { return val; }
    T operator()()              { return val; }
    T operator++()              { return (val<max)?(++val):(val=max); }   //++prefix
    T operator++(int)           { return (val<max)?(val++):(val=max); }   //postfix++
    T operator--()              { return (val>min)?(--val):(val=min); }   //--prefix
    T operator--(int)           { return (val>min)?(val--):(val=min); }   //postfix--
    T operator+=(int i)         { return (val+i<max)?(val+=i):(val=max); }
    T operator-=(int i)         { return (val>min+i)?(val-=i):(val=min); }
    T operator*=(int i)         { return ((long)val*i<max)?(val*=i):(val=max); }
    T operator<<=(int i)        { return ((long)(val<<i)<max)?(val<<=i):(val=max); }
    T operator/=(int i)         { return ((long)val/i>min)?(val/=i):(val=min); }
    T operator>>=(int i)        { return ((long)(val>>i)>min)?(val>>=i):(val=min); }
};
*/
#endif
