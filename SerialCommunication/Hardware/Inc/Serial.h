#ifndef __SERIAL_H
#define __SERIAL_H
#include <stdio.h>


//串口发送
void Serial_SendByte(uint8_t Byte);
void Serial_SendString(char* str);
void Serial_SendNum(uint32_t Num);

uint32_t My_Pow(uint32_t num, uint32_t n);
uint8_t My_numlen(uint32_t Num);
uint16_t My_strlen(char* str);

int fputc (int ch, FILE *f);

//串口接收
void Serial_Init(void);
uint8_t Serial_ReceiveByte(void);
uint8_t Serial_GetRxFlag(void);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
#endif
