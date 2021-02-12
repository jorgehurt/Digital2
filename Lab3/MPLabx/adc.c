/* 
 * File:   adc.c
 * Author: Jorge Rafael Hurtado Garcia
 * Libreria https://electrosome.com/lcd-pic-mplab-xc8/
 * Autor:   Ligo George
 * Autor: Pablo Mazariegos
 */


//**************************
// Importación de librerías
//**************************
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "LCD.h"
#include "adc.h"
#include <stdint.h>
#include <string.h>


#define _XTAL_FREQ 4000000
//Variables para Primer ADC en AN0
float ADCLA;
int DCADC1;
int ADC1A;
int ADC1B;
int ADC1C;
char ADCchar1A[5];
char ADCchar1B[5];
char ADCchar1C[5];
char PUNTO1A[5];
char test[5];
uint8_t ADC1ADRESH;

//Variables para Segundo ADC en AN1
float ADCLB;
int DCADC2;
int ADC2A;
int ADC2B;
int ADC2C;
char ADCchar2A[5];
char ADCchar2B[5];
char ADCchar2C[5];
char PUNTO2A[5];
uint8_t ADC2ADRESH;

//Variables para Comunicacion Serial
int PI;
int plc;
int Contador;
char Lectura;

void SerialCom(void) {
    //Habilitamos las Interrupciones
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    PIE1bits.RCIE = 1;
    PIE1bits.TXIE = 1;
    // Limpiamos las banderaS
    PIR1bits.RCIF = 0;
    PIR1bits.TXIF = 0;
    SPBRG = 23; //10417
    TXSTA = 0b00100100;
    RCSTA = 0b10010000;
}

void Counter(void) {
    if (Lectura == '+') {
        Contador = Contador + 1;
        Lectura = 0;
    }
    if (Lectura == '-') {
        Contador = Contador - 1;
        Lectura = 0;
    }
    Lectura = 0;
}

void __interrupt() ISR(void) {
    if (PIR1bits.RCIF == 1) {
        Lectura = RCREG;
        PIR1bits.RCIF = 0;
        Counter();

    }
}

void ADC(void) {
    while (1) {
        //Configuracion de ADC 
        ADCON0bits.ADCS = 01;
        ADCON0bits.ADON = 1; // adc on
        ADCON1bits.ADFM = 0;
        ADCON1bits.VCFG0 = 0;
        ADCON1bits.VCFG1 = 0;
        //Impresion de Headers en LCD
        lcd_msg("S1    S2   S3");
        // Loop principal de lectura e impresion
        while (1) {
            //Lectura de ADC en AN0
            __delay_ms(1);
            ADCON0bits.CHS = 0000;
            ADCON0bits.ADON = 1;
            ADCON0bits.GO = 1;
            while (ADCON0bits.GO);
            //Extraccion de Dato del Registro Adresh Luego de Conversion.
            ADC1ADRESH = ADRESH;
            //Mapeo y traslado de variable de float a int luego de lectura en bin.
            ADCLA = (ADC1ADRESH * 5.0) / 255.0;
            DCADC1 = (ADCLA)*100;
            //Ajuste de variables y conversion a datos char.
            ADC1A = DCADC1 % 10;
            itoa(ADCchar1A, ADC1A, 10);
            ADC1B = (DCADC1 / 10) % 10;
            itoa(ADCchar1B, ADC1B, 10);
            ADC1C = (DCADC1 / 100) % 10;
            itoa(ADCchar1C, ADC1C, 10);
            //Concat de Datos para impresion en la pantalla.
            strcat(ADCchar1B, ADCchar1A);
            strcpy(PUNTO1A, ".");
            strcat(PUNTO1A, ADCchar1B);
            strcat(ADCchar1C, PUNTO1A);

            __delay_us(600);
            ADCON0bits.CHS = 0001;
            ADCON0bits.ADON = 1; // adc on
            ADCON0bits.GO = 1;
            while (ADCON0bits.GO);
            ADC2ADRESH = ADRESH;
            ADCLB = ADC2ADRESH * 5.0 / 255.0;
            DCADC2 = (ADCLB)*100;
            ADC2A = DCADC2 % 10;
            itoa(ADCchar2A, ADC2A, 10);
            ADC2B = (DCADC2 / 10) % 10;
            itoa(ADCchar2B, ADC2B, 10);
            ADC2C = (DCADC2 / 100) % 10;
            itoa(ADCchar2C, ADC2C, 10);
            strcat(ADCchar2B, ADCchar2A);
            strcpy(PUNTO2A, ".");
            strcat(PUNTO2A, ADCchar2B);
            strcat(ADCchar2C, PUNTO2A);
            strcpy(test, ".");
            strcat(Contador, test);
            lcd_cmd(0xC0);
            // BAJAR A SEGUNDA LINEA
            lcd_msg(ADCchar1C);
            // DESPLIEGA EL CHAR
            lcd_msg("V ");
            // Espacio y V.d
            lcd_msg(ADCchar2C); // SIGUIENTE VALOR
            lcd_msg("V ");
            lcd_msg(Contador); // EL OTRO VALOR

        }
    }
    return;
}
