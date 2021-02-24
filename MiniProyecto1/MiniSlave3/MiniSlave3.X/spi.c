/* 
 * File:   spi.c
 * Author: Jorge Rafael Hurtado Garcia
 */

//**************************
// Importación de librerías
//**************************
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "spi.h"
#include "adc.h"
#include <stdint.h>
#include <string.h>
//Definimos frecuencia de oscilacion de XTAL
#define _XTAL_FREQ 8000000
//Variables para Comunicacion SPI

//Declaramos Funciones

//Configuramos el SPI

void SPIMaster(void) {
    //Configuramos el SPI Como Master.
    SSPSTATbits.SMP = 0;
    SSPSTATbits.CKE = 0;
    SSPCONbits.SSPEN = 1;
    SSPCONbits.CKP = 1;
    SSPCONbits.SSPM = 0b0010;
    //Configuramos los Pines como entrada
    TRISCbits.TRISC5 = 0;
    TRISCbits.TRISC4 = 1;
    TRISCbits.TRISC3 = 0;
    //Activamos las Interrupciones Para SPI
    PIE1bits.SSPIE = 1;
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    PIR1bits.SSPIF = 0;
}

void SPISlave(void) {
    //Configuramos el SPI Como Slave.
    SSPSTATbits.SMP = 0;
    SSPSTATbits.CKE = 0;
    SSPCONbits.SSPEN = 1;
    SSPCONbits.CKP = 1;
    SSPCONbits.SSPM = 0b0100;
    //Configuramos los PINES como IO.
    TRISCbits.TRISC5 = 0;
    TRISCbits.TRISC4 = 0;
    TRISCbits.TRISC3 = 1;
    TRISAbits.TRISA5 = 1;
    //Activamos las Interrupciones Para SPI
    PIE1bits.SSPIE = 1;
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    PIR1bits.SSPIF = 0;
}

char spiRead() {
    while (!SSPSTATbits.BF);
    return (SSPBUF);
}

void spiWrite(char dat) {
    SSPBUF = dat;
}
