#include <stdio.h>

extern char **environ;

int main (void){
  int i = 0;
  int c = 0;
  for (i = 0; environ[i] != NULL; i ++) {
    printf("%d : %s\n", i, environ[i]);
    c++;
  }
  printf("\n\nIl y a %d variables\n\n",c);
  return 0;
}
