#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <wait.h>

int main() {
	int fd[2];
	char buff[80];
	pipe(fd);
	int pid = fork();
	if(pid == 0) {
		dup2(fd[0] ,0);	//Redireccionar el canal d'entrada estandar
						//'0' amb el canal de lectura de la pipe
						//'fd[0]'
		close(fd[1]);	//Tancar canal d'escriptura de la pipe per
						//al procés fill (BLOQUEJARIA L'EXECUCIÓ)
		close(fd[0]);	//Ja em redireccionat, aixi que podem tancar
		execlp("cat","cat",0);	//Mutem
	}
	sprintf(buff,"Inicio\n");
	write(fd[1],buff,strlen(buff));	//Escrivim per el extrem d'	
						//escriptura de la pipe
	close(fd[0]);		//Tancar canal de lectura de la pipe (no perillos)
	//close(fd[1]);		//Tancar canal d'escriptura (BLOQUEJANT)
	waitpid(-1,NULL,0);
	sprintf(buff,"Fin\n");
	write(1,buff,strlen(buff));	//Escrivim pel canal estandar
}
