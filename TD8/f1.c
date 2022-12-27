#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

int main() {

  pid_t pid = fork();
  if (pid == -1) {
    printf("Impossible de fork\n");
  }

  else if (pid == 0) {
    printf("ici le fils, mon pid est %i, le pid de mon père est : %i \n", getpid(), getppid());

  }

  else {
    printf("ici le parent, mon pid est %i, le pid de mon fils est : %i\n", getpid(), pid);
  }

  return 0;
}
