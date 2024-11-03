/**************************************************************
**  Project: STM32 Embedded System
**  Description: Header file for STM32 USART Functions
**  Version: V1.1  
**  Author: Alexej Bohr
**  License: MIT License
**
**  Permission is hereby granted, free of charge, to any person obtaining a copy
**  of this software and associated documentation files (the "Software"), to deal
**  in the Software without restriction, including without limitation the rights
**  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
**  copies of the Software, and to permit persons to whom the Software is
**  furnished to do so, subject to the following conditions:
**
**  The above copyright notice and this permission notice shall be included in all
**  copies or substantial portions of the Software.
**
**  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
**  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
**  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
**  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
**  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
**  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
**  SOFTWARE.
***************************************************************/

#ifndef UART_H
#define UART_H

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

/* Function prototypes for USART functionalities */

/**
 * @brief Initializes USART1 with predefined settings.
 */
void USART_Configuration(void);

/**
 * @brief Sends a single byte over USART1.
 * @param data: The byte to be sent.
 */
void USART1_Send_Byte(uint8_t data);

/**
 * @brief Sends a string over USART1.
 * @param data: Pointer to the null-terminated string to send.
 */
void USART_Send_Str(const char* data);

/**
 * @brief Sends a newline (CR+LF) over USART1.
 */
void USART_Send_Enter(void);

/**
 * @brief Sends an unsigned integer as a string over USART1.
 * @param dat: The unsigned integer to be sent.
 */
void USART_Put_Num(uint32_t dat);

/**
 * @brief Sends a string message and an unsigned integer over USART1.
 * @param inf: Message string to send before the number.
 * @param dat: Unsigned integer to display after the message.
 */
void USART_Put_Inf(const char *inf, uint32_t dat);

/**
 * @brief Custom implementation of printf that sends formatted data over USART1.
 * @param format: Format string.
 * @param ...: Arguments for formatting.
 */
void uart_printf(const char *format, ...);

/**
 * @brief Converts a 32-bit integer to a null-terminated string.
 * @param dat: The integer to convert.
 * @param str: Pointer to the output string buffer.
 */
void uint32_ttostr(uint32_t dat, char *str);

/**
 * @brief Utility function to send numbers in different bases.
 * @param num: Number to be sent.
 * @param base: Base (e.g., 10 for decimal, 16 for hexadecimal).
 */
void send_number(unsigned int num, int base);

/**
 * @brief Implementation of fputc to redirect printf output to USART1.
 * @param ch: Character to send.
 * @param f: File stream (typically stdout).
 * @return Character that was sent.
 */
int fputc(int ch, FILE *f);

/**
 * @brief Implementation of fgetc to read input from USART1 for scanf.
 * @param f: File stream (typically stdin).
 * @return Character that was read.
 */
int fgetc(FILE *f);

/**
 * @brief USART1 Interrupt Handler.
 */
void USART1_IRQHandler(void);


/**
 * @brief Receives a string from USART1 and stores it in a buffer.
 *
 * This function continuously reads characters from USART1 until a newline character ('\n') is received,
 * or until the buffer is full (determined by the 'max_length' parameter). The received characters
 * are stored in the provided buffer, and a null terminator ('\0') is appended to mark the end of the string.
 *
 * @param str: Pointer to the character buffer where the received string will be stored.
 * @param max_length: Maximum length of the string that can be received. If the received string is
 *                     longer than 'max_length', it will be truncated.
 *
 * @return None.
 */
void USART_Get_String(char *str, uint8_t max_length);


#endif /* UART_H */
