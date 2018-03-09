///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         private/systemlib/time.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:
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



#ifndef _EXNG2_SYSTEMLIB_TIME_PRIVATE_HPP_
# define _EXNG2_SYSTEMLIB_TIME_PRIVATE_HPP_

namespace EXNGPrivate {
  class DatestampModifier {
    protected:
      static uint32* getDatestampRep(Time::Datestamp* ds) { return ds->data; }
  };
};

#endif
