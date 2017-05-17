#include <stdio.h>
#include <string.h>       
#include <fcntl.h>
#include <unistd.h>


int main() {
	char buffer[1];
	int fd = open("./file",O_RDONLY);
	int fd2 = open("./file",O_RDWR);
	int final = lseek(fd2,0,SEEK_END);
	int i = 0;
	while(i < final) {
		read(fd,buffer,1);
		write(fd2,buffer,1);
		++i;
	}
}
