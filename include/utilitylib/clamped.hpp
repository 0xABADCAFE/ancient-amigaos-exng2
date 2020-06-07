///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         utilitylib/rangedint.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Range bound integer class
//  Comment(s):
//  Library:      Utility
//  Created:      2006-10-08
//  Updated:      2006-10-08
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _EXNG2_UTILITYLIB_CLAMPED_HPP_
# define _EXNG2_UTILITYLIB_CLAMPED_HPP_

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Clamped
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T, int min, int max>
class Clamped {
  private:
    T val;

    void clampLo()
    {
      if (val<min) {
        val=min;
      }
    }

    void clampHi()
    {
      if (val>max) {
        val=max;
      }
    }

    void clamp()
    {
      if (val<min) {
        val=min;
      } else if (val>max) {
        val=max;
      }
    }

  public: // Construtor
    Clamped() : val(min)        { }
    Clamped(T i) : val(min)     { clamp(); }
    void operator=(T i)         { val=i; clamp(); }

  public: // Operators
    operator T()                { return val; }
    T operator()()              { return val; }

    T operator++() // ++prefix
    {
      ++val;
      clampHi();
      return val
    }

    T operator++(int) // postfix++
    {
      T res = val++;
      clampHi();
      return res;
    }

    T operator--() // --prefix
    {
      --val;
      clampLo();
      return val
    }

    T operator--(int) // postfix--
    {
      T res = val--;
      clampLo();
      return res;
    }

    T operator+=(T i)
    {
      val += i;
      clampHi();
      return val;
    }

    T operator-=(T i)
    {
      val -= i;
      clampLo();
      return val;
    }

    T operator*=(T i)
    {
      val *= i;
      clamp();
      return val;
    }

    T operator/=(T i)
    {
      val /= i;
      clamp();
      return val;
    }

    T operator<<=(int i)
    {
      val<<=i;
      clampHi();
      return val;
    }

    T operator>>=(int i)
    {
      val >>=i;
      clampLo();
      return val;
    }
};

#endif
