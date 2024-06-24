#ifndef CH57X_UART_THREADS_H
#define CH57X_UART_THREADS_H

#include "CH57x_common.h"
#include "CH57x_uart.h"
#include "protothread.h"

#define TX_BUFF_SIZE 100
#define RX_BUFF_SIZE 100

extern uint8_t TxBuff[TX_BUFF_SIZE];
extern uint8_t RxBuff[RX_BUFF_SIZE];

void UART1_Init(void);

extern struct pt pt_recv, pt_send;

PT_THREAD(protothread_recv(struct pt *pt));
PT_THREAD(protothread_send(struct pt *pt));

#endif
