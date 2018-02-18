#include <xbase.hpp>
#include <systemlib/cpu.hpp>
#include <systemlib/logger.hpp>
#include <iolib/streamio.hpp>
#include <cstdio>


class HelloWorld : public Application
{
	public:
		sint32 run();

	public:
		HelloWorld();
		~HelloWorld();
};

Application* Application::createInstance()
{
	return new HelloWorld();
}

void Application::destroyInstance(Application* app)
{
	delete app;
}

HelloWorld::HelloWorld()
{
//	SystemLog::write(SystemLog::INFO, "Created HelloWorld\n");
}

HelloWorld::~HelloWorld()
{
//	SystemLog::write(SystemLog::INFO,"Destroyed HelloWorld\n");
}

sint32 HelloWorld::run()
{
/*
	std::puts(CPU::getCPUName());
	std::puts(CPU::getFPUName());
	sint32 i = getArgInteger("-int", 0, 0);
	uint32 h = getArgHex("-hex", 0xDEADF00D, 0);
	std::printf(
		"\nArgs\n\n-int %ld\n-hex %08X\n\n",
		i,
		(unsigned)h
	);
	return i;
*/

	uint32 foo[] = { 0x12345678, 0x0ABADA55 };

	StreamOut test;
	test.open("ram:dummy.bin", false);

	test.write8(foo, 8);
	test.write16(foo, 4);
	test.write16Swap(foo, 4);
	test.write32(foo, 2);
	test.write32Swap(foo, 2);
	test.write64(foo, 1);
	test.write64Swap(foo, 1);

	return 0;
}
