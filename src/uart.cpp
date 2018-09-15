
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <stdint.h>
#include <iostream>
#include "uart.h"

uint8_t u8_bufWrite[50];
int mainfd = -1;
struct termios options;


int open_port(const char* port)
{
    int fd;

    fd = open(port, O_RDWR | O_NOCTTY | O_NDELAY);

    if (fd == -1)
    {
        return -1;
    }

    cout << "!!! Begin !!!" << endl;
    return (fd);
}

int InitUART0(void)
{
	mainfd = open_port("/dev/tty4");

	    if(mainfd == -1)
	    {
	        return -1;
	    }

	    fcntl(mainfd, F_SETFL, FNDELAY);

	    tcgetattr(mainfd, &options);
	    cfsetispeed(&options, B115200);
	    cfsetospeed(&options, B115200);


	    options.c_cflag |= (CLOCAL | CREAD);
	    options.c_cflag &= ~PARENB;
	    options.c_cflag &= ~CSTOPB;
	    options.c_cflag &= ~CSIZE;
	    options.c_cflag |=  CS8;
	    options.c_cflag &= ~CRTSCTS;               /* Disable hardware flow control */


	    options.c_lflag &= ~(ICANON | ECHO | ISIG);


	    tcsetattr(mainfd, TCSANOW, &options);

 }
