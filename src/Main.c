#include "uart.h"

uint8_t InitialTxBuff[] = "This is a tx exam\r\n"; // 去掉const限定符

int main(void)
{
    SetSysClock(CLK_SOURCE_PLL_60MHz);

    UART1_Init();
    UART1_SetTxBuff(InitialTxBuff); // 设置发送缓冲区
    UART1_SendMessage(InitialTxBuff); // 发送初始消息
    UART1_InterruptConfig();   // 配置中断

    while (1)
    {
        // 系统在中断触发时处理数据
    }
}
