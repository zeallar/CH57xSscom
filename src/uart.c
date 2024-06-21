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
    GPIOA_ModeCfg(GPIO_Pin_8, GPIO_ModeIN_PU);      // RXD-配置上拉输入
    GPIOA_ModeCfg(GPIO_Pin_9, GPIO_ModeOut_PP_5mA); // TXD-配置推挽输出，注意先让IO口输出高电平
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
    UART1_ByteTrigCfg(UART_1BYTE_TRIG); // 设置字节触发
    UART1_INTCfg(ENABLE, RB_IER_RECV_RDY | RB_IER_LINE_STAT); // 配置中断
    PFIC_EnableIRQ(UART1_IRQn);
}

__attribute__((interrupt("WCH-Interrupt-fast")))
__attribute__((section(".highcode")))
void UART1_IRQHandler(void)
{
    switch (UART1_GetITFlag())
    {
        case UART_II_LINE_STAT: // 线路状态错误
            UART1_GetLinSTA();
            break;
        case UART_II_RECV_RDY: // 数据达到设置触发点
        case UART_II_RECV_TOUT: // 接收超时
            while (R8_UART1_LSR & RB_LSR_DATA_RDY) // 检查接收数据是否就绪
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
        case UART_II_THR_EMPTY: // 发送缓存区空
            break;
        case UART_II_MODEM_CHG: // 只支持串口0
            break;
        default:
            break;
    }
}
