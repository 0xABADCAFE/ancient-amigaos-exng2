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
#include <systemlib/memory.hpp>
#include <iolib/xsfio.hpp>
#include <cstring>

namespace XSF {
  const char  signature[4]      = { 'X', 'S', 'F', Machine::SIGNATURE };
  const char  itemSignature[4] = { 'x', 's', 'f', Machine::SIGNATURE };
};

using namespace EXNGPrivate;

#define HDR_SIZE8   sizeof(Block8)
#define HDR_SIZE16  (sizeof(Block16)/sizeof(uint16))
#define HDR_SIZE32  (sizeof(Block32)/sizeof(uint32))
#define HDR_SIZE16B (sizeof(Block16))
#define HDR_SIZE32B (sizeof(Block32))

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  XSF::Stream::Header
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

XSF::Stream::Header::Header()
: block32(false), block16()
{
  *((uint32*)block8.fileSignature) = *((uint32*)XSF::signature);
  Mem::zero(block8.payloadSignature, sizeof(block8.payloadSignature));
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

XSF::Stream::Header::Header(IO::Stream::In& in)
: block16(), block32(false)
{
  // Private constructor, used by read method
  if (
    (in.read8(&block8.fileSignature[0], HDR_SIZE8+HDR_SIZE16B+HDR_SIZE32B)!=HDR_SIZE8+HDR_SIZE16B+HDR_SIZE32B)
  ) {
    THROW_NSX(IO, ReadError());
  }
  validate();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

XSF::Stream::Header::Header(IO::Stream::Out& out)
: block16(), block32(false)
{
  // Private constructor, used by read method
  if (EXNGPrivate::StreamUser::rawReadBytes(out, &block8.fileSignature[0], HDR_SIZE8+HDR_SIZE16B+HDR_SIZE32B, 0) != HDR_SIZE8+HDR_SIZE16B+HDR_SIZE32B) {
    THROW_NSX(IO, ReadError());
  }
  validate();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <systemlib/logger.hpp>

void XSF::Stream::Header::validate()
{
//   SystemLog::write(
//     SystemLog::INFO,
//     "StreamHeaderInfo\n"
//     "sizeof(XSF::Stream::Header)          = %d @ 0x%08X\n"
//     "sizeof(XSF::Stream::Header::Block8)  = %d @ 0x%08X\n"
//     "sizeof(XSF::Stream::Header::Block16) = %d @ Ox%08X\n"
//     "sizeof(XSF::Stream::Header::Block32) = %d @ Ox%08X\n",
//     (int)sizeof(Stream::Header),
//     (unsigned)(this),
//     (int)sizeof(Block8),
//     (unsigned)(&block8),
//     (int)sizeof(Block16),
//     (unsigned)(&block16),
//     (int)sizeof(Block32),
//     (unsigned)(&block32)
//   );

  if (std::strncmp((const char*)block8.fileSignature, XSF::signature, 3) != 0) {
    THROW_NSX(XSF, InvalidStreamTypeError());
  }
  if ((getMachineFlags() & Machine::ENDIANNESS) != (Machine::SIGNATURE & Machine::ENDIANNESS)) {
    Mem::swap16(&block16, &block16, HDR_SIZE16);
    Mem::swap32(&block32, &block32, HDR_SIZE32);
  }
  if (getXSFImplementation() > XSF::IMPLEMENTATION) {
    THROW_NSX(XSF, VersionError());
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

XSF::Stream::Header::Header(const char* id, uint16 v, uint16 r, uint8 mf)
: block16(v, r), block32(true)
{
  *((uint32*)block8.fileSignature) = *((uint32*)XSF::signature);
  setMachineFlags(mf);
  setPayloadId(id);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void XSF::Stream::Header::setPayloadId(const char* id)
{
  if (id) {
    Mem::zero(block8.payloadSignature, sizeof(block8.payloadSignature));
    std::strncpy(block8.payloadSignature, id, sizeof(block8.payloadSignature));
  } else {
    THROW_NSX(Error, NullPointer());
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool XSF::Stream::Header::matches(const char* id) const
{
  return (std::strncmp(id, block8.payloadSignature, sizeof(block8.payloadSignature))==0);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void XSF::Stream::Header::read(IO::Stream::In& in)
{
  // this ensures that the current instance is never trashed by failing to read, since instansiation always throws
  // on invalid data
  Header temp(in);
  *this = temp;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void XSF::Stream::Header::read(IO::Stream::Out& out)
{
  // this ensures that the current instance is never trashed by failing to read, since instansiation always throws
  // on invalid data
  Header temp(out);
  *this = temp;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void XSF::Stream::Header::write(IO::Stream::Out& out)
{
  if ((getMachineFlags() & Machine::ENDIANNESS) == (Machine::SIGNATURE & Machine::ENDIANNESS)) {
    if (
      (out.write8(&block8, HDR_SIZE8)    != HDR_SIZE8) ||
      (out.write16(&block16, HDR_SIZE16) != HDR_SIZE16) ||
      (out.write32(&block32, HDR_SIZE32) != HDR_SIZE32)
    ) {
      THROW_NSX(IO, WriteError());
    }
  }
  else {
    if (
      (out.write8(&block8, HDR_SIZE8)        != HDR_SIZE8) ||
      (out.write16Swap(&block16, HDR_SIZE16) != HDR_SIZE16) ||
      (out.write32Swap(&block32, HDR_SIZE32) != HDR_SIZE32)
    ) {
      THROW_NSX(IO, WriteError());
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  XSF::ItemHeader
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

XSF::ItemHeader::ItemHeader() :
block16(), block32(), block64()
{

}

XSF::ItemHeader::ItemHeader(uint32 cId, uint32 sId, uint16 v, uint16 r) :
block16(v, r), block32(cId, sId), block64()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

