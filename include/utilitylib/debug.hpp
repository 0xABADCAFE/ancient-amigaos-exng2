///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         utilitylib/debug.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Polling classes
//  Comment(s):
//  Library:      utility
//  Created:      2007-04-07
//  Updated:      2007-04-07
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _EXNG2_UTILITYLIB_DEBUG_HPP_
# define _EXNG2_UTILITYLIB_DEBUG_HPP_

class Debug {
  private:
    const char* name;
    static int  level;
  public:
    Debug(const char*);
    ~Debug();

    void printf(const char* fmt, ...);
};

#endif
