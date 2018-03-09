///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         dblib/db_abstract.cpp
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
#include <cstdlib>
#include <cstring>

DECLARE_MIN_RTTI(DB::RecordSet);
DECLARE_MIN_RTTI(DB::RecordSetBuffered);
DECLARE_MIN_RTTI(DB::Connector);
DECLARE_MIN_RTTI(DB::Questor);
DECLARE_MIN_RTTI(DB::TemporaryTable);
DECLARE_MIN_RTTI(DB::Instance);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  DB::Record (elemental type)
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


DB::Record::Record() : dataSection(0), numFields(0), field(0), name(0), fieldLength(0), nameLength(0) {}

DB::Record::~Record()
{
  if (dataSection) {
    Mem::free(dataSection);
  }
}
///////////////////////////////////////////////////////////////////////////////

const DB::Record* DB::Record::clone() const
{
  //std::puts("invoked DBRecord::clone()");
  // allocate storage for the data. This includes the pointer arrays
  // and the data they point to. Allocate all field data with sufficient space
  // to null terminate every string, ie length+1
  size_t  allocSize = numFields*(2*(sizeof(const char*)+sizeof(const unsigned long*)));
  for (uint32 i=0; i<numFields; i++) {
    allocSize += fieldLength[i] + nameLength[i] + 2;
  }
  // use malloc rather than new[] as we basically don't need zero initialisation
  // of the data. We also want a single chunk of memory rather than scattering
  // lots of individually allocated strings and pointer arrays, which is the sort
  // of dire resource efficiency we'd expect of java ;-)

  if (uint8* data = Mem::alloc<uint8>(allocSize)) {
    //std::printf("Allocated clone data buffer [%lu bytes] at 0x%08X\n", allocSize, (unsigned)data);
    DB::Record* clone   = new DB::Record();
    clone->numFields    = numFields;
    clone->dataSection  = data;

    // data will be filled as follows:

    // {field[]},{name[]},{fieldLength[]},{nameLength[]},{field0Value,0},{field0Name,0}...{fieldNValue,0},{fieldNName,0}

    // set up temporary pointers into the allocated space

    // field pointer array comes first
    char**           tmpField    = (char**)  data;

    // name pointer array next
    char**           tmpName     = (char**)  (data + numFields*sizeof(char**));

    // field length array next
    unsigned long*   tmpFieldLen = (unsigned long*) (data + numFields*(2*sizeof(char**)));

    // name length array next
    unsigned long*   tmpNameLen  = (unsigned long*) (data + numFields*(2*sizeof(char**)+sizeof(unsigned long*)));

    // finally the string data for each field/name pair
    char*            tmpString   = (char*)   (data + numFields*(2*(sizeof(char*)+sizeof(unsigned long*))));

    // set up clone record's pointer data
    // note that we can only assign these pointers, we can't use them to perform the copy
    // as the const qualifier ensures they are immutable.
    clone->field        = (const char**)tmpField;
    clone->name         = (const char**)tmpName;
    clone->fieldLength  = tmpFieldLen;
    clone->nameLength   = tmpNameLen;

    // copy the data, via the tmp pointers, since our clone members are const
    for (uint32 i=0; i<numFields; i++) {
      // copy the length data first, easy enough
      tmpFieldLen[i]  = fieldLength[i];
      tmpNameLen[i]   = nameLength[i];

      // copy the field data and enforce null termination
      std::strncpy(tmpString, field[i], fieldLength[i]);
      tmpField[i]     =   tmpString;
      tmpString       +=  fieldLength[i];
      *tmpString++    =   '\0';

      // copy the field name data and enforce null termination
      std::strncpy(tmpString, name[i], nameLength[i]);
      tmpName[i]      =   tmpString;
      tmpString       +=  nameLength[i];
      *tmpString++    =   '\0';
    }

    // OK, we have cloned the record completely.
    return clone;
  } else {
    return 0; // failed to clone
  }
}

///////////////////////////////////////////////////////////////////////////////
/*
#include <cstdio>


time_t DBUtils::sqlDateStringToTime(tm* callDate, const char* date, int len)
{
  char buffer[20];
  if (len) {
    std::strncpy(buffer, date, 19);
    buffer[19] = 0;
    date = buffer;
  }

  std::sscanf(
    date,
    "%d-%d-%d %d:%d:%d",
    &callDate->tm_year,
    &callDate->tm_mon,
    &callDate->tm_mday,
    &callDate->tm_hour,
    &callDate->tm_min,
    &callDate->tm_sec
  );

  callDate->tm_year  -= 1900;
  callDate->tm_mon   -= 1;

  callDate->tm_wday   = 0;
  callDate->tm_yday   = 0;
  callDate->tm_isdst  = -1;

  return mktime(callDate);
}
*/
