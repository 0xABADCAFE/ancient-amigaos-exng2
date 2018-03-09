///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/amigaos3_68k/iolib/streamio_native.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Stream output
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

using namespace OSNative;
using namespace EXNGPrivate;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  IO::StreamOut
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LOGGING_DECLARE_CLASSNAME(IO::StreamOut)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

IO::StreamOut::~StreamOut()
{
  close();
  if (textBuffer) {
    Mem::free(textBuffer);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void IO::StreamOut::open(const char* fileName, IO::WriteMode m, size_t reqSize)
{
  LOGGING_DECLARE_FUNCNAME(open)

  if (!fileName) {
    THROW_NSX(Error, InvalidValue());
  }
  if (file) {
    close();
  }

  if ((m==IO::MODE_APPEND || m==IO::MODE_APPENDTEXT) && (file = Open(fileName, MODE_READWRITE)) ) {
    flags |= FILE_APPEND;
    if (Seek(file, 0, OFFSET_END)>=0) {
      fileSize = Seek(file, 0, OFFSET_CURRENT);
    }
    else {
      Close(file);
      fileSize = 0;
      file = 0;
    }
  }
  else if ( (file = Open(fileName,MODE_NEWFILE)) ) {
    fileSize = 0;
    flags |= FILE_WRITE;
  }

  if (file) {
    BPTR lock = 0;
    blockSize = 512;
    if ( (lock = ParentOfFH(file)) ) {
      ALIGNSTACKOBJ32(InfoData, infoData);
      if (Info(lock, &infoData)) {
        blockSize  = infoData.id_BytesPerBlock;
      }
      UnLock(lock);
    }
    reqSize = (((reqSize + (blockSize*2) - 1) / (blockSize*2)) * (blockSize*2));
    if (create(reqSize)) {
      packet.sp_Pkt.dp_Type = ACTION_WRITE;
      bytesLeft             = bufferSize;
      flags |= FILE_GOOD;
      return;
    }
    else {
      flags &= ~(FILE_ACCESS|FILE_GOOD);
      Close(file);
      file = 0;
    }
  }

  #ifdef EXNG2_BUILD_LOGGED
  SystemLog::write(
    SystemLog::WARNING, "%s::%s - unable to open %s\n",
    loggingClassName, loggingFuncName, fileName
  );
  #endif

  THROW_NSX(IO, OpenError());

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void IO::StreamOut::close()
{
  flush();
  if (file) {
    Close(file);
    file = 0;
    destroy();
  }
  flags &= ~(FILE_ACCESS|FILE_GOOD);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void IO::StreamOut::flush()
{
  if (file) {
    sint32 result = waitPacket();
    if ((result >= 0) && (bufferSize > bytesLeft)) {
      if (Write(file,buffers[currentBuf],bufferSize - bytesLeft)<0) {
        THROW_NSX(IO, WriteError());
      }
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

IO::SeekPos IO::StreamOut::tell()
{
  return seek(0, FROM_CURRENT);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

IO::SeekPos IO::StreamOut::seek(IO::SeekPos position, IO::SeekMode mode)
{
  if (!file) {
    THROW_NSX(IO, SeekError());
  }
  sint32 bytesArrived = waitPacket();
  if (bytesArrived < 0) {
    THROW_NSX(IO, SeekError());
  }
  if (bufferSize > bytesLeft) {
    if (Write(file,buffers[currentBuf],bufferSize - bytesLeft) < 0) {
      recordSyncFailure();
      THROW_NSX(IO, SeekError());
    }
  }
  sint32 natMode;
  switch (mode) {
    case IO::FROM_START:    natMode = OFFSET_BEGINNING; break;
    case IO::FROM_CURRENT:  natMode = OFFSET_CURRENT; break;
    case IO::FROM_END:      natMode = OFFSET_END; break;
  }
  sint32 current = Seek(file, position, natMode);
  if (current < 0) {
    recordSyncFailure();
    THROW_NSX(IO, SeekError());
  }
  bytesLeft  = bufferSize;
  currentBuf = 0;
  offset     = buffers[0];
  return (IO::SeekPos) current;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

size_t IO::StreamOut::writeBytes(const void* buffer, size_t n)
{
  if (!file) {
    THROW_NSX(IO, WriteError());
  }
  size_t totalBytes = 0;
  while (n > bytesLeft) {
    if (!handler) { // NIL
      offset    = buffers[0];
      bytesLeft = bufferSize;
      return n;
    }

    if (bytesLeft) {
      Mem::copy(offset, (void*)buffer, bytesLeft);
      n               -= bytesLeft;
      ((char*)buffer) += bytesLeft;
      totalBytes      += bytesLeft;
    }
    if (waitPacket() < 0) {
      THROW_NSX(IO, WriteError());
    }

    // send the current buffer out to disk
    sendPacket(buffers[currentBuf]);

    currentBuf  ^= 1;
    offset      = buffers[currentBuf];
    bytesLeft   = bufferSize;
  }

  Mem::copy(offset, (void*)buffer, n);
  bytesLeft       -= n;
  ((char*)offset) += n;
  return totalBytes + n;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

size_t IO::StreamOut::write16Swap(const void* buffer,size_t n)
{
  if (!file) {
    THROW_NSX(IO, WriteError());
  }
  if (((uint32)buffer|(uint32)offset)&1UL) {
    THROW_NSX(Error, BadAlignment());
  }
  n <<= 1;
  size_t totalBytes = 0;
  while (n > bytesLeft) {
    if (!handler) { // NIL
      offset      = buffers[0];
      bytesLeft = bufferSize;
      return n;
    }

    if (bytesLeft) {
      Mem::swap16(offset, (void*)buffer, (bytesLeft>>1));
      n               -= bytesLeft;
      ((char*)buffer) += bytesLeft;
      totalBytes      += bytesLeft;
    }
    if (waitPacket() < 0) {
      THROW_NSX(IO, WriteError());
    }

    // send the current buffer out to disk
    sendPacket(buffers[currentBuf]);

    currentBuf ^= 1;
    offset      = buffers[currentBuf];
    bytesLeft = bufferSize;
  }

  Mem::swap16(offset, (void*)buffer, (n>>1));
  bytesLeft       -= n;
  ((char*)offset) += n;
  return (totalBytes + n)>>1;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

size_t IO::StreamOut::write32Swap(const void* buffer,size_t n)
{
  if (!file) {
    THROW_NSX(IO, WriteError());
  }
  if (((uint32)buffer|(uint32)offset)&1UL) {
    THROW_NSX(Error, BadAlignment());
  }
  n <<= 2;
  size_t totalBytes = 0;
  while (n > bytesLeft) {
    if (!handler) { // NIL
      offset    = buffers[0];
      bytesLeft = bufferSize;
      return n;
    }

    if (bytesLeft) {
      Mem::swap32(offset, (void*)buffer, (bytesLeft>>2));
      n               -= bytesLeft;
      ((char*)buffer) += bytesLeft;
      totalBytes      += bytesLeft;
    }
    if (waitPacket() < 0) {
      THROW_NSX(IO, WriteError());
    }
    // send the current buffer out to disk
    sendPacket(buffers[currentBuf]);

    currentBuf ^= 1;
    offset      = buffers[currentBuf];
    bytesLeft = bufferSize;
  }

  Mem::swap32(offset, (void*)buffer, (n>>2));
  bytesLeft       -= n;
  ((char*)offset) += n;
  return (totalBytes + n)>>2;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

size_t IO::StreamOut::write64Swap(const void* buffer,size_t n)
{
  if (!file) {
    THROW_NSX(IO, WriteError());
  }
  if (((uint32)buffer|(uint32)offset)&1UL) {
    THROW_NSX(Error, BadAlignment());
  }
  n <<= 3;
  size_t totalBytes = 0;
  while (n > bytesLeft) {
    if (!handler) { // NIL
      offset      = buffers[0];
      bytesLeft = bufferSize;
      return n;
    }

    if (bytesLeft) {
      Mem::swap64(offset, (void*)buffer, (bytesLeft>>3));
      n               -= bytesLeft;
      ((char*)buffer) += bytesLeft;
      totalBytes      += bytesLeft;
    }
    if (waitPacket() < 0) {
      THROW_NSX(IO, WriteError());
    }
    // send the current buffer out to disk
    sendPacket(buffers[currentBuf]);

    currentBuf ^= 1;
    offset      = buffers[currentBuf];
    bytesLeft   = bufferSize;
  }

  Mem::swap64(offset, (void*)buffer, (n>>3));
  bytesLeft       -= n;
  ((char*)offset) += n;
  return (totalBytes + n)>>3;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

size_t IO::StreamOut::writeText(const char* format,...)
{
  if (!file) {
    THROW_NSX(IO, WriteError());
  }
  if (!textBuffer) {
    if (!(textBuffer = (char*)Mem::alloc(STREAMOUT_TEXTBUFFSIZE))) {
      THROW_NSX(IO, WriteError());
    }
  }
  va_list a;
  va_start(a,format);
  sint32 num = vsprintf(textBuffer, format, a);
  va_end(a);
  return writeBytes(textBuffer, num);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

size_t IO::StreamOut::rawReadBytes(void* buffer, size_t n, sint32 filePos)
{
  // Note the existing file position, move to the requested absolute position,
  // read and then reset the original position.
  sint32 oldPos = Seek(file, 0, OFFSET_CURRENT);
  Seek(file, filePos, OFFSET_BEGINNING);
  sint32 result = Read(file, buffer, n);
  Seek(file, oldPos, OFFSET_BEGINNING);
  if (result<0) {
    THROW_NSX(IO, WriteError());
  }
  return (size_t)result;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

