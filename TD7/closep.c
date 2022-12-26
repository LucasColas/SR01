
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
int main() {
    int pid,i,status;
    int fd,fd2;

    fd=open("toto.txt",O_RDWR|O_CREAT,0666);
    printf( "avant close\n");
    close(1);
    printf("apres close\n");
    dup(fd);
    printf("apres dup\n");
    close(fd);
    close(1);
    fd = open("/dev/tty", O_RDWR, 0666); 
    printf("Le 4eme printf...\n");

    return 0;
}
