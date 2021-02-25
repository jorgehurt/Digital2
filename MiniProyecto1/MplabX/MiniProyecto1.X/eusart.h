/* 
 * File: Eusart.h   
 * Author: JORGE HURTADO 18052
 * Comments:
 * Revision history: 
 */

#ifndef _UART_H
#define	_UART_H
#ifndef _XTAL_FREQ
#define _XTAL_FREQ 8000000
#endif
void UART_INIT(void);
uint8_t UART_READ(void);
void UART_WRITE(int data);
void UART_Write_Text(char *text);
void UART_Read_Text(char *Output, unsigned int length);
#endif	/* UART_H */