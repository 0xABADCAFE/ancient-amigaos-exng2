///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/linux_noarch/iolib/streamio_native.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:
//  Comment(s):
//  Library:      iolib
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

#include <cstdio>

class StreamBuffer {
  protected:
    std::FILE*  file;
    void*       swapBuffer;
    size_t      swapSize;

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
      BUFF_ERROR  = 0x00010000,
    };

    static bool exists(const char* f);
    bool        create(size_t s);
    void        destroy();

    bool        valid() const
    {
      return file!=0 && std::ferror(file)==0;
    }

    void        assertValid() const
    {
      if (!valid()) THROW_NSX(IO, Error());
    }

    bool        end()   const
    {
      assertValid();
      return std::feof(file) ? true : false;
    }
    bool        start() const
    {
      assertValid();
      return std::ftell(file) ? false : true;
    }

    size_t      size()  const;

    void        assertPointer(const void* buffer)
    {
      if (!buffer) THROW_NSX(Error, NullPointer());
    }

    void        assertPointerAligned(const void* buffer, size_t alignBits)
    {
      if (!buffer) {
        THROW_NSX(Error, NullPointer());
      } else if ( alignBits && (((size_t)buffer)&alignBits)) {
        THROW_NSX(Error, BadAlignment());
      }
    }

    IO::SeekPos seek(IO::SeekPos p, IO::SeekMode m);
    IO::SeekPos tell();

    StreamBuffer() : file(0), swapBuffer(0), swapSize(0) {}
    ~StreamBuffer()  { destroy(); }

  private:
    LOGGING_DEFINE_CLASSNAME
};

namespace EXNGPrivate {
  class StreamUser;
}

////////////////////////////////////////////////////////////////////////////////
//
//  StreamIn
//
////////////////////////////////////////////////////////////////////////////////

class IO::StreamIn : private StreamBuffer {
  friend class EXNGPrivate::StreamUser;

  protected:
    size_t      rawWriteBytes(const void* buffer, size_t n, sint32 filePos);

    void        assertReadable() const
    {
      if (!StreamBuffer::valid()) THROW_NSX(IO, ReadError());
    }

  public:
    void        open(const char* f, IO::ReadMode m=IO::MODE_READ, size_t s=IO::DEFAULT_BUFFSIZE);
    void        close();
    void        flush();
    IO::SeekPos tell()                                              { return StreamBuffer::tell(); }
    IO::SeekPos seek(IO::SeekPos p, IO::SeekMode m=IO::FROM_START)  { return StreamBuffer::seek(p, m); }
    bool        valid()     const { return StreamBuffer::valid(); }
    bool        end()       const { return StreamBuffer::end(); }
    bool        start()     const { return StreamBuffer::start(); }
    size_t      size()      const { return StreamBuffer::size(); }
    sint32      getChar()
    {
      assertReadable();
      return std::fgetc(file);
    }

    size_t      readBytes(void* buffer, size_t n);
    size_t      read8(void* d, size_t n)  { return readBytes(d, n); }
    size_t      read16(void* d, size_t n) { return (readBytes(d, n<<1))>>1; }
    size_t      read32(void* d,size_t n)  { return (readBytes(d, n<<2))>>2; }
    size_t      read64(void* d, size_t n) { return (readBytes(d, n<<3))>>3; }
    size_t      read16Swap(void* d, size_t n);
    size_t      read32Swap(void* d, size_t n);
    size_t      read64Swap(void* d, size_t n);
    size_t      readText(char*buf, sint32 max, char mark=0, sint32 num=-1);

  public:
    StreamIn() : StreamBuffer() {}
    ~StreamIn() { close(); }

  private:
    StreamIn(const StreamIn& ) : StreamBuffer() {}
    StreamIn& operator=(const StreamIn&) { return *this; }

    LOGGING_DEFINE_CLASSNAME
};

////////////////////////////////////////////////////////////////////////////////
//
//  StreamOut
//
////////////////////////////////////////////////////////////////////////////////

class IO::StreamOut : private StreamBuffer {
  friend class EXNGPrivate::StreamUser;

  protected:
    void        assertWriteable() const
    {
      if (!StreamBuffer::valid()) THROW_NSX(IO, WriteError());
    }

    size_t      rawReadBytes(void* buffer, size_t n, sint32 filePos);

  public:
    void        open(const char* f, IO::WriteMode m, size_t s=IO::DEFAULT_BUFFSIZE);
    void        close();
    void        flush();
    IO::SeekPos tell()                                              { return StreamBuffer::tell(); }
    IO::SeekPos seek(IO::SeekPos p, IO::SeekMode m=IO::FROM_START)  { return StreamBuffer::seek(p, m); }
    bool        valid()     const { return StreamBuffer::valid(); }
    bool        end()       const { return StreamBuffer::end(); }
    bool        start()     const { return StreamBuffer::start(); }
    size_t      size()      const { return StreamBuffer::size(); }
    sint32      putChar(char ch)
    {
      assertWriteable();
      return std::fputc(ch, file);
    }

    size_t      writeBytes(const void* buffer, size_t n);
    size_t      write8(const void* s, size_t n)   { return writeBytes(s, n); }
    size_t      write16(const void* s, size_t n)  { return (writeBytes(s, n<<1))>>1; }
    size_t      write32(const void* s, size_t n)  { return (writeBytes(s, n<<2))>>2; }
    size_t      write64(const void* s, size_t n)  { return (writeBytes(s, n<<3))>>3; }
    size_t      write16Swap(const void* s, size_t n);
    size_t      write32Swap(const void* s, size_t n);
    size_t      write64Swap(const void* s, size_t n);
    size_t      writeText(const char* format,...);

  public:
    StreamOut() : StreamBuffer() {}
    ~StreamOut() { close(); }

  private:
    StreamOut(const StreamOut& ) : StreamBuffer() {}
    StreamOut& operator=(const StreamOut&) { return *this; }

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
    protected:
      static size_t rawReadBytes(IO::StreamOut& out, void* buffer, size_t n, sint32 filePos)
      {
        return out.rawReadBytes(buffer, n, filePos);
      }

      static size_t rawWriteBytes(IO::StreamIn& in, void* buffer, size_t n, sint32 filePos)
      {
        return in.rawWriteBytes(buffer, n, filePos);
      }
  };

};
#endif
