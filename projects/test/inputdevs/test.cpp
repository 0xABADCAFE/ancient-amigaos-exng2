#include <xbase.hpp>
#include <systemlib/cpu.hpp>
#include <systemlib/logger.hpp>
#include <iolib/inputdevices.hpp>
#include <cstdio>


class TestDispatcher : public Key::Dispatcher {

	protected:
		void applyKeyEventFilter(uint32 mask);

	public:
		void		emitNonPrintable(Key::CtrlKey code, bool state)	{ dispatchKeyNonPrintable(code, state); }
		void		emitPrintable(sint32 ch, bool state)						{ dispatchKeyPrintable(ch, state); }

	public:
		TestDispatcher();
		~TestDispatcher();
};

void TestDispatcher::applyKeyEventFilter(uint32 mask)
{
	std::printf("Dispatcher: mask = 0x%08X\n", (unsigned)mask);
}

TestDispatcher::TestDispatcher() : Key::Dispatcher()
{

}

TestDispatcher::~TestDispatcher()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class TestObserver : public Key::Observer {
	public:
		void nonPrintablePressed(const Key::Dispatcher* d, Key::CtrlKey code);
		void nonPrintableReleased(const Key::Dispatcher* d, Key::CtrlKey code);
		void printablePressed(const Key::Dispatcher* d, sint32 ch);
		void printableReleased(const Key::Dispatcher* d, sint32 ch);
	public:
		TestObserver();
		~TestObserver();
};

void TestObserver::nonPrintablePressed(const Key::Dispatcher* d, Key::CtrlKey code)
{
	std::printf("Observer [%lu] : pressed nonprintable 0x%08X\n", getId(), (unsigned)code);
}

void TestObserver::nonPrintableReleased(const Key::Dispatcher* d, Key::CtrlKey code)
{
	std::printf("Observer [%lu] : released nonprintable 0x%08X\n", getId(), (unsigned)code);
}

void TestObserver::printablePressed(const Key::Dispatcher* d, sint32 ch)
{
	std::printf("Observer [%lu] : pressed printable %c\n", getId(), ch);
}

void TestObserver::printableReleased(const Key::Dispatcher* d, sint32 ch)
{
	std::printf("Observer [%lu] : released printable %c\n", getId(), ch);
}

TestObserver::TestObserver() : Key::Observer()
{

}

TestObserver::~TestObserver()
{

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class InputTestApp : public Application
{
	private:
		TestDispatcher*	dispatcher;
		TestObserver*		observer;
	public:
		sint32 run();

	public:
		InputTestApp();
		~InputTestApp();
};

Application* Application::createInstance()
{
	return new InputTestApp();
}

void Application::destroyInstance(Application* app)
{
	delete app;
}

InputTestApp::InputTestApp()
{
	dispatcher = new TestDispatcher();
	observer = new TestObserver[4];
}

InputTestApp::~InputTestApp()
{
	delete[] observer;
	delete dispatcher;
}

sint32 InputTestApp::run()
{
	for (int i=0; i<4; i++) {
		dispatcher->addObserver(&observer[i]);
	}
	dispatcher->emitPrintable('!', true);
	dispatcher->emitNonPrintable(Key::CTRL, true);
	dispatcher->emitPrintable('!', false);
	return 0;
}
