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
    exit(1);
  }

  else if (pid == 0) {
    printf("ici le fils, mon pid est %i, le pid de mon père est : %i \n", getpid(), getppid());

  }

  else {
    printf("ici le parent, mon pid est %i, le pid de mon fils est : %i\n", getpid(), pid);
    wait(0);
    pid_t pid2 = fork();
    if (pid2 == -1) {
      exit(1);
    }

    else if (pid2== 0) {
      printf("ici le fils, mon pid est %i, le pid de mon père est : %i \n", getpid(), getppid());

    }

    else {
      wait(0);
      printf("ici le parent, mon pid est %i, le pid de mon fils est : %i\n", getpid(), pid);
      wait(0);
    }
  }

  return 0;
}
