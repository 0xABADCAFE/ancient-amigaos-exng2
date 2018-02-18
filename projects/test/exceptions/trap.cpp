/*

	Evil low level -> high level exception test code

*/

#include "error.hpp"
#include <cstdio>
#include <clib/exec_protos.h>

extern "C" {
	void trapCPU68K();
	void throwIllegalAddress() 	{ throw IllegalAddress(); }
	void throwBadAlign() 				{ throw BadAlignment(); }
	void throwZeroDivide()			{ throw ZeroDivide(); }
	void throwRangeError()			{ throw RangeError(); }
	void throwRuntimeError()		{ throw RuntimeError(); }
}

Trap::Trap()
{
	task		= FindTask(0);
	oldTrap	= task->tc_TrapCode;
	std::printf("Trap() [old code at 0x%08X]\n", (unsigned)oldTrap);
	enable();
}

Trap::~Trap()
{
	disable();
	std::puts("~Trap()");
}

void Trap::enable()
{
	task->tc_TrapCode = (void*)&trapCPU68K;
}

void Trap::disable()
{
	task->tc_TrapCode = oldTrap;
}
