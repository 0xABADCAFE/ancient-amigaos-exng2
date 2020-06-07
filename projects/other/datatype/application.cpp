///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         projects/blank_project/application.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Application wireframe
//  Comment(s):
//  Created:      2007-03-18
//  Updated:      2007-03-18
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <xbase.hpp>
//#include <systemlib/logger.hpp>
//#include <iolib/streamio.hpp>
//#include <cstdio>

namespace OSNative {
  extern "C" {
    #include <clib/alib_protos.h>
    #include <clib/dos_protos.h>
    #include <clib/datatypes_protos.h>
    #include <datatypes/pictureclass.h>
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Main Application
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class MainApplication : public Application
{
  public:
    sint32  run();

  public:
    MainApplication();
    ~MainApplication();

  private:

};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Application* Application::createInstance()
{
  return new MainApplication();
}

void Application::destroyInstance(Application* app)
{
  delete app;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

MainApplication::MainApplication()
{
  //SystemLog::write(SystemLog::INFO, "Created MainApplication\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

MainApplication::~MainApplication()
{
  //SystemLog::write(SystemLog::INFO,"Destroyed MainApplication\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 MainApplication::run()
{
  using namespace OSNative;

  const char* imagePath = getArgString("-src", 0, ARG_MANDATORY|ARG_CASE_SENSITIVE);

  // Create a picture datatype instance from the filename. We are only
  // concerned with obtaining the internal pixel array data so we need
  // to use v43 compliant image datatypes only.

  Object* src = NewDTObject(
    (char*)imagePath,
    DTA_GroupID, GID_PICTURE,
    PDTA_Remap, FALSE,
    PDTA_DestMode, PMODE_V43,
    TAG_END
  );

  if (src) {
    uint32  numColours;
    uint32* clrRegs;
  }

  return 0;
}


