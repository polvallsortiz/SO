#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	int fd = creat("./salida.txt",S_IRUSR|S_IWUSR);
	char buff[80];
	sprintf(buff,"ABCD\n");
	write(fd,buff,4);
	close(fd);
}
