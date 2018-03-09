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

#ifndef _EXNG2_DBLIB_DB_ERROR_HPP_
# define _EXNG2_DBLIB_DB_ERROR_HPP_

class DB::Error               : virtual public ::Error::Runtime { DEFINE_MIN_RTTI };
class DB::ConnectionError     : public DB::Error        { DEFINE_MIN_RTTI };
class DB::CommandSyncError    : public DB::Error        { DEFINE_MIN_RTTI };
class DB::QueryError          : public DB::Error        {
  DEFINE_MIN_RTTI
  private:
    const char* error;
  public:
    const char* getErrorText()                    { return error; }
    QueryError(const char* error) : error(error)  {}
};

#include <private/dblib/db_error_private.hpp>

#endif
