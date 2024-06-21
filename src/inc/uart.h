#ifndef UART_H
#define UART_H

#include "CH57x_common.h"

void UART1_Init(void);
void UART1_SendMessage(uint8_t *message); // 去掉const限定符
void UART1_InterruptConfig(void);
void UART1_SetTxBuff(uint8_t *message); // 去掉const限定符

#endif // UART_H
