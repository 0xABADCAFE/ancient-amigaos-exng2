///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         iolib/xsfio.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  XSF IO definitions
//  Comment(s):
//  Library:      IO
//  Created:      2007-04-19
//  Updated:      2007-04-19
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _EXNG2_IOLIB_XSF_STREAM_HPP_
# define _EXNG2_IOLIB_XSF_STREAM_HPP_


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  StreamIn
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class XSF::Stream::In : private IO::Stream::In {

  friend class XSF::Stream::User;

  private:
    typedef size_t (IO::Stream::In::* Read16)(void* d, size_t n);
    typedef size_t (IO::Stream::In::* Read32)(void* d, size_t n);
    typedef size_t (IO::Stream::In::* Read64)(void* d, size_t n);

    Header  header;
    uint32  streamFlags;
    Read16  ioRead16;
    Read32  ioRead32;
    Read64  ioRead64;

    void    setSwappedIO();
    void    setDirectIO();

  protected:
    size_t      read8(void* d, size_t n)            { return IO::Stream::In::read8(d, n); }
    size_t      read16(void* d, size_t n)           { return (this->*ioRead16)(d, n); }
    size_t      read32(void* d, size_t n)           { return (this->*ioRead32)(d, n); }
    size_t      read64(void* d, size_t n)           { return (this->*ioRead64)(d, n); }

    IO::Stream::SeekPos seek(IO::Stream::SeekPos p, IO::Stream::SeekMode m)
    {
      return IO::Stream::In::seek(p, m);
    }

  public:
    const Header& getHeader() const    { return header; }
    void          open(const char* name, size_t bufSize);
    void          open(const char* name, const char* id, uint16 minVer, uint16 minRev, size_t bufSize);
    void          close();

  public:
    In();
    ~In();
};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  StreamOut
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class XSF::Stream::Out : private IO::Stream::Out {

  friend class XSF::Stream::User;

  private:
    typedef size_t (IO::Stream::Out::* Write16)(const void* d, size_t n);
    typedef size_t (IO::Stream::Out::* Write32)(const void* d, size_t n);
    typedef size_t (IO::Stream::Out::* Write64)(const void* d, size_t n);

    Header    header;

    uint32    streamFlags;
    Write16   ioWrite16;
    Write32   ioWrite32;
    Write64   ioWrite64;

    void      setSwappedIO();
    void      setDirectIO();

  protected:
    size_t      write8(const void* s, size_t n)     { return IO::Stream::Out::write8(s, n); }
    size_t      write16(const void* s, size_t n)    { return (this->*ioWrite16)(s, n); }
    size_t      write32(const void* s, size_t n)    { return (this->*ioWrite32)(s, n); }
    size_t      write64(const void* s, size_t n)    { return (this->*ioWrite64)(s, n); }

    IO::Stream::SeekPos seek(IO::Stream::SeekPos p, IO::Stream::SeekMode m)
    {
      return IO::Stream::Out::seek(p, m);
    }

  public:
    const Header& getHeader() const      { return header; }
    void          open(const char* name, size_t bufSize);
    void          open(const char* name, const char* id, uint16 v, uint16 r, uint8 d, size_t bufSize);
    void          close();

  public:
    Out();
    ~Out();
};



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  StreamUser
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class XSF::Stream::User {
  protected:
    static size_t               read8(XSF::Stream::In* in, void* d, size_t n)                               { return in->read8(d, n); }
    static size_t               read16(XSF::Stream::In* in, void* d, size_t n)                              { return in->read16(d, n); }
    static size_t               read32(XSF::Stream::In* in, void* d, size_t n)                              { return in->read32(d, n); }
    static size_t               read64(XSF::Stream::In* in, void* d, size_t n)                              { return in->read64(d, n); }
    static IO::Stream::SeekPos  seek(XSF::Stream::In* in, IO::Stream::SeekPos p, IO::Stream::SeekMode m)    { return in->seek(p, m); }
    static size_t               write8(XSF::Stream::Out* out, const void* s, size_t n)                      { return out->write8(s, n); }
    static size_t               write16(XSF::Stream::Out* out, const void* s, size_t n)                     { return out->write16(s, n); }
    static size_t               write32(XSF::Stream::Out* out, const void* s, size_t n)                     { return out->write32(s, n); }
    static size_t               write64(XSF::Stream::Out* out, const void* s, size_t n)                     { return out->write64(s, n); }
    static IO::Stream::SeekPos  seek(XSF::Stream::Out* out, IO::Stream::SeekPos p, IO::Stream::SeekMode m)  { return out->seek(p, m); }
};


#endif
