///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         iolib/streamio.hpp
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

#ifndef _EXNG2_IOLIB_STREAMIO_HPP_
# define _EXNG2_IOLIB_STREAMIO_HPP_

#include "io.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Base definitions for streams
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace IO {

  typedef enum {
    MODE_READ       = 0,
    MODE_READTEXT
  } ReadMode;

  typedef enum {
    MODE_WRITE      = 0,
    MODE_WRITETEXT,
    MODE_APPEND,
    MODE_APPENDTEXT
  } WriteMode;

  typedef enum {
    FROM_START,
    FROM_CURRENT,
    FROM_END
  } SeekMode;

  typedef long SeekPos;

  enum {
    DEFAULT_BUFFSIZE  = 2048
  };

  class StreamIn;
  class StreamOut;
};

# include <iolib/streamio_native.hpp>

#endif
