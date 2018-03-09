///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         gfxlib/palette.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Range bound integer class
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

#include <gfxlib/palette.hpp>
#include <systemlib/logger.hpp>

#define CLAMP(val, min, max) (val<min ? min : (val>max ? max : val))

namespace {

  // contains x*x for x=0...255
  uint16 squares[256] = {
    0x0000,0x0001,0x0004,0x0009,0x0010,0x0019,0x0024,0x0031,0x0040,0x0051,0x0064,0x0079,0x0090,0x00A9,0x00C4,0x00E1,
    0x0100,0x0121,0x0144,0x0169,0x0190,0x01B9,0x01E4,0x0211,0x0240,0x0271,0x02A4,0x02D9,0x0310,0x0349,0x0384,0x03C1,
    0x0400,0x0441,0x0484,0x04C9,0x0510,0x0559,0x05A4,0x05F1,0x0640,0x0691,0x06E4,0x0739,0x0790,0x07E9,0x0844,0x08A1,
    0x0900,0x0961,0x09C4,0x0A29,0x0A90,0x0AF9,0x0B64,0x0BD1,0x0C40,0x0CB1,0x0D24,0x0D99,0x0E10,0x0E89,0x0F04,0x0F81,
    0x1000,0x1081,0x1104,0x1189,0x1210,0x1299,0x1324,0x13B1,0x1440,0x14D1,0x1564,0x15F9,0x1690,0x1729,0x17C4,0x1861,
    0x1900,0x19A1,0x1A44,0x1AE9,0x1B90,0x1C39,0x1CE4,0x1D91,0x1E40,0x1EF1,0x1FA4,0x2059,0x2110,0x21C9,0x2284,0x2341,
    0x2400,0x24C1,0x2584,0x2649,0x2710,0x27D9,0x28A4,0x2971,0x2A40,0x2B11,0x2BE4,0x2CB9,0x2D90,0x2E69,0x2F44,0x3021,
    0x3100,0x31E1,0x32C4,0x33A9,0x3490,0x3579,0x3664,0x3751,0x3840,0x3931,0x3A24,0x3B19,0x3C10,0x3D09,0x3E04,0x3F01,
    0x4000,0x4101,0x4204,0x4309,0x4410,0x4519,0x4624,0x4731,0x4840,0x4951,0x4A64,0x4B79,0x4C90,0x4DA9,0x4EC4,0x4FE1,
    0x5100,0x5221,0x5344,0x5469,0x5590,0x56B9,0x57E4,0x5911,0x5A40,0x5B71,0x5CA4,0x5DD9,0x5F10,0x6049,0x6184,0x62C1,
    0x6400,0x6541,0x6684,0x67C9,0x6910,0x6A59,0x6BA4,0x6CF1,0x6E40,0x6F91,0x70E4,0x7239,0x7390,0x74E9,0x7644,0x77A1,
    0x7900,0x7A61,0x7BC4,0x7D29,0x7E90,0x7FF9,0x8164,0x82D1,0x8440,0x85B1,0x8724,0x8899,0x8A10,0x8B89,0x8D04,0x8E81,
    0x9000,0x9181,0x9304,0x9489,0x9610,0x9799,0x9924,0x9AB1,0x9C40,0x9DD1,0x9F64,0xA0F9,0xA290,0xA429,0xA5C4,0xA761,
    0xA900,0xAAA1,0xAC44,0xADE9,0xAF90,0xB139,0xB2E4,0xB491,0xB640,0xB7F1,0xB9A4,0xBB59,0xBD10,0xBEC9,0xC084,0xC241,
    0xC400,0xC5C1,0xC784,0xC949,0xCB10,0xCCD9,0xCEA4,0xD071,0xD240,0xD411,0xD5E4,0xD7B9,0xD990,0xDB69,0xDD44,0xDF21,
    0xE100,0xE2E1,0xE4C4,0xE6A9,0xE890,0xEA79,0xEC64,0xEE51,0xF040,0xF231,0xF424,0xF619,0xF810,0xFA09,0xFC04,0xFE01
  };

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  void setRGB666(Colour32* data)
  {
    uint32 red  = 0;
    int    r    = 6;
    while (r--) {
      uint32 green  = 0;
      int    g      = 6;
      while (g--) {
        uint32 blue   = 0;
        int    b      = 6;
        while (b--) {
          data->alpha() = 0xFF;
          data->red()   = red;
          data->green() = green;
          data->blue()  = blue;
          ++data;
          blue += 0x33;
        }
        green += 0x33;
      }
      red += 0x33;
    }
    // fill the remaining 40 indexes with some higher definition grey and primary shades, giving a total of 16 shades each for pure red/green/blue/grey

    // red 0x11/22/44/55/77/88/AA/BB/DD/EE
    uint32 start    = 0xFF000000;
    uint32 val      = start;
    uint32 step     = 0x00110000;
    r   = 5;
    while (r--) {
      *data++ = (val += step);
      *data++ = (val += step);
      val += step;
    }

    // green 0x11/22/44/55/77/88/AA/BB/DD/EE
    val     = start;
    step    = 0x00001100;
    r   = 5;
    while (r--) {
      *data++ = (val += step);
      *data++ = (val += step);
      val += step;
    }

    // blue 0x11/22/44/55/77/88/AA/BB/DD/EE
    val     = start;
    step    = 0x00000011;
    r   = 5;
    while (r--) {
      *data++ = (val += step);
      *data++ = (val += step);
      val += step;
    }
    // grey 0x11/22/44/55/77/88/AA/BB/DD/EE
    val     = start;
    step    = 0x00111111;
    r   = 5;
    while (r--) {
      *data++ = (val += step);
      *data++ = (val += step);
      val += step;
    }
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  void setRGB676(Colour32* data)
  {
    uint32 red  = 0;
    int    r    = 6;
    while (r--) {
      uint32 green  = 0;
      int    g      = 7;
      while (g--) {
        uint32 blue   = 0;
        int    b      = 6;
        while (b--) {
          data->alpha() = 0xFF;
          data->red()   = red;
          data->green() = (green>>8);
          data->blue()  = blue;
          ++data;
          blue += 0x33;
        }
        green += 0x2AAA;
      }
      red += 0x33;
    }
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  void setRGB775(Colour32* data)
  {
    uint32 s    = 0x2AAA;
    uint32 red  = 0;
    int    r    = 7;
    while (r--) {
      uint32 green  = 0;
      int    g      = 7;
      while (g--) {
        uint32 blue   = 0;
        int    b      = 5;
        while (b--) {
          data->alpha() = 0xFF;
          data->red()   = (red>>8);
          data->green() = (green>>8);
          data->blue()  = (blue>>8);
          ++data;
          blue += 0x3FFF;
        }
        green += s;
      }
      red += s;
    }
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  void setRGB884(Colour32* data)
  {
    uint32 s    = 0x1FFF;
    uint32 red  = 0;
    int    r    = 8;
    while (r--) {
      uint32 green  = 0;
      int    g      = 8;
      while (g--) {
        uint32 blue   = 0;
        int    b      = 4;
        while (b--) {
          data->alpha() = 0xFF;
          data->red()   = (red>>8);
          data->green() = (green>>8);
          data->blue()  = (blue>>8);
          ++data;
          blue += 0x5555;
        }
        green += s;
      }
      red += s;
    }
  }

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  void setGrey(Colour32* data)
  {
    uint32 grey = 0xFF000000UL;
    int g       = 256;
    while (g--) {
      *data++ = grey;
      grey += 0x00010101UL;
    }
  }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Palette* Palette::presets[Palette::PAL_CUSTOM] = { 0 };

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Palette::scaleAlpha(float32 scf, sint8 ofs, uint8 min, uint8 max)
{
  Colour32* c = data;
  sint32 t, n = 65;
  while (--n) {
    t = (sint32)(scf*c->alpha())+ofs; (c++)->alpha()=CLAMP(t, min, max);
    t = (sint32)(scf*c->alpha())+ofs; (c++)->alpha()=CLAMP(t, min, max);
    t = (sint32)(scf*c->alpha())+ofs; (c++)->alpha()=CLAMP(t, min, max);
    t = (sint32)(scf*c->alpha())+ofs; (c++)->alpha()=CLAMP(t, min, max);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Palette::scaleRed(float32 scf, sint8 ofs, uint8 min, uint8 max)
{
  Colour32* c = data;
  sint32 t, n = 65;
  while (--n) {
    t = (sint32)(scf*c->red())+ofs; (c++)->red()=CLAMP(t, min, max);
    t = (sint32)(scf*c->red())+ofs; (c++)->red()=CLAMP(t, min, max);
    t = (sint32)(scf*c->red())+ofs; (c++)->red()=CLAMP(t, min, max);
    t = (sint32)(scf*c->red())+ofs; (c++)->red()=CLAMP(t, min, max);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Palette::scaleGreen(float32 scf, sint8 ofs, uint8 min, uint8 max)
{
  Colour32* c = data;
  sint32 t, n = 65;
  while (--n) {
    t = (sint32)(scf*c->green())+ofs; (c++)->green()=CLAMP(t, min, max);
    t = (sint32)(scf*c->green())+ofs; (c++)->green()=CLAMP(t, min, max);
    t = (sint32)(scf*c->green())+ofs; (c++)->green()=CLAMP(t, min, max);
    t = (sint32)(scf*c->green())+ofs; (c++)->green()=CLAMP(t, min, max);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Palette::scaleBlue(float32 scf, sint8 ofs, uint8 min, uint8 max)
{
  Colour32* c = data;
  sint32 t, n = 65;
  while (--n) {
    t = (sint32)(scf*c->blue())+ofs; (c++)->blue()=CLAMP(t, min, max);
    t = (sint32)(scf*c->blue())+ofs; (c++)->blue()=CLAMP(t, min, max);
    t = (sint32)(scf*c->blue())+ofs; (c++)->blue()=CLAMP(t, min, max);
    t = (sint32)(scf*c->blue())+ofs; (c++)->blue()=CLAMP(t, min, max);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
typedef struct {
   unsigned char r, g, b;
} RGB;

double ColourDistance(RGB e1, RGB e2)
{
  long rmean = ( (long)e1.r + (long)e2.r ) / 2;
  long r = (long)e1.r - (long)e2.r;
  long g = (long)e1.g - (long)e2.g;
  long b = (long)e1.b - (long)e2.b;
  return sqrt((((512+rmean)*r*r)>>8) + 4*g*g + (((767-rmean)*b*b)>>8));
}
*/
size_t Palette::findBestMatch(Colour32 c, bool ignoreAlpha) const
{
  sint32 minDistSqrd = 0x7FFFFFFF;
  sint32 distSqrd    = minDistSqrd;
  size_t best        = 0;
  sint32 deltaAlpha, deltaRed, deltaGreen, deltaBlue, rMean;

  for (int i=0; i<256; i++) {
    deltaRed    =  c.red();   deltaRed    -= data[i].red();   deltaRed*=deltaRed;
    deltaGreen  =  c.green(); deltaGreen  -= data[i].green(); deltaGreen*=deltaGreen;
    deltaBlue   =  c.blue();  deltaBlue   -= data[i].blue();  deltaBlue*=deltaBlue;

    distSqrd = (deltaRed<<1) + (deltaGreen<<2) + (deltaBlue);

    if (distSqrd < minDistSqrd) {
      best = i;
      if (!(minDistSqrd = distSqrd)) {
        // zero distSqrd implies exact match
        break;
      }
    }
  }
  return best;

//   for (int i=0; i<256; i++) {
//     rMean = (c.red() + data[i].red())>>1;
//
//     int tmp;
//
//     if ((tmp = (int)c.red() - (int)data[i].red())<0) {
//       deltaRed = squares[-tmp];
//     } else {
//       deltaRed = squares[tmp];
//     }
//
//     if ((tmp = (int)c.green() - (int)data[i].green())<0) {
//       deltaGreen = squares[-tmp];
//     } else {
//       deltaGreen = squares[tmp];
//     }
//
//     if ((tmp = (int)c.blue() - (int)data[i].blue())<0) {
//       deltaBlue = squares[-tmp];
//     } else {
//       deltaBlue = squares[tmp];
//     }
//
//     distSqrd    = (((512+rMean)*deltaRed)>>8) + (deltaGreen<<2) + (((767-rMean)*deltaBlue)>>8);
//     if (distSqrd < minDistSqrd) {
//       best = i;
//       if (!(minDistSqrd = distSqrd)) {
//         // zero distSqrd implies exact match
//         break;
//       }
//     }
//   }
//   return best;

//   if (ignoreAlpha) {
//     for (int i=0; i<256; i++) {
//       rMean = (c.red() + data[i].red())>>1;
//
//       deltaRed    = (sint16)c.red()     - (sint16)data[i].red();    deltaRed    *= deltaRed;
//       deltaGreen  = (sint16)c.green()   - (sint16)data[i].green();  deltaGreen  *= deltaGreen;
//       deltaBlue   = (sint16)c.blue()    - (sint16)data[i].blue();   deltaBlue   *= deltaBlue;
//       distSqrd    = (((512+rMean)*deltaRed)>>8) + (deltaGreen<<2) + (((767-rMean)*deltaBlue)>>8);
//       if (distSqrd < minDistSqrd) {
//         best = i;
//         if (!(minDistSqrd = distSqrd)) {
//           // zero distSqrd implies exact match
//           break;
//         }
//       }
//     }
//     return best;
//   }
//   else {
//     for (int i=0; i<256; i++) {
//       deltaAlpha  = (sint16)c.alpha()   - (sint16)data[i].alpha();  deltaAlpha  *= deltaAlpha;
//       deltaRed    = (sint16)c.red()     - (sint16)data[i].red();    deltaRed    *= deltaRed;
//       deltaGreen  = (sint16)c.green()   - (sint16)data[i].green();  deltaGreen  *= deltaGreen;
//       deltaBlue   = (sint16)c.blue()    - (sint16)data[i].blue();   deltaBlue   *= deltaBlue;
//       distSqrd    = deltaAlpha + deltaRed + deltaGreen + deltaBlue;
//       if (distSqrd < minDistSqrd) {
//         best = i;
//         if (!(minDistSqrd = distSqrd)) {
//           // zero distSqrd implies exact match
//           break;
//         }
//       }
//     }
//   }
//   return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const Palette* Palette::getPresetPalette(Preset p)
{
  if (p>PAL_GREY) {
    THROW_NSX(Error, Range());
  }
  Palette* result = 0;
  if (!(result = presets[p])) {
    presets[p] = result = new Palette(p);

    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::INFO,
      "Palette::getPresetPalette() - created shared instance for enum %d at %p\n",
      (int)p,
      result
    );
    #endif

  }
  return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Palette::setPreset(Preset p)
{
  switch (p) {
    case PAL_FAKERGB_666: setRGB666(data);    break;
    case PAL_FAKERGB_676: setRGB676(data);    break;
    case PAL_FAKERGB_775: setRGB775(data);    break;
    case PAL_FAKERGB_884: setRGB884(data);    break;
    case PAL_GREY:        setGrey(data);      break;
    default:
      break;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Palette::done()
{
  for (int i=0;i<PAL_GREY; i++) {
    if (presets[i]) {
      delete presets[i];
      presets[i] = 0;

    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::INFO,
      "Palette::done() - destroyed shared instance for enum %d\n",
      i
    );
    #endif


    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
