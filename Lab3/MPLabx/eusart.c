#include <xc.h>
#include <stdint.h>
#include "eusart.h"

uint8_t UART_INIT(const long int baudrate){
	SPBRG = (_XTAL_FREQ - baudrate*16)/(baudrate*16); //Valor a meter a SPBRG, dependinte del baudrate usado
     TXSTAbits.BRGH = 1;
    TXSTAbits.TXEN = 1;
    TXSTAbits.SYNC = 0;
    TXSTAbits.TX9 = 0;
    //RX
    RCSTAbits.CREN = 1;
    RCSTAbits.SPEN = 1;
    RCSTAbits.RX9 = 0;
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
