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
#include <systemlib/thread.hpp>
#include <private/systemlib/error.hpp>
#include <cstdlib>
#include <cstdio>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  MyThread - basic extension of Thread. The alternative method is to bind a standard Thread to a Runnable instance
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class MyThread : public Thread, public ThreadRunObserver {
	public:
		MyThread();
		~MyThread();

		void setTrap() { boobyTrap = true; }
		void notifyReturned(Thread* thread, sint32 retVal);
		void notifyThrown(Thread* thread, const RuntimeError* error);

	protected:
		sint32	run();

	private:
		std::FILE*	file;
		int					dummy;
		int					zero;
		bool				boobyTrap;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

MyThread::MyThread() : Thread(PRI_NORMAL, 4096), dummy(2), zero(0), boobyTrap(false)
{
	file = std::fopen("CON:32/32/640/240/MyThread/CLOSE/WAIT", "w");
	if (file) {
		std::fprintf(file, "This console is used by the created thread for output\n");
		std::fflush(file);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

MyThread::~MyThread()
{
	if (hasStarted()) {
		stop();
	}
	if (file) {
		std::fprintf(file, "\nBye!\n");
		std::fclose(file);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 MyThread::run()
{
	// bind observer to self
	setRunObserver(this);

	if (!file) {
		EXNGPrivate::throwNullPointer();
	}

	std::fprintf(file, "MyThread::run() invoked OK\n");
	std::fflush(file);
	// turn on low level exception handling
	enableLowLevelExceptions();


	while (!stopRequested()) {
		std::fprintf(file, "Sleeping for 2000ms...");
		std::fflush(file);
		switch (suspend(2000, SLEEP_IGNORE_UNKNOWN|SLEEP_DISPOSE_TIMEOUT)) {
			case Thread::WAKE_TIMEOUT:
				std::fprintf(file, "OK\n");
				break;
			case Thread::WAKE_WAKE:
				std::fprintf(file, "interrupted by wake()\n");
				break;
			case Thread::WAKE_STOP:
				std::fprintf(file, "interrupted by stop()\n");
				break;
			case Thread::WAKE_SYSBREAK:
				std::fprintf(file, "interrupted by system break\n");
				break;
			case Thread::WAKE_USER:
				std::fprintf(file, "interrupted by user signal\n");
				break;
			case Thread::WAKE_SHUTDOWN:
				std::fprintf(file, "interrupted by ~Thread()\n");
				break;
			case Thread::WAKE_UNKNOWN:
				std::fprintf(file, "interrupted by unknown\n");
				break;
			default:
				break;
		}
		std::fflush(file);

		if (boobyTrap) {
			boobyTrap = false;
			dummy /= zero;
		}

	}
	std::fprintf(file, "\nMyThread::run() completed\n");
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MyThread::notifyReturned(Thread* thread, sint32 retVal)
{
	SystemLog::write(
		SystemLog::INFO,
		"*** Observer: Thread %s returned %d\n",
		thread->getResourceName(),
		retVal
	);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MyThread::notifyThrown(Thread* thread, const RuntimeError* error)
{
	SystemLog::write(
		SystemLog::INFO,
		"*** Observer: Thread %s threw uncaught %s\n",
		thread->getResourceName(),
		(error ? error->getClass() : "exception")
	);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Main Application
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ThreadTestApp : public Application
{
	public:
		sint32	run();

	public:
		ThreadTestApp();
		~ThreadTestApp();

	private:
		void				showUptime();

		MyThread*		thread;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Application* Application::createInstance()
{
	return new ThreadTestApp();
}

void Application::destroyInstance(Application* app)
{
	delete app;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ThreadTestApp::ThreadTestApp() : thread()
{
	thread = new MyThread();
	SystemLog::write(SystemLog::INFO, "Created ThreadTestApp\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ThreadTestApp::~ThreadTestApp()
{
	Interval t = Thread::getCurrent()->getUptime();
	std::printf(
		"Main Program Uptime:%3lu days %02lu hours %02lu mins %02lu secs %03lu millis\n",
		t.days(), t.hours(), t.mins(), t.secs(), t.millisecs()
	);

	delete thread;

	SystemLog::write(SystemLog::INFO,"Destroyed ThreadTestApp\n");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

sint32 ThreadTestApp::run()
{
	if (!thread) {
		EXNGPrivate::throwNullPointer();
	}
	std::printf(
		"\nCreated Thread %s, child of %s\n\n",
		thread->getResourceName(),
		thread->getParent()->getResourceName()
	);

	std::puts("Choose method\n1 start()\n2 stop()\n3 wake()\n4 getUpTime()\n5 set boobytrap\nQ Quit");

	bool quit = false;
	while (!quit) {
		try {
			switch (std::getchar()) {
				case '1':		thread->start();		break;
				case '2':		thread->stop();			break;
				case '3':		thread->wake();			break;
				case '4':		showUptime();				break;
				case '5':		thread->setTrap();	break;
				case 'q':
				case 'Q':		quit = true;			break;

				default:
					break;
			}
		}
		catch (RuntimeError& e) {
			std::printf("Unable to complete operation, caught %s\n", e.getClass());
		}
		catch(...) {
			std::printf("Unable to complete operation, caught an exception\n");
		}
	}
	std::puts("Bye!");
	return 0;
}


void ThreadTestApp::showUptime()
{
	Interval t = thread->getUptime();
	std::printf(
		"Uptime:%3lu days %02lu hours %02lu mins %02lu secs %03lu millis\n",
		t.days(), t.hours(), t.mins(), t.secs(), t.millisecs()
	);
}
