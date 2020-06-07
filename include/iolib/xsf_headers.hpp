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

#ifndef _EXNG2_IOLIB_XSF_HEADERS_HPP_
# define _EXNG2_IOLIB_XSF_HEADERS_HPP_

# include <systemlib/time.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  XSF::StreamHeader
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class XSF::Stream::Header : private EXNGPrivate::StreamUser {
  friend class XSF::Stream::In;
  friend class XSF::Stream::Out;

  private:
    struct Block8 {
      uint8   fileSignature[4];
      char    payloadSignature[20];
    } block8;

    struct Block16 {
      uint16  xsfVersion;
      uint16  xsfRevision;
      uint16  payloadVersion;
      uint16  payloadRevision;
      Block16() :
        xsfVersion(XSF::VERSION),
        xsfRevision(XSF::REVISION),
        payloadVersion(0),
        payloadRevision(0) {}
      Block16(uint16 pv, uint16 pr) :
        xsfVersion(XSF::VERSION),
        xsfRevision(XSF::REVISION),
        payloadVersion(pv),
        payloadRevision(pr) {}
    } block16;

    struct Block32 {
      Time::Datestamp created;
      Time::Datestamp modified;
      Block32(bool init) : created(init), modified(init) {}
    } block32;

    void    init();
    void    read(IO::Stream::In& in);
    void    read(IO::Stream::Out& out);
    void    write(IO::Stream::Out& out);

  public:
    const   Time::Datestamp& getDateCreated() const { return block32.created; }
    uint32  getXSFVersion()                   const { return block16.xsfVersion; }
    uint32  getXSFRevision()                  const { return block16.xsfRevision; }
    uint32  getPayloadVersion()               const { return block16.payloadVersion; }
    uint32  getPayloadRevision()              const { return block16.payloadRevision; }
    uint32  getMachineFlags()                 const { return block8.fileSignature[3]; }
    uint32  getXSFImplementation()            const { return block16.xsfVersion<<16 | block16.xsfRevision; }
    uint32  getPayloadImplementation()        const { return block16.payloadVersion<<16 | block16.payloadRevision; }

    bool    matches(const char* id)     const;

    void    setPayloadId(const char* id);
    void    setPayloadVersion(uint16 v)  { block16.payloadVersion = v; }
    void    setPayloadRevision(uint16 v) { block16.payloadRevision = v; }
    void    setMachineFlags(uint8 f)     { block8.fileSignature[3] = f; }

    void    setCreated()                 { block32.created.now(); }
    void    setUpdated()                 { block32.modified.now(); }
    void    initDate()                   { block32.created.now(); block32.modified = block32.created; }

    Header();
    Header(const char* id, uint16 v, uint16 r, uint8 df);

  private:
    void validate();

    Header(IO::Stream::In& in);
    Header(IO::Stream::Out& out);

};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  XSF::ItemHeader
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class XSF::ItemHeader {
  private:
    struct Block8 {
      uint8 headerSignature[4];
    } block8;

    struct Block16 {
      uint16  itemVersion;
      uint16  itemRevision;
      Block16() :
        itemVersion(0),
        itemRevision(0) {}
      Block16(uint16 v, uint16 r) :
        itemVersion(v),
        itemRevision(r) {}
    } block16;

    struct Block32 {
      uint32  classId;
      uint32  subClassId;
      Block32() :
        classId(0),
        subClassId(0) {}
      Block32(uint32 cId, uint32 sId) :
        classId(cId),
        subClassId(sId) {}
    } block32;

    struct Block64 {
      uint64  itemRawSize;
      Block64() : itemRawSize(0) {}
    } block64;

  public:

    uint32  getItemVersion()                  const { return block16.itemVersion; }
    uint32  getItemRevision()                 const { return block16.itemRevision; }
    uint32  getItemImplementation()           const { return block16.itemVersion<<16 | block16.itemRevision; }
    uint32  getMachineFlags()                 const { return block8.headerSignature[3]; }
    uint32  getClassId()                      const { return block32.classId; }
    uint32  getSubClassId()                   const { return block32.subClassId; }
    uint64  getItemRawSize()                  const { return block64.itemRawSize; }

    void    setItemVersion(uint16 v)          { block16.itemVersion  = v; }
    void    setItemRevision(uint16 v)         { block16.itemRevision = v; }
    void    setClassId(uint32 id)             { block32.classId         = id; }
    void    setSubClassId(uint32 id)          { block32.subClassId      = id; }

    size_t  write(XSF::Stream::Out* f); // returns total bytes written
    size_t  read(XSF::Stream::In* f);   // returns total bytes read

  public:
    ItemHeader();
    ItemHeader(uint32 cId, uint32 scId, uint16 v, uint16 r);
};

#endif
