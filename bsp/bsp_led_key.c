#include "bsp_led_key.h"

void led_init()
{
    LED_OFF();
    LED_GPIO_INIT();
}
