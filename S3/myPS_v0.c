#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void error_y_exit(char *msg,int exit_status)
{
	perror(msg);
	exit(exit_status);
} 	

/* Ejecuta el comando ps –u username mediante la llamada al sistema execlp */
/* Devuelve: el código de error en el caso de que no se haya podido mutar */
void muta_a_PS(char *username)
{
	execlp("ps","ps","-u",username,(char*) NULL);
	error_y_exit("Ha fallado la mutacion", 1);
}

int main(int argc,char *argv[]) {
	char buff[200];
	sprintf(buff,"Soy el proceso padre con pid: %d\n",getpid());
	write(1,buff,strlen(buff));
	int pid = fork();
	if(pid == 0) { //HIJO
		sprintf(buff,"Soy el proceso hijo con pid: %d con parametro %s\n",getpid(),argv[1]);
		write(1,buff,strlen(buff));
		muta_a_PS(argv[1]);
	}
	//LO EJECUTAN LOS DOS I NO TERMINAN
	while(1);
}
