/********************************** (C) COPYRIGHT *******************************
 * File Name          : CH57x_uart_threads.c
 * Author             : WCH
 * Version            : V1.0
 * Date               : 2020/08/06
 * Description        : 串口和protothread相关函数的实现
 *******************************************************************************/

#include "CH57x_uart_threads.h"
#include <string.h>

uint8_t TxBuff[TX_BUFF_SIZE];
uint8_t RxBuff[RX_BUFF_SIZE];

struct pt pt_recv, pt_send;

/*********************************************************************
 * @fn      UART1_Init
 *
 * @brief   初始化串口1
 *
 * @return  none
 */
void UART1_Init(void)
{
    GPIOA_SetBits(GPIO_Pin_9);
    GPIOA_ModeCfg(GPIO_Pin_8, GPIO_ModeIN_PU);      // RXD-配置上拉输入
    GPIOA_ModeCfg(GPIO_Pin_9, GPIO_ModeOut_PP_5mA); // TXD-配置推挽输出，注意先让IO口输出高电平
    UART1_DefInit();
}

/*********************************************************************
 * @fn      protothread_recv
 *
 * @brief   处理接收串口数据的protothread
 *
 * @param   pt - protothread控制块
 *
 * @return  protothread状态
 */

PT_THREAD(protothread_recv(struct pt *pt))
{
    PT_BEGIN(pt);

    static uint8_t len;
    static uint8_t index = 0;

    while (1) {
        len = UART1_RecvString(RxBuff + index); // 接收字符串并追加到缓冲区
        if (len) {
            index += len; // 更新当前缓冲区索引
            RxBuff[index] = '\0'; // 确保字符串终止符

            // 检查接收到的字符串是否包含换行符
            uint8_t *newline_pos = (uint8_t *)strchr((char *)RxBuff, '\n');
            if (newline_pos != NULL) {
                // 找到换行符的位置
                size_t line_length = (newline_pos - RxBuff) + 1;

                // 进行回显处理
                UART1_SendString((uint8_t *)"Received: ", 10);
                UART1_SendString(RxBuff, line_length);
                UART1_SendString((uint8_t *)"\r\n", 2);

                // 将缓冲区剩余部分前移
                memmove(RxBuff, newline_pos + 1, index - line_length);
                index -= line_length;
            }

            // 如果缓冲区满了，强制终止并重置索引（避免溢出）
            if (index >= RX_BUFF_SIZE - 1) {
                UART1_SendString((uint8_t *)"Buffer Overflow: ", 17);
                UART1_SendString(RxBuff, index);
                UART1_SendString((uint8_t *)"\r\n", 2);
                index = 0;
            }
        }

        PT_YIELD(pt);
    }

    PT_END(pt);
}

/*********************************************************************
 * @fn      protothread_send
 *
 * @brief   定时发送数据的protothread
 *
 * @param   pt - protothread控制块
 *
 * @return  protothread状态
 */
PT_THREAD(protothread_send(struct pt *pt))
{
    PT_BEGIN(pt);

    static uint8_t send_interval = 100; // 发送间隔，单位：ms
    static uint8_t i = 0;

    while (1) {
        // 不再发送提示信息，只做定时操作
        for (i = 0; i < send_interval; i++) {
            PT_YIELD(pt);
        }
    }

    PT_END(pt);
}
