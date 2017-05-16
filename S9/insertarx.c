#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>


int main() {
	int fd = open("./salida.txt",O_RDWR);
	lseek(fd,-1,SEEK_END);
	char c[1];
	read(fd,c,1);
	lseek(fd,-1,SEEK_CUR);
	write(fd,"X",sizeof(char));
	write(fd,c,sizeof(char));
	close(fd);
}
