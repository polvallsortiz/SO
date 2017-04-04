#include <unistd.h>
#include <stdio.h>
#include <string.h>


int main(int argc,char *argv[])
{
	int pid;
	char buffer[80];
	sprintf(buffer,"Abans del fork %d\n",getpid());
	write(1,buffer,strlen(buffer));
	sprintf(buffer,"El pare del pare es %d\n",getppid());
	write(1,buffer,strlen(buffer));
	pid=fork();
	if(pid != 0) {
		//PARE
		sprintf(buffer,"Esperant al fill a morir %d\n",getpid());
		write(1,buffer,strlen(buffer));
		int pid2 = waitpid(-1,NULL,0);
		sprintf(buffer,"Ja ha mort %d\n",pid2);
		write(1,buffer,strlen(buffer));
	}
	else {
		sprintf(buffer,"Soc el fill i vaig a executar %d\n",getpid());
		write(1,buffer,strlen(buffer));
		execlp("./silly","./silly",(char *) 0);
	}
	/* A partir de esta línea de código tenemos 2 procesos */

	sprintf(buffer,"Soy el proceso %d\n",getpid());
	write(1, buffer, strlen(buffer));
	return 0;
}
