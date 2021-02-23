#include <xc.h>
#include <stdint.h>
#include "eusart.h"

void UART_INIT(void){
    //Habilitamos las Interrupciones
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    PIE1bits.RCIE = 1;
    PIE1bits.TXIE = 1;
    // Limpiamos las banderas
    PIR1bits.RCIF = 0;
    PIR1bits.TXIF = 0;
    SPBRGH = 0;
    SPBRG = 25; //9600
    TXSTA = 0b00100100;
    RCSTA = 0b10010000;
    BAUDCTLbits.BRG16 = 0;
}
uint8_t UART_READ(){
    if(PIR1bits.RCIF==1){
        return RCREG;
    }  
}
void UART_WRITE(char data){
  while(!TXSTAbits.TRMT); 
  TXREG = data;
}
