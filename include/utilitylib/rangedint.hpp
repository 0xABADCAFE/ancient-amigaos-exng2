///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         utilitylib/rangedint.hpp
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

#ifndef _EXNG2_UTILITYLIB_RANGEDINT_HPP_
# define _EXNG2_SYSTEMLIB_RANGEDINT_HPP_

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  RangedInt
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

#endif
