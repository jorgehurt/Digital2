/* 
 * File:  jORGE HURTADO 18052 
 * Author: 
 * Comments:
 * Revision history: 
 */

#ifndef _UART_H
#define	_UART_H
#ifndef _XTAL_FREQ
#define _XTAL_FREQ 8000000
#endif
uint8_t UART_INIT(const long int baudrate);
uint8_t UART_READ(void);
void UART_Read_Text(char *Output, unsigned int length);
void UART_WRITE(char data);
void UART_Write_Text(char *text);

#endif	/* UART_H */