#include "CH57x_common.h"
#include "st7789v_driver.h"

#define ST7789V_RES_PIN     GPIO_Pin_15 // A15 - Reset Pin
#define ST7789V_DC_PIN      GPIO_Pin_5  // A5 - Data/Command Pin
#define ST7789V_CS_PIN      GPIO_Pin_12 // A12 - Chip Select Pin
#define ST7789V_CLK_PIN     GPIO_Pin_13 // A13 - SPI Clock Pin
#define ST7789V_MOSI_PIN    GPIO_Pin_14 // A14 - SPI MOSI Pin
#define ST7789V_BL_PIN      GPIO_Pin_4  // A4 - Backlight Control Pin

void LCD_IO_Init(void) {
    GPIOA_ModeCfg(ST7789V_RES_PIN | ST7789V_DC_PIN | ST7789V_CS_PIN | ST7789V_CLK_PIN | ST7789V_MOSI_PIN | ST7789V_BL_PIN, GPIO_ModeOut_PP_5mA);
    GPIOA_ResetBits(ST7789V_RES_PIN); // Reset the display
    LCD_IO_Delay(50);
    GPIOA_SetBits(ST7789V_RES_PIN);
    GPIOA_ResetBits(ST7789V_BL_PIN); // Turn on backlight (低电平点亮)

    SPI0_MasterDefInit();
}

void LCD_IO_WriteCommand(uint8_t command) {
    GPIOA_ResetBits(ST7789V_CS_PIN);  // CS低电平
    GPIOA_ResetBits(ST7789V_DC_PIN);  // DC低电平，表示命令
    SPI0_MasterSendByte(command);
    GPIOA_SetBits(ST7789V_CS_PIN);  // CS高电平
}

void LCD_IO_WriteData(uint8_t *data, uint8_t length) {
    GPIOA_ResetBits(ST7789V_CS_PIN);  // CS低电平
    GPIOA_SetBits(ST7789V_DC_PIN);    // DC高电平，表示数据
    SPI0_MasterTrans(data, length);
    GPIOA_SetBits(ST7789V_CS_PIN);  // CS高电平
}

void LCD_IO_Delay(uint32_t delay) {
    DelayMs(delay);
}

void DebugInit(void) {
    GPIOA_SetBits(GPIO_Pin_9);
    GPIOA_ModeCfg(GPIO_Pin_8, GPIO_ModeIN_PU);
    GPIOA_ModeCfg(GPIO_Pin_9, GPIO_ModeOut_PP_5mA);
    UART1_DefInit();
}

int main() {
    SetSysClock(CLK_SOURCE_PLL_60MHz);

    DebugInit();
    PRINT("Start @ChipID=%02X\n", R8_CHIP_ID);

    PRINT("1.spi0 mul master mode send data ...\n");
    DelayMs(100);

    SPI0_MasterDefInit();
    st7789_Init();

    PRINT("Initialization complete.\n");

    st7789_Clear(ST7789_WHITE);  // 清空屏幕为白色
    PRINT("Screen cleared.\n");

    st7789_FillArea(ST7789_RED, 50, 50, 100, 100);  // 在屏幕上绘制一个红色矩形
    PRINT("Drew a red rectangle.\n");

    PRINT("END ...\n");
    while (1);
}
