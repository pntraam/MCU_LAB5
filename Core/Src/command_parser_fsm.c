/*
 * command_parser_fsm.c
 *
 *  Created on: Dec 25, 2022
 *      Author: USER
 */
#include "global.h"
#include "command_parser_fsm.h"

void command_parser_fsm(){
	  int index_rst, index_ok;
	  if(index_buffer == 0){
		  index_ok = MAX_BUFFER_SIZE-1;
		  index_rst = MAX_BUFFER_SIZE-1;
	  }
	  if(index_buffer != 0){
		  index_ok = index_buffer-1;
		  index_rst = index_buffer-1;
	  }
	  switch (status_command_rst) {
		case INIT:
			if(buffer[index_rst] == '!')
				status_command_rst = RST_INIT;
			break;
		case RST_INIT:
			if(buffer[index_rst] == '!')
				status_command_rst = RST_INIT;
			else if(buffer[index_rst] == 'R')
				status_command_rst = RST_R;
			else if(buffer[index_rst] != '!' && buffer[index_rst] != 'R')
				status_command_rst = INIT;
			break;
		case RST_R:
			if(buffer[index_rst] == 'S')
				status_command_rst = RST_S;
			else if(buffer[index_rst]!='S')
				status_command_rst = INIT;
			break;
		case RST_S:
			if(buffer[index_rst] == 'T')
				status_command_rst = RST_T;
			else if(buffer[index_rst] != 'T')
				status_command_rst = INIT;
			break;
		case RST_T:
			if(buffer[index_rst] == '#') {
				status_command_rst = RST_END;
				status_uart = UART_SEND;
			}
			else if(buffer[index_rst] != '#')
				status_command_rst = INIT;
			break;
		case RST_END:
			if(buffer[index_rst] == '!')
				status_command_rst= RST_INIT;
			else if(buffer[index_rst]!='!')
				status_command_rst = INIT;
			break;
		default:
			break;
	  }
	  switch (status_command_ok) {
	  		case INIT:
	  			if(buffer[index_ok] == '!')
	  				status_command_ok = OK_INIT;
	  			break;
	  		case OK_INIT:
	  			if(buffer[index_ok] == '!')
	  				status_command_ok = OK_INIT;
	  			else if(buffer[index_ok] == 'O')
	  				status_command_ok = OK_O;
	  			else status_command_ok = INIT;
	  			break;
	  		case OK_O:
	  			if(buffer[index_ok] == 'K')
	  				status_command_ok = OK_K;
	  			else if(buffer[index_ok] != 'K')
	  				status_command_ok = INIT;
	  			break;
	  		case OK_K:
	  			if(buffer[index_ok] == '#'){
	  				status_command_ok = OK_END;
	  				status_uart = UART_END;
	  			}
	  			else if(buffer[index_ok] != '#')
	  				status_command_ok = INIT;
	  			break;
	  		case OK_END:
	  			if(buffer[index_ok] == '!')
	  				status_command_ok = OK_INIT;
	  			else if(buffer[index_ok] != '!')
	  				status_command_ok = INIT;
	  			break;
	  		default:
	  			break;
	  	}
  }
