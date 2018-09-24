/**
 * @brief 
 * 
 * @file adc.cpp
 * @author NKNguyen
 * @date 2018-09-17
 */
#include "adc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>

/**
 * @brief Read data form ADC pin number 0-9
 * 
 * @param adc_pin 
 * @return int 
 */
int adc_pin_read(char adc_pin)
{
	int fd, len=5;
	char* buf;
	char* addr;
	//sprintf(addr,"/sys/bus/iio/devices/iio:device0/in_voltage%c_raw",adc_pin);
	snprintf(addr, sizeof(addr), SYSFS_ADC_DIR  "/in_voltage%c_raw", adc_pin);
	fd = open(addr, O_RDONLY);
	if (fd < 0) {
		perror("adc_pin");
		return fd;
	}
	read(fd, buf, len);
	close(fd);
	return stod(buf);
}

/**
 * @brief Convert string to integer
 * 
 * @param string 
 * @return int 
 */
int stod(char* string)
{
	int i,sum,len;
	len = sizeof(string);
	for(i=0; i<len; i++)
	{
		if(len-1-i>0)
			sum += string[i]*10*(len-1-i);
		else
			sum += string[i];
	}
	return sum;
}
