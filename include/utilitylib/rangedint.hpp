///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         utilitylib/rangedint.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Runnable interface
//  Comment(s):
//  Library:      System
//  Created:      2006-10-08
//  Updated:      2006-10-08
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill, Serkan YAZICI
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _EXNG2_UTILITYLIB_RANGEDINT_HPP_
#	define _EXNG2_SYSTEMLIB_RANGEDINT_HPP_

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Rint
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T, int min, int max> class Rint {
	private:
		T val;
	public:	// Construtor
		Rint() : val(min)     { }
		Rint(int i)           { (i>min)?((i<max)?(val=i):(val=max)):(val=min); }
		void operator=(int i) { (i>min)?((i<max)?(val=i):(val=max)):(val=min); }
	public:	// Operators
		operator T()          { return val; }
		T operator()()        { return val; }
		T operator++()        { return (val<max)?(++val):(val=max); }   //++prefix
		T operator++(int)     { return (val<max)?(val++):(val=max); }   //postfix++
		T operator--()        { return (val>min)?(--val):(val=min); }   //--prefix
		T operator--(int)     { return (val>min)?(val--):(val=min); }   //postfix--
		T operator+=(int i)   { return (val+i<max)?(val+=i):(val=max); }
		T operator-=(int i)   { return (val>min+i)?(val-=i):(val=min); }
		T operator*=(int i)   { return ((long)val*i<max)?(val*=i):(val=max); }
		T operator<<=(int i)  { return ((long)(val<<i)<max)?(val<<=i):(val=max); }
		T operator/=(int i)   { return ((long)val/i>min)?(val/=i):(val=min); }
		T operator>>=(int i)  { return ((long)(val>>i)>min)?(val>>=i):(val=min); }
};

#endif
