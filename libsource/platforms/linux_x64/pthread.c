#include <stdio.h>
#include <pthread.h>

int main(int argn, char** argv)
{
	size_t i, s;
	pthread_t p;

	p = pthread_self();
	s = sizeof(pthread_t);

	printf("size of pthread_t = %zd\n", s);

	unsigned char* u = (unsigned char*)(&p);

	printf("Byte rep of pthread_t for self = ");

	for (i=0; i<s; i++) {
		printf("%02X ", (unsigned) u[i]);
	}

	printf("\n");

	return 0;
}
