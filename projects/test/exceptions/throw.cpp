/*

  Evil low level -> high level exception test code

*/

#include <cstdio>
#include "error.hpp"

void riskyFunction(int x1, int x2, int steps)
{
  while (steps--) {
    std::printf("%d/%d = %d\n", x1, x2, x1/x2);
    x1++;
    x2--;
  }
}


int main(int argN, char** argV)
{
  // install our trap
  Trap trap;

  // try it out
  try {
    std::puts("Time to try something naughty...");
    riskyFunction(1,5,6);
  }
  catch (ZeroDivide& zd) {
    std::puts("\nCaught a ZeroDivide\n");
  }
  catch (...) {
    std::puts("\nCaught... something anyway\n");
  }

  return 0;
}