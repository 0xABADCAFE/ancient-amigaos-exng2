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
//  IO::Stream::Out
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


size_t IO::Stream::Out::rawReadBytes(void* buffer, size_t n, IO::Stream::SeekPos filePos)
{
  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void IO::Stream::Out::open(const char* fileName, IO::Stream::WriteMode mode, size_t size)
{
  if (!fileName) {
    THROW_NSX(Error, InvalidValue());
  }
  if (file) {
    close();
  }
  switch(mode) {
    case IO::Stream::MODE_WRITE:
    case IO::Stream::MODE_WRITETEXT:
      file = std::fopen(fileName, "w+");
      break;
    case IO::Stream::MODE_APPEND:
    case IO::Stream::MODE_APPENDTEXT:
      file = std::fopen(fileName, "a+");
      break;

    default:
      THROW_NSX(Error, InvalidValue());
      break;
  }
  if (file) {
    if (!create(size)) {
      close();
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void IO::Stream::Out::close()
{
  if (file) {
    std::fclose(file);
    destroy();
    file = 0;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void IO::Stream::Out::flush()
{
  assertWriteable();
  std::fflush(file);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

size_t IO::Stream::Out::writeBytes(const void* buffer, size_t n)
{
  assertWriteable();
  assertPointer(buffer);
  return std::fwrite(buffer, 1, n, file);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

size_t IO::Stream::Out::write16Swap(const void* buffer, size_t n)
{
  assertWriteable();
  assertPointer(buffer);

  size_t blocks   = (n<<1)/swapSize;
  size_t nWords   = swapSize>>1;
  size_t nWritten = 0;

  while (blocks--) {
    Mem::swap16(swapBuffer, buffer, nWords);
    nWritten += std::fwrite(swapBuffer, 2, nWords, file);
    n -= nWords;
  }
  Mem::swap16(swapBuffer, buffer, n);
  nWritten += std::fwrite(swapBuffer, 2, n, file);
  return nWritten;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

size_t IO::Stream::Out::write32Swap(const void* buffer, size_t n)
{
  assertWriteable();
  assertPointer(buffer);

  size_t blocks   = (n<<2)/swapSize;
  size_t nWords   = swapSize>>2;
  size_t nWritten = 0;

  while (blocks--) {
    Mem::swap32(swapBuffer, buffer, nWords);
    nWritten += std::fwrite(swapBuffer, 4, nWords, file);
    n -= nWords;
  }
  Mem::swap32(swapBuffer, buffer, n);
  nWritten += std::fwrite(swapBuffer, 4, n, file);
  return nWritten;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

size_t IO::Stream::Out::write64Swap(const void* buffer, size_t n)
{
  assertWriteable();
  assertPointer(buffer);

  size_t blocks   = (n<<3)/swapSize;
  size_t nWords   = swapSize>>3;
  size_t nWritten = 0;

  while (blocks--) {
    Mem::swap64(swapBuffer, buffer, nWords);
    nWritten += std::fwrite(swapBuffer, 8, nWords, file);
    n -= nWords;
  }
  Mem::swap64(swapBuffer, buffer, n);
  nWritten += std::fwrite(swapBuffer, 8, n, file);
  return nWritten;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

size_t IO::Stream::Out::writeText(const char* format,...)
{
  assertWriteable();
  assertPointer(format);
  va_list args;
  va_start(args,format);
  long num = std::vfprintf(file, format, args);
  va_end(args);
  if (num>0) {
    return num;
  }
  THROW_NSX(IO, WriteError());
}
