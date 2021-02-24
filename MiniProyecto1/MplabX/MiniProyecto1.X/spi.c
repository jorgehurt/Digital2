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
#include "LCD.h"
#include "adc.h"
#include "eusart.h"
#include <stdint.h>
#include <string.h>
//Definimos frecuencia de oscilacion de XTAL
#define _XTAL_FREQ 8000000
//Variables para Comunicacion SPI

//Declaramos Funciones

//Configuramos el SPI
void SPIInit(void){
    PORTD=0;
    
}

