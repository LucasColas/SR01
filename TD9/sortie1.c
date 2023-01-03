#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  int m = 42;
  if (m==42) {
    exit(0);
  }
  else {
    exit(1);
  }
  return 0;
}
