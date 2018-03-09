///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         audiolib/audio.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Top level definitions
//  Comment(s):
//  Library:      IO
//  Created:      2009-01-04
//  Updated:      2009-01-04
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _EXNG2_AUDIOLIB_AUDIO_HPP_
# define _EXNG2_AUDIOLIB_AUDIO_HPP_

# include <xbase.hpp>
# include <systemlib/error.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Base definitions
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Audio {

  // error classes
  class Error;
};

class Audio::Error              : public RuntimeError { DEFINE_MIN_RTTI };

#include XP_INCLUDE_PLATFORM("audiolib/audio_native.hpp")

#endif