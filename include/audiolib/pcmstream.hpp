///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         audiolib/pcmstream.hpp
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

# include <audiolib/audio.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  PCM Stream (file) classes
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Audio {
  namespace PCMStream {

    class In {
      DEFINE_MIN_RTTI
      public:
        virtual void              open(const char* fileName)          = 0;
        virtual void              close()                             = 0;
        virtual float64           getRecFreq() const                  = 0;
        virtual uint32            getNumChannels() const              = 0;
        virtual Machine::ElemType getSampleType() const               = 0;
        virtual uint32            getChannelMask() const              = 0;
        virtual Audio::Channel    getChannelSpec(uint32 ch) const     = 0;
        virtual uint32            getBitDepth()                       = 0;
        virtual size_t            readCombine(void* buf, size_t len)  = 0;
        virtual size_t            readSplit(void* buf[], size_t len)  = 0;

      public:
        virtual ~In() {}
    };

    class Out {
      DEFINE_MIN_RTTI
      public:
        virtual void    open(const char* fileName)                    = 0;
        virtual void    close()                                       = 0;
        virtual sint32  setRecFreq(float64 f)                         = 0;
        virtual sint32  setNumChannels(sint32 c)                      = 0;
        virtual size_t  writeCombine(void* buf, size_t len)           = 0;
        virtual size_t  writeSplit(void* buf[], size_t len)           = 0;

      public:
        virtual ~Out() {}
    };

  };


};

#endif
