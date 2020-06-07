///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/linux_noarch/iolib/streamio_native.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Stream Error
//  Comment(s):
//  Library:      System
//  Created:      2007-01-12
//  Updated:      2007-01-12
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <xbase.hpp>
#include <systemlib/memory.hpp>
#include <iolib/streamio.hpp>
#include <private/systemlib/error.hpp>

#include <systemlib/logger.hpp>

#include <cstdarg>

using namespace EXNGPrivate;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  IO::StreamIn
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

size_t IO::Stream::In::rawWriteBytes(const void* buffer, size_t n, IO::Stream::SeekPos filePos)
{
  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void IO::Stream::In::open(const char* fileName, IO::Stream::ReadMode m, size_t s)
{
  //LOGGING_DECLARE_FUNCNAME(open)
  if (!fileName) {
    THROW_NSX(Error, InvalidValue());
  }
  if (file) {
    close();
  }
  if ((file = std::fopen(fileName, "r+"))) {
    if (!create(s)) {
      close();
    }
  } else {
    THROW_NSX(IO, OpenError());
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void IO::Stream::In::close()
{
  if (file) {
    std::fclose(file);
    destroy();
    file = 0;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void IO::Stream::In::flush()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//#include <cstdio>

size_t IO::Stream::In::readBytes(void* buffer, size_t n)
{
  assertReadable();
  assertPointer(buffer);
  size_t bytes = std::fread(buffer, 1, n, file);
  if (bytes<n /*&& !std::feof(file)*/) {
    //std::printf("Requested %z bytes, got %z\n", n, bytes);
    THROW_NSX(IO, ReadError());
  }
  return bytes;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

size_t IO::Stream::In::read16Swap(void* buffer, size_t n)
{
  assertReadable();
  assertPointer(buffer);

  size_t blocks = (n<<1)/swapSize;
  size_t nWords = swapSize>>1;
  size_t nRead  = 0;

  while (blocks--) {
    nRead += fread(swapBuffer, 2, nWords, file);
    Mem::swap16(buffer, swapBuffer, nWords);
    n -= nWords;
  }
  nRead += fread(swapBuffer, 2, n, file);
  Mem::swap16(buffer, swapBuffer, n);
  return nRead;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

size_t IO::Stream::In::read32Swap(void* buffer, size_t n)
{
  assertReadable();
  assertPointer(buffer);

  size_t blocks = (n<<2)/swapSize;
  size_t nWords = swapSize>>2;
  size_t nRead  = 0;

  while (blocks--) {
    nRead += fread(swapBuffer, 4, nWords, file);
    Mem::swap32(buffer, swapBuffer, nWords);
    n -= nWords;
  }
  nRead += fread(swapBuffer, 4, n, file);
  Mem::swap32(buffer, swapBuffer, n);
  return nRead;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

size_t IO::Stream::In::read64Swap(void* buffer, size_t n)
{
  assertReadable();
  assertPointer(buffer);

  size_t blocks = (n<<3)/swapSize;
  size_t nWords = swapSize>>3;
  size_t nRead  = 0;

  while (blocks--) {
    nRead += fread(swapBuffer, 8, nWords, file);
    Mem::swap64(buffer, swapBuffer, nWords);
    n -= nWords;
  }
  nRead += fread(swapBuffer, 8, n, file);
  Mem::swap64(buffer, swapBuffer, n);
  return nRead;

  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

size_t IO::Stream::In::readText(char* buffer, sint32 max, char mark, sint32 num)
{
  assertReadable();
  assertPointer(buffer);

  char*   p = buffer;
  sint32  i = max;
  while (--i && num) {
    sint32 c = std::fgetc(file);
    if (c==EOF) {
      // terminate if error
      break;
    }
    if (c==(sint32)mark) {
      num--;
    }
    *(p++) = (char)c;
  }
  *p = 0; // null terminate
  return (max-i); // return num chars read
}

