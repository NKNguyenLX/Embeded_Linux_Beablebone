




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

	fd = open("/sys/class/pwm/pwmchip4/export", O_WRONLY);
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

int pwm_duty_set(unsigned int duty)
{
	int fd, len;
	char buf[MAX_BUF];

	fd = open("/sys/class/pwm/pwmchip4/pwm-4:0/duty_cycle", O_WRONLY);
	if (fd < 0) {
		perror("pwm/duty");
		return fd;
	}

	len = snprintf(buf, sizeof(buf), "%d", duty);
	write(fd, buf, len);
	close(fd);

	return 0;
}

int pwm_period_set(unsigned int period)
{
	int fd, len;
	char buf[MAX_BUF];

	fd = open("/sys/class/pwm/pwmchip4/pwm-4:0/period", O_WRONLY);
	if (fd < 0) {
		perror("pwm/period");
		return fd;
	}

	len = snprintf(buf, sizeof(buf), "%d", period);
	write(fd, buf, len);
	close(fd);

	return 0;
}

int pwm_enable(unsigned int enable)
{
	int fd, len;
	char buf[MAX_BUF];

	fd = open("/sys/class/pwm/pwmchip4/pwm-4:0/enable", O_WRONLY);
	if (fd < 0) {
		perror("pwm/enable");
		return fd;
	}

	len = snprintf(buf, sizeof(buf), "%d", enable);
	write(fd, buf, len);
	close(fd);

	return 0;
}
