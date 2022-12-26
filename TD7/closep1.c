#include <stdio.h>
#include <fcntl.h>

int main() {
  int pid,i,status;
  int fd,fd2;

  fd=open("toto.txt",O_RDWR|O_CREAT,0666); //ajouté dans la première case disponible()
  printf( "avant close\n");
  close(1); //ferme stdout
  printf("apres close\n"); //print pas car pas de stdout
  dup(fd); //duplique le disquéteur dans la première case disponible. Donc il sera dans stdout
  printf("apres dup\n");
  close(fd); //On ferme fd mais on l'a dupliqué dans stdout
  close(1);
  fd = open("/dev/tty", O_RDWR, 0666); //lecture ecrite dans stdout
  printf("Le 4eme printf...\n");
  //on peut avoir cat le contenu de toto
  
  return 0;
}
