#include "uart.h"

uint8_t InitialTxBuff[] = "This is a tx exam\r\n"; // ȥ��const�޶���

int main(void)
{
    SetSysClock(CLK_SOURCE_PLL_60MHz);

    UART1_Init();
    UART1_SetTxBuff(InitialTxBuff); // ���÷��ͻ�����
    UART1_SendMessage(InitialTxBuff); // ���ͳ�ʼ��Ϣ
    UART1_InterruptConfig();   // �����ж�

    while (1)
    {
        // ϵͳ���жϴ���ʱ��������
    }
}
