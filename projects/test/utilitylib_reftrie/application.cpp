///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         projects/test/reflist.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Thread class test
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
#include <systemlib/logger.hpp>
#include <iolib/streamio.hpp>
#include <utilitylib/referencetrie.hpp>
#include <cstdio>


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Main Application
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class RefTrieTestApp : public Application
{
  public:
    sint32  run();

  public:
    RefTrieTestApp();
    ~RefTrieTestApp();

  private:

};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Application* Application::createInstance()
{
  return new RefTrieTestApp();
}

void Application::destroyInstance(Application* app)
{
  delete app;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

RefTrieTestApp::RefTrieTestApp()
{
  SystemLog::write(SystemLog::INFO, "Created RefTrieTestApp\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

RefTrieTestApp::~RefTrieTestApp()
{
  SystemLog::write(SystemLog::INFO,"Destroyed RefTrieTestApp\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 RefTrieTestApp::run()
{
  if (getNumArgs()<=1) {
    std::printf(
      "Usage: %s -file <filename>\n",
      getArg(0)
    );
    return 0;
  }
  char buffer[256];
  buffer[255]=0;


  IO::Stream::In input;
  KeyRefTrie<const char*, Application> trie;

  input.open(getArgString("-file", 0, ARG_CASE_SENSITIVE));

  std::printf("Testing KeyRefTrie\n");

  sint32 n = 1000;
  sint32 s = 0;

  while ((s = input.readText(buffer, 255, '\n', 1)) && n--) {
    if (--s) {
      if (buffer[s]=='\n') {
        buffer[s]=0;
      }
      trie.addItem(buffer, this);
    }
    //std::printf("%s %d\n", buffer, s);
  }
  input.close();

  std::printf(
    "%u nodes allocated, max key length %u\n",
    (unsigned) trie.getNodeCount(),
    (unsigned) trie.getMaxKeyLen()
  );


/*
  std::printf("Testing KeyRefTrie<const char*, Application>\n");
  trie->addItem("thisthing", this);
  std::printf(
    "Total nodes allocated %u\n"
    "this:%p\n"
    "getItem(\"thisthing\"):%p\n"
    "getItem(\"anotherthing\"):%p\n",
    (unsigned) trie->getNodeCount(),
    this,
    trie->getItem("thisthing"),
    trie->getItem("anotherthing")
  );

  std::printf("\nTesting KeyRefTrie<uint16, Application>\n");
  trie2->addItem(0xBEEF, this);
  std::printf(
    "Total nodes allocated %u\n"
    "this:%p\n"
    "getItem(0xBEEF):%p\n"
    "getItem(0xF00D):%p\n",
    (unsigned) trie2->getNodeCount(),
    this,
    trie2->getItem(0xBEEF),
    trie2->getItem(0xF00D)
  );
*/
  return 0;
}


