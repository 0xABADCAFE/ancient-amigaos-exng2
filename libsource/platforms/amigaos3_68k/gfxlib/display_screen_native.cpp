///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/amigaos3_68k/gfxlib/display_screen_native.hpp
//  Tab Size:     2
//  Max Line:     120
//  Description:
//  Comment(s):
//  Library:      Graphics
//  Created:      2007-12-08
//  Updated:      2007-12-11
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <gfxlib/display.hpp>
#include <systemlib/memory.hpp>

#include <cstring>

namespace OSNative {
  extern "C" {
#   include <proto/graphics.h>
#   include <proto/cybergraphics.h>
#   include <clib/alib_protos.h>
  }
}

using namespace EXNGPrivate;
using namespace OSNative;

LOGGING_DECLARE_CLASSNAME(OSScreen)
LOGGING_DECLARE_CLASSNAME(OSScreenBuffered)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  OSScreen
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

OSScreen::OSScreen() :
  OSDisplay(),
  properties(0)
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

OSScreen::~OSScreen()
{
  closeDisplay();
  delete drawSurface;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool OSScreen::openDisplay(const Display::Properties* p)
{
  LOGGING_DECLARE_FUNCNAME(openDisplay)
  if (p && openFullscreen(p->getUniqueId())) {
    properties = p;
    setDisplayTitle(name, true);
    return true;
  }
  else {
    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::ERROR, "%s::%s - Unable to open display\n",
      loggingClassName, loggingFuncName
    );
    #endif
    return false;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool OSScreen::reopenDisplay()
{
  LOGGING_DECLARE_FUNCNAME(reopenDisplay)
  if (properties) {
    return openFullscreen(properties->getUniqueId());
  } else {
    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::ERROR, "%s::%s - Unable to (re)open display\n",
      loggingClassName, loggingFuncName
    );
    #endif
    return false;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void OSScreen::closeDisplay()
{
  SurfaceProvider::releaseSurface(drawSurface);
  closeFullscreen();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void OSScreen::bindSurface()
{
  LOGGING_DECLARE_FUNCNAME(bindSurface)
  if (!drawSurface) {
    drawSurface = SurfaceProvider::createNewSurfaceFromBitMap(window->RPort->BitMap);
  }
  else {
    SurfaceProvider::assignBitMapToSurface(drawSurface, window->RPort->BitMap);
  }
  SurfaceProvider::setWinUser(drawSurface, window);
  SurfaceProvider::setSurfacePalette(drawSurface, palette);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  OSScreenBuffered
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

OSScreenBuffered::OSScreenBuffered(bool triple) :
  OSScreen(),
  drawBuffer(0),
  flags(0)
{
  for (int i=0; i<3; ++i) {
    buffer[i] = 0;
  }
  if (triple) {
    flags |= SBF_TRIPLE_BUFFER;
  }
  allocatePorts();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

OSScreenBuffered::~OSScreenBuffered()
{
  closeDisplay();
  freePorts();
  delete drawSurface;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool OSScreenBuffered::allocatePorts()
{
  if ((vidSafePort = CreatePort(0, 0)) && (vidDispPort = CreatePort(0, 0))) {
    flags &= ~SBF_PORT_ERROR;
    return true;
  }
  flags |= SBF_PORT_ERROR;
  freePorts();
  return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void OSScreenBuffered::freePorts()
{
  if (vidDispPort) {
    DeletePort(vidDispPort);
    vidDispPort = 0;
  }
  if (vidSafePort) {
    DeletePort(vidSafePort);
    vidSafePort = 0;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool OSScreenBuffered::openDisplay(const Display::Properties* p)
{
  if (!(flags & SBF_PORT_ERROR)) {
    if (OSScreen::openDisplay(p)) {
      if (allocateBuffers()) {
        return true;
      }
      OSScreen::closeDisplay();
    }
  }
  return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool OSScreenBuffered::reopenDisplay()
{
  if (!(flags & SBF_PORT_ERROR)) {
    if (OSScreen::reopenDisplay()) {
      if (allocateBuffers()) {
        return true;
      }
      OSScreen::closeDisplay();
    }
  }
  return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool OSScreenBuffered::setTripleBuffered(bool state)
{
  LOGGING_DECLARE_FUNCNAME(setTripleBuffered)
  if (isAllocated()) {
    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::WARNING, "%s::%s - Attempted to change buffer count without closing screen\n",
      loggingClassName, loggingFuncName
    );
    #endif
    return false;
  }
  if (state) {
    flags |= SBF_TRIPLE_BUFFER;
  } else {
    flags &= ~SBF_TRIPLE_BUFFER;
  }
  return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void OSScreenBuffered::closeDisplay()
{
  SurfaceProvider::releaseSurface(drawSurface);
  freeBuffers();
  OSScreen::closeDisplay();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool OSScreenBuffered::allocateBuffers()
{
  LOGGING_DECLARE_FUNCNAME(allocateBuffers)

  do {
    // try to assign buffer[0] to the screen's BitMap
    if (!(buffer[0] = AllocScreenBuffer(screen, 0, SB_SCREEN_BITMAP))) {

      #ifdef EXNG2_BUILD_LOGGED
      SystemLog::write(
        SystemLog::ERROR, "%s::%s - Couldn't assign ScreenBuffer[0]\n",
        loggingClassName, loggingFuncName
      );
      #endif

      break;
    }

    // try to allocate secondary buffer
    if (!(buffer[1] = AllocScreenBuffer(screen, 0, 0))) {

      #ifdef EXNG2_BUILD_LOGGED
      SystemLog::write(
        SystemLog::ERROR, "%s::%s - Couldn't allocater ScreenBuffer[1]\n",
        loggingClassName, loggingFuncName
      );
      #endif

      break;
    }

    // try to allocate tertiarty buffer if requested, else fall back onto double buffering
    if (flags & SBF_TRIPLE_BUFFER && !(buffer[2] = AllocScreenBuffer(screen, 0, 0))) {
      flags &= ~SBF_TRIPLE_BUFFER;

      #ifdef EXNG2_BUILD_LOGGED
      SystemLog::write(
        SystemLog::WARNING, "%s::%s - Couldn't allocate ScreenBuffer[2], falling back to double-buffered mode\n",
        loggingClassName, loggingFuncName
      );
      #endif

    }

    // set up the buffer ports
    drawBuffer = 1;
    buffer[0]->sb_DBufInfo->dbi_DispMessage.mn_ReplyPort = vidDispPort;
    buffer[0]->sb_DBufInfo->dbi_SafeMessage.mn_ReplyPort = vidSafePort;
    buffer[1]->sb_DBufInfo->dbi_DispMessage.mn_ReplyPort = vidDispPort;
    buffer[1]->sb_DBufInfo->dbi_SafeMessage.mn_ReplyPort = vidSafePort;
    if (buffer[2]) {
      buffer[2]->sb_DBufInfo->dbi_DispMessage.mn_ReplyPort = vidDispPort;
      buffer[2]->sb_DBufInfo->dbi_SafeMessage.mn_ReplyPort = vidSafePort;
    }
    flags |= SBF_VID_DISP|SBF_VID_SAFE;
    return true;

  } while(0);

  freeBuffers();
  return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void OSScreenBuffered::freeBuffers()
{
  LOGGING_DECLARE_FUNCNAME(allocateBuffers)

  // discard any pending port messages
  sint32 m=0;
  if (!(flags & SBF_VID_SAFE)) {
    if (vidSafePort) {
      while(!GetMsg(vidSafePort)) {
        m++;
      }
    }

    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::INFO, "%s::%s - discarded %ld messages from vidSafePort\n",
      loggingClassName, loggingFuncName, m
    );
    #endif
  }
  if (!(flags & SBF_VID_DISP)) {
    m=0;
    if (vidDispPort) {
      while(!GetMsg(vidDispPort)) {
        m++;
      }
    }
    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::INFO, "%s::%s - discarded %ld messages from vidDispPort\n",
      loggingClassName, loggingFuncName, m
    );
    #endif
  }

  if (buffer[0]) {
    buffer[0]->sb_DBufInfo->dbi_SafeMessage.mn_ReplyPort = 0;
    while (!ChangeScreenBuffer(screen, buffer[0])) {
      ;
    }
    FreeScreenBuffer(screen, buffer[0]);
    buffer[0] = 0;
  }
  if (buffer[1]) {
    FreeScreenBuffer(screen, buffer[1]);
    buffer[1] = 0;
  }
  if (buffer[2]) {
    FreeScreenBuffer(screen, buffer[2]);
    buffer[2] = 0;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void OSScreenBuffered::flipBuffers()
{
  if (screen) {
    sint16 curBuf = drawBuffer;
    if (flags & SBF_TRIPLE_BUFFER) {
      if (++drawBuffer == 3) {
        drawBuffer = 0;
      }
    }
    else {
      drawBuffer ^=1;
    }
    buffer[curBuf]->sb_DBufInfo->dbi_SafeMessage.mn_ReplyPort = 0;

    // FIXME - proper double buffer switching seems to wait forever


//    if (ChangeScreenBuffer(scr, buffer[curBuf])!=0)
//      flags &= ~(NSB_VID_DISP|NSB_VID_SAFE);
//
//    if (!(flags & NSB_VID_SAFE)) {
//      while (!GetMsg(vidSafePort))
//        Wait(1<<vidSafePort->mp_SigBit);
//      flags |= NSB_VID_SAFE;
//    }

    while(!ChangeScreenBuffer(screen, buffer[curBuf])) {
      ;
    }
    SurfaceProvider::assignBitMapToSurfaceQuick(drawSurface, buffer[drawBuffer]->sb_BitMap);
  }
}

/*
void _NatScrBuff::refresh()
{
  if (scr) {
    sint32 curBuf = drawBuffer;
    if (flags & NSB_TRIPLE_BUFFER) {
      if (++drawBuffer == 3) {
        drawBuffer = 0;
      }
    }
    else {
      drawBuffer ^=1;
    }
    buffer[curBuf]->sb_DBufInfo->dbi_SafeMessage.mn_ReplyPort = 0;

    // FIXME - proper double buffer switching seems to wait forever


//    if (ChangeScreenBuffer(scr, buffer[curBuf])!=0)
//      flags &= ~(NSB_VID_DISP|NSB_VID_SAFE);
//
//    if (!(flags & NSB_VID_SAFE)) {
//      while (!GetMsg(vidSafePort))
//        Wait(1<<vidSafePort->mp_SigBit);
//      flags |= NSB_VID_SAFE;
//    }

    while(!ChangeScreenBuffer(scr, buffer[curBuf])) {
      ;
    }
    assignSurfaceQuick(drawSurface, buffer[drawBuffer]->sb_BitMap);

//    if (flags & NSB_CLONE_BUFFER)
//    {
//      BltBitMap(buffer[drawBuffer]->sb_BitMap, 0, 0,
//                buffer[curBuf]->sb_BitMap, 0, 0,
//                width, height, 0xC0, 0xFF, 0);
//    }

  }
}

void _NatScrBuff::waitSync()
{
  if (!(flags & NSB_VID_DISP)) {
    while (!GetMsg(vidDispPort)) {
      Wait(1<<vidDispPort->mp_SigBit);
    }
    flags |= NSB_VID_DISP;
  }
}
*/

void OSScreenBuffered::bindSurface()
{
  LOGGING_DECLARE_FUNCNAME(bindSurface)
  if (!drawSurface) {
    drawSurface = SurfaceProvider::createNewSurfaceFromBitMap(buffer[drawBuffer]->sb_BitMap);
  }
  else {
    SurfaceProvider::assignBitMapToSurface(drawSurface, buffer[drawBuffer]->sb_BitMap);
  }
  SurfaceProvider::setWinUser(drawSurface, window);
}
