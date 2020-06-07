///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _PCMSTREAM_AIFF_HPP
#define _PCMSTREAM_AIFF_HPP

#include "pcmstream.hpp"
#include <iolib/streamio.hpp>

class InputAIFF16 : public InputPCMStream, private IO::StreamIn {
  private:
    float64 freq;
    sint32  numCh;
    size_t  dataOffset;
    size_t  dataSize;
    sint16* splitBuffer;
    void    decodeIEEEExt(uint8* ieee);

  public:
    void open(const char* fileName);
    void close();

    float64 getRecFreq()      { return freq; }
    sint32  getNumChannels()  { return numCh; }

    sint32  getBitDepth()     { return 16; }
    bool    isSigned()        { return true; }

    size_t  readCombine(void* buf, size_t len);
    size_t  readSplit(void* buf[], size_t len);

  public:
    InputAIFF16();
    ~InputAIFF16();
};


#endif
