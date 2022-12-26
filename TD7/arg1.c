#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[], char *envp[]) {
  int c = 0;
  while(*envp) {
    printf("%s\n",*envp++);
    c++;
  }
  printf("Il y a %d variables\n", c);
  return 0;
}
