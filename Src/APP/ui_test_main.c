//#include "st7789v_driver.h"
//#include "gpio_test.h"
//__attribute__((aligned(4))) uint8_t spiBuff[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6};
//__attribute__((aligned(4))) uint8_t spiBuffrev[16];

/*********************************************************************
 * @fn      DebugInit
 *
 * @brief   调试初始化
 *
 * @return  none
 */
//void DebugInit(void)
//{
//    GPIOA_SetBits(GPIO_Pin_9);
//    GPIOA_ModeCfg(GPIO_Pin_8, GPIO_ModeIN_PU);
//    GPIOA_ModeCfg(GPIO_Pin_9, GPIO_ModeOut_PP_5mA);
//    UART1_DefInit();
//}

/*********************************************************************
 * @fn      main
 *
 * @brief   主函数
 *
 * @return  none
 */
//int main()
//{
//    SetSysClock(CLK_SOURCE_PLL_60MHz);
//
//    /* 配置串口调试 */
//    DebugInit();
//    PRINT("Start @ChipID=%02X\n", R8_CHIP_ID);
//
//    /* SPI 和 GPIO 初始化 */
//    SPI_Init();
//    GPIO_Init();
//
//    /* 初始化ST7789V */
//    ST7789V_Init();
//    PRINT("ST7789V Initialized...\n");
//
//    /* 显示测试图案 */
//    ST7789V_TestPattern();
//    PRINT("Test Pattern Displayed...\n");
//
//    while (1) {
//        // 主循环
//    }
//}

////gpio测试
//int main()
//{
//    SetSysClock(CLK_SOURCE_PLL_60MHz);
//
//    /* 配置串口调试 */
//    DebugInit();
//    PRINT("Start @ChipID=%02X\n", R8_CHIP_ID);
//
//    /* 运行GPIO测试 */
//    GPIO_Test();
//
//    while (1) {
//        // 主循环
//    }
//}
