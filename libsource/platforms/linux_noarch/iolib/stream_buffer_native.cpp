///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/linux_noarch/iolib/streamio_native.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Stream buffer
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

LOGGING_DECLARE_CLASSNAME(StreamBuffer)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  StreamBuffer
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


bool StreamBuffer::exists(const char* f)
{
  std::FILE* p = std::fopen(f, "r");
  if (p) {
    std::fclose(p);
    return true;
  }
  return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool StreamBuffer::create(size_t s)
{
  //LOGGING_DECLARE_FUNCNAME(create)
  if (file && (!swapBuffer)) {
    swapBuffer = Mem::alloc(s, Mem::ZEROFILL);
    swapSize = s;
    return true;
  }
  return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void StreamBuffer::destroy()
{
  if (swapBuffer) {
    Mem::free(swapBuffer);
    swapBuffer  = 0;
    swapSize    = 0;
  }
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

size_t  StreamBuffer::size()  const
{
  if (!file) {
    THROW_NSX(IO, Error());
  }

  long pos = std::ftell(file);

  if (pos<0 || std::fseek(file, 0, SEEK_END)<0) {
    THROW_NSX(IO, SeekError());
  }
  int len = std::ftell(file);
  if (len<0 || std::fseek(file, pos, SEEK_SET)) {
    THROW_NSX(IO, SeekError());
  }
  return len;
}

IO::Stream::SeekPos StreamBuffer::tell()
{
  if (!file) {
    THROW_NSX(IO, SeekError());
  }
  long res = std::ftell(file);
  if (res<0) {
    THROW_NSX(IO, SeekError());
  }
  return (IO::Stream::SeekPos)res;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

IO::Stream::SeekPos StreamBuffer::seek(IO::Stream::SeekPos p, IO::Stream::SeekMode m)
{
  if (!file) {
    THROW_NSX(IO, SeekError());
  }
  int res = 0;
  switch (m) {
    case IO::Stream::FROM_START:    res = std::fseek(file, p, SEEK_SET); break;
    case IO::Stream::FROM_CURRENT:  res = std::fseek(file, p, SEEK_CUR); break;
    case IO::Stream::FROM_END:      res = std::fseek(file, p, SEEK_END); break;
  }
  if (res<0) {
    THROW_NSX(IO, SeekError());
  }
  return tell();
}

