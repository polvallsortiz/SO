#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void error_y_exit(char *msg,int exit_status)
{
	perror(msg);
	exit(exit_status);
} 	

int main(int argc,char *argv[]) {
	char buff[200];
	sprintf(buff,"Soy el proceso padre con pid: %d\n",getpid());
	write(1,buff,strlen(buff));
	int pid;
	for(int i = 1; i < argc; ++i) {
		if((pid = fork()) < 0) error_y_exit("Error en fork",1);
		if(pid == 0) { //HIJO
			sprintf(buff,"Soy el proceso hijo con pid: %d con parametro %s\n",getpid(),argv[i]);
			write(1,buff,strlen(buff));
			exit(0);
		}
	}
}
