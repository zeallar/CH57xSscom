#ifndef ST7789V_DRIVER_H
#define ST7789V_DRIVER_H

#include "CH57x_common.h"
#include "CH57x_spi.h"
#include "CH57x_gpio.h"
#include "stdint.h"

// ST7789V GPIO和SPI定义
#define ST7789V_RES_PIN     GPIO_Pin_15 // A15 - Reset Pin
#define ST7789V_DC_PIN      GPIO_Pin_5  // A5 - Data/Command Pin
#define ST7789V_CS_PIN      GPIO_Pin_12 // A12 - Chip Select Pin
#define ST7789V_CLK_PIN     GPIO_Pin_13 // A13 - SPI Clock Pin
#define ST7789V_MOSI_PIN    GPIO_Pin_14 // A14 - SPI MOSI Pin
#define ST7789V_BL_PIN      GPIO_Pin_4  // A4 - Backlight Control Pin

#define ST7789V_BG_H GPIOA_SetBits(ST7789V_BL_PIN)  // 背光开
#define ST7789V_BG_L GPIOA_ResetBits(ST7789V_BL_PIN) // 背光关

#define ST7789V_BG_ON ST7789V_BG_H
#define ST7789V_BG_OFF ST7789V_BG_L

// ST7789V 命令定义
#define ST7789V_CMD_SWRESET 0x01
#define ST7789V_CMD_SLPOUT  0x11
#define ST7789V_CMD_DISPON  0x29
#define ST7789V_CMD_CASET   0x2A
#define ST7789V_CMD_RASET   0x2B
#define ST7789V_CMD_RAMWR   0x2C

void SPI_Init(void);
void GPIO_Init(void);
void ST7789V_SendCommand(uint8_t cmd);
void ST7789V_SendData(uint8_t data);
void ST7789V_Init(void);
void ST7789V_TestPattern(void);
void ST7789V_Clear(uint16_t color);

#endif // ST7789V_DRIVER_H
