#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


int main() {
  FILE * fin, *fout;
  char c;
  char buf[4] = "xxx\n";
  int n;
  fin = fopen("fop.in","r");
  if (fin==NULL) {
    perror("fin erreur :");
    exit(0);
  }

  fout = fopen("fop.out", "w+");
  if (fout == NULL) {
    perror("fout erreur");
  }

  while (!feof(fin)) {
    n = fread(&c, 1, 1, fin);
    if (n==1) {
      if (c != '\n') {
        n = fwrite(&c,1,1,fout);
      }

      else {
        n = fwrite(buf, 1,4, fout);
      }
    }
  }

  fclose(fin);
  fclose(fout);
  return 0;
}
