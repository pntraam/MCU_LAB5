/*
 * global.h
 *
 *  Created on: Dec 25, 2022
 *      Author: USER
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include "command_parser_fsm.h"
#include "software_timer.h"
#include "stdio.h"
#define		INIT		255

#define		RST_INIT	0
#define		RST_R		1
#define		RST_S		2
#define		RST_T		3
#define		RST_END		4

#define		OK_INIT		10
#define		OK_O		11
#define		OK_K		12
#define		OK_END		13

#define		UART_INIT	20
#define		UART_SEND	21
#define		UART_END	22


int status_command_rst;
int status_command_ok;
int status_uart;
#define MAX_BUFFER_SIZE 30
uint8_t temp;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer;
uint8_t buffer_flag;
uint32_t ADC_value;
char str[20];
#endif /* INC_GLOBAL_H_ */
