#ifndef _ST7789V_H_
#define _ST7789V_H_

#ifdef __cplusplus
 extern "C" {
#endif
#include "CH57x_common.h"
#include <stdint.h>
#include <stdlib.h>

#define ST7789_LCD_WIDTH             240
#define ST7789_LCD_HEIGHT            320

#define ST7789_CMD_NOP               0x00
#define ST7789_CMD_SWRESET           0x01
#define ST7789_CMD_RDDID             0x04
#define ST7789_CMD_RDDST             0x09
#define ST7789_CMD_SLPIN             0x10
#define ST7789_CMD_SLPOUT            0x11
#define ST7789_CMD_PTLON             0x12
#define ST7789_CMD_NORON             0x13
#define ST7789_CMD_INVOFF            0x20
#define ST7789_CMD_INVON             0x21
#define ST7789_CMD_GAMSET            0x26
#define ST7789_CMD_DISPOFF           0x28
#define ST7789_CMD_DISPON            0x29
#define ST7789_CMD_CASET             0x2A
#define ST7789_CMD_RASET             0x2B
#define ST7789_CMD_RAMWR             0x2C
#define ST7789_CMD_RAMRD             0x2E
#define ST7789_CMD_COLMOD            0x3A
#define ST7789_CMD_MADCTL            0x36
#define ST7789_CMD_PORCTRL           0xB2
#define ST7789_CMD_GCTRL             0xB7
#define ST7789_CMD_VCOMS             0xBB
#define ST7789_CMD_LCMCTRL           0xC0
#define ST7789_CMD_VDVVRHEN          0xC2
#define ST7789_CMD_VRHS              0xC3
#define ST7789_CMD_VDVSET            0xC4
#define ST7789_CMD_PWCTRL1           0xD0
#define ST7789_CMD_FRCTR2            0xC6
#define ST7789_CMD_PVGAMCTRL         0xE0
#define ST7789_CMD_NVGAMCTRL         0xE1
#define ST7789_CMD_RGBCTRL           0xB1
#define ST7789_CMD_RAMCTRL           0xB0
#define ST7789_CMD_CMD2EN            0xDF
#define ST7789_CMDLIST_END           0xFF

#define ST7789_BLACK   0x0000
#define ST7789_WHITE   0xFFFF
#define ST7789_RED     0xF800

typedef struct {
    uint8_t command;
    uint16_t waitMs;
    uint8_t dataSize;
    uint8_t *data;
} st7789_command_t;

void st7789_Init(void);
void st7789_Reset(void);
void st7789_DisplayOn(void);
void st7789_DisplayOff(void);
void st7789_RunCommand(const st7789_command_t *command);
void st7789_RunCommands(const st7789_command_t *sequence);
void st7789_SetWindow(uint16_t xStart, uint16_t yStart, uint16_t xEnd, uint16_t yEnd);
void st7789_FillArea(uint16_t color, uint16_t startX, uint16_t startY, uint16_t width, uint16_t height);
void st7789_Clear(uint16_t color);

extern void LCD_IO_Init(void);
extern void LCD_IO_WriteCommand(uint8_t command);
extern void LCD_IO_WriteData(uint8_t *data, uint8_t length);
extern void LCD_IO_Delay(uint32_t delay);

#ifdef __cplusplus
}
#endif

#endif  // _ST7789V_H_
