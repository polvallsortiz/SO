#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

#define REGION_SIZE		4096

void tract_seg(int status) {
	char buff[80];
	sprintf(buff,"Sortint del SEGMENTATION FAULT\n");
	perror("SIGSEV");
	exit(status);
}

int *p;

int main(int argc, char *argv[])
{
	char buff[256];	
	struct sigaction sa;				
	sigset_t mask;
	sa.sa_handler = &tract_seg;
	sa.sa_flags = 0;
	sigemptyset(&mask);
	sigaction(SIGSEGV,&sa,NULL);
	sprintf( buff, "Addresses:\n");
	write(1, buff, strlen(buff));	
	sprintf( buff, "\tp: %p\n", &p);
	write(1, buff, strlen(buff));	

	*p = 5;

	sprintf( buff, "\tp Address: %p, p value: %p, *p: %d\n", &p, p, *p);
	write(1, buff, strlen(buff));	

	exit(0);

}
