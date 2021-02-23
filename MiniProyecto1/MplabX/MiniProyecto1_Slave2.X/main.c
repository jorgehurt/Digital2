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
#include "LCD.h"
#include "adc.h"
#include "IOCPORTB.h"
#include "eusart.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

#define _XTAL_FREQ 8000000
//**************************
// Main Program
//**************************

//Insertamos Variables de Control
uint8_t Inc = 0;
uint8_t Dec = 0;
uint8_t ContadorID=0;

//Insertamos prototipos de Funciones
void Contador(void);

void main(void) {
    //Setup
    //Configuracion del Oscilador.
    OSCCONbits.IRCF = 0b111; //8Mhz
    OSCCONbits.OSTS = 0;
    OSCCONbits.HTS = 0;
    OSCCONbits.LTS = 0;
    OSCCONbits.SCS = 1;
    //Configuracion de Puertos y lectura de datos.
    //Lectura de potencimetros en AN0.
    ANSEL = 0;
    ANSELH = 0;
    TRISA = 0;
    TRISB = 0b00000011;
    TRISD = 0;
    TRISC = 0;
    TRISE = 0;
    PORTA = 0;
    PORTB = 0;
    PORTC = 0;
    PORTD = 0;
    PORTE = 0;
    //**************************
    // Loop Program
    //**************************    

    while (1) {
        IOCInit();
        //Imprimimos el valor del contador al puerto D.
        PORTD = ContadorID;
    }

}

void __interrupt() ISR(void) {
    if (INTCONbits.RBIF == 1) {
        Contador();
        INTCONbits.RBIF = 0;
        return;
    }
}

void Contador(void) {
    if (PORTBbits.RB0 == 1) {
        Inc = 1;
    }
    if (PORTBbits.RB0 == 0 && Inc == 1) {
        Inc = 0;
        ContadorID=ContadorID+1;
    }
    if (PORTBbits.RB1 == 1) {
        Dec = 1;
    }
    if (PORTBbits.RB1 == 0 && Dec == 1) {
        Dec = 0;
        ContadorID=ContadorID-1;
    }

}