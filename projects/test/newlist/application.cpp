
#include <xbase.hpp>
#include <systemlib/memory.hpp>
#include <systemlib/logger.hpp>
#include <systemlib/error.hpp>
#include <cstdio>

#include "reflist.hpp"

using namespace EXNGPrivate;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Test Application
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class NewListTestApp : public Application
{
	public:
		sint32 run();

	public:
		NewListTestApp();
		~NewListTestApp();
	private:
};

Application* Application::createInstance()
{
	return new NewListTestApp();
}

void Application::destroyInstance(Application* app)
{
	delete app;
}

NewListTestApp::NewListTestApp()
{
	SystemLog::write(SystemLog::INFO, "Created NewListTestApp\n");

}

NewListTestApp::~NewListTestApp()
{
	SystemLog::write(SystemLog::INFO,"Destroyed NewListTestApp\n");
}

sint32 NewListTestApp::run()
{
	static VLinkCache::VLinkNode* node[64];

	for (sint32 i=0; i<64; i++) {
		node[i] = VLinkCache::createLink();
		if (node[i]) {
			node[i]->item = this;
		}
		//if ((i%3)==0) {
			VLinkCache::destroyLink(node[i]);
		//}
	}
	return 0;
}
