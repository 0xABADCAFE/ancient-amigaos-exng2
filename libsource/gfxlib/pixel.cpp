///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         gfxlib/pixel.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Pixel definitions
//  Comment(s):
//  Library:      Graphics
//  Created:      2006-10-08
//  Updated:      2006-10-08
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <gfxlib/pixel.hpp>
#include <systemlib/logger.hpp>

#define BFW_15 Pixel::Layout::packCP(5, 5, 5)
#define BFP_15 Pixel::Layout::packCP(10, 5, 0)
#define BFW_16 Pixel::Layout::packCP(5, 6, 5)
#define BFP_16 Pixel::Layout::packCP(11, 5, 0)
#define BFW_32 Pixel::Layout::packCP(8, 8, 8, 8)

#define LO_RGB  Pixel::Layout::packCP(Pixel::Layout::RED,   Pixel::Layout::GREEN, Pixel::Layout::BLUE )
#define LO_BGR  Pixel::Layout::packCP(Pixel::Layout::BLUE,  Pixel::Layout::GREEN, Pixel::Layout::RED )
#define LO_ARGB Pixel::Layout::packCP(Pixel::Layout::ALPHA, Pixel::Layout::RED,   Pixel::Layout::GREEN, Pixel::Layout::BLUE )
#define LO_ABGR Pixel::Layout::packCP(Pixel::Layout::ALPHA, Pixel::Layout::BLUE,  Pixel::Layout::GREEN, Pixel::Layout::RED )
#define LO_BGRA Pixel::Layout::packCP(Pixel::Layout::BLUE,  Pixel::Layout::GREEN, Pixel::Layout::RED,   Pixel::Layout::ALPHA )
#define LO_RGBA Pixel::Layout::packCP(Pixel::Layout::RED,   Pixel::Layout::GREEN, Pixel::Layout::BLUE,  Pixel::Layout::ALPHA )

#if (X_ENDIAN == XA_BIGENDIAN)
# define WT_PB   0
# define WT_SB   0
# define WT_SL   Pixel::Layout::IS_BYTESWAPPED
# define _RGB15  Pixel::RGB_555B
# define _RGB16  Pixel::RGB_565B
# define _ARGB32 Pixel::ARGB_8888
# define BFP_32 Pixel::Layout::packCP(24, 16, 8, 0)
#else
# define WT_PB   0
# define WT_SB   Pixel::Layout::IS_BYTESWAPPED
# define WT_SL   0
# define _RGB15  Pixel::RGB_555L
# define _RGB16  Pixel::RGB_565L
# define _ARGB32 Pixel::BGRA_8888
# define BFP_32 Pixel::Layout::packCP(0, 8, 16, 24)
#endif



#define componentType props[0]
#define accessType    props[1]
#define numComponents props[2]
#define totalSize     props[3]


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint8 Pixel::fbPrefFormats[6] = {
  // Initial best guess values
  Pixel::CUSTOM_FB,
  Pixel::LUT_8,
  _RGB15,
  _RGB16,
  Pixel::RGB_888,
  _ARGB32
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Pixel::FBType Pixel::getPrefferedFormat(uint32 d)
{
  static uint8 test[6] = { 0, 8, 15, 16, 24, 32 };

  for (int i=0; i<6; i++) {
    if (d <= test[i]) {
      return (Pixel::FBType)fbPrefFormats[i];
    }
  }
  return Pixel::CUSTOM_FB;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Pixel::Layout Pixel::fbTypeLayout[Pixel::CUSTOM_FB] = {
  Pixel::Layout(Pixel::Layout::packBP(WT_PB, Machine::ET_UINT8, 1), Pixel::Layout::VALUE),       // LUT_8
  Pixel::Layout(Pixel::Layout::packBP(WT_SB, Machine::ET_UINT16, 3), LO_RGB, BFW_15, BFP_15),   // RGB_555B
  Pixel::Layout(Pixel::Layout::packBP(WT_SB, Machine::ET_UINT16, 3), LO_BGR, BFW_15, BFP_15),   // BGR_555B
  Pixel::Layout(Pixel::Layout::packBP(WT_SL, Machine::ET_UINT16, 3), LO_RGB, BFW_15, BFP_15),   // RGB_555L
  Pixel::Layout(Pixel::Layout::packBP(WT_SL, Machine::ET_UINT16, 3), LO_BGR, BFW_15, BFP_15),   // BGR_555L
  Pixel::Layout(Pixel::Layout::packBP(WT_SB, Machine::ET_UINT16, 3), LO_RGB, BFW_16, BFP_16),   // RGB_565B
  Pixel::Layout(Pixel::Layout::packBP(WT_SB, Machine::ET_UINT16, 3), LO_BGR, BFW_16, BFP_16),   // BGR_565B
  Pixel::Layout(Pixel::Layout::packBP(WT_SL, Machine::ET_UINT16, 3), LO_RGB, BFW_16, BFP_16),   // RGB_565L
  Pixel::Layout(Pixel::Layout::packBP(WT_SL, Machine::ET_UINT16, 3), LO_BGR, BFW_16, BFP_16),   // BGR_565L
  Pixel::Layout(Pixel::Layout::packBP(WT_PB, Machine::ET_UINT8, 3), LO_RGB),                     // RGB_24
  Pixel::Layout(Pixel::Layout::packBP(WT_PB, Machine::ET_UINT8, 3), LO_BGR),                     // BGR_24

  Pixel::Layout(Pixel::Layout::packBP(WT_PB, Machine::ET_UINT32, 4), LO_ARGB, BFW_32, BFP_32),  // ARGB_8888
  Pixel::Layout(Pixel::Layout::packBP(WT_PB, Machine::ET_UINT32, 4), LO_ABGR, BFW_32, BFP_32),  // ABGR_8888
  Pixel::Layout(Pixel::Layout::packBP(WT_PB, Machine::ET_UINT32, 4), LO_BGRA, BFW_32, BFP_32),  // BGRA_8888
  Pixel::Layout(Pixel::Layout::packBP(WT_PB, Machine::ET_UINT32, 4), LO_RGBA, BFW_32, BFP_32)   // RGBA_8888

/*
  Pixel::Layout(Pixel::Layout::packBP(WT_SB, Machine::ET_UINT32, 4), LO_ARGB, BFW_32, BFP_32),  // ARGB_32B
  Pixel::Layout(Pixel::Layout::packBP(WT_SB, Machine::ET_UINT32, 4), LO_ABGR, BFW_32, BFP_32),  // ABGR_32B
  Pixel::Layout(Pixel::Layout::packBP(WT_SL, Machine::ET_UINT32, 4), LO_ARGB, BFW_32, BFP_32),  // ARGB_32B
  Pixel::Layout(Pixel::Layout::packBP(WT_SL, Machine::ET_UINT32, 4), LO_ABGR, BFW_32, BFP_32)   // ABGR_32B
*/
};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Pixel::Layout
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LOGGING_DECLARE_CLASSNAME(Pixel::Layout)

Pixel::Layout::Layout(
  uint32  bProps,
  uint32  cDef,
  uint32  fldW,
  uint32  fldP
) :
  flags(bProps & MASK_USER_SET),
  compMap(0)
{
  // Constructor for bitfield component pixels

  props_u32 = 0;
  width_u32 = 0;
  pos_u32   = 0;
  componentType = Machine::WT_BITFIELD;


  uint8 n       = bProps&0xFF;
  uint8 wType   = (bProps>>8) & 0xFF;

  if (n<MIN_CHANNELS || n>MAX_CHANNELS) {
    THROW_NSX(Error, InvalidValue());
  }

  initCompMap(n, cDef);

  switch (wType) {
    case Machine::ET_UINT8:   flags &= ~IS_BYTESWAPPED;
                              initBitfield(fldW, fldP, wType, 1); break;
    case Machine::ET_UINT16:  initBitfield(fldW, fldP, wType, 2); break;
    case Machine::ET_UINT32:  initBitfield(fldW, fldP, wType, 4); break;
    default:
      THROW_NSX(Error, InvalidValue());
      break;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Pixel::Layout::Layout(
  uint32  bProps,
  uint32  cDef
) :
  flags(bProps & MASK_USER_SET),
  compMap(0)
{
  // Constructor for elemental component pixels

  props_u32 = 0;
  width_u32 = 0;
  pos_u32   = 0;

  uint8 n       = bProps&0xFF;
  uint8 wType   = (bProps>>8) & 0xFF;

  if (n<MIN_CHANNELS || n>MAX_CHANNELS) {
    THROW_NSX(Error, InvalidValue());
  }

  accessType = componentType = wType;

  initCompMap(n, cDef);

  switch (wType) {
    case Machine::ET_UINT8:   flags &= ~IS_BYTESWAPPED;
                              initElemental(1);   break;
    case Machine::ET_UINT16:  initElemental(2);   break;
    case Machine::ET_UINT32:  initElemental(4);   break;
    case Machine::ET_UINT64:  initElemental(8);   break;
    case Machine::ET_UINT128: initElemental(16);  break;

    default:
      THROW_NSX(Error, InvalidValue());
      break;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool Pixel::Layout::compare(const Pixel::Layout& pix) const
{
  // it's possible for 8-bit wide fields to be represented as bytes too, so this method is used to see wether
  // the representations are comparable.
  if (
    flags     == pix.flags      &&
    compMap   == pix.compMap
  ) {
    uint32 m1 = componentType==Machine::WT_BITFIELD ? width_u32 : width_u32<<3;


  }
  return false;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Pixel::Layout::initCompMap(size_t n, uint32 compDef)
{
  for (size_t i=0; i<n; i++) {
    uint32 c = compDef & 0x000000FF;
    uint32 f = 1<<c;
    if (c>DEF_MAX || (flags & f)) {
      // invalid/duplicate component type
      THROW_NSX(Error, InvalidValue());
    } else {
      comp[i] =   c;
      flags   |=  f;
      c       <<= 1;
      compMap |=  (i << c);
    }
    compDef >>= 8;
  }
  numComponents = n;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Pixel::Layout::initElemental(size_t elemSize)
{
  size_t n    = numComponents;
  totalSize   = elemSize * n;
  while (n--) {
    width[n]  = elemSize;
    pos[n]    = elemSize*n;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Pixel::Layout::initBitfield(uint32 fldW, uint32 fldP, uint8 t, uint8 s)
{
  //LOGGING_DECLARE_FUNCNAME(initBitfield)

  accessType      = t;
  totalSize       = s;
  size_t  n       = numComponents;
  uint32  wordLen = ((uint32)totalSize << 3);
  uint32  mask[4];
  for (size_t i=0; i<n; i++) {
    uint32 fPos = fldP & 0x000000FF; fldP >>= 8;
    uint32 fWid = fldW & 0x000000FF; fldW >>= 8;
    if ( (fPos + fWid) > wordLen) {
/*
      #ifdef EXNG2_BUILD_LOGGED
      SystemLog::write(
        SystemLog::WARNING, "%s::%s width %" XPF_U32 " at position %" XPF_U32 " exceeds word length [%" XPF_U32 " bits]\n",
        loggingClassName, loggingFuncName,
        fWid,
        fPos,
        wordLen
      );
      #endif
*/
      THROW_NSX(Error, InvalidValue());
    }
    mask[i]     = ((1<<fldW)-1)<<fPos;
/*
    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::INFO, "%s::%s channel %u has mask 0x%08X\n",
      loggingClassName, loggingFuncName,
      (unsigned)i,
      (unsigned)mask[i]
    );
    #endif
*/
    width[i]    = fWid;
    pos[i]      = fPos;
  }

  // all pairs test. No pair of masks must share a given bit
  for (size_t i=0; i<n; i++) {
    for(size_t j=0; j<n; j++) {
      if (j==i) {
        continue;
      }
      if (mask[i] & mask[j]) {
/*
        #ifdef EXNG2_BUILD_LOGGED
        SystemLog::write(
          SystemLog::WARNING, "%s::%s bitfield overlap for masks %08X and %08X]\n",
          loggingClassName, loggingFuncName,
          (unsigned)mask[i],
          (unsigned)mask[j]
        );
        #endif
*/
        THROW_NSX(Error, InvalidValue());
      }
    }
  }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 Pixel::Layout::getIdxComp(Component c) const
{
  uint32 temp = 1<<c;
  if (!(flags & temp)) {
    THROW_NSX(Error, InvalidValue());
  }
  temp = c<<1;
  return (compMap>>temp) & 3UL;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Pixel::Layout::Component Pixel::Layout::getComponentType(uint32 ch)   const
{
  if (ch >= numComponents) {
    THROW_NSX(Error, InvalidValue());
  }
  return (Component)comp[ch];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32    Pixel::Layout::getComponentWidth(uint32 ch)       const
{
  if (ch >= numComponents) {
    THROW_NSX(Error, InvalidValue());
  }
  return width[ch];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32    Pixel::Layout::getComponentPosition(uint32 ch)    const
{
  if (ch >= numComponents) {
    THROW_NSX(Error, InvalidValue());
  }
  return pos[ch];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32    Pixel::Layout::getComponentMax(uint32 ch)    const
{
  if (ch >= numComponents) {
    THROW_NSX(Error, InvalidValue());
  }
  return computeMax(ch);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32    Pixel::Layout::getComponentMask(uint32 ch)    const
{
  if (ch >= numComponents) {
    THROW_NSX(Error, InvalidValue());
  }
  return computeMask(ch);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32    Pixel::Layout::getMax(Component c)    const
{
  return computeMax(getIdxComp(c));
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32    Pixel::Layout::getMask(Component c)    const
{
  return computeMask(getIdxComp(c));
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32    Pixel::Layout::getComponentNumBits(uint32 ch)       const
{
  if (ch >= numComponents) {
    THROW_NSX(Error, InvalidValue());
  }
  return componentType == Machine::WT_BITFIELD ? width[ch] : width[ch]<<3;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

uint32 Pixel::Layout::computeMask(uint32 ch) const
{
  uint32 res;
  if (componentType == Machine::WT_BITFIELD) {
    res = ((1UL<<width[ch])-1)<<pos[ch];
  }
  else {
    res = (1UL<<(width[ch]<<3))-1;
  }
  return res;
}

uint32 Pixel::Layout::computeMax(uint32 ch) const
{
  uint32 res;
  if (componentType == Machine::WT_BITFIELD) {
    res = (1UL<<width[ch])-1;
  }
  else {
    res = flags & IS_FLOAT_FORMAT ? 1 : (1UL<<(width[ch]<<3))-1;
  }
  return res;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool operator==(const Pixel::Layout& a, const Pixel::Layout& b)
{
  return (
    a.flags     == b.flags      &&
    a.compMap   == b.compMap    &&
    a.props_u32 == b.props_u32  &&
    a.comp_u32  == b.comp_u32   &&
    a.width_u32 == b.width_u32  &&
    a.pos_u32   == b.pos_u32
  );
}

