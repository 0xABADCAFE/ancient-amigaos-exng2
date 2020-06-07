///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/amigaos3_68k/iolib/streamio_native.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Processor query, native implementation
//  Comment(s):
//  Library:      System
//  Created:      2006-10-08
//  Updated:      2006-10-08
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _EXNG2_IOLIB_STREAM_NATIVE_HPP_
# define _EXNG2_IOLIB_STREAM_NATIVE_HPP_

namespace OSNative {
  extern "C" {
    #include <proto/dos.h>
  }
  //#include <library_inlines/dos.hpp>
};


namespace EXNGPrivate {

  class AsyncStreamBuffer {
    protected:
      size_t  bufferSize;
      size_t  fileSize;
      size_t  blockSize;
      uint32  flags;
      uint32  currentBuf;
      uint32  seekOffset;
      sint32  bytesLeft;
      void*   buffers[2];
      void*   offset;

      OSNative::BPTR            file;
      OSNative::MsgPort*        handler;
      OSNative::StandardPacket  packet;
      OSNative::MsgPort         packetPort;


      sint32  waitPacket();
      void    sendPacket(void* p);
      void    requeuePacket();
      void    recordSyncFailure();

      enum {
        WAIT_PACKET = 0x00000001,
        FILE_ATEND  = 0x00000002,
        FILE_START  = 0x00000004,
        FILE_GOOD   = 0x00000008,
        FILE_READ   = 0x00000010,
        FILE_WRITE  = 0x00000020,
        FILE_APPEND = 0x00000040,
        FILE_TEXT   = 0x00000080,
        FILE_ACCESS = 0x000000F0,
        BUFF_ERROR  = 0x00010000
      };

      static  bool exists(const char* f);
      bool    create(size_t s);
      void    destroy();

      bool    valid() const { return flags & FILE_GOOD; }
      bool    end()   const { return flags & FILE_ATEND; }
      bool    start() const { return flags & FILE_START; }
      size_t  size()  const { if (!(flags & FILE_ACCESS)) THROW_NSX(IO, Error()); return fileSize; }

      AsyncStreamBuffer() : file(0), flags(0) { buffers[0] = 0; }
      ~AsyncStreamBuffer()  { destroy(); }

    private:
      LOGGING_DEFINE_CLASSNAME
  };

  class StreamUser;

}

////////////////////////////////////////////////////////////////////////////////
//
//  StreamIn
//
////////////////////////////////////////////////////////////////////////////////

class IO::Stream::In : private EXNGPrivate::AsyncStreamBuffer {
  friend class EXNGPrivate::StreamUser;

  private:
    sint32  getNextCharIO();

  protected:
    size_t  rawWriteBytes(const void* buffer, size_t n, SeekPos filePos);

  public:
    void    open(const char* f, ReadMode m=MODE_READ, size_t s=DEFAULT_BUFFSIZE);
    void    close();
    void    flush();
    SeekPos tell();
    SeekPos seek(SeekPos p, SeekMode m=IO::Stream::FROM_START);
    bool    valid()     const { return AsyncStreamBuffer::valid(); }
    bool    end()       const { return AsyncStreamBuffer::end(); }
    bool    start()     const { return AsyncStreamBuffer::start(); }
    size_t  size()      const { return AsyncStreamBuffer::size(); }
    sint32  getChar()
    {
      if (bytesLeft==0) {
        return getNextCharIO();
      }
      bytesLeft--;
      return *((char*)offset)++;
    }

    size_t  readBytes(void* buffer, size_t n);

    size_t  read8(void* d, size_t n)  { return readBytes(d, n); }
    size_t  read16(void* d, size_t n) { return (readBytes(d, n<<1))>>1; }
    size_t  read32(void* d,size_t n)  { return (readBytes(d, n<<2))>>2; }
    size_t  read64(void* d, size_t n) { return (readBytes(d, n<<3))>>3; }

    size_t  read16Swap(void* d, size_t n);
    size_t  read32Swap(void* d, size_t n);
    size_t  read64Swap(void* d, size_t n);
    size_t  readText(char*buf, sint32 max, char mark=0, sint32 num=-1);

  public:
    In() : AsyncStreamBuffer() {}
    ~In();

  private:
    In(const In&) : AsyncStreamBuffer() {}
    In& operator=(const In&) { return *this; }

    LOGGING_DEFINE_CLASSNAME
};

////////////////////////////////////////////////////////////////////////////////
//
//  StreamOut
//
////////////////////////////////////////////////////////////////////////////////

#define STREAMOUT_TEXTBUFFSIZE 2048

class IO::Stream::Out : private EXNGPrivate::AsyncStreamBuffer {
  friend class EXNGPrivate::StreamUser;

  private:
    char*   textBuffer;

  protected:
    size_t  rawReadBytes(void* buffer, size_t n, SeekPos filePos);

  public:
    void    open(const char* f, WriteMode m, size_t s=DEFAULT_BUFFSIZE);
    void    close();
    void    flush();
    SeekPos tell();
    SeekPos seek(SeekPos p, SeekMode m=FROM_START);
    bool    valid()     const { return AsyncStreamBuffer::valid(); }
    bool    end()       const { return AsyncStreamBuffer::end(); }
    bool    start()     const { return AsyncStreamBuffer::start(); }
    size_t  size()      const { return AsyncStreamBuffer::size(); }
    sint32  putChar(char ch)
    {
      if (bytesLeft==0) {
        if (waitPacket() < 0) {
          flags &= ~FILE_GOOD;
          THROW_NSX(IO, WriteError());
        }
        sendPacket(buffers[currentBuf]); // send the current buffer
        currentBuf  ^= 1;
        offset      = buffers[currentBuf];
        bytesLeft   = bufferSize;
      }
      bytesLeft--;
      *(((char*)offset)++) = ch;
      return ch;
    }

    size_t  writeBytes(const void* buffer, size_t n);
    size_t  write8(const void* s, size_t n)   { return writeBytes(s, n); }
    size_t  write16(const void* s, size_t n)  { return (writeBytes(s, n<<1))>>1; }
    size_t  write32(const void* s, size_t n)  { return (writeBytes(s, n<<2))>>2; }
    size_t  write64(const void* s, size_t n)  { return (writeBytes(s, n<<3))>>3; }
    size_t  write16Swap(const void* s, size_t n);
    size_t  write32Swap(const void* s, size_t n);
    size_t  write64Swap(const void* s, size_t n);
    size_t  writeText(const char* format,...);

  public:
    Out() : AsyncStreamBuffer(), textBuffer(0) {}
    ~Out();

  private:
    Out(const Out& ) : AsyncStreamBuffer() {}
    Out& operator=(const Out&) { return *this; }

    LOGGING_DEFINE_CLASSNAME
};

////////////////////////////////////////////////////////////////////////////////
//
//  StreamUser
//
//  Exposes protected StreamIn/Out methods to inheritor
//
////////////////////////////////////////////////////////////////////////////////

namespace EXNGPrivate {

  class StreamUser {

    ALIGN_INHERITED

    protected:
      static size_t rawReadBytes(IO::Stream::Out& out, void* buffer, size_t n, IO::Stream::SeekPos filePos)
      {
        return out.rawReadBytes(buffer, n, filePos);
      }

      static size_t rawWriteBytes(IO::Stream::In& in, void* buffer, size_t n, IO::Stream::SeekPos filePos)
      {
        return in.rawWriteBytes(buffer, n, filePos);
      }
  };

};
#endif
