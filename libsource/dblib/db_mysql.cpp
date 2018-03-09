///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         dblib/db_mysql.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Database definitions
//  Comment(s):
//  Library:      dblib
//  Created:      2007-04-19
//  Updated:      2007-04-19
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <xbase.hpp>
#include <systemlib/memory.hpp>
#include <dblib/db_abstract.hpp>
#include <dblib/db_mysql.hpp>

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstdarg>

#include <new>

#include <mysql/errmsg.h>
#include <mysql/mysql.h>

using namespace EXNGPrivate;

/////////////////////////////////////////////////////////////////////////
//
//  Shared implementation code
//
/////////////////////////////////////////////////////////////////////////

class MySQLResultWrapper {
  private:
    MYSQL_RES*        mysqlRes;
    MYSQL_FIELD*      fields;

  protected:
    DB::Record        current;

    const DB::Record* fetch();
    void              disposeUnusedRecords();

    uint32            numFields()     { return current.numFields; }
    uint64            numRows()       { return (uint64)mysql_num_rows(mysqlRes); }
    void              seek(uint64 p)  { mysql_data_seek(mysqlRes, (my_ulonglong)p); }

    MySQLResultWrapper(MYSQL_RES* res);
    ~MySQLResultWrapper();
};

/////////////////////////////////////////////////////////////////////////

MySQLResultWrapper::MySQLResultWrapper(MYSQL_RES* res)
: mysqlRes(res)
{
  fields                = mysql_fetch_fields(mysqlRes);
  current.numFields     = mysql_num_fields(mysqlRes);
  current.fieldLength   = 0;
  current.nameLength    = Mem::alloc<const unsigned long>(current.numFields);//(const unsigned long*)Mem::alloc(current.numFields*sizeof(unsigned long));
  current.field         = 0;
  current.name          = Mem::alloc<const char*>(current.numFields);//(const char**)Mem::alloc(current.numFields*sizeof(const char*));

  // copy field names to record template
  for (uint32 i=0; i<current.numFields; i++) {
    current.name[i]                   = fields[i].name;
    ((uint32*)current.nameLength)[i]  = std::strlen(fields[i].name);
  }
}

/////////////////////////////////////////////////////////////////////////

MySQLResultWrapper::~MySQLResultWrapper()
{
  Mem::free((void*)current.nameLength);
  Mem::free((void*)current.name);
  mysql_free_result(mysqlRes);
  //std::puts("*** Destroyed MySQLResultWrapper");
}

/////////////////////////////////////////////////////////////////////////

const DB::Record* MySQLResultWrapper::fetch()
{
  // assumes MYSQL_ROW is char**
  // probably less than ideal if it ever changes
  MYSQL_ROW row         = mysql_fetch_row(mysqlRes);
  if (row) {
    current.fieldLength = mysql_fetch_lengths(mysqlRes);
    current.field       = (const char**)row;
    return &current;
  }
  else {
    return 0;
  }
}

/////////////////////////////////////////////////////////////////////////

void MySQLResultWrapper::disposeUnusedRecords()
{
  // swallow unused records
  uint32    i = 0;
  MYSQL_ROW row;
  while((row = mysql_fetch_row(mysqlRes))) {
    i++;
  }
  //std::printf("*** MySQLResultWrapper::disposeUnusedRecords() discarded %lu rows\n", i);
}

/////////////////////////////////////////////////////////////////////////
//
//  MySQL DBRecordSet implementation
//
//  Note that the DBRecord returns a reference to an internal structure,
//  the values contained within will change on subsequent calls to fetch
//
/////////////////////////////////////////////////////////////////////////


class MySQLRecordSet : public DB::RecordSet, private MySQLResultWrapper {

  public:
    const DB::Record* fetch()         { return MySQLResultWrapper::fetch(); }
    uint32            getNumColumns() { return MySQLResultWrapper::numFields(); }
    MySQLRecordSet(MYSQL_RES* result) : MySQLResultWrapper(result) {
      //std::puts("*** Constructed MySQLRecordSet");
    }
    ~MySQLRecordSet();
};


/////////////////////////////////////////////////////////////////////////

MySQLRecordSet::~MySQLRecordSet()
{
  disposeUnusedRecords();
  //std::puts("*** Destroyed MySQLRecordSet");
}

/////////////////////////////////////////////////////////////////////////
//
//  MySQL DBRecordSetBuffered implementation
//
//  Note that the DBRecord returns a reference to an internal structure,
//  the values contained within will change on subsequent calls to fetch
//
/////////////////////////////////////////////////////////////////////////


class MySQLRecordSetBuffered : public DB::RecordSetBuffered, private MySQLResultWrapper {
  private:
    uint64            numRows;
    uint64            cursor;
  public:
    const DB::Record* fetch();
    uint32            getNumColumns()       { return MySQLResultWrapper::numFields(); }
    uint64            getNumRows()          { return numRows; }
    uint64            getCursor()           { return cursor; }
    bool              setCursor(uint64 p);

    MySQLRecordSetBuffered(MYSQL_RES* result);
    ~MySQLRecordSetBuffered();
};


MySQLRecordSetBuffered::MySQLRecordSetBuffered(MYSQL_RES* result)
: MySQLResultWrapper(result), cursor(0)
{
  numRows = MySQLResultWrapper::numRows();
  //std::printf("*** Constructed MySQLRecordSetBuffered with %lu rows\n", (uint32)numRows);
}

/////////////////////////////////////////////////////////////////////////

MySQLRecordSetBuffered::~MySQLRecordSetBuffered()
{
  //std::puts("*** Destroyed MySQLRecordSetBuffered");
}

/////////////////////////////////////////////////////////////////////////

const DB::Record* MySQLRecordSetBuffered::fetch()
{
  const DB::Record* r = MySQLResultWrapper::fetch();
  if (r) {
    cursor++;
  }
  return r;
}

/////////////////////////////////////////////////////////////////////////

bool MySQLRecordSetBuffered::setCursor(uint64 p)
{
  if (p<numRows) {
    MySQLResultWrapper::seek(p);
    cursor = p;
    return true;
  }
  return false;
}


/////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////
//
//  MySQL Database implementation
//
/////////////////////////////////////////////////////////////////////////

class MySQLDatabase : public DB::Instance {

  private:
    const char* currentHost;
    const char* currentUser;
    const char* currentPass;
    const char* currentDb;
    const char* currentSocket;
    uint32      currentPort;
    uint32      currentFlags;
    const char* serverInfo;
    char*       qBuffer;
    size_t      qBufferLen;
    MYSQL       mysql;
    bool        isOpen;

    void        handleInvalidQueryReturn();
    void        checkConnection() const
    {
      if (!isOpen) THROW_NSX(DB, ConnectionError());
      //if (!isOpen) { throwDBConnectionError(); }
    };

    void        checkQueryReturn(int retVal);

    void        makeQuery(const char* qt, va_list args);

  public:
     bool open(
      const char* hostname,
      const char* username,
      const char* password,
      const char* database,
      const char* socket,
      uint32 port,
      uint32 flags = 0
    );

    void close();

    bool                    setDatabase(const char* db);

    DB::RecordSet*          queryUnbuffered(const char* query);
    DB::RecordSet*          queryfUnbuffered(const char* qt, ...);

    DB::RecordSetBuffered*  query(const char* query);
    DB::RecordSetBuffered*  queryf(const char* qt, ...);

    DB::TemporaryTable*     queryTemporary(const char* query);
    DB::TemporaryTable*     queryfTemporary(const char* qt, ...);


    bool                    getLastBooleanResult();
    uint64                  getLastInsert();
    uint64                  getAffectedRows();

    const char* getDatabase() const;
    const char* getServerInfo() const;

    const char* getImplementationName() const;

    MySQLDatabase();
    ~MySQLDatabase();

  private:

};

/////////////////////////////////////////////////////////////////////////

MySQLDatabase::MySQLDatabase()
: currentHost(0), currentUser(0), currentPass(0),
  currentDb(0), currentSocket(0), currentPort(0),
  currentFlags(0),
  serverInfo(0), qBuffer(0), qBufferLen(1024),
  isOpen(false)
{
  mysql_init(&mysql);
  //std::puts("*** created MySQLDatabase instance");
}

/////////////////////////////////////////////////////////////////////////

MySQLDatabase::~MySQLDatabase()
{
  mysql_close(&mysql);
  //std::puts("*** destroyed MySQLDatabase instance");
}

/////////////////////////////////////////////////////////////////////////

bool MySQLDatabase::setDatabase(const char* db)
{
  if (isOpen) {
    switch (mysql_select_db(&mysql, db)) {
      case 0:
        currentDb = db;
        return true;
        break;

      case CR_SERVER_GONE_ERROR:
      case CR_SERVER_LOST:
        isOpen = false;
        THROW_NSX(DB, ConnectionError());
        break;

      case CR_COMMANDS_OUT_OF_SYNC:
        THROW_NSX(DB, CommandSyncError());
        break;
      case CR_UNKNOWN_ERROR:
        //THROW_NSX(DB, Error());
      default:
        break;
    }
  }
  return false;
}

/////////////////////////////////////////////////////////////////////////

void MySQLDatabase::makeQuery(const char* qt, va_list args)
{
  if (!qBuffer) {
    qBuffer = Mem::alloc<char>(qBufferLen);//(char*)Mem::alloc(qBufferLen);
  }
  int outLength = 0;
  while (1) {
    outLength = std::vsnprintf(qBuffer, qBufferLen, qt, args);
    if (outLength > -1 && ((size_t)outLength < qBufferLen)) {
      break;
    }

    if (outLength > -1) {
      qBufferLen = outLength+1;  // glibc 2.1
    }
    else {
      qBufferLen<<=1;            // glibc 2.0
    }
    char* newBuff = Mem::alloc<char>(qBufferLen);//(char*)Mem::alloc(qBufferLen); // may throw
    Mem::free(qBuffer);
    qBuffer = newBuff;
  }
}

/////////////////////////////////////////////////////////////////////////

bool MySQLDatabase::open(
      const char* hostname,
      const char* username,
      const char* password,
      const char* database,
      const char* socket,
      uint32 port,
      uint32 flags)
{
  //Debug trace("MySQLDatabase::open");
  //trace.printf(
  //  "\"%s\":\"%s\":\"%s\":%u:%u\n",
  //  hostname, username, database, socket, port, flags
  //);
  if (isOpen) {
    // If the current connection/account details are the same,
    // see if all we are doing is actually selecting a different database
    if (
      std::strcmp(hostname, currentHost)==0 &&
      std::strcmp(username, currentUser)==0 &&
      std::strcmp(password, currentPass)==0 &&
      socket!=0 && currentSocket!=0 &&
      std::strcmp(socket, currentSocket)==0
    ) {
      if (std::strcmp(database, currentDb)!=0) {
        return setDatabase(database);
      }
    } else {
      // details don't match, so close the current connection
      close();
    }
  }

  if (mysql_real_connect(&mysql, hostname, username, password, database, port, socket, flags)) {
    currentHost   = hostname;
    currentUser   = username;
    currentPass   = password;
    currentDb     = database;
    currentSocket = socket;
    currentPort   = port;
    currentFlags  = flags;
    serverInfo    = mysql_get_server_info(&mysql);
    isOpen        = true;
    //trace.printf("Opened connection\n");
    return true;
  } else {
    // failure to connect is always an exception
    //throwDBConnectionError();
    THROW_NSX(DB, ConnectionError());
  }
  //trace.printf("Failed to open connection, %s\n", mysql_error(&mysql));
  return false;
}

/////////////////////////////////////////////////////////////////////////

void MySQLDatabase::close()
{
  if (isOpen) {
    mysql_close(&mysql);
    isOpen = false;
    //std::puts("*** MySQLDatabase::close() - closed connection");
  }
}

/////////////////////////////////////////////////////////////////////////

DB::RecordSet* MySQLDatabase::queryUnbuffered(const char* query)
{
  checkConnection();
  checkQueryReturn(mysql_query(&mysql, query));

  MYSQL_RES* res = mysql_use_result(&mysql);
  if (res == 0) {
    // no recordset doesn't always imply an error, was this query not a select?
    if (mysql_errno(&mysql)==0) {
      // this wasn't a SELECT type query as no error number has been raised.
      return 0;
    } else {
      //throwDBQueryError(mysql_error(&mysql));
      THROW_NSX(DB, QueryError(mysql_error(&mysql)));
    }
  }
  return new MySQLRecordSet(res);
}

/////////////////////////////////////////////////////////////////////////

DB::RecordSet* MySQLDatabase::queryfUnbuffered(const char* qt, ...)
{
  if (!qt) {
    THROW_NSX(Error, NullPointer());
  }
  va_list   args;
  va_start(args, qt);
  makeQuery(qt, args);
  va_end(args);

  return queryUnbuffered(qBuffer);
}

/////////////////////////////////////////////////////////////////////////

DB::RecordSetBuffered* MySQLDatabase::query(const char* query)
{
  checkConnection();
  checkQueryReturn(mysql_query(&mysql, query));

  MYSQL_RES* res = mysql_store_result(&mysql);
  if (res == 0) {
    // no recordset doesn't always imply an error, was this query not a select?
    if (mysql_errno(&mysql)==0) {
      // this wasn't a SELECT type query as no error number has been raised.
      return 0;
    } else {
      THROW_NSX(DB, QueryError(mysql_error(&mysql)));
    }
  }
  return new MySQLRecordSetBuffered(res);
}

/////////////////////////////////////////////////////////////////////////

DB::RecordSetBuffered* MySQLDatabase::queryf(const char* qt, ...)
{
  if (!qt) {
    THROW_NSX(Error, NullPointer());
  }
  va_list   args;
  va_start(args, qt);
  makeQuery(qt, args);
  va_end(args);

  return query(qBuffer);
}

/////////////////////////////////////////////////////////////////////////

DB::TemporaryTable* MySQLDatabase::queryTemporary(const char* query)
{
  checkConnection();
  return 0;
}

/////////////////////////////////////////////////////////////////////////

DB::TemporaryTable* MySQLDatabase::queryfTemporary(const char* qt, ...)
{
  if (!qt) {
    THROW_NSX(Error, NullPointer());
  }
  va_list   args;
  va_start(args, qt);
  makeQuery(qt, args);
  va_end(args);

  return queryTemporary(qBuffer);
}

/////////////////////////////////////////////////////////////////////////


bool MySQLDatabase::getLastBooleanResult()
{
  checkConnection();
  return false;
}

/////////////////////////////////////////////////////////////////////////

uint64 MySQLDatabase::getLastInsert()
{
  checkConnection();
  return (uint64)mysql_insert_id(&mysql);
}

/////////////////////////////////////////////////////////////////////////

uint64 MySQLDatabase::getAffectedRows()
{
  checkConnection();
  return (uint64)mysql_affected_rows(&mysql);
}

/////////////////////////////////////////////////////////////////////////

const char* MySQLDatabase::getDatabase() const
{
  checkConnection();
  return currentDb;
}

/////////////////////////////////////////////////////////////////////////

const char* MySQLDatabase::getServerInfo() const
{
  checkConnection();
  return serverInfo;
}

/////////////////////////////////////////////////////////////////////////

const char* MySQLDatabase::getImplementationName() const
{
  static const char* impName = "MySQLDatabase";
  return impName;
}

/////////////////////////////////////////////////////////////////////////

void MySQLDatabase::checkQueryReturn(int retVal)
{
  switch (retVal) {
    case 0:
      return;
      break;

    case CR_SERVER_GONE_ERROR:
    case CR_SERVER_LOST:
      isOpen = false;
      THROW_NSX(DB, ConnectionError());
      break;

    case CR_COMMANDS_OUT_OF_SYNC:
      THROW_NSX(DB, CommandSyncError());
      break;

    case CR_UNKNOWN_ERROR:
      THROW_NSX(DB, Error());
      break;

    default:
      if (mysql_errno(&mysql)!=0) {
        THROW_NSX(DB, QueryError(mysql_error(&mysql)));
      }
      break;
  }
}

/////////////////////////////////////////////////////////////////////////
//
//  MySQL Database implementation
//
/////////////////////////////////////////////////////////////////////////

//Database* MySQL::shared[DBUsers::MAX_DBUSER] = { 0 };

DB::Instance* MySQL::createInstance()
{
  return new(std::nothrow) MySQLDatabase();
}

/////////////////////////////////////////////////////////////////////////

void MySQL::destroyInstance(DB::Instance* db)
{
  delete db;
}

/////////////////////////////////////////////////////////////////////////
/*
Database* MySQL::getSharedInstance(DBUsers::UserId id)
{
  if (id<0 || id>=DBUsers::MAX_DBUSER) {
    throwDBConnectionError();
  }
  if (!shared[id]) {
    if (!(shared[id] = new(std::nothrow) MySQLDatabase())) {
      throwDBConnectionError();
    }
    DBUsers::connectAs(shared[id], id);
  }
  return shared[id];
}

/////////////////////////////////////////////////////////////////////////

void MySQL::finalizeInstances()
{
  for (int i=0; i<DBUsers::MAX_DBUSER; i++) {
    if (shared[i]) {
      delete shared[i];
      shared[i] = 0;
    }
  }
}
*/
