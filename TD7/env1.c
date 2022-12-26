#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

int main() {
  char s[40];
  printf("Entrez un nom : \n");
  scanf("%s", s);
  printf("\n%s\n", s);
  char* val = getenv(s);
  printf("val : %s\n", val);
  char nouvel_val[50];
  printf("Entrez la nouvelle valeur : ");
  scanf("%s",nouvel_val);
  //strcat(s, "=");
  //strcat(s, nouvel_val);
  printf("%s\n", s);
  setenv(s, nouvel_val, 1);
  val = getenv(s);
  printf("val : %s\n", val);
  return 0;
}
