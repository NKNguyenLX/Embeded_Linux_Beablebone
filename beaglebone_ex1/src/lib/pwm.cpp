/**
 * @brief 
 * 
 * @file pwm.cpp
 * @author NKNguyen
 * @date 2018-09-17
 */


#include "pwm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>


/**
 * @brief Export pwm0 or pwm1
 * 
 * @param pwm 
 * @return int 
 */
int pwm_export(unsigned int pwm)
{
	int fd, len;
	char buf[MAX_BUF];

	fd = open(SYSFS_PWM_EXPORT, O_WRONLY);
	if (fd < 0) {
		perror("pwm/export");
		return fd;
	}

	len = snprintf(buf, sizeof(buf), "%d", pwm);
	write(fd, buf, len);
	close(fd);

	return 0;
}
/**
 * @brief Unexport pwm0 or pwm1
 * 
 * @param pwm 
 * @return int 
 */
int pwm_unexport(unsigned int pwm)
{
	int fd, len;
	char buf[MAX_BUF];

	fd = open(SYSFS_PWM_UNEXPORT, O_WRONLY);
	if (fd < 0) {
		perror("pwm/unexport");
		return fd;
	}

	len = snprintf(buf, sizeof(buf), "%d", pwm);
	write(fd, buf, len);
	close(fd);

	return 0;
}
/**
 * @brief Set duty cricle
 * 
 * @param duty 
 * @param pwm_n 
 * @return int 
 */
int pwm_duty_set(unsigned int duty,char* pwm_n)
{
	int fd, len;
	char buf[MAX_BUF];
	char* addr;

	snprintf(addr, sizeof(addr), SYSFS_PWM_DIR  "/%s/duty_cycle", pwm_n);
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
/**
 * @brief Set period
 * 
 * @param period 
 * @param pwm_n 
 * @return int 
 */
int pwm_period_set(unsigned int period,char* pwm_n)
{
	int fd, len;
	char buf[MAX_BUF];

	//fd = open("/sys/class/pwm/pwmchip0/pwm-0:0/period", O_WRONLY);
	char* addr;
	snprintf(addr, sizeof(addr), SYSFS_PWM_DIR  "/%s/period", pwm_n);
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
/**
 * @brief Enable pwm0 or pwm1
 * 
 * @param enable 
 * @param pwm_n 
 * @return int 
 */
int pwm_enable(unsigned int enable,char* pwm_n)
{
	int fd, len;
	char buf[MAX_BUF];

	//fd = open("/sys/class/pwm/pwmchip0/pwm-0:0/enable", O_WRONLY);
	char* addr;
	snprintf(addr, sizeof(addr), SYSFS_PWM_DIR  "/%s/enable", pwm_n);
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
