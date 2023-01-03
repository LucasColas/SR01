#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
void test() {
  printf("Exit 0\n");
}
int main() {
  int m = 42;
  if (m==42) {
    atexit(test);
    exit(0);
  }
  else {
    exit(1);
  }
  return 0;
}
