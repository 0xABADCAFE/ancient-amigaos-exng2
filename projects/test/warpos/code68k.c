#include "shared.hpp"

void init68K(struct SharedStruct* s)
{
	if (s) {
		s->foo = 0;
		s->bar = 1.0;
	}
}
