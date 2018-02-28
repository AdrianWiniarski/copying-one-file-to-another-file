#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
``
int main(void)
{
int fd, rd,wd,zd;
char buf[512];
fd = open("plik1",O_RDONLY);
wd = open("plik2",O_WRONLY);
if(wd < 0) {
perror("write");
return 0;
}
if(fd < 0) {
perror("open");
return 0;
}
do {
rd = read(fd,buf,512);
if(rd < 0) {
perror("read");
return 0;
}
printf("Odczytano %d bajtów\n",rd);
zd = write(wd,buf,rd);
printf("Zapisano %d bajtów\n" ,zd);
} while(rd > 0);
close(fd);
close(wd);
return 0;
}