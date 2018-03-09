///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         utilitylib/hashkeyd.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Simple text hashing
//  Comment(s):
//  Library:      utility
//  Created:      2007-04-07
//  Updated:      2007-04-07
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <xbase.hpp>
#include <utilitylib/hashkeys.hpp>
#include <systemlib/machine_bitops.hpp>
#include <private/systemlib/error.hpp>

uint32 Key32::evalHash(const char* text)
{
  if (!text) {
    THROW_NSX(Error, NullPointer());
  }
  ruint32 v = 0;
  ruint8* p = (uint8*)text;
  while (*p) {
    // bitwise rotate (so bits are never lost) and xor with byte
    v = Machine::rotLeft32(1, v);
    v ^= (uint32) *p++;
  }
  return v;
}

////////////////////////////////////////////////////////////////////////////////

uint64 Key64::evalHash(const char* text)
{
  if (!text) {
    THROW_NSX(Error, NullPointer());
  }
  uint64 v = 0;
  ruint8* p = (uint8*)text;
  while (*p) {
    // bitwise rotate (so bits are never lost) and xor with byte
    v = Machine::rotRight64(1, v);
    v ^= (uint64) *p++;
  }
  return v;
}

