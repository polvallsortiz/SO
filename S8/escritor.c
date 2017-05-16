#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main() {
	int fd;
	fd = open("pipe1",O_WRONLY);
	char buff[300];
	int m = read(0,buff,300);
	while(m != 0) {
		if(m > 0) write(fd,buff,m);
		m = read(0,buff,300);
	}
}
