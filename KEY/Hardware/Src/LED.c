#include "stm32f1xx_hal.h"

// LED高电平点亮

// LED_B(对应KEY_1)的开、关、翻转
void LED_B_ON(void)
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
}

void LED_B_OFF(void)
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
}

void LED_B_TURN(void)
{
    if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0)
    {
        LED_B_ON();
    }
    else
    {
        LED_B_OFF();
    }
}


// LED_R（对应KEY_2)的开、关、翻转
void LED_R_ON(void)
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);
}

void LED_R_OFF(void)
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);
}

void LED_R_TURN(void)
{
    if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2) == 0)
    {
        LED_R_ON();
    }
    else
    {
        LED_R_OFF();
    }
}
