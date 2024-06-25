#include "st7789v_driver.h"

void st7789_Init(void) {
    LCD_IO_Init();

    const uint8_t caset[4] = {
        0x00, 0x00,
        (ST7789_LCD_WIDTH - 1) >> 8, (ST7789_LCD_WIDTH - 1) & 0xFF
    };

    const uint8_t raset[4] = {
        0x00, 0x00,
        (ST7789_LCD_HEIGHT - 1) >> 8, (ST7789_LCD_HEIGHT - 1) & 0xFF
    };

    const st7789_command_t initSequence[] = {
        {ST7789_CMD_SLPIN, 10, 0, NULL},
        {ST7789_CMD_SWRESET, 200, 0, NULL},
        {ST7789_CMD_SLPOUT, 120, 0, NULL},
        {ST7789_CMD_CMD2EN, 0, 0, NULL},
        {ST7789_CMD_MADCTL, 0, 1, (uint8_t *)"\x00"},
        {ST7789_CMD_COLMOD, 0, 1, (uint8_t *)"\x55"},
        {ST7789_CMD_INVON, 0, 0, NULL},
        {ST7789_CMD_CASET, 0, 4, (uint8_t *)caset},
        {ST7789_CMD_RASET, 0, 4, (uint8_t *)raset},
        {ST7789_CMD_PORCTRL, 0, 5, (uint8_t *)"\x0c\x0c\x00\x33\x33"},
        {ST7789_CMD_GCTRL, 0, 1, (uint8_t *)"\x35"},
        {ST7789_CMD_VCOMS, 0, 1, (uint8_t *)"\x1f"},
        {ST7789_CMD_VDVVRHEN, 0, 1, (uint8_t *)"\x01"},
        {ST7789_CMD_LCMCTRL, 0, 1, (uint8_t *)"\x2c"},
        {ST7789_CMD_VRHS, 0, 1, (uint8_t *)"\x12"},
        {ST7789_CMD_VDVSET, 0, 1, (uint8_t *)"\x20"},
        {ST7789_CMD_PWCTRL1, 0, 2, (uint8_t *)"\xa4\xa1"},
        {ST7789_CMD_FRCTR2, 0, 1, (uint8_t *)"\x0f"},
        {ST7789_CMD_GAMSET, 0, 1, (uint8_t *)"\x01"},
        {ST7789_CMD_PVGAMCTRL, 0, 14, (uint8_t *)"\xd0\x08\x11\x08\x0c\x15\x39\x33\x50\x36\x13\x14\x29\x2d"},
        {ST7789_CMD_NVGAMCTRL, 0, 14, (uint8_t *)"\xd0\x08\x10\x08\x06\x06\x39\x44\x51\x0b\x16\x14\x2f\x31"},
        {ST7789_CMD_DISPON, 100, 0, NULL},
        {ST7789_CMD_RAMWR, 50, 0, NULL},
        {ST7789_CMDLIST_END, 0, 0, NULL},
    };

    PRINT("Running Init Sequence...\n");
    st7789_RunCommands(initSequence);

    LCD_IO_Delay(10);
    st7789_Clear(ST7789_WHITE);

    const st7789_command_t initSequence2[] = {
        {ST7789_CMD_RGBCTRL, 0, 3, (uint8_t *)"\x42\x08\x3c"},
        {ST7789_CMD_RAMCTRL, 0, 2, (uint8_t *)"\x11\xc2"},
        {ST7789_CMD_DISPON, 100, 0, NULL},
        {ST7789_CMD_RAMWR, 50, 0, NULL},
        {ST7789_CMDLIST_END, 0, 0, NULL},
    };

    PRINT("Running Init Sequence 2...\n");
    st7789_RunCommands(initSequence2);
}

void st7789_Reset(void) {
    LCD_IO_Init();
}

void st7789_DisplayOn(void) {
    LCD_IO_WriteCommand(ST7789_CMD_DISPON);
}

void st7789_DisplayOff(void) {
    LCD_IO_WriteCommand(ST7789_CMD_DISPOFF);
}

void st7789_RunCommand(const st7789_command_t *command) {
    PRINT("Sending Command: 0x%02X\n", command->command);
    LCD_IO_WriteCommand(command->command);
    if (command->dataSize > 0) {
        PRINT("Sending Data: ");
        for (int i = 0; i < command->dataSize; i++) {
            PRINT("0x%02X ", command->data[i]);
        }
        PRINT("\n");
        LCD_IO_WriteData(command->data, command->dataSize);
    }
    if (command->waitMs > 0) {
        LCD_IO_Delay(command->waitMs);
    }
}

void st7789_RunCommands(const st7789_command_t *sequence) {
    while (sequence->command != ST7789_CMDLIST_END) {
        st7789_RunCommand(sequence);
        sequence++;
    }
}

void st7789_SetWindow(uint16_t xStart, uint16_t yStart, uint16_t xEnd, uint16_t yEnd) {
    uint8_t caset[4];
    uint8_t raset[4];

    caset[0] = (uint8_t)(xStart >> 8);
    caset[1] = (uint8_t)(xStart & 0xFF);
    caset[2] = (uint8_t)(xEnd >> 8);
    caset[3] = (uint8_t)(xEnd & 0xFF);

    raset[0] = (uint8_t)(yStart >> 8);
    raset[1] = (uint8_t)(yStart & 0xFF);
    raset[2] = (uint8_t)(yEnd >> 8);
    raset[3] = (uint8_t)(yEnd & 0xFF);

    st7789_command_t sequence[] = {
        {ST7789_CMD_CASET, 0, 4, caset},
        {ST7789_CMD_RASET, 0, 4, raset},
        {ST7789_CMDLIST_END, 0, 0, NULL},
    };

    st7789_RunCommands(sequence);

    const st7789_command_t ram_wr = {ST7789_CMD_RAMWR, 0, 0, NULL};
    st7789_RunCommand(&ram_wr);
}

void st7789_FillArea(uint16_t color, uint16_t startX, uint16_t startY, uint16_t width, uint16_t height) {
    uint8_t hi = (color >> 8) & 0xFF;
    uint8_t lo = (uint8_t)color;

    st7789_SetWindow(startX, startY, startX + width - 1, startY + height - 1);

    PRINT("Filling Area with Color: 0x%04X\n", color);
    for (uint32_t i = 0; i < width * height; i++) {
        LCD_IO_WriteData(&hi, 1);
        LCD_IO_WriteData(&lo, 1);
    }
}

void st7789_Clear(uint16_t color) {
    st7789_FillArea(color, 0, 0, ST7789_LCD_WIDTH, ST7789_LCD_HEIGHT);
}
