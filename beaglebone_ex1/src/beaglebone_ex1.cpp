//============================================================================
// Name        : beaglebone_ex1.cpp
// Author      : Nguyen
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <stdio.h>

#include "lib/SimpleGPIO.h"
#include "lib/uart.h"
#include "lib/pwm.h"

using namespace std;

/**
 * @brief Init variable
 * 
 */
char rc_buf;
char buf[50];
int n;
int8_t flag_rc = 0;
int8_t idx_rc = 0;
char* cToken;

unsigned int led_1_period;
unsigned int led_1_duty;
unsigned int led_2_period;
unsigned int led_2_duty;


int main() {
	cout << "Start exercise 1" << endl;

	/**
	 * @brief Init UART4
	 * 
	 */
	uart_properties *uart = (uart_properties *) malloc(sizeof(uart_properties));
	uart->uart_id = uart4;
	uart->baudrate = B9600;
	cout << "UART_init" << endl;
	uint8_t isOpen = uart_open(uart);
	cout << "UART_open_done" << endl;

	/**
	 * @brief Read period and duty cycle of LED1 and LED2 with the format:
	 * 			[<led1_period>,<led1_duty>,<led2_period>,<led2_duty>,]
	 * 
	 */
	if (isOpen == 0) {
		while(1)
		{
	        n = read(uart->fd, &rc_buf, 1);
	        if(n > 0)
	        {
	            if(rc_buf == ']')
	            {
	                flag_rc = 0;
	                cToken = strtok(buf, ",");
	                if(cToken != NULL)
	                {
	                    led_1_period = (unsigned int)atof(cToken);
	                    cToken = strtok(NULL,",");
	                    if(cToken != NULL)
	                    {
	                    	led_1_duty = (unsigned int)atof(cToken);
	                    	cToken = strtok(NULL,",");
	                    	if(cToken != NULL)
	                    	{
	                    		led_2_period = (unsigned int)atof(cToken);
	                    		cToken = strtok(NULL,",");
	                    		if(cToken != NULL)
	                    		{
	                    			led_2_duty = (unsigned int)atof(cToken);
	                    			break;
	                    		}
	                    	}
	                    }
	                }
	            }
	            if(flag_rc)
	            {
	                buf[idx_rc++] = rc_buf;
	            }
	            if(rc_buf == '[')
	            {
	                flag_rc = 1;
	                idx_rc = 0;
	            }
	        }
		}
		usleep(50000);
		}
	uart_close(uart);

	/**
	 * @brief Dislay LED1 by using PWM0
	 * 
	 */
	pwm_export(0);
	pwm_period_set(led_1_period,(char*)PWM0);
	pwm_duty_set(led_1_duty,(char*)PWM0);
	pwm_enable(1,(char*)PWM0);

	/**
	 * @brief Display LED2 by using PWM1
	 * 
	 */
	pwm_export(1);
	pwm_period_set(led_2_period,(char*)PWM1);
	pwm_duty_set(led_2_duty,(char*)PWM1);
	pwm_enable(1,(char*)PWM1);



}

