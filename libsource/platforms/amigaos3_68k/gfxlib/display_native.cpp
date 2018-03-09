///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         platforms/amigaos3_68k/gfxlib/display_native.hpp
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

#include <new>
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
void OSDisplay::AmigaPalette::setGrey()
{
  uint32 grey = 0;
  Entry* p    = data;
  int g       = 256;
  while (g--) {
    p->blue = p->green = p->red = grey;
    ++p;
    grey += 0x01010101UL;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void OSDisplay::AmigaPalette::setRGB666()
{
  Entry* p    = data;
  uint32 s    = 0x33333333UL;
  uint32 red  = 0;
  int    r    = 6;
  while (r--) {
    uint32 green  = 0;
    int    g      = 6;
    while (g--) {
      uint32 blue   = 0;
      int    b      = 6;
      while (b--) {
        p->red    = red;
        p->green  = green;
        p->blue   = blue;
        ++p;
        blue += s;
      }
      green += s;
    }
    red += s;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void OSDisplay::AmigaPalette::setRGB676()
{
  Entry* p    = data;
  uint32 s    = 0x33333333UL;
  uint32 red  = 0;
  int    r    = 6;
  while (r--) {
    uint32 green  = 0;
    int    g      = 7;
    while (g--) {
      uint32 blue   = 0;
      int    b      = 6;
      while (b--) {
        p->red    = red;
        p->green  = green;
        p->blue   = blue;
        ++p;
        blue += s;
      }
      green += 0x2AAAAAAAUL;
    }
    red += s;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void OSDisplay::AmigaPalette::setRGB775()
{
  Entry* p    = data;
  uint32 s    = 0x2AAAAAAAUL;
  uint32 red  = 0;
  int    r    = 7;
  while (r--) {
    uint32 green  = 0;
    int    g      = 7;
    while (g--) {
      uint32 blue   = 0;
      int    b      = 5;
      while (b--) {
        p->red    = red;
        p->green  = green;
        p->blue   = blue;
        ++p;
        blue += 0x3FFFFFFFUL;
      }
      green += s;
    }
    red += s;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void OSDisplay::AmigaPalette::setRGB884()
{
  Entry* p    = data;
  uint32 s    = 0x1FFFFFFFUL;
  uint32 red  = 0;
  int    r    = 8;
  while (r--) {
    uint32 green  = 0;
    int    g      = 8;
    while (g--) {
      uint32 blue   = 0;
      int    b      = 4;
      while (b--) {
        p->red    = red;
        p->green  = green;
        p->blue   = blue;
        ++p;
        blue += 0x55555555UL;
      }
      green += s;
    }
    red += s;
  }
}*/


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void OSDisplay::AmigaPalette::setCustom(const Palette* p)
{
  Entry*    d = data;
  const Colour32* c = p->getTable();
  int i= 256;
  while (i--) {
    d->red    = c->red()<<24;
    d->green  = c->green()<<24;
    d->blue   = c->blue()<<24;
    ++d;
    ++c;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  OSDisplay
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LOGGING_DECLARE_CLASSNAME(OSDisplay)

uint32 OSDisplay::hostLockCount = 0;

OSDisplay::OSDisplay() :
  drawSurface(0),
  screen(0),
  window(0),
  palette(0),
  viewPalette(0)
{
  name[0] = 0;
  initDispatcher();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

OSDisplay::~OSDisplay()
{
  finalizeDispatcher();
  delete viewPalette;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


Screen* OSDisplay::lockHostDisplay()
{
  LOGGING_DECLARE_FUNCNAME(lockHostDisplay)

  static const char* pubScreen = Application::getArgString("-amiga_pubscreen", 0, Application::ARG_CASE_SENSITIVE);
  Screen* res = LockPubScreen(pubScreen);
  if (res) {
    ++hostLockCount;

    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::INFO, "%s::%s - locked screen\n",
      loggingClassName, loggingFuncName
    );
    #endif

  }
  #ifdef EXNG2_BUILD_LOGGED
  else {
    SystemLog::write(
      SystemLog::WARNING, "%s::%s - Unable to lock host screen\n",
      loggingClassName, loggingFuncName
    );
  }
  #endif
  return res;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void OSDisplay::unlockHostDisplay(Screen* screen)
{
  LOGGING_DECLARE_FUNCNAME(unlockHostDisplay)

  if (screen) {
    UnlockPubScreen(0, screen);
    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::INFO, "%s::%s - unlocked screen\n",
      loggingClassName, loggingFuncName
    );
    #endif
    if (hostLockCount>0) {
      --hostLockCount;
    }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void OSDisplay::setPalette(const Palette* p)
{
  LOGGING_DECLARE_FUNCNAME(setPalette)

  if (!p) {
    THROW_NSX(Error, NullPointer());
  }
  if (!viewPalette && !(viewPalette = new(nothrow) AmigaPalette())) {
    THROW_NSX(Mem, Exhausted(sizeof(AmigaPalette)));
  }
  palette = p;
  viewPalette->setCustom(p);

  if (drawSurface) {
    SurfaceProvider::setSurfacePalette(drawSurface, palette);
  }

  #ifdef EXNG2_BUILD_LOGGED
  SystemLog::write(
    SystemLog::INFO, "%s::%s - Attached Palette instance at %p\n",
    loggingClassName, loggingFuncName, p
  );
  #endif

//   if (ip==Display::IPAL_CUSTOM && p==0) {
//     THROW_NSX(Error, NullPointer());
//   }
//   if (!viewPalette && !(viewPalette = new(nothrow) AmigaPalette())) {
//     THROW_NSX(Mem, Exhausted(sizeof(AmigaPalette)));
//   }
//   switch (ip) {
//     case Display::IPAL_FAKERGB_666: viewPalette->setRGB666();     break;
//     case Display::IPAL_FAKERGB_676: viewPalette->setRGB676();     break;
//     case Display::IPAL_FAKERGB_775: viewPalette->setRGB775();     break;
//     case Display::IPAL_FAKERGB_884: viewPalette->setRGB884();     break;
//     case Display::IPAL_GREY:        viewPalette->setGrey();       break;
//     case Display::IPAL_CUSTOM:      viewPalette->setCustom(p);    break;
//       break;
//     default:
//       #ifdef EXNG2_BUILD_LOGGED
//       SystemLog::write(
//         SystemLog::WARNING, "%s::%s - unexpected IndexedPalette enum value %d\n",
//         loggingClassName, loggingFuncName,
//         (int)ip
//       );
//       #endif
//       break;
//   }

//   printf("%08X [%d]\n", viewPalette->info, (int)sizeof(AmigaPalette));
//   for (int i=0;i<256;i++) {
//     std::printf(
//       "%3d:%08X %08X %08X\n",
//       i,
//       viewPalette->data[i].red,
//       viewPalette->data[i].green,
//       viewPalette->data[i].blue
//     );
//   }

  if (screen) {
    LoadRGB32(&(screen->ViewPort), (uint32*)viewPalette);
//     if (screen->ViewPort.ColorMap) {
//       printf("ColorMap.Count=%d\n",(int)(screen->ViewPort.ColorMap->Count));
//     }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void OSDisplay::waitSync()
{
  if (screen) {
    WaitBOVP(&(screen->ViewPort));
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool OSDisplay::openFullscreen(uint32 modeId)
{
  LOGGING_DECLARE_FUNCNAME(openFullscreen)

  do {
    // check screen not already open
    if (screen) {
      #ifdef EXNG2_BUILD_LOGGED
      SystemLog::write(
        SystemLog::WARNING, "%s::%s - Screen already open\n",
        loggingClassName, loggingFuncName, (unsigned)modeId
      );
      #endif
      break;
    }

    // try to open screen
    if (!(screen = OpenScreenTags(0,
      SA_Depth,     8L,
      SA_DisplayID, modeId,
      SA_ShowTitle, false,
      SA_Draggable, false,
      SA_SharePens, true,
      SA_Title,     (uint32)name,
      TAG_DONE))
    ) {

      #ifdef EXNG2_BUILD_LOGGED
      SystemLog::write(
        SystemLog::ERROR, "%s::%s - Failed to open screen [mode:%0x08X]\n",
        loggingClassName, loggingFuncName, (unsigned)modeId
      );
      #endif

      break;
    }

    // try to allocate window
    if (!(window = OpenWindowTags(0,
      WA_CustomScreen,  (uint32)screen,
      WA_Width,         (uint32)screen->Width,
      WA_Height,        (uint32)screen->Height,
      WA_Left,          0,
      WA_Top,           0,
      WA_Title,         0,
      WA_Flags,         WFLG_ACTIVATE|WFLG_BORDERLESS|WFLG_BACKDROP|
                        WFLG_REPORTMOUSE|WFLG_RMBTRAP,
      TAG_DONE))
    ) {

      #ifdef EXNG2_BUILD_LOGGED
      SystemLog::write(
        SystemLog::ERROR, "%s::%s - Failed to create window\n",
        loggingClassName, loggingFuncName
      );
      #endif

      CloseScreen(screen);
      screen = 0;
      break;
    }

    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::INFO, "%s::%s - Opened screen [mode:0x%08X]\n",
      loggingClassName, loggingFuncName, (unsigned)modeId
    );
    #endif

    return true;
  } while (0);
  return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void OSDisplay::closeFullscreen()
{
  LOGGING_DECLARE_FUNCNAME(closeFullscreen)
  if (screen) {
    if (window)   {
      CloseWindow(window);
      window = 0;
    }
    CloseScreen(screen);
    screen = 0;
    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::INFO, "%s::%s - Closed screen\n",
      loggingClassName, loggingFuncName
    );
    #endif
  } else {
    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::WARNING, "%s::%s - Screen already closed\n",
      loggingClassName, loggingFuncName
    );
    #endif
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool OSDisplay::openWindowed(sint16 x, sint16 y, sint16 w, sint16 h, uint32 flags)
{
  LOGGING_DECLARE_FUNCNAME(openWindowed)

  do {
    if (!screen) {
      #ifdef EXNG2_BUILD_LOGGED
      SystemLog::write(
        SystemLog::WARNING, "%s::%s - Screen not locked\n",
        loggingClassName, loggingFuncName
      );
      #endif
      break;
    }
    if (window) {
      #ifdef EXNG2_BUILD_LOGGED
      SystemLog::write(
        SystemLog::WARNING, "%s::%s - Display already open\n",
        loggingClassName, loggingFuncName
      );
      #endif
      break;
    }

    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::INFO, "%s::%s - Requesting window with flags 0x%08X\n",
      loggingClassName, loggingFuncName, (unsigned)flags
    );
    #endif

    window = OpenWindowTags(0,
      WA_PubScreen,   (uint32)screen,
      WA_InnerWidth,  (uint32)w,
      WA_InnerHeight, (uint32)h,
      WA_Left,        x,
      WA_Top,         y,
      WA_Title,       (uint32)name,
      WA_DepthGadget, true,
      WA_Flags,       flags,
      TAG_DONE
    );

    if (!window) {
      #ifdef EXNG2_BUILD_LOGGED
      SystemLog::write(
        SystemLog::WARNING, "%s::%s - Couldn't open window\n",
        loggingClassName, loggingFuncName
      );
      #endif
      break;
    }

    return true;
  } while (0);

  return false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void OSDisplay::closeWindowed()
{
  if (window) {
    CloseWindow(window);
    window = 0;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void OSDisplay::setDisplayTitle(const char* title, bool fullscreen)
{
  if (title) {
    strncpy(name, title, MAX_TITLE_LENGTH);
  }
  if (fullscreen && screen!=0) {
    SetWindowTitles(window, (char*)(0xFFFFFFFFUL), name);
  }
  else if (window!=0) {
    SetWindowTitles(window, name, (char*)(0xFFFFFFFFUL));
  }
}
