#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	char buff[120];
	sprintf(buff,"Soc el pare amb pid: %d\n",getpid());
	write(1,buff,strlen(buff));
	int pid = fork();
	if (pid != 0) 	kill(pid);
	if(pid == 0) { //HIJO
		sprintf(buff,"Soc fill amb pid: %d\n",getpid());
		write(1,buff,strlen(buff));
	}
}
