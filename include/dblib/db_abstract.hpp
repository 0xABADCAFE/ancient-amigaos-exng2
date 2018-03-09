///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         dblib/db_abstract.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Database definitions
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

#ifndef _EXNG2_DBLIB_DB_ABSTRACT_HPP_
# define _EXNG2_DBLIB_DB_ABSTRACT_HPP_

namespace DB {
  struct  Record;
  class   RecordSet;
  class   RecordSetBuffered;
  class   Connector;

  class   Questor;
  class   TemporaryTable;
  class   Instance;

  class   Error;
  class   ConnectionError;
  class   CommandSyncError;
  class   QueryError;
};

#include "db_error.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  DB::Record (elemental type)
//
//  DB::Record references returned from DB::RecordSet fetch operations are not unique!
//
//  If you need to get a unique copy of a DBRecord, use the clone() method, but be sure to delete it once you no
//  longer require it.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct DB::Record {
  private:
    void*                 dataSection;  // points to raw record data for cloned records
  public:
    uint32                numFields;    // number of fields in record
    const char**          field;        // field contents
    const char**          name;         // feild names
    const unsigned long*  fieldLength;  // field lengths
    const unsigned long*  nameLength;   // field name lengths

  public:
    Record();
    ~Record();
    const Record* clone() const;    // Creates a unique copy of the record
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  DB::RecordSet interfaces
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class DB::RecordSet {
  DEFINE_MIN_RTTI
  public:
    virtual const DB::Record* fetch()         = 0;
    virtual uint32            getNumColumns() = 0;

    virtual ~RecordSet() {}
};

class DB::RecordSetBuffered : public DB::RecordSet {
  DEFINE_MIN_RTTI
  public:
    virtual uint64  getNumRows()            = 0;
    virtual uint64  getCursor()             = 0;
    virtual bool    setCursor(uint64 p)     = 0;

    virtual ~RecordSetBuffered() {}
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  DB::Connector interface
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class DB::Connector {
  DEFINE_MIN_RTTI
  public:
    virtual bool open(
      const char* host,
      const char* user,
      const char* pass,
      const char* db,
      const char* socket,
      uint32 port,
      uint32 flags = 0
    ) = 0;

    virtual void        close()                           = 0;
    virtual bool        setDatabase(const char* database) = 0;
    virtual const char* getDatabase() const               = 0;
    virtual const char* getServerInfo() const             = 0;

    virtual             ~Connector() {}
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  DB::Questor interface
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class DB::Questor {
  DEFINE_MIN_RTTI
  public:
    virtual DB::RecordSet*          queryUnbuffered(const char* query)    = 0;
    virtual DB::RecordSet*          queryfUnbuffered(const char* qt, ...) = 0;
    virtual DB::RecordSetBuffered*  query(const char* query)              = 0;
    virtual DB::RecordSetBuffered*  queryf(const char* qt, ...)           = 0;
    virtual bool                    getLastBooleanResult()                = 0;
    virtual uint64                  getLastInsert()                       = 0;
    virtual uint64                  getAffectedRows()                     = 0;

    virtual                         ~Questor() {}
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  DB::TemporaryTable interface
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class DB::TemporaryTable : public DB::Questor {
  DEFINE_MIN_RTTI
  public:
    virtual void        regenerate()            = 0;
    virtual const char* getName()               = 0;
    virtual void        sort(const char* query) = 0;
    virtual             ~TemporaryTable() {}
};

class DB::Instance : public DB::Connector, public DB::Questor {
  DEFINE_MIN_RTTI
  public:
    virtual const char*           getImplementationName() const       = 0;
    virtual DB::TemporaryTable*   queryTemporary(const char* query)   = 0;
    virtual DB::TemporaryTable*   queryfTemporary(const char* qt,...) = 0;
    virtual                       ~Instance() {}
};


#endif
