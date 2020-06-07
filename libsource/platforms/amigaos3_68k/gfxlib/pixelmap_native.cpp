///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         gfxlib/pixelmap_native.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:
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

#include <new>
#include <gfxlib/gfx.hpp>
#include <gfxlib/pixelmap.hpp>
#include <utilitylib/autoclean.hpp>
#include <systemlib/logger.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  DTObjectWrapper
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <gfxlib/pixelmap_native.hpp>
using namespace OSNative;

LOGGING_DECLARE_CLASSNAME(DTObjectWrapper)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DTObjectWrapper::DTObjectWrapper(const char* name) : dtObject(0)
{
  if (
    !(dtObject = NewDTObject(
      (char*)name,
      DTA_GroupID,      GID_PICTURE,
      PDTA_Remap,       FALSE,
      PDTA_DestMode,    PMODE_V43,
      //PDTA_SourceMode,  PMODE_V43,
      TAG_END
    ))
  ) {
    THROW_NSX(Error, ResourceUnavailable("DTObject"));
  }

  #ifdef EXNG2_BUILD_LOGGED
  SystemLog::write(
    SystemLog::INFO,
    "%s <constructor> allocated DTObject at %p for file '%s'\n",
    loggingClassName, dtObject, name
  );
  #endif
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

DTObjectWrapper::~DTObjectWrapper()
{
  if (dtObject) {
    DisposeDTObject(dtObject);
    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::INFO,
      "%s <denstructor> disposing DTObject\n",
      loggingClassName
    );
    #endif
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DTObjectWrapper::process()
{
  LOGGING_DECLARE_FUNCNAME(process)

  #ifdef EXNG2_BUILD_LOGGED
  SystemLog::write(
    SystemLog::INFO,
    "%s::%s - invoking DTM_PROCLAYOUT\n",
    loggingClassName, loggingFuncName
  );
  #endif
  DoMethod(dtObject, DTM_PROCLAYOUT, NULL, 1);

  #ifdef EXNG2_BUILD_LOGGED
  SystemLog::write(
    SystemLog::INFO,
    "%s::%s - invoking GetDTAttrs()\n",
    loggingClassName, loggingFuncName
  );
  #endif
  GetDTAttrs(
    dtObject,
    PDTA_BitMapHeader, &bmpHeader,
    PDTA_NumColors,    &numColours,
    PDTA_CRegs,        &colourMap,
    TAG_END
  );

  #ifdef EXNG2_BUILD_LOGGED
  SystemLog::write(
    SystemLog::INFO,
    "%s::%s - got: bmpHeader @ %p, numColours %" XPF_U32 ", colourMap @ %p\n",
    loggingClassName, loggingFuncName,
    bmpHeader,
    numColours,
    colourMap
  );
  #endif

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DTObjectWrapper::readPixelArray(uint32 cpyFmt, sint32 bpr, void* destData)
{
  LOGGING_DECLARE_FUNCNAME(readPixelArray)

  #ifdef EXNG2_BUILD_LOGGED
  SystemLog::write(
    SystemLog::INFO,
    "%s::%s - invoking %p.PDTM_READPIXELARRAY cpyFmt:%" XPF_U32 ", bpr:%" XPF_S32 ", dest:%p, w:%" XPF_S32 ", h:%" XPF_S32 "\n",
    loggingClassName, loggingFuncName,
    dtObject,
    cpyFmt,
    bpr,
    destData,
    getWidth(),
    getHeight()
  );
  #endif
  DoMethod(
    dtObject,
    PDTM_READPIXELARRAY,
    destData,
    cpyFmt,
    bpr,
    0, 0,
    getWidth(),
    getHeight()
  );
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  ImageLoader
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//LOGGING_DECLARE_CLASSNAME(ImageLoader)

ImageBuffer* ImageLoader::loadImage(const char* name, bool aligned=true)
{
  LOGGING_DECLARE_FUNCNAME(ImageLoader::loadImage)

  if (!name) {
    THROW_NSX(Error, NullPointer());
  }

  // Create a picture datatype instance from the supplied filename.
  // We are only bothered with the internal pixelarray data so we
  // just use v43 datatype only.

  DTObjectWrapper         dtObject(name);
  ImageBuffer*            ibResult = new ImageBuffer();

  #ifdef EXNG2_BUILD_LOGGED
  SystemLog::write(
    SystemLog::INFO,
    "%s - Allocated ImageBuffer @ %p\n",
    loggingFuncName,
    ibResult
  );
  #endif

  // if stuff throws later, we want to automatically delete this instance
  AutoDelete<ImageBuffer> ibCleaner(ibResult);

  uint32          cpyFmt;
  Pixel::FBType   dstFmt;
  sint32          dstBytesPerRow;
  uint32          createFlags = 0;

  dtObject.process();

  if (dtObject.getDepth()<=8) {
    dstFmt         = Pixel::LUT_8;
    cpyFmt         = PBPAFMT_LUT8;
    createFlags    = ImageBuffer::IB_CREATE_PALETTE;
    dstBytesPerRow = dtObject.getWidth();
  }
  else if (dtObject.getDepth()<=24 && aligned==false) {
    dstFmt  = Pixel::RGB_888;
    cpyFmt  = PBPAFMT_RGB;
    dstBytesPerRow = dtObject.getWidth()*3;
  }
  else {
    dstFmt  = Pixel::ARGB_8888;
    cpyFmt  = PBPAFMT_ARGB;
    dstBytesPerRow = dtObject.getWidth()*4;
  }

  ibResult->create(
    dtObject.getWidth(),
    dtObject.getHeight(),
    dstFmt,
    0,
    createFlags
  );

  dtObject.readPixelArray(cpyFmt, dstBytesPerRow, ibResult->lockData());
  ibResult->unlockData();

  const uint32* colourMap  = dtObject.getColourMap();
  Palette*      palette    = ibResult->getPalette();
  uint32        numColours = dtObject.getNumColours();

  if ((createFlags & ImageBuffer::IB_CREATE_PALETTE) && colourMap && palette) {
    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::INFO,
      "%s - transferring %" XPF_U32 " colours from colourMap @ %p to Palette @ %p\n",
      loggingFuncName,
      numColours,
      colourMap,
      palette
    );
    #endif
    for (uint32 i=0; i<numColours;i++) {
      (*palette)[i].red()   =(*(colourMap++)>>24);
      (*palette)[i].green() =(*(colourMap++)>>24);
      (*palette)[i].blue()  =(*(colourMap++)>>24);
    }
  }

  ibCleaner.set(0); // unbind the auto delete
  return ibResult;
}

