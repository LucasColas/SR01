#include <stdio.h>
#include <stdlib.h>

void my_system(char *path, char **argv) {
  
}

int main() {
  printf("/bin/ls -la :\n");
  system("/bin/ls -la ");

  printf("\n\n");

  printf("/bin/ls *.c :\n");
  system("/bin/ls *.c");
  return 0;
}
