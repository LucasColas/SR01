#include <stdio.h>
#include <stdlib.h>



int main() {
  printf("/bin/ls -la :\n");
  system("/bin/ls -la ");

  printf("\n\n");

  printf("/bin/ls *.c :\n");
  system("/bin/ls *.c");
  return 0;
}
