/* 
 * File:   Template Digital 2
 * Author: Jorge Rafael Hurtado Garcia 18052
 * 
 * Template Proyectos Digital 2
 * 
 * Created on 2021
 */

//**************************
// Importación de librerías
//**************************

#include <xc.h>
#include <stdint.h>
#include "pic16f887.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "I2C.h"
#include "RTC.h"
#include "eusart.h"
#define _XTAL_FREQ 4000000

uint8_t i, second, minute, hour, m_day, month, year, Bandera;
uint8_t Start = 0b00000000;


//**************************
// Palabra de configuración
//**************************
// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming
// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

void main(void) {
    //Setup
    //Configuracion del Oscilador.
    OSCCONbits.IRCF = 0b110; //4Mhz
    OSCCONbits.OSTS = 0;
    OSCCONbits.HTS = 0;
    OSCCONbits.LTS = 0;
    OSCCONbits.SCS = 1;
    //Configuracion de Puertos y lectura de datos.
    //Lectura de potencimetros en AN0 y AN1
    ANSEL = 0;
    ANSELH = 0;
    TRISA = 0;
    TRISB = 0;
    TRISD = 0;
    TRISC=0b11011000;
    TRISE = 0;
    PORTA = 0;
    PORTB = 0;
    PORTC = 0;
    PORTD = 0;
    PORTE = 0;
    minute = 45;
    hour = 8;
    m_day = 5;
    month = 3;
    year = 21;
    Bandera = 0b00000000;
    
      //Habilitamos las Interrupciones // Habilitamos UART a 9600 BaudRate.
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    PIE1bits.RCIE = 1;
    //PIE1bits.TXIE = 1;
    // Limpiamos las banderas
    PIR1bits.RCIF = 0;
    PIR1bits.TXIF = 0;
    SPBRGH = 0;
    SPBRG = 0b00011001;
    TXSTA = 0b00100100;
    RCSTA = 0b10010000;
    BAUDCTLbits.BRG16 = 0;
    
    //
    //**************************
    // Loop Program
    //**************************
    I2C_Master_Init(100000);
    SET_RTC(minute, hour, m_day, month, year);
    //UART_INIT();
    while (1) {
        READ_RTC();
        TXREG=second;
        __delay_ms(20);
        __delay_ms(20);
        PORTD = Bandera;
    }
}

 void __interrupt() ISR(void) {
    if(PIR1bits.RCIF==1){
        PIR1bits.RCIF=0;
        Bandera = RCREG;
        return;
    }  
 }