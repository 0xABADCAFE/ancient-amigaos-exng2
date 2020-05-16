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

#ifndef _EXNG2_IOLIB_XSFIO_HPP_
# define _EXNG2_IOLIB_XSFIO_HPP_

# include <iolib/streamio.hpp>
# include <private/iolib/xsfio.hpp>
# include <utilitylib/referencelist.hpp>
# include <utilitylib/hashkeys.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  XSF namespace
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace XSF {

  // Main Participants
  class Loader;
  class Storable;

  namespace Stream {
    class In;
    class Out;
    class Header;
    class User;
  };

  class ItemHeader;

  class Error;
  class InvalidStreamTypeError;
  class VersionError;
  class PayloadTypeError;
  class PayloadVersionError;
  class BadStorableError;
  class UnreadyStorableError;
  class MachineLimitError;

  enum {
    VERSION         = 1,
    REVISION        = 0,
    IMPLEMENTATION  = VERSION<<16 | REVISION
  };

  enum {
    STREAM_DIRECT       = 0x00000000,
    STREAM_SWAPBYTES    = 0x00000001,
    STREAM_CONVERT_NEG  = 0x00000002
  };
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Auxilliaries
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "xsf_error.hpp"
#include "xsf_headers.hpp"
#include "xsf_stream.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Storeable
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class XSF::Storable : private XSF::Stream::User {
  DEFINE_MIN_RTTI

  private:
    XSF::ItemHeader header;

  protected:
    virtual bool    readyForWrite()                   = 0;
    virtual bool    readyForRead()                    = 0;
    virtual size_t  writePayload(XSF::Stream::Out *f) = 0;
    virtual size_t  readPayload(XSF::Stream::In* f)   = 0;

  public:
    size_t  write(XSF::Stream::Out* f); // returns total bytes written
    size_t  read(XSF::Stream::In* f);   // returns total bytes read

  public:
    Storable();
    Storable(const char* desc, uint16 super, uint16 sub, uint8 ver, uint8 rev);

    virtual ~Storable() {}
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Loader
//
//  Manages a set of factory methods for unserializing various Storeable object types from an input stream
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class XSF::Loader {
  public:
    // Factory method
    typedef XSF::Storable* (*StorableFactory)(XSF::Stream::In*);

    static void                       addFactory(StorableFactory factory, uint32 classId, uint32 subClassId);

    // Inspect a file
    // An item is unloadable if there is no factory method for it or if it contains data that exceeds the host
    // machine capability
    static RefList<XSF::ItemHeader>*  getLoadableItemList(XSF::Stream::In*);
    static RefList<XSF::ItemHeader>*  getUnLoadableItemList(XSF::Stream::In*);
    static RefList<XSF::Storable>*    readAllLoadable(XSF::Stream::In*);

  private:
    typedef struct {
      StorableFactory   factory;
      uint32            classId;
      uint32            subClassId;
    } RegisteredLoader;

    static RegisteredLoader* loaders;
};


#endif
