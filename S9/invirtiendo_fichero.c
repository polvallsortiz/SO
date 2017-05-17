#include <stdio.h>
#include <string.h>       
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
	char buffer[80];
	if(argc != 2) {
		sprintf(buffer,"PARAMETROS INCORRECTOS\n");
		write(1,buffer,strlen(buffer));
		exit(0);
	}
	int fd = open(argv[1],O_RDONLY);
	int total = lseek(fd,0,SEEK_END);
	sprintf(buffer,"./%s.inv",argv[1]);
	int fdf = creat(buffer,S_IRUSR|S_IWUSR);
	char buff[1];
	lseek(fd,-1,SEEK_END);
	while(total != 0) {
		read(fd,buff,1);
		write(fdf,buff,1);
		lseek(fd,-2,SEEK_CUR);
		--total;
	}
}
