#include <cstdio>
#include <cstdlib>

int main(int argN, char** argV)
{
  char* endPtr;

  for (int i=1; i<argN; i++) {
    long int j = std::strtol(argV[i], &endPtr, 10);
    std::printf("%ld\n", j);
    if (*endPtr) {
      std::puts("Garbage at end of string");
    }
    else {
      std::puts("String OK");
    }
  }

  return 0;
}
