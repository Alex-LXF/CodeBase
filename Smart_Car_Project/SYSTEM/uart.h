
#ifndef _UART_H_
#define _UART_H_

#include "stm32f4xx.h"

void Uart1_Init(void);
void Send_Str(u8 *str);
void Uart_Open(void);


#endif



