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

  return 0;
}

