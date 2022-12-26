#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>


int main() {
  pid_t pid_main = getpid();
  pid_t pid = fork();
  if (pid == -1) {
    printf("Erreur fork\n");
  }

  else if (pid == 0) {
    printf("mon pid : %i et celui de mon père est : %d\n", getpid(), getppid());

  }

  else {
    printf("mon pid : %d celui de mon fils : %d\n", getpid(), pid);
  }
  return 0;
}
