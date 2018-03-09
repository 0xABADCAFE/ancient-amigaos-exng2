///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/amigaos3_68k/systemlib/cpu_native.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  CPU control and query
//  Comment(s):
//  Library:      System
//  Created:      2006-10-08
//  Updated:      2006-10-08
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <xbase.hpp>
#include <systemlib/memory.hpp>
#include <systemlib/machine_bitops.hpp>
#include <private/systemlib/error.hpp>
#include <cstdlib>
#include <cstring>

using namespace EXNGPrivate;

LOGGING_DECLARE_CLASSNAME(RawMemHandler)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void RawMemHandler::init()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void RawMemHandler::done()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void* RawMemHandler::alloc(size_t size, uint32 flags)
{
  return flags & Mem::ZEROFILL ? std::calloc(size, 1) : std::malloc(size);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void RawMemHandler::free(void* ptr, size_t size)
{
  std::free(ptr);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void RawMemHandler::copy(void* dst, const void* src, size_t len)
{
  std::memcpy(dst, src, len);
}

void RawMemHandler::swap16(void* dst, const void* src, size_t num)
{
  // crude, unoptimised version
  uint16* d = (uint16*)dst;
  uint16* s = (uint16*)src;
  while (num--) {
    uint16 v = *s++;
    *d++ = Machine::swap16(v);
  }
}

void RawMemHandler::swap32(void* dst, const void* src, size_t num)
{
  // crude, unoptimised version
  uint32* d = (uint32*)dst;
  uint32* s = (uint32*)src;
  while (num--) {
    uint32 v = *s++;
    *d++ = Machine::swap32(v);
  }
}

void RawMemHandler::swap64(void* dst, const void* src, size_t num)
{
  // crude, unoptimised version
  uint64* d = (uint64*)dst;
  uint64* s = (uint64*)src;
  while (num--) {
    uint64 v = *s++;
    *d++ = Machine::swap64(v);
  }
}

void RawMemHandler::zero(void* dst, size_t len)
{
  std::memset(dst, 0, len);
}

void RawMemHandler::set(void* dst, int val, size_t len)
{
  std::memset(dst, val, len);
}

void RawMemHandler::set16(void* dst, uint16 val, size_t num)
{
  // crude, unoptimised version
  uint16* d = (uint16*)dst;
  while (num--) {
    *d++ = val;
  }
}

void RawMemHandler::set32(void* dst, uint32 val, size_t num)
{
  // crude, unoptimised version
  uint32* d = (uint32*)dst;
  while (num--) {
    *d++ = val;
  }
}

void RawMemHandler::set64(void* dst, const uint64& val, size_t num)
{
  // crude, unoptimised version
  uint64* d = (uint64*)dst;
  while (num--) {
    *d++ = val;
  }
}

size_t getRemainingFreeSize()
{
  return 0;
}
