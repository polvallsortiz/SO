#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

int main() {
	char buff[300];
	int fd;
	fd = open("pipe1",O_WRONLY);
	while(fd == -1 && errno == ENXIO) {
		sprintf(buff,"No hay lector\n");
		write(1,buff,strlen(buff));
		fd = open("pipe1",O_WRONLY);
	}
	int m = read(0,buff,300);
	while(m != 0) {
		if(m > 0) write(fd,buff,m);
		m = read(0,buff,300);
	}
}
