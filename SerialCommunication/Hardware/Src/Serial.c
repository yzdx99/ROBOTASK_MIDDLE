#include "stm32f1xx_hal.h"
#include "Serial.h"

extern UART_HandleTypeDef huart1;

static uint8_t Serial_RxData;   // 中断收到的字节暂存
static uint8_t Serial_RxFlag;   // 收到新数据的标志

//串口发送

//Serial_SendByte函数
void Serial_SendByte(uint8_t Byte)
{
    HAL_UART_Transmit(&huart1, &Byte , 1, 200);
}
//Serial_SendString函数
void Serial_SendString(char *str)
{
    HAL_UART_Transmit(&huart1, (uint8_t *)str , My_strlen(str), 200);
}
//Serial_SendNum函数   发送不带符号数字
void Serial_SendNum(uint32_t Num)
{
    uint8_t len = My_numlen(Num);
    
    for (uint8_t i = len; i > 0 ; i--)
    {
        uint32_t pos = My_Pow(10,i - 1);
        Serial_SendByte(Num / pos + '0');
        Num %= pos;
    }
}


//My_numlen函数
uint8_t My_numlen(uint32_t Num)
{
    uint8_t i = 0;
    
    do
    {
        i++;
        Num /= 10;
    }
    while(Num);
    
    return i;
}

//My_Pow函数
uint32_t My_Pow(uint32_t num, uint32_t n)
{
    uint32_t  result = 1;
    while(n--)
    {
        result *= num;
    }
    
    return result;
}


//My_strlen函数
uint16_t My_strlen(char* str)
{
    uint16_t i = 0;
    for ( ; str[i] != '\0' ; i++)
    {
    
    }
    return i;
}

//fputc重定向到串口
int fputc (int ch, FILE *f)
{
    Serial_SendByte(ch);
    return ch;
}




//串口接收(单字节)


//接收初始化
void Serial_Init(void)
{
    Serial_RxFlag = 0;
    HAL_UART_Receive_IT(&huart1, &Serial_RxData, 1);
}

//Serial_ReceiveByte函数
uint8_t Serial_ReceiveByte(void)
{
    Serial_RxFlag = 0;          
    return Serial_RxData;
}

//GetRxFlag函数
uint8_t Serial_GetRxFlag(void)
{
    return Serial_RxFlag;   // 直接返回，C 里 0/1 就是 false/true
}

//回调函数  重启接收
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    Serial_RxFlag = 1;
    HAL_UART_Receive_IT(&huart1, &Serial_RxData, 1);
}
