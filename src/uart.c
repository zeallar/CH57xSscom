#include "uart.h"
#include <string.h>
#include <stdio.h>

#define RX_BUFFER_SIZE 100
#define REPLY_PREFIX "reply: "

static uint8_t RxBuff[RX_BUFFER_SIZE];
static volatile uint8_t RxIndex = 0;
static uint8_t *TxBuff;

void UART1_Init(void)
{
    GPIOA_SetBits(GPIO_Pin_9);
    GPIOA_ModeCfg(GPIO_Pin_8, GPIO_ModeIN_PU);      // RXD-������������
    GPIOA_ModeCfg(GPIO_Pin_9, GPIO_ModeOut_PP_5mA); // TXD-�������������ע������IO������ߵ�ƽ
    UART1_DefInit();
}

void UART1_SendMessage(uint8_t *message)
{
    UART1_SendString(message, strlen((char *)message));
}

void UART1_SetTxBuff(uint8_t *message)
{
    TxBuff = message;
}

void UART1_InterruptConfig(void)
{
    UART1_ByteTrigCfg(UART_1BYTE_TRIG); // �����ֽڴ���
    UART1_INTCfg(ENABLE, RB_IER_RECV_RDY | RB_IER_LINE_STAT); // �����ж�
    PFIC_EnableIRQ(UART1_IRQn);
}

__attribute__((interrupt("WCH-Interrupt-fast")))
__attribute__((section(".highcode")))
void UART1_IRQHandler(void)
{
    switch (UART1_GetITFlag())
    {
        case UART_II_LINE_STAT: // ��·״̬����
            UART1_GetLinSTA();
            break;
        case UART_II_RECV_RDY: // ���ݴﵽ���ô�����
        case UART_II_RECV_TOUT: // ���ճ�ʱ
            while (R8_UART1_LSR & RB_LSR_DATA_RDY) // �����������Ƿ����
            {
                uint8_t receivedByte = UART1_RecvByte();
                RxBuff[RxIndex++] = receivedByte;

                if (receivedByte == '\n' || RxIndex >= RX_BUFFER_SIZE)
                {
                    uint8_t ReplyBuff[RX_BUFFER_SIZE + sizeof(REPLY_PREFIX)];
                    int reply_len = snprintf((char *)ReplyBuff, sizeof(ReplyBuff), "%s%.*s", REPLY_PREFIX, RxIndex, RxBuff);

                    UART1_SendString(ReplyBuff, reply_len);
                    RxIndex = 0;
                }
            }
            break;
        case UART_II_THR_EMPTY: // ���ͻ�������
            break;
        case UART_II_MODEM_CHG: // ֻ֧�ִ���0
            break;
        default:
            break;
    }
}
