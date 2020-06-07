#include <xbase.hpp>
#include <systemlib/machine_bitops.hpp>



void naiveSwap16(void* dst, const void* src, size_t len)
{
  const uint16* s = (const uint16*)src;
  uint16*       d = (uint16*)dst;
  while (len--) {
    *d++ = Machine::swap16(*s++);
  }
}

void naiveSwap32(void* dst, const void* src, size_t len)
{
  const uint32* s = (const uint32*)src;
  uint32*       d = (uint32*)dst;
  while (len--) {
    *d++ = Machine::swap32(*s++);
  }
}

void naiveSwap64(void* dst, const void* src, size_t len)
{
  const uint64* s = (const uint64*)src;
  uint64*       d = (uint64*)dst;
  while (len--) {
    *d++ = Machine::swap64(*s++);
  }
}

