///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         utilitylib/rangedint.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Range bound numeric class
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

#ifndef _EXNG2_UTILITYLIB_RANGED_HPP_
# define _EXNG2_UTILITYLIB_RANGED_HPP_

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Ranged (numeric types only, limits are integer)
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T, int min, int max> class Ranged {
  private:
    T val;
  public: // Construtor
    Ranged() : val(0)        { val = val<min ? min : val>max ? max : val; }
    Ranged(T i)              { (i>min)?((i<max)?(val=i):(val=max)):(val=min); }
    void operator=(int i)    { (i>min)?((i<max)?(val=i):(val=max)):(val=min); }
  public: // Operators
    operator T()             { return val; }
    T operator()()           { return val; }
    T operator++()           { return (val<max)?(++val):(val=max); }   //++prefix
    T operator++(int)        { return (val<max)?(val++):(val=max); }   //postfix++
    T operator--()           { return (val>min)?(--val):(val=min); }   //--prefix
    T operator--(int)        { return (val>min)?(val--):(val=min); }   //postfix--
    T operator+=(T i)        { return (val+i<max)?(val+=i):(val=max); }
    T operator-=(T i)        { return (val>min+i)?(val-=i):(val=min); }
    T operator*=(T i)        { return (val*i<max)?(val*=i):(val=max); }
    T operator<<=(int i)     { return ((val<<i)<max)?(val<<=i):(val=max); }
    T operator/=(T i)        { return (val/i>min)?(val/=i):(val=min); }
    T operator>>=(int i)     { return ((val>>i)>min)?(val>>=i):(val=min); }
};

#endif
