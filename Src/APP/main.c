/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : WCH
 * Version            : V1.0
 * Date               : 2020/08/06
 * Description        : ��������ϵͳ��ʼ��
 *******************************************************************************/

#include "CH57x_common.h"
#include "CH57x_uart_threads.h"
#include "st7789v_driver.h"
/*********************************************************************
 * @fn      main
 *
 * @brief   ������ ���ڽ���demo
 *
 * @return  none
 */
//int main()
//{
//    SetSysClock(CLK_SOURCE_PLL_60MHz);
//
//    // ��ʼ������
//    UART1_Init();
//
//    // ����ʱ��ʾ�û�����
//    UART1_SendString((PUINT8)"Enter command: ", 15);
//
//    // ��ʼ��protothread
//    PT_INIT(&pt_recv);
//    PT_INIT(&pt_send);
//
//    while (1) {
//        protothread_recv(&pt_recv);
//        protothread_send(&pt_send);
//    }
//}

