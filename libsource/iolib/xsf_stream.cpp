///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         iolib/xsf_stream.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  XSF Stream implementations
//  Comment(s):
//  Library:      IO
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
#include <iolib/xsfio.hpp>
#include <cstring>

using namespace EXNGPrivate;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  XSF::Stream::In
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

XSF::Stream::In::In() : header(), streamFlags(0)
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

XSF::Stream::In::~In()
{
  close();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void XSF::Stream::In::setSwappedIO()
{
  ioRead16 = &IO::Stream::In::read16Swap;
  ioRead32 = &IO::Stream::In::read32Swap;
  ioRead64 = &IO::Stream::In::read64Swap;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void XSF::Stream::In::setDirectIO()
{
  ioRead16 = &IO::Stream::In::read16;
  ioRead32 = &IO::Stream::In::read32;
  ioRead64 = &IO::Stream::In::read64;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void XSF::Stream::In::open(const char* name, size_t bufSize)
{
  IO::Stream::In::open(name, IO::Stream::MODE_READ, bufSize);

  header.read(*this); // may throw, but is always non-destructive on failure

  streamFlags = 0;

  if ((header.getMachineFlags() & Machine::ENDIANNESS) != (Machine::SIGNATURE & Machine::ENDIANNESS)) {
    streamFlags |= XSF::STREAM_SWAPBYTES;
    setSwappedIO();
  } else {
    setDirectIO();
  }
  if ((header.getMachineFlags() & Machine::NEG_FORMAT) != (Machine::SIGNATURE & Machine::NEG_FORMAT)) {
    streamFlags |= XSF::STREAM_CONVERT_NEG;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void XSF::Stream::In::open(const char* name, const char* id, uint16 minVer, uint16 minRev, size_t bufSize)
{
  IO::Stream::In::open(name, IO::Stream::MODE_READ, bufSize);

  header.read(*this);

  if (!header.matches(id)) {
    THROW_NSX(XSF, PayloadTypeError());
  }
  if (header.getPayloadImplementation() > (((uint32)minVer<<16)|minRev)) {
    THROW_NSX(XSF, PayloadVersionError());
  }
  if ((header.getMachineFlags() & Machine::ENDIANNESS) != (Machine::SIGNATURE & Machine::ENDIANNESS)) {
    streamFlags |= XSF::STREAM_SWAPBYTES;
    setSwappedIO();
  } else {
    setDirectIO();
  }
  if ((header.getMachineFlags() & Machine::NEG_FORMAT) != (Machine::SIGNATURE & Machine::NEG_FORMAT)) {
    streamFlags |= XSF::STREAM_CONVERT_NEG;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void XSF::Stream::In::close()
{
  IO::Stream::In::close();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  XSF::Stream::Out
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

XSF::Stream::Out::Out() : header(), streamFlags(0)
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

XSF::Stream::Out::~Out()
{
  close();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void XSF::Stream::Out::setSwappedIO()
{
  ioWrite16 = &IO::Stream::Out::write16Swap;
  ioWrite32 = &IO::Stream::Out::write32Swap;
  ioWrite64 = &IO::Stream::Out::write64Swap;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void XSF::Stream::Out::setDirectIO()
{
  ioWrite16 = &IO::Stream::Out::write16;
  ioWrite32 = &IO::Stream::Out::write32;
  ioWrite64 = &IO::Stream::Out::write64;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void XSF::Stream::Out::open(const char* name, size_t bufSize)
{
  IO::Stream::Out::open(name, IO::Stream::MODE_APPEND, bufSize);
  header.read(*this);
  streamFlags = 0;
  if ((header.getMachineFlags() & Machine::ENDIANNESS) != (Machine::SIGNATURE & Machine::ENDIANNESS)) {
    streamFlags |= XSF::STREAM_SWAPBYTES;
    setSwappedIO();
  }
  else {
    setDirectIO();
  }
  if ((header.getMachineFlags() & Machine::NEG_FORMAT) != (Machine::SIGNATURE & Machine::NEG_FORMAT)) {
    streamFlags |= XSF::STREAM_CONVERT_NEG;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void XSF::Stream::Out::open(const char* name, const char* id, uint16 minVer, uint16 minRev,  uint8 mf, size_t bufSize)
{
  IO::Stream::Out::open(name, IO::Stream::MODE_WRITE, bufSize);
  header.setPayloadId(id);
  header.setPayloadVersion(minVer);
  header.setPayloadRevision(minRev);
  header.setMachineFlags(mf);
  header.initDate();
  streamFlags = 0;

  if ((mf & Machine::ENDIANNESS) != (Machine::SIGNATURE & Machine::ENDIANNESS)) {
    streamFlags |= XSF::STREAM_SWAPBYTES;
    setSwappedIO();
  } else {
    setDirectIO();
  }
  if ((mf & Machine::NEG_FORMAT) != (Machine::SIGNATURE & Machine::NEG_FORMAT)) {
    streamFlags |= XSF::STREAM_CONVERT_NEG;
  }

  header.write(*this);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void XSF::Stream::Out::close()
{
  IO::Stream::Out::close();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
XSF::Storable::Storable() :
  chunkId("undefined"), superClass(0), subClass(0), cnctSuper(0), cnctSub(0),
  rawSize(0), namePtr(0), extProps(0), control(0), version(0), revision(0)
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


XSF::Storable::Storable(const char* desc, uint16 super, uint16 sub, uint8 ver, uint8 rev) :
  chunkId(desc), superClass(super), subClass(sub), cnctSuper(0), cnctSub(0), rawSize(0),
  namePtr(0), extProps(0), control(0), version(ver), revision(rev)
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

XSF::Storable::~Storable()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 XSF::Storable::write(XSF::Stream::Out* out)
{

  return 0;
}

sint32 XSF::Storable::read(XSF::Stream::In* in)
{

  return 0;
}
*/

