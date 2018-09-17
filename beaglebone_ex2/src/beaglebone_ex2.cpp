//============================================================================
// Name        : beaglebone_ex2.cpp
// Author      : Nguyen
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iostream>
#include <string.h>
#include <stdio.h>

#include "lib/SimpleGPIO.h"
#include "lib/uart.h"
#include "lib/adc.h"

using namespace std;

/**
 * @brief Init variable
 * 
 */
char rc_buf;
char buf[50];
int n,adc_value;
int8_t flag_rc = 0;
int8_t idx_rc = 0;
char* cToken;

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

	if (isOpen == 0) {
		while(1)
		{
			/**
			 * @brief Choose ADC pin form keybroad
			 * 
			 */
			cout << "Enter ADC port 0 - 9: " << endl;
			n = read(uart->fd, &rc_buf, 1);
			/**
			 * @brief Read ADC pin
			 * 
			 */
			adc_value = adc_pin_read(rc_buf);
			cout << "ADC value of port " << rc_buf << " : " << adc_value << endl;
			usleep(50000);
		}
	}
	return 0;
}
