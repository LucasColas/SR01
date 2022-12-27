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
    exit(1);
  }

  else if (pid == 0) {
    printf("ici le fils, mon pid est %i, le pid de mon père est : %i \n", getpid(), getppid());
    exit(42);
  }

  else {
    printf("ici le parent, mon pid est %i, le pid de mon fils est : %i\n", getpid(), pid);
    //wait(0);
    pid_t pid2 = fork();
    if (pid2 == -1) {
      exit(1);
    }

    else if (pid2== 0) {
      printf("Ici le fils, mon pid est %i, le pid de mon père est : %i \n", getpid(), getppid());
      exit(40);
    }

    else {
      //wait(0);
      printf("ici le parent, mon pid est %i, le pid de mon fils est : %i\n", getpid(), pid);
      waitpid(pid, &status, 0);
      printf("Mon premier fils viens de se terminer et m'a renvoyé %d\n", WEXITSTATUS(status));

      printf("\nIci le père, j'attends la fin de mon deuxième fils.\n");
      waitpid(pid2, &status, 0);
      printf("Mon deuxième fils viens de se terminer et m'a renvoyé %d\n", WEXITSTATUS(status));
    }
  }

  return 0;
}
