#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void alternative() {
	char buff[80];
	sprintf(buff,"SIGINT Entrant\n");
	write(1,buff,strlen(buff));
}

int main() {
	struct sigaction trat;
	sigset_t mask;
	sigemptyset(&mask);
	trat.sa_flags = 0;
	trat.sa_mask = mask;
	trat.sa_handler = &alternative;
	sigaddset(&mask,SIGINT);
	sigaction(SIGINT,&trat,NULL);
	while(1);
}
