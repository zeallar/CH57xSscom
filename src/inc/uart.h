#ifndef UART_H
#define UART_H

#include "CH57x_common.h"

void UART1_Init(void);
void UART1_SendMessage(uint8_t *message); // ȥ��const�޶���
void UART1_InterruptConfig(void);
void UART1_SetTxBuff(uint8_t *message); // ȥ��const�޶���

#endif // UART_H
