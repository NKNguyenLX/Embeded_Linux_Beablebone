




#include "pwm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>

/****************************************************************
 * pwm funtions
 ****************************************************************/

int pwm_export(unsigned int pwm)
{
	int fd, len;
	char buf[MAX_BUF];

	fd = open("/sys/class/pwm/pwmchip0/export", O_WRONLY);
	if (fd < 0) {
		perror("pwm/export");
		return fd;
	}

	len = snprintf(buf, sizeof(buf), "%d", pwm);
	write(fd, buf, len);
	close(fd);

	return 0;
}

int pwm_unexport(unsigned int pwm)
{
	int fd, len;
	char buf[MAX_BUF];

	fd = open(SYSFS_PWM_DIR "/unexport", O_WRONLY);
	if (fd < 0) {
		perror("pwm/unexport");
		return fd;
	}

	len = snprintf(buf, sizeof(buf), "%d", pwm);
	write(fd, buf, len);
	close(fd);

	return 0;
}

int pwm_duty_set(unsigned int duty,char* pwm_n)
{
	int fd, len;
	char buf[MAX_BUF];
	char* addr;
	sprintf(addr,"/sys/class/pwm/pwmchip0/%s/duty_cycle",pwm_n);
	fd = open(addr, O_WRONLY);
	if (fd < 0) {
		perror("pwm/duty");
		return fd;
	}

	len = snprintf(buf, sizeof(buf), "%d", duty);
	write(fd, buf, len);
	close(fd);

	return 0;
}

int pwm_period_set(unsigned int period,char* pwm_n)
{
	int fd, len;
	char buf[MAX_BUF];

	//fd = open("/sys/class/pwm/pwmchip0/pwm-0:0/period", O_WRONLY);
	char* addr;
	sprintf(addr,"/sys/class/pwm/pwmchip0/%s/period",pwm_n);
	fd = open(addr, O_WRONLY);
	if (fd < 0) {
		perror("pwm/period");
		return fd;
	}

	len = snprintf(buf, sizeof(buf), "%d", period);
	write(fd, buf, len);
	close(fd);

	return 0;
}

int pwm_enable(unsigned int enable,char* pwm_n)
{
	int fd, len;
	char buf[MAX_BUF];

	//fd = open("/sys/class/pwm/pwmchip0/pwm-0:0/enable", O_WRONLY);
	char* addr;
	sprintf(addr,"/sys/class/pwm/pwmchip0/%s/enable",pwm_n);
	fd = open(addr, O_WRONLY);
	if (fd < 0) {
		perror("pwm/enable");
		return fd;
	}

	len = snprintf(buf, sizeof(buf), "%d", enable);
	write(fd, buf, len);
	close(fd);

	return 0;
}
