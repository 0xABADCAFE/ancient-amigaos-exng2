///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/amigaos3_68k/iolib/streamio_native.cpp
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

using namespace OSNative;
using namespace EXNGPrivate;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  IO::StreamIn
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LOGGING_DECLARE_CLASSNAME(IO::StreamIn)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

IO::StreamIn::~StreamIn()
{
  close();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 IO::StreamIn::getNextCharIO()
{
  sint32 bytesArrived = waitPacket();
  if (bytesArrived <= 0) {
    if (bytesArrived == 0) { // end of file reached
      flags |= FILE_ATEND;
      SetIoErr(0);
      return EOF;
    } else {
      flags &= ~FILE_GOOD;
      THROW_NSX(IO, ReadError());
    }
  }
  sendPacket(buffers[currentBuf^1]); // ask that the buffer be filled
  if (seekOffset > bytesArrived) {
    seekOffset = bytesArrived;
  }
  offset      = ((char*)(buffers[currentBuf])+seekOffset);
  currentBuf  ^= 1;
  bytesLeft   = bytesArrived - seekOffset;
  seekOffset  = 0;

  bytesLeft--;
  return *((char*)offset)++;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void IO::StreamIn::open(const char* fileName, IO::ReadMode m, size_t reqSize)
{
  LOGGING_DECLARE_FUNCNAME(open)

  if (!fileName) {
    THROW_NSX(Error, InvalidValue());
  }
  if (file) {
    close();
  }
  if ( (file = Open(fileName, MODE_OLDFILE)) ) {
    if (Seek(file, 0, OFFSET_END)>=0) {
      fileSize = Seek(file, 0, OFFSET_CURRENT);
    }
    else {
      Close(file);
      fileSize = 0;
      file = 0;

      #ifdef EXNG2_BUILD_LOGGED
      SystemLog::write(
        SystemLog::WARNING, "%s::%s - stream %s contains no data\n",
        loggingClassName, loggingFuncName, fileName
      );
      #endif

      THROW_NSX(IO, OpenError());
    }
    Seek(file, 0, OFFSET_BEGINNING);
    flags |= FILE_READ;
    blockSize = 512;
    BPTR lock = 0;
    if ( (lock = Lock(fileName, ACCESS_READ)) ) {
      ALIGNSTACKOBJ32(InfoData, infoData);
      if (Info(lock,&infoData)) {
        blockSize  = infoData.id_BytesPerBlock;
      }
      UnLock(lock);
    }
    reqSize = (((reqSize + (blockSize*2) - 1) / (blockSize*2)) * (blockSize*2));
    if (create(reqSize)) {  // prefetch
      packet.sp_Pkt.dp_Type = ACTION_READ;
      bytesLeft             = 0;
      offset                = buffers[1];
      if (handler) {
        sendPacket(buffers[0]);
      }
      flags |= FILE_GOOD;
      if (m==IO::MODE_READTEXT) {
        flags |= FILE_TEXT;
      }
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

void IO::StreamIn::close()
{
  if (file) {
    waitPacket();
    Close(file);
    destroy();
    file = 0;
    flags &= ~(FILE_ACCESS|FILE_GOOD);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void IO::StreamIn::flush()
{
  if (file) {
    waitPacket();
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

IO::SeekPos IO::StreamIn::tell()
{
  if (!file) {
    THROW_NSX(IO, SeekError());
  }
  sint32 bytesArrived = waitPacket();
  if (bytesArrived < 0) {
    THROW_NSX(IO, SeekError());
  }
  return (IO::SeekPos)Seek(file, 0, OFFSET_CURRENT)-(bytesLeft+bytesArrived)+seekOffset;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

IO::SeekPos IO::StreamIn::seek(sint32 position, IO::SeekMode mode)
{
  if (!file) {
    THROW_NSX(IO, SeekError());
  }
  sint32 bytesArrived = waitPacket();
  if (bytesArrived < 0) {
    THROW_NSX(IO, SeekError());
  }

  // figure out what the actual file position is
  sint32 filePos = Seek(file, 0, OFFSET_CURRENT);
  if (filePos < 0) {
    recordSyncFailure();
    THROW_NSX(IO, SeekError());
  }
  // figure out what the caller's file position is
  sint32 current = filePos - (bytesLeft+bytesArrived) + seekOffset;
  sint32 target=0;
  // figure out the absolute offset within the file where we must seek to

  switch (mode) {
    case IO::FROM_START:
      target = position;
      break;

    case IO::FROM_CURRENT:
      target = current + position;
      break;

    case IO::FROM_END: {
        ALIGNSTACKOBJ32(FileInfoBlock, fib);
        if ( !ExamineFH(file, &fib) ) {
          recordSyncFailure();
          THROW_NSX(IO, SeekError());
        }
        target = fib.fib_Size + position;
      }
      break;

    default:
      THROW_NSX(IO, SeekError());
      break;
  }

  // figure out what range of the file is currently in our buffers
  sint32 minBuf = current-(sint32)((uint32)offset-(uint32)buffers[currentBuf^1]);
  sint32 maxBuf = current + bytesLeft + bytesArrived;  // WARNING: this is one too big
  sint32 diff = target - current;

  if ((target < minBuf) || (target >= maxBuf)) {
    sint32 roundTarget = (target / blockSize) * blockSize;
    if ( Seek(file, roundTarget - filePos, OFFSET_CURRENT) < 0 ) {
      recordSyncFailure();
      THROW_NSX(IO, SeekError());
    }
    sendPacket(buffers[0]);
    seekOffset = target-roundTarget;
    bytesLeft  = 0;
    currentBuf = 0;
    offset     = buffers[1];
  }
  else if ((target < current) || (diff <= bytesLeft)) {
    requeuePacket();
    bytesLeft       -= diff;
    ((char*)offset) += diff;
  }
  else {
    sendPacket(buffers[currentBuf^1]);
    diff        -= bytesLeft - seekOffset;
    offset      = (char*)(buffers[currentBuf]) + diff;
    bytesLeft   = bytesArrived - diff;
    seekOffset  = 0;
    currentBuf  ^= 1;
  }
  return (IO::SeekPos) current;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

size_t IO::StreamIn::readBytes(void* buffer, size_t n)
{
  if (!file) {
    //throwStreamReadError();
    THROW_NSX(IO, ReadError());
  }
  size_t totalBytes = 0;
  // if we need more bytes than there are in the current buffer, enter the read
  // loop
  while (n > bytesLeft) {
    Mem::copy(buffer, offset, bytesLeft);
    n               -= bytesLeft;
    ((char*)buffer) += bytesLeft;
    totalBytes      += bytesLeft;
    bytesLeft       = 0;
    sint32 bytesArrived = waitPacket();
    if (bytesArrived <= 0) {
      if (bytesArrived == 0) { // end of file reached
        flags |= FILE_ATEND;
        SetIoErr(0);
        return totalBytes;
      }
      THROW_NSX(IO, ReadError());
    }
    // ask that the buffer be filled
    sendPacket(buffers[currentBuf^1]);
    if (seekOffset > bytesArrived) {
      seekOffset = bytesArrived;
    }
    offset      = (char*)(buffers[currentBuf]) + seekOffset;
    currentBuf  ^= 1;
    bytesLeft   = bytesArrived - seekOffset;
    seekOffset  = 0;
  }
  Mem::copy(buffer, offset, n);
  bytesLeft       -= n;
  ((char*)offset) += n;
  return totalBytes + n;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

size_t IO::StreamIn::read16Swap(void* buffer,size_t n)
{
  if (!file) {
    THROW_NSX(IO, ReadError());
  }
  if (((uint32)buffer|(uint32)offset)&1UL) {
    THROW_NSX(Error, BadAlignment());
  }
  n <<= 1;
  size_t totalBytes = 0;
  while (n > bytesLeft) {
    Mem::swap16(buffer, offset, (bytesLeft>>1));
    n                   -= bytesLeft;
    ((char*)buffer)     += bytesLeft;
    totalBytes          += bytesLeft;
    bytesLeft       = 0;
    sint32 bytesArrived = waitPacket();
    if (bytesArrived <= 0) {
      if (bytesArrived == 0) {
        // end of file reached
        flags |= FILE_ATEND;
        SetIoErr(0);
        return totalBytes>>1;
      }
      THROW_NSX(IO, ReadError());
    }
    // ask that the buffer be filled
    sendPacket(buffers[currentBuf^1]);
    if (seekOffset > bytesArrived) {
      seekOffset = bytesArrived;
    }
    offset      = (char*)(buffers[currentBuf]) + seekOffset;
    currentBuf ^= 1;
    bytesLeft   = bytesArrived - seekOffset;
    seekOffset  = 0;
  }
  Mem::swap16(buffer, offset, (n>>1));

  bytesLeft       -= n;
  ((char*)offset) += n;
  return (totalBytes + n)>>1;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

size_t IO::StreamIn::read32Swap(void* buffer,size_t n)
{
  if (!file) {
    THROW_NSX(IO, ReadError());
  }
  if (((uint32)buffer|(uint32)offset)&1UL) {
    THROW_NSX(Error, BadAlignment());
  }
  n <<= 2;
  size_t totalBytes = 0;
  while (n > bytesLeft) {
    Mem::swap32(buffer, offset, (bytesLeft>>2));
    n                   -= bytesLeft;
    ((char*)buffer)     += bytesLeft;
    totalBytes          += bytesLeft;
    bytesLeft       = 0;
    sint32 bytesArrived = waitPacket();
    if (bytesArrived <= 0) {
      if (bytesArrived == 0) {
        // end of file reached
        flags |= FILE_ATEND;
        SetIoErr(0);
        return totalBytes>>2;
      }
      THROW_NSX(IO, ReadError());
    }
    // ask that the buffer be filled
    sendPacket(buffers[currentBuf^1]);
    if (seekOffset > bytesArrived) {
      seekOffset = bytesArrived;
    }
    offset      = (char*)(buffers[currentBuf]) + seekOffset;
    currentBuf ^= 1;
    bytesLeft   = bytesArrived - seekOffset;
    seekOffset  = 0;
  }
  Mem::swap32(buffer, offset, (n>>2));
  bytesLeft       -= n;
  ((char*)offset) += n;
  return (totalBytes + n)>>2;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

size_t IO::StreamIn::read64Swap(void* buffer,size_t n)
{
  if (!file) {
    THROW_NSX(IO, ReadError());
  }
  if (((uint32)buffer|(uint32)offset)&1UL) {
    THROW_NSX(Error, BadAlignment());
  }
  n <<= 3;
  size_t totalBytes = 0;
  while (n > bytesLeft) {
    Mem::swap64(buffer, offset, (bytesLeft>>3));
    n                   -= bytesLeft;
    ((char*)buffer)     += bytesLeft;
    totalBytes          += bytesLeft;
    bytesLeft       = 0;
    sint32 bytesArrived = waitPacket();
    if (bytesArrived <= 0) {
      if (bytesArrived == 0) {
        // end of file reached
        flags |= FILE_ATEND;
        SetIoErr(0);
        return totalBytes>>3;
      }
      //throwStreamReadError();
      THROW_NSX(IO, ReadError());
    }
    // ask that the buffer be filled
    sendPacket(buffers[currentBuf^1]);
    if (seekOffset > bytesArrived) {
      seekOffset = bytesArrived;
    }
    offset      = (char*)(buffers[currentBuf]) + seekOffset;
    currentBuf ^= 1;
    bytesLeft   = bytesArrived - seekOffset;
    seekOffset  = 0;
  }
  Mem::swap64(buffer, offset, (n>>3));
  //Mem::copy(buffer, offset, bytesLeft);
  bytesLeft       -= n;
  ((char*)offset) += n;
  return (totalBytes + n)>>3;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

size_t IO::StreamIn::readText(char* buf, sint32 max, char mark, sint32 num)
{
  if (!file) {
    THROW_NSX(IO, ReadError());
  }
  char* p = buf;
  rsint32 i = max;
  while (--i && num) {
    rsint32 c = getChar();
    if (c==EOF) { // terminate if error
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

size_t IO::StreamIn::rawWriteBytes(const void* buffer, size_t n, sint32 filePos)
{
  return 0;
}



