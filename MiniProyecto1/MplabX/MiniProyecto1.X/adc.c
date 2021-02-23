/* 
 * File:   adc.c
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
#include "eusart.h"
#include <stdint.h>
#include <string.h>


#define _XTAL_FREQ 8000000
//Variables para Primer ADC en AN0


void ADCInit(void) {
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    PIE1bits.ADIE = 1;
    PIR1bits.ADIF = 0;
    ADCON0bits.ADCS = 01;
    ADCON0bits.CHS = 0000;//Seleccion Canal AN0
    ADCON0bits.ADON = 1;
    ADCON1bits.ADFM = 0;
    ADCON1bits.VCFG1 = 0;
    ADCON1bits.VCFG0 = 0;
    __delay_ms(10);
}

//SECUENCIA DE INTERRUPCION PARA LECTURA DE ADC.
/*
 void __interrupt() ISR(void) {
    if (PIR1bits.ADIF==1) {
        ADC1ADRESH=ADRESH;
        PIR1bits.ADIF=0;
        return;
    }
}
 
 */


//CONFIGURACION DE ADC Y ENCENDIDO.
/*
 while (1) {
        ADCInit();
        ADCON0bits.ADON = 1;
        ADCON0bits.GO = 1;
        while (ADCON0bits.GO);
        __delay_ms(10);
        PORTD=ADC1ADRESH;
        
    }
 
 
 */


