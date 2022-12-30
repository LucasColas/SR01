#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


int main() {
  FILE * f;
  printf("Avant freopen\n");
  f = freopen("freop.log", "a+", stdout);

  if (f == NULL){
    perror("freopen erreur : ");
    exit(0);
  }

  printf("Apres freopen\n");
  fclose(f);

  printf("Apres fclose(fa)\n");
  f = freopen("/dev/tty", "a+", stdout);
  printf("apres freopen(/dev/tty)\n");


  return 0;
}
