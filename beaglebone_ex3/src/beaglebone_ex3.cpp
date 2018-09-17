//============================================================================
// Name        : beaglebone_ex3.cpp
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

/**
 * @brief Define LED pin
 * 
 */
#define LED0 67		// P8.8
#define LED1 68		// P8.10
#define LED2 44		// P8.12
#define LED3 26		// P8.14

using namespace std;

/**
 * @brief Init variable
 * 
 */
char rc_buf;
char buf[50];
int n,i,k;
int8_t flag_rc = 0;
int8_t idx_rc = 0;
char* cToken;
int num_a, num_b;		// number a and b get form UART
bool led_binary[4];		// binary form for displaying LED

int main() {
	cout << "Start exercise 1" << endl;

	/**
	 * @brief Init UART
	 * 
	 */
	uart_properties *uart = (uart_properties *) malloc(sizeof(uart_properties));
	uart->uart_id = uart4;
	uart->baudrate = B9600;
	cout << "UART_init" << endl;
	uint8_t isOpen = uart_open(uart);
	cout << "UART_open_done" << endl;

	/**
	 * @brief Getting number a and b form UART with format [<number_A>,<number_B>,]
	 * 
	 */
	cout << "Enter number A and number B: "<< endl;
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
	                    num_a = (int)atof(cToken);
	                    cToken = strtok(NULL,",");
	                    if(cToken != NULL)
	                    {
	                    	num_b = (int)atof(cToken);
	                    	break;
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
	        usleep(50000);
		}
	}
	uart_close(uart);

	/**
	 * @brief Init LED pins
	 * 
	 */
	gpio_export(LED0);	// P8.8
	gpio_export(LED1);	// P8.10
	gpio_export(LED2);	// P8.12
	gpio_export(LED3);	// P8.14

	/**
	 * @brief Set output for LED pins
	 * 
	 */
	gpio_set_dir(LED0,OUTPUT_PIN);
	gpio_set_dir(LED1,OUTPUT_PIN);
	gpio_set_dir(LED2,OUTPUT_PIN);
	gpio_set_dir(LED3,OUTPUT_PIN);

	/**
	 * @brief Display number form numner A to number B by binary form
	 * 
	 */
	for(i = num_a; i<= num_b; i++)
	{
		/**
		 * @brief Convert to little endian binary form
		 * 
		 */
		itob(i,led_binary);
		/**
		 * @brief Display LED and switch to big endian form
		 * 
		 */
		if(led_binary[0])
			gpio_set_value(LED3,HIGH);
		else gpio_set_value(LED3,LOW);

		if(led_binary[1])
			gpio_set_value(LED2,HIGH);
		else gpio_set_value(LED2,LOW);

		if(led_binary[2])
			gpio_set_value(LED1,HIGH);
		else gpio_set_value(LED1,LOW);

		if(led_binary[3])
			gpio_set_value(LED0,HIGH);
		else gpio_set_value(LED0,LOW);

	}
}
