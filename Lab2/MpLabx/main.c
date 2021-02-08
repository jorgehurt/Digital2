/* 
 * File:   Template Digital 2
 * Author: Jorge Rafael Hurtado Garcia 18052
 * 
 * Template Proyectos Digital 2
 * 
 * Created on 2021
 */

//**************************
// Importaci�n de librer�as
//**************************

#include <xc.h>
#include "oscilador.h"
#include "adc.h"

//**************************
// Palabra de configuraci�n
//**************************
// CONFIG1
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator: Crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)


#define _XTAL_FREQ 8000000


#define Ledr PORTEbits.RE0

//**************************
// Variables
//**************************

char contadorJA = 0;


//**************************
// Prototipos de funciones
//**************************
void setup(void);
//**************************
// Ciclo principal
//**************************

void main(void) {

    setup();

    //**************************
    // Loop principal
    //**************************

    while (1) {

    }
}

//**************************
// Configuraci�n
//**************************

void setup(void) {
    //Configuracion del Oscilador con libreria.
    initosc(7);
    OSCCONbits.OSTS = 0;
    OSCCONbits.HTS = 0;
    OSCCONbits.LTS = 0;
    //Configuracion de Las interrupciones (Habilitacion de las mismas.)
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    INTCONbits.RBIE = 1;
    INTCONbits.T0IE = 1;
    INTCONbits.INTE = 1;
    PIE1bits.ADIE = 1;
    //Limpieza de Banderas de Interrupciones.
    INTCONbits.T0IF = 0;//Bandera de Timer 0
    INTCONbits.RBIF = 0;//Bandera de IOC
    PIR1bits.ADIF = 0;//Bandera del ADC
    //Enable Bits de IOC del Puerto B en RB0 y RB1 para los PushButton.
    IOCBbits.IOCB0 = 1;
    IOCBbits.IOCB1 = 1;
    IOCBbits.IOCB2 = 1;
    //Configuracion de Puertos y limpieza de los mismos.
    ANSEL = 0;
    ANSELH = 0b00000001;
    TRISA = 0;
    PORTA = 0;
    TRISB = 0b00000111;
    PORTB = 0;
    TRISC = 0;
    PORTC = 0;
    TRISD = 0;
    PORTD = 0;
    TRISE = 0;
    PORTE = 0;
}

//**************************
// Funciones
//**************************

//**************************
// Interrupciones
//**************************

void __interrupt() ISR() {
    if (INTCONbits.RBIF == 1 && PORTBbits.RB0 == 0) {
        PORTD = PORTD + 1;
        INTCONbits.RBIF = 0;
    }
    if (INTCONbits.RBIF == 1 && PORTBbits.RB1 == 0) {
        PORTD = PORTD - 1;
        INTCONbits.RBIF = 0;
    }
    if (INTCONbits.RBIF == 1) {
        INTCONbits.RBIF = 0;
        conversion(1000);
        PORTD=ADRESH;
    }
    
}
