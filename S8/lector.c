#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main() {
	int fd;
	fd = open("pipe1",O_RDONLY);
	char buff[300];
	int m = read(fd,buff,300);
	while(m != 0) {
		if(m > 0) write(1,buff,m);
		m = read(fd,buff,300);
	}
}
