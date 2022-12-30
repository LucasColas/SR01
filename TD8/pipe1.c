#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
int tab1[10]={11,22,33,44,55,66,77,88,99,1000};
int tab2[10];
int i,fd;

int tube[2];

pipe(tube);


write (tube[1],tab1,10*sizeof(int));

//fd=open("titi.txt",O_RDWR,0666);
read(tube[0],tab2,10*sizeof(int));
close(tube[0]);
close(tube[1]);

for (i=0;i<10;i++)
	printf("%d,%d\n",tab2[i],tab1[i]);

return 0;
}
