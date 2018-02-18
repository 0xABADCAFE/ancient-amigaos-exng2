#include <cstdio>

struct Barf {
	int i;
};

void dummy() throw (Barf)
{
	std::printf("Throwing 1\n");
	throw Barf();
}

int main(int argN, char** argV)
{
	std::printf("Hello World\n");
	try {
		dummy();
	}
	catch (Barf) {
		std::printf("Uhhandled Exception!\n");
	}
	catch (...) {

	}
	std::printf("Done\n");
	return 0;
}
