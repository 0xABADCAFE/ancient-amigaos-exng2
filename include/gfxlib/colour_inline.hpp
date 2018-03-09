///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         gfxlib/colour_inline.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  inline functions
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

#ifndef _EXNG2_GFXLIB_COLOUR_INLINE_HPP_
# define _EXNG2_GFXLIB_SURFACE_INLINE_HPP_

inline bool operator==(const ColourARGB_8888& c1, const ColourARGB_8888& c2)
{
  return c1.u32 == c2.u32;
}

inline bool operator==(const ColourARGB_8888& c1, const ColourABGR_8888& c2)
{
  uint32 tmp = Machine::swap32(c2.u32);           // ABGR -> RGBA
  return c1.u32 == Machine::rotRight32<8>(tmp);   // RGBA -> ARGB
}

inline bool operator==(const ColourARGB_8888& c1, const ColourRGBA_8888& c2)
{
  return c1.u32 == Machine::rotLeft32<8>(c2.u32); // RGBA -> ARGB
}

inline bool operator==(const ColourARGB_8888& c1, const ColourBGRA_8888& c2)
{
  return c1.u32 == Machine::swap32(c2.u32);       // BGRA -> ARGB
}

inline bool operator!=(const ColourARGB_8888& c1, const ColourARGB_8888& c2)  { return !(c1==c2); }
inline bool operator!=(const ColourARGB_8888& c1, const ColourABGR_8888& c2)  { return !(c1==c2); }
inline bool operator!=(const ColourARGB_8888& c1, const ColourRGBA_8888& c2)  { return !(c1==c2); }
inline bool operator!=(const ColourARGB_8888& c1, const ColourBGRA_8888& c2)  { return !(c1==c2); }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline bool operator==(const ColourABGR_8888& c1, const ColourARGB_8888& c2)
{
  uint32 tmp = Machine::swap32(c2.u32);           // ARGB -> BGRA
  return c1.u32 == Machine::rotRight32<8>(tmp);   // BGRA -> ABGR
}

inline bool operator==(const ColourABGR_8888& c1, const ColourABGR_8888& c2)
{
  return c1.u32 == c2.u32;
}

inline bool operator==(const ColourABGR_8888& c1, const ColourRGBA_8888& c2)
{
  return c1.u32 == Machine::swap32(c2.u32);       // RGBA -> ABGR
}

inline bool operator==(const ColourABGR_8888& c1, const ColourBGRA_8888& c2)
{
  return c1.u32 == Machine::rotRight32<8>(c2.u32); // BGRA -> ABGR
}

inline bool operator!=(const ColourABGR_8888& c1, const ColourARGB_8888& c2)  { return !(c1==c2); }
inline bool operator!=(const ColourABGR_8888& c1, const ColourABGR_8888& c2)  { return !(c1==c2); }
inline bool operator!=(const ColourABGR_8888& c1, const ColourRGBA_8888& c2)  { return !(c1==c2); }
inline bool operator!=(const ColourABGR_8888& c1, const ColourBGRA_8888& c2)  { return !(c1==c2); }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


inline bool operator==(const ColourRGBA_8888& c1, const ColourARGB_8888& c2)
{
  return c1.u32 == Machine::rotLeft32<8>(c2.u32);  // ARGB -> RGBA
}

inline bool operator==(const ColourRGBA_8888& c1, const ColourABGR_8888& c2)
{
  return c1.u32 == Machine::swap32(c2.u32);        // ABGR -> RGBA
}

inline bool operator==(const ColourRGBA_8888& c1, const ColourRGBA_8888& c2)
{
  return c1.u32 == c2.u32;
}

inline bool operator==(const ColourRGBA_8888& c1, const ColourBGRA_8888& c2)
{
  uint32 tmp = Machine::swap32(c2.u32);           // BGRA -> ARGB
  return c1.u32 == Machine::rotLeft32<8>(tmp);    // ARGB -> RGBA
}

inline bool operator!=(const ColourRGBA_8888& c1, const ColourARGB_8888& c2)  { return !(c1==c2); }
inline bool operator!=(const ColourRGBA_8888& c1, const ColourABGR_8888& c2)  { return !(c1==c2); }
inline bool operator!=(const ColourRGBA_8888& c1, const ColourRGBA_8888& c2)  { return !(c1==c2); }
inline bool operator!=(const ColourRGBA_8888& c1, const ColourBGRA_8888& c2)  { return !(c1==c2); }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


inline bool operator==(const ColourBGRA_8888& c1, const ColourARGB_8888& c2)
{
  return c1.u32 == Machine::swap32(c2.u32);        // ARGB -> BGRA
}

inline bool operator==(const ColourBGRA_8888& c1, const ColourABGR_8888& c2)
{
  return c1.u32 == Machine::rotRight32<8>(c2.u32);  // ABGR -> BGRA
}

inline bool operator==(const ColourBGRA_8888& c1, const ColourRGBA_8888& c2)
{
  uint32 tmp = Machine::swap32(c2.u32);           // RGBA -> ABGR
  return c1.u32 == Machine::rotLeft32<8>(tmp);    // ABGR -> BGRA
}

inline bool operator==(const ColourBGRA_8888& c1, const ColourBGRA_8888& c2)
{
  return c1.u32 == c2.u32;
}

inline bool operator!=(const ColourBGRA_8888& c1, const ColourARGB_8888& c2)  { return !(c1==c2); }
inline bool operator!=(const ColourBGRA_8888& c1, const ColourABGR_8888& c2)  { return !(c1==c2); }
inline bool operator!=(const ColourBGRA_8888& c1, const ColourRGBA_8888& c2)  { return !(c1==c2); }
inline bool operator!=(const ColourBGRA_8888& c1, const ColourBGRA_8888& c2)  { return !(c1==c2); }

#endif
