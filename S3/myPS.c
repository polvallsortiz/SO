#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
	if((pid = fork()) < 0) error_y_exit("Error en fork",1);
	if(pid == 0) { //HIJO
		sprintf(buff,"Soy el proceso hijo con pid: %d con parametro %s\n",getpid(),argv[1]);
		write(1,buff,strlen(buff));
	}
	//LO EJECUTAN LOS DOS I NO TERMINAN
	while(1);
}
