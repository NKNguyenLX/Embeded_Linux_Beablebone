/**
 * @brief 	- Tree overlay must be installed first by add BB-ADC-00A0.dtbo to /boot/uEvn.txt
 * 			- Using uart_open() function to init UART4
 * 			- Read or write data by using the two functions uart_sed() and uart_read(),
 * 			- Access UART4 by this address /dev/ttyO4
 * 
 * @file uart.h
 * @author NKNguyen
 * @date 2018-09-17
 */
#ifndef UART_H_
#define UART_H_

#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include <string.h>
#include "core.h"


typedef enum {
	uart0 = 0, uart1 = 1, uart2 = 2, uart3 = 3, uart4 = 4, uart5 = 5
} uart;


typedef struct {
	int fd;
	uart uart_id;
	int baudrate;
} uart_properties;

extern int uart_open(uart_properties *uart);
extern int uart_send(uart_properties *uart, char *tx, int length);
extern int uart_read(uart_properties *uart,char *rx, int length);
extern int uart_close(uart_properties *uart);

#endif /* UART_H_ */
