///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         gfxlib/surface_native.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Display classes
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

#ifndef _EXNG2_GFXLIB_PIXELMAP_NATIVE_HPP_
# define _EXNG2_GFXLIB_PIXELMAP_NATIVE_HPP_

namespace OSNative {
  extern "C" {
    #include <clib/alib_protos.h>
    #include <clib/dos_protos.h>
    #include <clib/datatypes_protos.h>
    #include <datatypes/pictureclass.h>
  }

  class DTObjectWrapper {

    LOGGING_DEFINE_CLASSNAME

    private:
      Object*         dtObject;
      BitMapHeader*   bmpHeader;
      uint32          numColours;
      uint32*         colourMap;

    public:
      void          process();
      void          readPixelArray(uint32 cpyFmt, sint32 bpr, void* dest);
      uint32        getNumColours()   const { return numColours; }
      const uint32* getColourMap()    const { return colourMap; }

      uint32        getWidth()        const { return bmpHeader->bmh_Width; }
      uint32        getHeight()       const { return bmpHeader->bmh_Height; }
      uint32        getDepth()        const { return bmpHeader->bmh_Depth; }

       DTObjectWrapper(const char* name);
      ~DTObjectWrapper();
  };
};

#endif
