///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         iolib/io.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  IO definitions
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

#ifndef _EXNG2_IOLIB_IO_HPP_
# define _EXNG2_IOLIB_IO_HPP_

# include <xbase.hpp>
# include <systemlib/error.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Base definitions
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace IO {

  class Error         : virtual public ::Error::Runtime { DEFINE_MIN_RTTI };
  class OpenError     : public Error { DEFINE_MIN_RTTI };
  class CreateError   : public Error { DEFINE_MIN_RTTI };
  class ReadError     : public Error { DEFINE_MIN_RTTI };
  class WriteError    : public Error { DEFINE_MIN_RTTI };
  class SeekError     : public Error { DEFINE_MIN_RTTI };
  class TimeoutError  : public Error { DEFINE_MIN_RTTI };

}

#include <private/iolib/io.hpp>

#endif
