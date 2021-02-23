/* 
 * File:   Interrupt on Change PORTB.c
 * Author: Jorge Rafael Hurtado Garcia
 */


//**************************
// Importación de librerías
//**************************
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "LCD.h"
#include "adc.h"
#include "IOCPORTB.h"
#include "eusart.h"
#include <stdint.h>
#include <string.h>


#define _XTAL_FREQ 8000000
//Variables para Primer ADC en AN0

void IOCInit(void) {
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    INTCONbits.RBIE =1;
    INTCONbits.RBIF =0;
    TRISBbits.TRISB0 = 1; //Configurar puerto como entrada RB0
    TRISBbits.TRISB1 = 1; //Configurar puerto como entrada RB1        
    IOCBbits.IOCB0 = 1;// IOC ACTIVO EN RB0
    IOCBbits.IOCB1 = 1;// IOC ACTIVO EN RB1
}

//Secuencia de Interrupcion IOC.


/*
void __interrupt() ISR(void) {
    if (INTCONbits.RBIF == 1) {
        Contador();
        INTCONbits.RBIF = 0;
        return;
    }
}
 */

// Secuencia de llamado y Setup de IOC.
/*
 while (1) {
        IOCInit();
        //Imprimimos el valor del contador al puerto D.
        PORTD = ContadorID;
    }
 */


//Secuencia para Contador de 8 bits.

/*
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
 */