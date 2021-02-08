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
#include "oscilador.h"
#include "adc.h"

//**************************
// Palabra de configuración
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

//**************************
// Variables
//**************************

char x = 0;
char y = 0;
char pato = 0;
char tog = 0;

uint8_t segmentos[] = {
    0b00111111,
    0b00000110,
    0b01011011,
    0b01001111,
    0b01100110,
    0b01101101,
    0b01111101,
    0b00000111,
    0b01111111,
    0b01101111,
    0b01110111,
    0b01111100,
    0b00111001,
    0b01011110,
    0b01111001,
    0b01110001
};
//**************************
// Prototipos de funciones
//**************************
void setup(void);
void toggle(void);
//**************************
// Ciclo principal
//**************************

void main(void) {

    setup();

    //**************************
    // Loop principal
    //**************************
    while (1) {
        conversion(1000);
        ADCON0bits.ADON = 1;
        __delay_ms(10);
        ADCON0bits.GO_DONE = 1;
        while (ADCON0bits.GO_DONE == 1);
        if (tog == 0) {
            PORTEbits.RE0 = 1;
            PORTEbits.RE1 = 0;
            PORTC = segmentos[y];
            tog=1;

        }
        if (tog == 1) {
            PORTEbits.RE0 = 0;
            PORTEbits.RE1 = 1;
            PORTC = segmentos[x];
            tog=0;

        }
        if (pato>=PORTD){
            PORTBbits.RB3 =1;
        }
        PORTBbits.RB3 =0;

    }
}

//**************************
// Configuración
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
    INTCONbits.T0IF = 0; //Bandera de Timer 0
    INTCONbits.RBIF = 0; //Bandera de IOC
    PIR1bits.ADIF = 0; //Bandera del ADC
    //Enable Bits de IOC del Puerto B en RB0 y RB1 para los PushButton.
    IOCBbits.IOCB0 = 1;
    IOCBbits.IOCB1 = 1;
    IOCBbits.IOCB2 = 1;
    //Configuracion de Puertos y limpieza de los mismos.
    //timer 0 configuration bits
    OPTION_REGbits.nRBPU = 1;
    OPTION_REGbits.INTEDG = 0;
    OPTION_REGbits.T0CS = 0;
    OPTION_REGbits.T0SE = 0;
    OPTION_REGbits.PSA = 0;
    OPTION_REGbits.PS = 0b000; // 1:2 tmr0 rate 
    TMR0 = 2;
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

void toggle(void) {
    if (tog == 0) {
        tog = 1;
    }
    if (tog == 1) {
        tog = 0;
    }
}


//**************************
// Interrupciones
//**************************

void __interrupt() ISR() {
    if (INTCONbits.RBIF == 1 && PORTBbits.RB0 == 0) {
        PORTD = PORTD + 1;
        INTCONbits.RBIF = 0;
        return;
    }
    if (INTCONbits.RBIF == 1 && PORTBbits.RB1 == 0) {
        PORTD = PORTD - 1;
        INTCONbits.RBIF = 0;
        return;
    }
    if (PIR1bits.ADIF == 1) {
        PIR1bits.ADIF = 0;
        INTCONbits.RBIF = 0;
        pato = ADRESH;
        y = pato;
        x = pato & 0x0F;
        y = ((pato & 0xF0) >> 4);
        return;

    }
    if (INTCONbits.T0IF == 1) {
        toggle();
        INTCONbits.T0IF = 0;
        return;
    }

}