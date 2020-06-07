///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef _PCMSTREAM_HPP
#define _PCMSTREAM_HPP

#include <xbase.hpp>

class PCM {

  public:
    typedef enum {
      U8_MONO           = 0,
      U8_STEREO_RL,
      U8_STEREO_LR,
      S8_MONO,
      S8_STEREO_RL,
      S8_STEREO_LR,
      S16_MONO,
      S16_STEREO_RL,
      S16_STEREO_LR,
      OTHER
    } PCMType;
};

class InputPCMStream :public PCM {
  public:
    virtual void    open(const char* fileName)            = 0;
    virtual void    close()                               = 0;
    virtual float64 getRecFreq()                          = 0;
    virtual sint32  getNumChannels()                      = 0;
    virtual sint32  getBitDepth()                         = 0;
    virtual bool    isSigned()                            = 0;
    virtual size_t  readCombine(void* buf, size_t len)    = 0;
    virtual size_t  readSplit(void* buf[], size_t len)    = 0;

  public:
    virtual ~InputPCMStream() {}
};

class OutputPCMStream : public PCM {
  public:
    virtual void    open(const char* fileName)            = 0;
    virtual void    close()                               = 0;
    virtual sint32  setRecFreq(float64 f)                 = 0;
    virtual sint32  setNumChannels(sint32 c)              = 0;
    virtual size_t  writeCombine(void* buf, size_t len)   = 0;
    virtual size_t  writeSplit(void* buf[], size_t len)   = 0;

  public:
    virtual ~OutputPCMStream() {}
};


#endif
