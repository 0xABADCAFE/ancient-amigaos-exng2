///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         dblib/db_error.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Runtime error exception classes
//  Comment(s):
//  Library:      dblib
//  Created:      2006-10-08
//  Updated:      2006-10-08
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <xbase.hpp>
#include <dblib/db_abstract.hpp>

using namespace EXNGPrivate;

DECLARE_MIN_RTTI(DB::Error);
DECLARE_MIN_RTTI(DB::ConnectionError);
DECLARE_MIN_RTTI(DB::CommandSyncError);
DECLARE_MIN_RTTI(DB::QueryError);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Private Exception throwers - Given C linkage as used by asm code. Also used to avoid inline exception bloat
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef EXNG2_BUILD_AVOID_BLOAT
extern "C" {
  // exception specifier bloat minimisation. Use these instead of local use of throw
  void throwDBError()                       { throw DB::Error(); }
  void throwDBConnectionError()             { throw DB::ConnectionError(); }
  void throwDBCommandSyncError()            { throw DB::CommandSyncError(); }
  void throwDBQueryError(const char* error) { throw DB::QueryError(error); }
}
#endif

