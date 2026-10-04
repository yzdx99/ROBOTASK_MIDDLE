#include "stm32f1xx_hal.h"

// 判断被按下的按键编号
uint8_t Key_Scan(void)
{
    uint8_t KeyNum = 0;

    if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == 0)
    {
        HAL_Delay(20);
        while (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0) == 0);
        HAL_Delay(20);
        KeyNum = 1;
    }

    if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10) == 0)
    {
        HAL_Delay(20);
        while (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10) == 0);
        HAL_Delay(20);
        KeyNum = 2;
    }

    return KeyNum;
}
