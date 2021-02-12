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
#include <stdint.h>
#include <string.h>


#define _XTAL_FREQ 4000000
float ADCLA;
int DCADC1;
int ADC1A;
int ADC1B;
int ADC1C;
char ADCchar1A[5];
char ADCchar1B[5];
char ADCchar1C[5];
char PUNTO1A[5];
uint8_t ADC1ADRESH;

//Segundo ADC
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




int PI;
int plc;
char ARDUINO[5];
void PC(int  n){
    plc = n;
    PI = (plc)*1;
     itoa(ARDUINO,PI,10);
}
void ADC(void){
    while(1){
    ADCON0bits.ADCS = 01;
    ADCON0bits.ADON = 1;   // adc on
    ADCON1bits.ADFM = 0;
    ADCON1bits.VCFG0 = 0;
    ADCON1bits.VCFG1 = 0;
    lcd_msg("S1    S2   S3");
    while(1){
        __delay_ms(1);
        ADCON0bits.CHS = 0000;
        ADCON0bits.ADON = 1;
        ADCON0bits.GO = 1;
        while(ADCON0bits.GO);
        ADC1ADRESH = ADRESH;
        ADCLA = (ADC1ADRESH*5.0)/255.0;
        DCADC1 = (ADCLA)*100;
        ADC1A = DCADC1%10;
        itoa(ADCchar1A,ADC1A,10);
        ADC1B = (DCADC1/10)%10;
        itoa(ADCchar1B,ADC1B,10);
        ADC1C = (DCADC1/100)%10;
        itoa(ADCchar1C,ADC1C,10);
        strcat(ADCchar1B,ADCchar1A);
        strcpy(PUNTO1A,".");
        strcat(PUNTO1A,ADCchar1B);
        strcat(ADCchar1C,PUNTO1A);
        
        __delay_us(600);
        ADCON0bits.CHS = 0001;
        ADCON0bits.ADON = 1;   // adc on
        ADCON0bits.GO = 1;
        while(ADCON0bits.GO);
        ADC2ADRESH = ADRESH;
        ADCLB = ADC2ADRESH*5.0/255.0;
        DCADC2 = (ADCLB)*100; 
        ADC2A = DCADC2%10;
        itoa(ADCchar2A,ADC2A,10);       //transforma el valor int POT2A a char POT2SA
        ADC2B = (DCADC2/10)%10;          
        itoa(ADCchar2B,ADC2B,10);
        ADC2C = (DCADC2/100)%10;
        itoa(ADCchar2C,ADC2C,10);
        strcat(ADCchar2B,ADCchar2A);       // concatena 
        strcpy(PUNTO2A,".");         // transforma caracter a char
        strcat(PUNTO2A,ADCchar2B);
        strcat(ADCchar2C,PUNTO2A);
        
        lcd_cmd(0xC0);                  // BAJAR A SEGUNDA LINEA
        lcd_msg(ADCchar1C);             // DESPLIEGA EL CHAR
        lcd_msg("V ");                  // ESPACIO
        lcd_msg(ADCchar2C);          // SIGUIENTE VALOR
        lcd_msg("V ");
        lcd_msg(ARDUINO);             // EL OTRO VALOR
       
    }
    }
    return;
}
