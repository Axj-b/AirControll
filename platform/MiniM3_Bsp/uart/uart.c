/**************************************************************
**  Project: STM32 Embedded System
**  Description: STM32 USART Functions
**  Version: V1.1  
***************************************************************/ 
#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include "stm32f10x.h"
#include "uart.h"

size_t strlen(const char *str) {
    size_t len = 0;
    while (*str++) len++;
    return len;
}

extern void USART1_Send_Byte(uint8_t c); // UART send character function

    void uart_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'd': {
                    int num = va_arg(args, int);
                    if (num < 0) {
                        USART1_Send_Byte('-');
                        num = -num;
                    }
                    send_number(num, 10);
                    break;
                }
                case 'u': {
                    unsigned int num = va_arg(args, unsigned int);
                    send_number(num, 10);
                    break;
                }
                case 's': {
                    char *str = va_arg(args, char*);
                    while (*str) {
                        USART1_Send_Byte(*str++);
                    }
                    break;
                }
                case 'x': {
                    unsigned int num = va_arg(args, unsigned int);
                    send_number(num, 16);
                    break;
                }
                default:
                    USART1_Send_Byte('%');
                    USART1_Send_Byte(*format);
            }
        } else {
            USART1_Send_Byte(*format);
        }
        format++;
    }

    va_end(args);
}

void send_number(unsigned int num, int base) {
    char buffer[10];
    int i = 0;
    do {
        int digit = num % base;
        buffer[i++] = (digit < 10) ? '0' + digit : 'a' + (digit - 10);
        num /= base;
    } while (num > 0);

    while (i > 0) {
        USART1_Send_Byte(buffer[--i]);
    }
}

void USART1_Send_Byte(uint8_t Data) { 
    // Wait until TX buffer is empty
    while (!(USART1->SR & USART_FLAG_TXE));
    
    // Send the byte
    USART1->DR = Data;
}


void USART_Send_Str(const char* data) {
    size_t len = strlen(data);
    for (size_t i = 0; i < len; i++) {
        USART1_Send_Byte(data[i]);
    }
    if(data[len - 1] == '\n') {
        USART_Send_Enter();
    }
}

void USART_Send_Enter(void) {
    USART1_Send_Byte(0x0D);
    USART1_Send_Byte(0x0A);
}

void USART_Put_Num(uint32_t dat) {
    char temp[20];
    uint32_ttostr(dat, temp);
    USART_Send_Str(temp);
}

void USART_Put_Inf(const char *inf, uint32_t dat) {
    USART_Send_Str(inf);
    USART_Put_Num(dat);
    USART_Send_Str("\n");  
}

void USART_Configuration(void) {
    USART_InitTypeDef USART_InitStructure;
    USART_InitStructure.USART_BaudRate = 115200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_Init(USART1, &USART_InitStructure);
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
    USART_Cmd(USART1, ENABLE);     
}

void USART1_IRQHandler(void) {
    uint8_t c;
    if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) {     
        c = (uint8_t)(USART1->DR & 0xFF);
        USART1_Send_Byte(c);     
    } 
}

void uint32_ttostr(uint32_t dat, char *str) {
    char temp[20];
    uint8_t i = 0, j = 0;
    if (dat == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }
    while (dat) {
        temp[i++] = (dat % 10) + '0';
        dat /= 10;
    }
    for (j = 0; j < i; j++) {
        str[j] = temp[i - j - 1];
    }
    str[j] = '\0';
}

int fputc(int ch, FILE *f) {
    USART_SendData(USART1, (uint8_t)ch);
    while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
    return ch;
}

int fgetc(FILE *f) {
    while (!(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == SET));
    return (int)(USART_ReceiveData(USART1) & 0xFF);
}


void USART_Get_String(char *str, uint8_t max_length) {
    uint8_t i = 0;
    while (i < max_length - 1) {
        int ch = fgetc(stdin);
        if (ch == '\r' || ch == '\n') {
            break;
        }
        str[i++] = ch;
    }
    str[i] = '\0';
}