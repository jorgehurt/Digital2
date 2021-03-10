/* 
 * File:   Template Digital 2
 * Author: Jorge Rafael Hurtado Garcia 18052
 * 
 * Template Proyectos Digital 2
 * 
 * Created on 2021
 */

#include <xc.h>
#include <stdint.h>
#include "eusart.h"

void UART_INIT(void){
    //Habilitamos las Interrupciones // Habilitamos UART a 9600 BaudRate.
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    PIE1bits.RCIE = 1;
    PIE1bits.TXIE = 1;
    // Limpiamos las banderas
    PIR1bits.RCIF = 0;
    PIR1bits.TXIF = 0;
    SPBRGH = 0;
    SPBRG = 11; //10417
    TXSTA = 0b00100000;
    RCSTA = 0b10010000;
    BAUDCTLbits.BRG16 = 0;
}
uint8_t UART_READ(){
    if(PIR1bits.RCIF==1){
        PIR1bits.RCIF=0;
        return RCREG;
    }  
}
void UART_WRITE(int data){
  while(!TXSTAbits.TRMT); 
  TXREG = data;
}

void UART_Read_Text(char *Output, unsigned int length)
{
	unsigned int i;
	for(int i=0;i<length;i++)
		Output[i] = UART_READ();
}
//**************************
//Función para mandar un string por UART
//**************************
void UART_Write_Text(char *text)
{
  int i;
  for(i=0;text[i]!='\0';i++) //Por cada caracter del string, mandelo y aumente el contador
	  UART_WRITE(text[i]);
}
