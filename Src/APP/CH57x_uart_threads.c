/********************************** (C) COPYRIGHT *******************************
 * File Name          : CH57x_uart_threads.c
 * Author             : WCH
 * Version            : V1.0
 * Date               : 2020/08/06
 * Description        : ���ں�protothread��غ�����ʵ��
 *******************************************************************************/

#include "CH57x_uart_threads.h"
#include <string.h>

uint8_t TxBuff[TX_BUFF_SIZE];
uint8_t RxBuff[RX_BUFF_SIZE];

struct pt pt_recv, pt_send;

/*********************************************************************
 * @fn      UART1_Init
 *
 * @brief   ��ʼ������1
 *
 * @return  none
 */
void UART1_Init(void)
{
    GPIOA_SetBits(GPIO_Pin_9);
    GPIOA_ModeCfg(GPIO_Pin_8, GPIO_ModeIN_PU);      // RXD-������������
    GPIOA_ModeCfg(GPIO_Pin_9, GPIO_ModeOut_PP_5mA); // TXD-�������������ע������IO������ߵ�ƽ
    UART1_DefInit();
}

/*********************************************************************
 * @fn      protothread_recv
 *
 * @brief   ������մ������ݵ�protothread
 *
 * @param   pt - protothread���ƿ�
 *
 * @return  protothread״̬
 */

PT_THREAD(protothread_recv(struct pt *pt))
{
    PT_BEGIN(pt);

    static uint8_t len;
    static uint8_t index = 0;

    while (1) {
        len = UART1_RecvString(RxBuff + index); // �����ַ�����׷�ӵ�������
        if (len) {
            index += len; // ���µ�ǰ����������
            RxBuff[index] = '\0'; // ȷ���ַ�����ֹ��

            // �����յ����ַ����Ƿ�������з�
            uint8_t *newline_pos = (uint8_t *)strchr((char *)RxBuff, '\n');
            if (newline_pos != NULL) {
                // �ҵ����з���λ��
                size_t line_length = (newline_pos - RxBuff) + 1;

                // ���л��Դ���
                UART1_SendString((uint8_t *)"Received: ", 10);
                UART1_SendString(RxBuff, line_length);
                UART1_SendString((uint8_t *)"\r\n", 2);

                // ��������ʣ�ಿ��ǰ��
                memmove(RxBuff, newline_pos + 1, index - line_length);
                index -= line_length;
            }

            // ������������ˣ�ǿ����ֹ���������������������
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
 * @brief   ��ʱ�������ݵ�protothread
 *
 * @param   pt - protothread���ƿ�
 *
 * @return  protothread״̬
 */
PT_THREAD(protothread_send(struct pt *pt))
{
    PT_BEGIN(pt);

    static uint8_t send_interval = 100; // ���ͼ������λ��ms
    static uint8_t i = 0;

    while (1) {
        // ���ٷ�����ʾ��Ϣ��ֻ����ʱ����
        for (i = 0; i < send_interval; i++) {
            PT_YIELD(pt);
        }
    }

    PT_END(pt);
}
