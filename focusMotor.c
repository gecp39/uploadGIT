
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>		/* low-level i/o */
#include <unistd.h>
#include <getopt.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/mman.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <pthread.h>
#include <time.h>
#include <sys/stat.h>

#include <signal.h>

#include <asm/arch/davinci_pwm.h>

//-----------------------------------------------------
//add by jiun
#define sockConnect "/var/run/pwmsocket"
#define BUFFSIZE 255
//-----------------------------------------------------


int main(int argc, char *argv[])
{	
	int fd, sz = 0;
	char cmd[BUFFSIZE];
	
	fd = socket(AF_UNIX, SOCK_STREAM, 0);

	struct sockaddr_un un;
	un.sun_family = AF_UNIX;
	strcpy(un.sun_path, sockConnect);
	sz = sizeof(un.sun_family) + strlen(un.sun_path);
	connect(fd, (struct sockaddr *)  &un, sz);
	while(1)
	{	
		//connect(fd,socket);	
		printf("Input Iris--mode :");
		scanf("%s", cmd);
		send(fd, cmd, BUFFSIZE,0);
		memset(cmd, 0, sizeof(char) * BUFFSIZE);
	//	printf("fd  %d\n", fd);
	//	sendto(fd, cmd, (int)strlen(cmd) + 1, 0, (struct sockaddr *)&un, sz);

	}
	close(fd);
}