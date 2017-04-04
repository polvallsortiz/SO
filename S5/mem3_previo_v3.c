#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

#define REGION_SIZE		4096

void tract_seg(int status) {
	char buff[80];
	sprintf(buff,"Sortint del SEGMENTATION FAULT\n");
	write(1,buff,strlen(buff));
}

int *p;

int main(int argc, char *argv[])
{
	char buff[256];					
	struct sigaction;
	sigset_t mask;
	sigaction.sa_handler = tract_seg;
	sigaction.sa_mask = &mask;
	sigemptyset(&mask);
	sigaddset(&mask,SIGSEGV);
	sprintf( buff, "Addresses:\n");
	write(1, buff, strlen(buff));	
	sprintf( buff, "\tp: %p\n", &p);
	write(1, buff, strlen(buff));	

	*p = 5;

	sprintf( buff, "\tp Address: %p, p value: %p, *p: %d\n", &p, p, *p);
	write(1, buff, strlen(buff));	

	exit(0);

}
