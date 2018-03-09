///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         systemlib/runnable.hpp
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
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef _EXNG2_SYSTEMLIB_RUNNABLE_HPP_
# define _EXNG2_SYSTEMLIB_RUNNABLE_HPP_

class Runnable {
  DEFINE_MIN_RTTI
  public:
    virtual sint32 run() = 0;
    virtual ~Runnable() {}
};



#endif
