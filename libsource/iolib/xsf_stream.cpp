///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         iolib/streamio_error.cpp
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
#include <iolib/xsfio.hpp>
#include <cstring>

using namespace EXNGPrivate;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  XSF::StreamIn
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

XSF::StreamIn::StreamIn() : header(), streamFlags(0)
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

XSF::StreamIn::~StreamIn()
{
  close();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void XSF::StreamIn::setSwappedIO()
{
  ioRead16 = &IO::StreamIn::read16Swap;
  ioRead32 = &IO::StreamIn::read32Swap;
  ioRead64 = &IO::StreamIn::read64Swap;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void XSF::StreamIn::setDirectIO()
{
  ioRead16 = &IO::StreamIn::read16;
  ioRead32 = &IO::StreamIn::read32;
  ioRead64 = &IO::StreamIn::read64;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void XSF::StreamIn::open(const char* name, size_t bufSize)
{
  IO::StreamIn::open(name, IO::MODE_READ, bufSize);

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

void XSF::StreamIn::open(const char* name, const char* id, uint16 minVer, uint16 minRev, size_t bufSize)
{
  IO::StreamIn::open(name, IO::MODE_READ, bufSize);

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

void XSF::StreamIn::close()
{
  IO::StreamIn::close();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  XSF::StreamOut
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

XSF::StreamOut::StreamOut() : header(), streamFlags(0)
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

XSF::StreamOut::~StreamOut()
{
  close();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void XSF::StreamOut::setSwappedIO()
{
  ioWrite16 = &IO::StreamOut::write16Swap;
  ioWrite32 = &IO::StreamOut::write32Swap;
  ioWrite64 = &IO::StreamOut::write64Swap;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void XSF::StreamOut::setDirectIO()
{
  ioWrite16 = &IO::StreamOut::write16;
  ioWrite32 = &IO::StreamOut::write32;
  ioWrite64 = &IO::StreamOut::write64;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void XSF::StreamOut::open(const char* name, size_t bufSize)
{
  IO::StreamOut::open(name, IO::MODE_APPEND, bufSize);
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

void XSF::StreamOut::open(const char* name, const char* id, uint16 minVer, uint16 minRev,  uint8 mf, size_t bufSize)
{
  IO::StreamOut::open(name, IO::MODE_WRITE, bufSize);
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

void XSF::StreamOut::close()
{
  IO::StreamOut::close();
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

sint32 XSF::Storable::write(XSF::StreamOut* out)
{

  return 0;
}

sint32 XSF::Storable::read(XSF::StreamIn* in)
{

  return 0;
}
*/

