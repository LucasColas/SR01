/* fop.c -- demo fopen fread ... */
#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING_LENGTH 80

int main()
{ FILE * fa;
  char buf[MAX_STRING_LENGTH+1];
  int n;
  fa = fopen("fop.txt","a+");
  if (fa==NULL) {
    perror("fop erreur :");
    exit(0);
  }
  n = fread(buf,1,MAX_STRING_LENGTH,fa);
  if (n!=MAX_STRING_LENGTH) {
     perror("read");
  }
  buf[n]='\0';
  printf ("lu n=%d =>%s\n",n,buf);
  n = fwrite ("xxx yyy\n",1,8,fa);
  if (n!=8) {
     perror("write"); }
  fclose(fa);
}
