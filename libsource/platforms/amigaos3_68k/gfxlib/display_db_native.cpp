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

#include <gfxlib/gfx.hpp>
#include <gfxlib/display.hpp>
#include <systemlib/memory.hpp>
#include <new>
#include <cstring>

namespace OSNative {
  extern "C" {
#   include <proto/graphics.h>
#   include <proto/cybergraphics.h>
#   include <clib/alib_protos.h>
#   include <cybergraphics/cybergraphics.h>
  }
}

using namespace EXNGPrivate;
using namespace OSNative;

LOGGING_DECLARE_CLASSNAME(DisplayDatabase)


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  DisplayDatabase
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const Display::Properties* DisplayDatabase::getWindowedMode()
{
  LOGGING_DECLARE_FUNCNAME(getWindowedMode)
  if (availableModes) {
    Screen* hostScreen;
    if ( (hostScreen = OSDisplay::lockHostDisplay()) ) {
      uint32 workbenchModeId = GetVPModeID(&(hostScreen->ViewPort));

      for (size_t i=0; i<numModes; ++i) {
        if (availableModes[i].getUniqueId() == workbenchModeId) {
          #ifdef EXNG2_BUILD_LOGGED
          SystemLog::write(
            SystemLog::INFO, "%s::%s matched host displaymode [0x%08X] as %s, windowed mode display available\n",
            loggingClassName, loggingFuncName,
            (unsigned)workbenchModeId,
            availableModes[i].getName()
          );
          #endif
          OSDisplay::unlockHostDisplay(hostScreen);
          return &availableModes[i];
        }
      }
      OSDisplay::unlockHostDisplay(hostScreen);

      #ifdef EXNG2_BUILD_LOGGED
      SystemLog::write(
        SystemLog::WARNING, "%s::%s unable to match Workbench displaymode [0x%08X] to amy known RTG mode, windowed display unavailable\n",
        loggingClassName, loggingFuncName,
        (unsigned)workbenchModeId
      );
      #endif
    }
    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::WARNING, "%s::%s unable to inspect  Workbench display, windowed display unavailable\n",
      loggingClassName, loggingFuncName
    );
    #endif
  }
  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool DisplayDatabase::createDatabase()
{
  LOGGING_DECLARE_FUNCNAME(createDatabase)

  if (!Display::Properties::modeList) {
    if ( !(Display::Properties::modeList = new(nothrow) ConstRefList<Display::Properties>()) ) {

      #ifdef EXNG2_BUILD_LOGGED
      SystemLog::write(
        SystemLog::ERROR, "%s::%s failed to initialise Display::Properties listt\n",
        loggingClassName, loggingFuncName
      );
      #endif

      return false;
    }
  } else {
    Display::Properties::modeList->clear();
  }

  ALIGNSTACKOBJ32(MonitorInfo, monInfo);

  List* cyberModeList = AllocCModeListTagList(0);
  if (!cyberModeList) {

    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::ERROR, "%s::%s failed to get cyrbergraphics display list\n",
      loggingClassName, loggingFuncName
    );
    #endif

    return false;
  }

  // count the number of modes present
  size_t numCyberModes = 0;
  Node* node;
  for (node = cyberModeList->lh_Head; node->ln_Succ; node = node->ln_Succ) {
    ++numCyberModes;
  }

  // allocate node list
  if (!allocPropertyNodes(numCyberModes)) {
    FreeCModeList(cyberModeList);

    #ifdef EXNG2_BUILD_LOGGED
    SystemLog::write(
      SystemLog::ERROR, "%s::%s unable to build cybergraphics display list\n",
      loggingClassName, loggingFuncName
    );
    #endif

    return false;
  }

  DisplayMode* displayMode = availableModes;

  for (node = cyberModeList->lh_Head; node->ln_Succ; node = node->ln_Succ, ++displayMode) {
    CyberModeNode*  cyberMode   = (CyberModeNode*)node;

    displayMode->setUniqueId(cyberMode->DisplayID);
    if (GetDisplayInfoData(
      0,
      (uint8*)&monInfo,
      sizeof(MonitorInfo),
      DTAG_MNTR,
      cyberMode->DisplayID
      ) >= offsetof(MonitorInfo, TotalColorClocks)
    ) {

      uint32 hNano  = (280*(uint32)monInfo.TotalColorClocks);
      uint32 vMicro = (280*(uint32)monInfo.TotalColorClocks*(uint32)monInfo.TotalRows)/1000;

      displayMode->setTiming(hNano, vMicro);
    }
    else {
      displayMode->setTiming(10000, 20000);
    }

    Pixel::FBType pixFmt = (Pixel::FBType)GfxResource::nativeToAbstract[GetCyberIDAttr(CYBRIDATTR_PIXFMT, cyberMode->DisplayID)];

    displayMode->setDimension(cyberMode->Width, cyberMode->Height);
    displayMode->setFormat(pixFmt, (Pixel::FBDepth)cyberMode->Depth);
    displayMode->setName(cyberMode->ModeText);

    // add to public Display::Properties list
    Display::Properties::modeList->pushBack(displayMode);
  }
  FreeCModeList(cyberModeList);
  return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void DisplayDatabase::freeDatabase()
{
  LOGGING_DECLARE_FUNCNAME(freeDatabase)

  if (Display::Properties::modeList) {
    delete Display::Properties::modeList;
    Display::Properties::modeList = 0;
  }
  freePropertyNodes();
}
