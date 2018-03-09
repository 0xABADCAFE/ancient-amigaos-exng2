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

class XSF::StreamIn : private IO::StreamIn {

  friend class XSF::StreamUser;

  private:
    typedef size_t (IO::StreamIn::* Read16)(void* d, size_t n);
    typedef size_t (IO::StreamIn::* Read32)(void* d, size_t n);
    typedef size_t (IO::StreamIn::* Read64)(void* d, size_t n);

    XSF::StreamHeader header;
    uint32            streamFlags;
    Read16            ioRead16;
    Read32            ioRead32;
    Read64            ioRead64;

    void              setSwappedIO();
    void              setDirectIO();

  protected:
    size_t      read8(void* d, size_t n)            { return IO::StreamIn::read8(d, n); }
    size_t      read16(void* d, size_t n)           { return (this->*ioRead16)(d, n); }
    size_t      read32(void* d, size_t n)           { return (this->*ioRead32)(d, n); }
    size_t      read64(void* d, size_t n)           { return (this->*ioRead64)(d, n); }
    IO::SeekPos seek(IO::SeekPos p, IO::SeekMode m) { return IO::StreamIn::seek(p, m); }

  public:
    const XSF::StreamHeader& getHeader() const      { return header; }

    void open(const char* name, size_t bufSize);
    void open(const char* name, const char* id, uint16 minVer, uint16 minRev, size_t bufSize);
    void close();

  public:
    StreamIn();
    ~StreamIn();
};
/*
inline size_t XSF::StreamIn::read8(void* d, size_t n)
{
  return IO::StreamIn::read8(d, n);
}

inline size_t XSF::StreamIn::read16(void* d, size_t n)
{
  return (streamFlags & XSF::STREAM_SWAPBYTES) ? IO::StreamIn::read16Swap(d, n) : IO::StreamIn::read16(d, n);
}

inline size_t XSF::StreamIn::read32(void* d, size_t n)
{
  return (streamFlags & XSF::STREAM_SWAPBYTES) ? IO::StreamIn::read32Swap(d, n) : IO::StreamIn::read32(d, n);
}

inline size_t XSF::StreamIn::read64(void* d, size_t n)
{
  return (streamFlags & XSF::STREAM_SWAPBYTES) ? IO::StreamIn::read64Swap(d, n) : IO::StreamIn::read64(d, n);
}
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  StreamOut
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class XSF::StreamOut : private IO::StreamOut {

  friend class XSF::StreamUser;

  private:
    typedef size_t (IO::StreamOut::* Write16)(const void* d, size_t n);
    typedef size_t (IO::StreamOut::* Write32)(const void* d, size_t n);
    typedef size_t (IO::StreamOut::* Write64)(const void* d, size_t n);

    XSF::StreamHeader header;

    uint32            streamFlags;
    Write16           ioWrite16;
    Write32           ioWrite32;
    Write64           ioWrite64;

    void              setSwappedIO();
    void              setDirectIO();

  protected:
    size_t      write8(const void* s, size_t n)     { return IO::StreamOut::write8(s, n); }
    size_t      write16(const void* s, size_t n)    { return (this->*ioWrite16)(s, n); }
    size_t      write32(const void* s, size_t n)    { return (this->*ioWrite32)(s, n); }
    size_t      write64(const void* s, size_t n)    { return (this->*ioWrite64)(s, n); }
    IO::SeekPos seek(IO::SeekPos p, IO::SeekMode m) { return IO::StreamOut::seek(p, m); }

  public:
    const XSF::StreamHeader& getHeader() const      { return header; }

    void open(const char* name, size_t bufSize);
    void open(const char* name, const char* id, uint16 v, uint16 r, uint8 d, size_t bufSize);
    void close();

  public:
    StreamOut();
    ~StreamOut();
};

/*
inline size_t XSF::StreamOut::write8(const void* s, size_t n)
{
  return IO::StreamOut::write8(s, n);
}

inline size_t XSF::StreamOut::write16(const void* s, size_t n)
{
  return (streamFlags & XSF::STREAM_SWAPBYTES) ? IO::StreamOut::write16Swap(s, n) : IO::StreamOut::write16(s, n);
}

inline size_t XSF::StreamOut::write32(const void* s, size_t n)
{
  return (streamFlags & XSF::STREAM_SWAPBYTES) ? IO::StreamOut::write32Swap(s, n) : IO::StreamOut::write32(s, n);
}

inline size_t XSF::StreamOut::write64(const void* s, size_t n)
{
  return (streamFlags & XSF::STREAM_SWAPBYTES) ? IO::StreamOut::write64Swap(s, n) : IO::StreamOut::write64(s, n);
}
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  StreamUser
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class XSF::StreamUser {
  protected:
    static size_t       read8(XSF::StreamIn* in, void* d, size_t n)             { return in->read8(d, n); }
    static size_t       read16(XSF::StreamIn* in, void* d, size_t n)            { return in->read16(d, n); }
    static size_t       read32(XSF::StreamIn* in, void* d, size_t n)            { return in->read32(d, n); }
    static size_t       read64(XSF::StreamIn* in, void* d, size_t n)            { return in->read64(d, n); }
    static IO::SeekPos  seek(XSF::StreamIn* in, IO::SeekPos p, IO::SeekMode m)  { return in->seek(p, m); }
    static size_t       write8(XSF::StreamOut* out, const void* s, size_t n)    { return out->write8(s, n); }
    static size_t       write16(XSF::StreamOut* out, const void* s, size_t n)   { return out->write16(s, n); }
    static size_t       write32(XSF::StreamOut* out, const void* s, size_t n)   { return out->write32(s, n); }
    static size_t       write64(XSF::StreamOut* out, const void* s, size_t n)   { return out->write64(s, n); }
    static IO::SeekPos  seek(XSF::StreamOut* out, IO::SeekPos p, IO::SeekMode m){ return out->seek(p, m); }
};


#endif
