
#include <xbase.hpp>
#include <systemlib/memory.hpp>
#include <cstdio>
#include "maps.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Map::Map() : data(0)
{
  size_t size = (1UL<<MAP_DIMENSION)*(1UL<<MAP_DIMENSION);

  data = Mem::alloc<uint8>(size);
  printf("Map::Map() - allocated %d bytes data\n", (int)size);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Map::~Map()
{
  Mem::free(data);
  printf("Map::~Map() - freed data\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint8& LinearMap::point(uint32 x, uint32 y)
{
  return data[(y<<MAP_DIMENSION)+x];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LinearMap::LinearMap()
: Map()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint8& SubPatch16Map::point(uint32 x, uint32 y)
{
  // YYYYYYYY XXXXXXXX
  // YYYYYYXX XXXXYYXX

  asm(
    "ror.l  #2,     %0\n\t"   // 00000000 00000000 00000000 XXXXXXXX -> XX000000 00000000 00000000 00XXXXXX
    "ror.l  #2,     %1\n\t"   // 00000000 00000000 00000000 YYYYYYYY -> YY000000 00000000 00000000 00YYYYYY
    "lsl.w  #2,     %0\n\t"   // XX000000 00000000 00000000 00XXXXXX -> XX000000 00000000 00000000 XXXXXX00
    "lsl.w  #6,     %1\n\t"   // YY000000 00000000 00000000 00YYYYYY -> YY000000 00000000 0000YYYY YY000000
    "rol.l  #2,     %0\n\t"   // XX000000 00000000 00000000 XXXXXX00 -> 00000000 00000000 000000XX XXXX00XX
    "rol.l  #4,     %1\n\t"   // YY000000 00000000 00YYYYYY 00000000 -> 00000000 00000000 YYYYYY00 0000YY00
    "or.l   %1,     %0\n\t"
    : "=d"(x) : "d"(y), "0"(x) : "cc"
  );
/*


  uint32 scooby = (x & MASK_LOWER) |
                  ((y & MASK_LOWER)<<2) |
                  ((x & MASK_UPPER)<<2) |
                  ((y & MASK_UPPER)<<MAP_DIMENSION);
  return data[scooby];*/
  return data[x];
}

SubPatch16Map::SubPatch16Map()
: Map()
{

}

