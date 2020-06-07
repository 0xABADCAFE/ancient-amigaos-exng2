///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "pcmstream_aiff.hpp"

#include <cmath>
#include <cstring>
#include <cstdio>

// AIFF is always organised as big endian

#if (X_ENDIAN == XA_BIGENDIAN)
  #define _READBIG64(d,n) (read64((d),(n)))
  #define _READBIG32(d,n) (read32((d),(n)))
  #define _READBIG16(d,n) (read16((d),(n)))
  #define _WRITEBIG64(d,n) (write64((d),(n)))
  #define _WRITEBIG32(d,n) (write32((d),(n)))
  #define _WRITEBIG16(d,n) (write16((d),(n)))
#else
  #define _READBIG64(d,n) (read64Swap((d),(n)))
  #define _READBIG32(d,n) (read32Swap((d),(n)))
  #define _READBIG16(d,n) (read16Swap((d),(n)))
  #define _WRITEBIG64(d,n) (write64Swap((d),(n)))
  #define _WRITEBIG32(d,n) (write32Swap((d),(n)))
  #define _WRITEBIG16(d,n) (write16Swap((d),(n)))
#endif

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  InputAIFF16
//
//  InputPCMStream implementation, supports basic AIFF 16 only
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#define COMMSIZE 18
#define SSNDSIZE 8

InputAIFF16::InputAIFF16() : StreamIn(), freq(0), numCh(0), dataOffset(0), dataSize(0)
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

InputAIFF16::~InputAIFF16()
{
  close();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define U2F(u) (((float64)((sint32)(u - 2147483647L - 1))) + 2147483648.0)

void InputAIFF16::decodeIEEEExt(uint8* ieee)
{
  float64 f;

  sint32  expnt   = ((ieee[0] & 0x7F)<<8) | (ieee[1] & 0xFF);
  uint32  hiMant  = ((uint32)(ieee[2]))<<24
                  | ((uint32)(ieee[3]))<<16
                  | ((uint32)(ieee[4]))<<8
                  | ((uint32)(ieee[5]));
  uint32  loMant  = ((uint32)(ieee[6]))<<24
                  | ((uint32)(ieee[7]))<<16
                  | ((uint32)(ieee[8]))<<8
                  | ((uint32)(ieee[9]));

  if ((!expnt) && (!hiMant) && (!loMant)) {
    f = 0;
  }
  else {
    if (expnt == 0x7FFF) {
      f = HUGE_VAL;
    }
    else {
      expnt -= 16383;
      f =   std::ldexp(U2F(hiMant), expnt-=31);
      f +=  std::ldexp(U2F(loMant), expnt-=32);
    }
  }


  freq = f < 1.0 ? 1.0 : f > 1000000.0 ? 1000000.0 : f;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InputAIFF16::close()
{
  freq        = 0;
  numCh       = 0;
  dataOffset  = 0;
  dataSize    = 0;
/*
  if (splitBuffer) {
    Mem::free(splitBuffer);
    splitBuffer=0;
  }
*/
  StreamIn::close();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InputAIFF16::open(const char* fileName)
{
  StreamIn::open(fileName);

  char chunkName[4];

  // FORM chunk
  uint32  totalSize;
  if ((read8(chunkName, 4)!=4) || (strncmp(chunkName, "FORM", 4)!=0) ||
      (_READBIG32(&totalSize,1)!=1) ||
      (read8(chunkName, 4)!=4) || (strncmp(chunkName, "AIFF", 4)!=0)) {
    StreamIn::close();
  }

  // COMM chunk
  uint32  chunkSize;
  uint32  samples;
  uint16  chan;
  uint16  bitsPerSample;
  uint8   freqIEEEExt[10];

  if ((read8(chunkName, 4)!=4) || (strncmp(chunkName, "COMM", 4)!=0) ||
      (_READBIG32(&chunkSize, 1)!=1) || (chunkSize!=COMMSIZE) ||
      (_READBIG16(&chan, 1)!=1) || (_READBIG32(&samples, 1)!=1) ||
      (_READBIG16(&bitsPerSample, 1)!=1) || (read8(freqIEEEExt, 10)!=10)) {
    StreamIn::close();
    THROW_NSX(IO, ReadError());
  }

  if (bitsPerSample!=16) {
    StreamIn::close();
    THROW_NSX(IO, ReadError());
  }

  // SSND chunk
  uint32 offset;
  uint32 blockSize;

  if ((read8(chunkName, 4)!=4) || (strncmp(chunkName, "SSND", 4)!=0) ||
      (_READBIG32(&chunkSize, 1)!=1) || (_READBIG32(&offset, 1)!=1) ||
      (_READBIG32(&blockSize, 1)!=1)) {
    StreamIn::close();
    THROW_NSX(IO, ReadError());
  }

  if (blockSize) {
    StreamIn::close();
    THROW_NSX(IO, ReadError());
  }

  if (offset) {
    StreamIn::seek(offset, IO::FROM_CURRENT);
  }
/*
  if (!(splitBuffer = Mem::alloc(256*numCh*sizeof(sint16), false, Mem::ALIGN_CACHE))) {
    X_ERROR("InputAIFF16::open() - unable to allocate split buffer");
    StreamIn::close();
    return ERR_NO_FREE_STORE;
  }
*/

  dataOffset  = StreamIn::tell();
  dataSize    = samples;
  numCh       = chan;
  decodeIEEEExt(freqIEEEExt);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

size_t InputAIFF16::readCombine(void* buf, size_t len)
{
  if (!buf) {
    THROW_NSX(Error, NullPointer());
  }
  if (len <1) {
    THROW_NSX(Error, InvalidValue());
  }
  return _READBIG16(buf, len*numCh);
}

size_t InputAIFF16::readSplit(void* buf[], size_t len)
{

  THROW_NSX(IO, ReadError());

  return 0;
}
