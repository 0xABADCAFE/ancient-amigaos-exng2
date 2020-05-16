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

#ifndef _EXNG2_UTILITYLIB_AUTOCLEAN_HPP_
# define _EXNG2_SYSTEMLIB_AUTOCLEAN_HPP_

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  AutoDelete
//
//  Autodelete holder(<pointer to thing>)
//
//  Deletes the referenced item when the instance is destroyed
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
class AutoDelete {

  private:
    T* instance;
  public:
    void unbind()                   { instance = 0; }
    void set(T* p)                  { instance = p; }
    AutoDelete(T* p) : instance(p)  { }
    ~AutoDelete()                   { if (instance) delete instance; }
};




#endif
