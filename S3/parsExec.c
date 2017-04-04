#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

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
	for(int i = 1; i < 5; ++i) {
		if((pid = fork()) < 0) error_y_exit("Error del fork",1);
		if(pid == 0) { //HIJO
			sprintf(buff,"Soy hijo con pid: %d\n",getpid());
			write(1,buff,strlen(buff));
			execlp("listaParametros",argv);
			sprintf(buff,"Muero con pid: %d\n",getpid());
			write(1,buff,strlen(buff));
			exit(0);
		}
	}
	waitpid();
	sprintf(buff,"Soy el padre pid: %d\n",getpid());
	write(1,buff,strlen(buff));
}
