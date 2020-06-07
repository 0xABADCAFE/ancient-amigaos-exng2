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
  class Error : virtual public ::Error::Runtime { DEFINE_MIN_RTTI };

  // standard channel definitions
  typedef enum {
    SPEAKER_FRONT_LEFT            = 0,
    SPEAKER_FRONT_RIGHT           = 1,
    SPEAKER_FRONT_CENTER          = 2,
    SPEAKER_LOW_FREQUENCY         = 3,
    SPEAKER_BACK_LEFT             = 4,
    SPEAKER_BACK_RIGHT            = 5,
    SPEAKER_FRONT_LEFT_OF_CENTER  = 6,
    SPEAKER_FRONT_RIGHT_OF_CENTER = 7,
    SPEAKER_BACK_CENTER           = 8,
    SPEAKER_SIDE_LEFT             = 9,
    SPEAKER_SIDE_RIGHT            = 10,
    SPEAKER_LEFT_HEIGHT           = 11,
    SPEAKER_RIGHT_HEIGHT          = 12
  } Channel;

  enum {
    SF_FRONT_LEFT             = 1<<SPEAKER_FRONT_LEFT,
    SF_FRONT_RIGHT            = 1<<SPEAKER_FRONT_RIGHT,
    SF_FRONT_CENTER           = 1<<SPEAKER_FRONT_CENTER,
    SF_LOW_FREQUENCY          = 1<<SPEAKER_LOW_FREQUENCY,
    SF_BACK_LEFT              = 1<<SPEAKER_BACK_LEFT,
    SF_BACK_RIGHT             = 1<<SPEAKER_BACK_RIGHT,
    SF_FRONT_LEFT_OF_CENTER   = 1<<SPEAKER_FRONT_LEFT_OF_CENTER,
    SF_FRONT_RIGHT_OF_CENTER  = 1<<SPEAKER_FRONT_RIGHT_OF_CENTER,
    SF_BACK_CENTER            = 1<<SPEAKER_BACK_CENTER,
    SF_SIDE_LEFT              = 1<<SPEAKER_SIDE_LEFT,
    SF_SIDE_RIGHT             = 1<<SPEAKER_SIDE_RIGHT,
    SF_LEFT_HEIGHT            = 1<<SPEAKER_LEFT_HEIGHT,
    SF_RIGHT_HEIGHT           = 1<<SPEAKER_RIGHT_HEIGHT
  };

  // common audio formats
  enum {
    AF_10_MONO                  = 0,
    AF_20_STEREO                = 1,
    AF_21_STEREO                = 2,
    AF_40_SURROUND              = 3,
    AF_40_QUAD                  = 4,
    AF_41                       = 5,
    AF_51                       = 6,
    AF_51_SIDE                  = 7,
    AF_61                       = 8,
    AF_71_FRONT                 = 9,
    AF_71_SURROUND              = 10,
    AF_91_SURROUND              = 11
  };

};


#include <audiolib/audio_native.hpp>

#endif
