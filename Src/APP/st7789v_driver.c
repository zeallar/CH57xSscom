#include "st7789v_driver.h"

uint16_t gLcdHeight = 240, gLcdWidth = 320;

// SPI ��ʼ��
void SPI_Init(void) {
    SPI0_MasterDefInit();
    SPI0_CLKCfg(4);  // ����ʱ�ӷ�Ƶ
    SPI0_DataMode(Mode0_HighBitINFront);  // ����ģʽ
    PRINT("SPI Initialized.\n");
}

// GPIO ��ʼ��
void GPIO_Init(void) {
    GPIOA_ModeCfg(ST7789V_BL_PIN, GPIO_ModeOut_PP_5mA);  // A4 - �����������
    GPIOA_ModeCfg(ST7789V_DC_PIN, GPIO_ModeOut_PP_5mA);  // A5 - ����/����ѡ������
    GPIOA_ModeCfg(ST7789V_CS_PIN, GPIO_ModeOut_PP_5mA);  // A12 - оƬѡ������
    GPIOA_ModeCfg(ST7789V_RES_PIN, GPIO_ModeOut_PP_5mA); // A15 - ��������
    GPIOA_SetBits(ST7789V_CS_PIN); // Ƭѡ�øߣ�δ����
    GPIOA_SetBits(ST7789V_BL_PIN); // �򿪱���
    PRINT("GPIO Initialized.\n");
}

// ��������
void ST7789V_SendCommand(uint8_t cmd) {
    GPIOA_ResetBits(ST7789V_CS_PIN);
    GPIOA_ResetBits(ST7789V_DC_PIN);
    SPI0_MasterSendByte(cmd);
    GPIOA_SetBits(ST7789V_CS_PIN);
    PRINT("Sent Command: 0x%02X\n", cmd);  // ������Ϣ
    DelayMs(20); // ������ʱ��ȷ����������
}

// ��������
void ST7789V_SendData(uint8_t data) {
    GPIOA_ResetBits(ST7789V_CS_PIN);
    GPIOA_SetBits(ST7789V_DC_PIN);
    SPI0_MasterSendByte(data);
    GPIOA_SetBits(ST7789V_CS_PIN);
    PRINT("Sent Data: 0x%02X\n", data);  // ������Ϣ
    DelayMs(20); // ������ʱ��ȷ�����ݴ������
}

// ���ô�������
void ST7789V_SetWindow(uint16_t Xstart, uint16_t Xend, uint16_t Ystart, uint16_t Yend) {
    ST7789V_SendCommand(ST7789V_CMD_CASET);
    ST7789V_SendData(Xstart >> 8);
    ST7789V_SendData(Xstart & 0xFF);
    ST7789V_SendData(Xend >> 8);
    ST7789V_SendData(Xend & 0xFF);

    ST7789V_SendCommand(ST7789V_CMD_RASET);
    ST7789V_SendData(Ystart >> 8);
    ST7789V_SendData(Ystart & 0xFF);
    ST7789V_SendData(Yend >> 8);
    ST7789V_SendData(Yend & 0xFF);
}

// ��������
void ST7789V_Clear(uint16_t color) {
    uint32_t i, n;
    ST7789V_SetWindow(0, gLcdWidth - 1, 0, gLcdHeight - 1);
    ST7789V_SendCommand(ST7789V_CMD_RAMWR);

    GPIOA_ResetBits(ST7789V_CS_PIN);
    GPIOA_SetBits(ST7789V_DC_PIN);
    GPIOA_SetBits(ST7789V_BL_PIN);

    n = (gLcdHeight * gLcdWidth);

    for (i = 0; i < n; i++) {
        SPI0_MasterSendByte(color >> 8);
        SPI0_MasterSendByte(color & 0xFF);
    }
    GPIOA_SetBits(ST7789V_CS_PIN);
}

// ��ʼ�� ST7789V
void ST7789V_Init(void) {
    GPIOA_ResetBits(ST7789V_RES_PIN);
    DelayMs(100);  // ����
    GPIOA_SetBits(ST7789V_RES_PIN);
    DelayMs(200);
    PRINT("ST7789V Reset.\n");

    ST7789V_SendCommand(ST7789V_CMD_SLPOUT);
    DelayMs(150);
    PRINT("Exit Sleep Mode.\n");

    ST7789V_SendCommand(0x36);
    ST7789V_SendData(0x00);

    ST7789V_SendCommand(0x3A);
    ST7789V_SendData(0x05);

    ST7789V_SendCommand(0xB2);
    ST7789V_SendData(0x0C);
    ST7789V_SendData(0x0C);
    ST7789V_SendData(0x00);
    ST7789V_SendData(0x33);
    ST7789V_SendData(0x33);

    ST7789V_SendCommand(0xB7);
    ST7789V_SendData(0x35);

    ST7789V_SendCommand(0xBB);
    ST7789V_SendData(0x19);

    ST7789V_SendCommand(0xC0);
    ST7789V_SendData(0x2C);

    ST7789V_SendCommand(0xC2);
    ST7789V_SendData(0x01);

    ST7789V_SendCommand(0xC3);
    ST7789V_SendData(0x12);

    ST7789V_SendCommand(0xC4);
    ST7789V_SendData(0x20);

    ST7789V_SendCommand(0xC6);
    ST7789V_SendData(0x0F);

    ST7789V_SendCommand(0xD0);
    ST7789V_SendData(0xA4);
    ST7789V_SendData(0xA1);

    ST7789V_SendCommand(ST7789V_CMD_DISPON);
    DelayMs(200);
    PRINT("Display On.\n");
}

// ��ʾ����ͼ��
void ST7789V_TestPattern(void) {
    int i;
    ST7789V_SetWindow(0, 239, 0, 319);
    ST7789V_SendCommand(ST7789V_CMD_RAMWR);
    for (i = 0; i < 240 * 320; i++) {
        ST7789V_SendData(0xFF); // ��ɫ
        ST7789V_SendData(0x00);
    }
    PRINT("Test Pattern Displayed.\n");
}
