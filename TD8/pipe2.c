#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
  pid_t pid;
  int tube[2];
  pipe(tube);

  pid = fork();

  if (pid == -1) {
    printf("error");
    exit(404);
  }

  if (pid == 0) {
    //fils
    close(1);
    dup(tube[1]);
    execlp("ls", "ls", "-l", "/", (char *)NULL);
    close(tube[1]);
    exit(0);
  }
  else {

    printf("dans le père");
    close(0);
    dup(tube[0]);
    close(tube[1]);
    wait();
    execlp("wc", "wc", "-l", NULL);
    exit(0);
  }
  return 0;
}
