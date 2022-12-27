#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

int main() {

  pid_t pid = fork();
  int status;
  if (pid == -1) {
    printf("Impossible de fork\n");
  }

  else if (pid == 0) {

    printf("ici le fils, mon pid est %i, le pid de mon père est : %i \n", getpid(), getppid());
    exit(42);
  }

  else {
    wait(&status);
    printf("ici le parent, mon pid est %i, le pid de mon fils est : %i\n", getpid(), pid);
    printf("Exit status fils : %d\n", WEXITSTATUS(status));
  }

  return 0;
}
