///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         dblib/db_abstract.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Database definitions
//  Comment(s):
//  Library:      IO
//  Created:      2007-04-19
//  Updated:      2007-04-19
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _EXNG2_DBLIB_DB_ERROR_PRIVATE_HPP_
# define _EXNG2_DBLIB_DB_ERROR_PRIVATE_HPP_

namespace EXNGPrivate {
  extern "C" {
    // exception specifier bloat minimisation. Use these instead of local 'throw <classname>'
    void throwDBError();
    void throwDBConnectionError();
    void throwDBCommandSyncError();
    void throwDBQueryError(const char* error);
  }
}

#endif
