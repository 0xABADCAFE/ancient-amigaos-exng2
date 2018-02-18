///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  File:         projects/test/thread.cpp
//  Tab Size:     2
//  Max Line:     120
//  Description:  Thread class test
//  Comment(s):
//  Created:      2007-03-18
//  Updated:      2007-03-18
//  Author(s):    Karl Churchill
//  Note(s):
//  Copyright:    (C)2006+, eXtropia Studios
//                Karl Churchill, Serkan YAZICI
//                All Rights Reserved.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <xbase.hpp>
#include <systemlib/logger.hpp>
#include <systemlib/reflist.hpp>
#include <cstdio>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Main Application
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class RefListTestApp : public Application
{
	public:
		sint32	run();

	public:
		RefListTestApp();
		~RefListTestApp();

	private:
		RefList<uint8>* list;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Application* Application::createInstance()
{
	return new RefListTestApp();
}

void Application::destroyInstance(Application* app)
{
	delete app;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

RefListTestApp::RefListTestApp()
{
	list = new RefList<uint8>();
	SystemLog::write(SystemLog::INFO, "Created RefListTestApp\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

RefListTestApp::~RefListTestApp()
{
	delete list;
	SystemLog::write(SystemLog::INFO,"Destroyed RefListTestApp\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 RefListTestApp::run()
{
	std::printf("sizeof(RefList<uint8>) = %d\n", sizeof(RefList<uint8>));
	std::printf("sizeof(RefListFwdIterator<uint8>) = %d\n", sizeof(RefListFwdIterator<uint8>));
	std::printf("sizeof(RefListEevIterator<uint8>) = %d\n", sizeof(RefListRevIterator<uint8>));
	if (list) {
		for (sint32 i=0; i<16; i++) {
			list->pushBack((uint8*)(0xF00D0000|i));
		}

		// test forwards
		{
			RefListFwdIterator<uint8> itor(*list);
			std::puts("Created forward iterator\n");
			for (uint8* p = itor.first(); p; p = itor.next()) {
				std::printf("0x%08X\n", (unsigned)p);
			}
		}

		// test reverse
		{
			RefListRevIterator<uint8> itor(*list);
			std::puts("Created reverse iterator\n");
			for (uint8* p = itor.first(); p; p = itor.next()) {
				std::printf("0x%08X\n", (unsigned)p);
			}
		}
	}
	return 0;
}


