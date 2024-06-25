#include "gpio_test.h"

#define TEST_PIN_RES  GPIO_Pin_15 // A15 - Reset Pin
#define TEST_PIN_DC   GPIO_Pin_5  // A5 - Data/Command Pin
#define TEST_PIN_CS   GPIO_Pin_12 // A12 - Chip Select Pin
#define TEST_PIN_CLK  GPIO_Pin_13 // A13 - SPI Clock Pin
#define TEST_PIN_MOSI GPIO_Pin_14 // A14 - SPI MOSI Pin
#define TEST_PIN_BL   GPIO_Pin_4  // A4 - Backlight Control Pin

static const uint16_t test_pins[] = {TEST_PIN_RES, TEST_PIN_DC, TEST_PIN_CS, TEST_PIN_CLK, TEST_PIN_MOSI, TEST_PIN_BL};
static const char *pin_names[] = {"RESET", "DC", "CS", "CLK", "MOSI", "BLCK"};

void GPIO_Test(void) {
    uint8_t current_pin = 0;
    char user_input[2];

    // 配置所有测试引脚为输出模式
    for (int i = 0; i < sizeof(test_pins) / sizeof(test_pins[0]); i++) {
        GPIOA_ModeCfg(test_pins[i], GPIO_ModeOut_PP_5mA);
    }

    while (1) {
        PRINT("Testing pin %s (input '1' to set high, '0' to set low):\n", pin_names[current_pin]);

        while (1) {
            if (UART1_RecvString(user_input)) {
                if (user_input[0] == '1') {
                    GPIOA_SetBits(test_pins[current_pin]);
                    PRINT("Pin %s High\n", pin_names[current_pin]);
                    break;
                } else if (user_input[0] == '0') {
                    GPIOA_ResetBits(test_pins[current_pin]);
                    PRINT("Pin %s Low\n", pin_names[current_pin]);
                    break;
                } else {
                    PRINT("Invalid input, please enter '1' or '0'\n");
                }
            }
        }

        PRINT("Continue to next pin? (input 'y' for yes, 'n' for no):\n");
        while (1) {
            if (UART1_RecvString(user_input)) {
                if (user_input[0] == 'y' || user_input[0] == 'Y') {
                    current_pin = (current_pin + 1) % (sizeof(test_pins) / sizeof(test_pins[0]));
                    break;
                } else if (user_input[0] == 'n' || user_input[0] == 'N') {
                    break;
                } else {
                    PRINT("Invalid input, please enter 'y' or 'n'\n");
                }
            }
        }
    }
}
