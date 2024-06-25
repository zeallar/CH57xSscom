/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : WCH
 * Version            : V1.0
 * Date               : 2020/08/06
 * Description        : 主函数和系统初始化
 *******************************************************************************/

#include "CH57x_common.h"
#include "CH57x_uart_threads.h"
#include "st7789v_driver.h"
/*********************************************************************
 * @fn      main
 *
 * @brief   主函数 串口交互demo
 *
 * @return  none
 */
//int main()
//{
//    SetSysClock(CLK_SOURCE_PLL_60MHz);
//
//    // 初始化串口
//    UART1_Init();
//
//    // 启动时提示用户输入
//    UART1_SendString((PUINT8)"Enter command: ", 15);
//
//    // 初始化protothread
//    PT_INIT(&pt_recv);
//    PT_INIT(&pt_send);
//
//    while (1) {
//        protothread_recv(&pt_recv);
//        protothread_send(&pt_send);
//    }
//}

