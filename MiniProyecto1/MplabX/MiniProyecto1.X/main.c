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
#include "eusart.h"
#include "spi.h"
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
//**************************
// Main Program
//**************************
//Define local Variables
//Variables para Control y Recepcion de SPI.
uint8_t SSbit1 = 0;
int PotenciometroLectura = 0;
int Potenciometro = 0;
uint8_t ContadorLectura = 0;
uint8_t Contador = 0;
uint8_t TemperaturaLectura = 0;
uint8_t Temperatura = 0;
//Variables para impresion en LCD.
char ContadorSend[5];
char PotenciometroSend[5];
char TemperaturaSend[5];
//Variables para Mapeo de Potencimetro

int Pot1A;
int Pot1B;
int Pot1C;
int POINT;
char POTchar1A[5];
char POTchar1B[5];
char POTchar1C[5];
//Variables para USart
char Titlea[5] = "Contador";

//Funciones Locales para Comunicacion SPI
void ComSPI(void);
void MapPot(void);

void main(void) {
    //Setup
    //Configuracion del Oscilador.
    OSCCONbits.IRCF = 0b111; //8Mhz
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
    TRISC = 0b10010000;
    TRISE = 0;
    PORTA = 0;
    PORTB = 0;
    PORTC = 0;
    PORTD = 0;
    PORTE = 0;
    PIE1bits.SSPIE = 1;
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    PIR1bits.SSPIF = 0;
    SPIMaster();
    SSbit1 = 1;
    inicializacion();
    UART_INIT();
    //
    //**************************
    // Loop Program
    //**************************
    //Impresion de Headers en LCD
    lcd_msg("S1:   S2:    S3:");
    // Loop principal de lectura e impresion    
    while (1) {
        ComSPI();
        sprintf(ContadorSend, "%.3i", Contador);
        sprintf(PotenciometroSend, "%.4i", Potenciometro);
        sprintf(TemperaturaSend, "%.3i", Temperatura);
        lcd_cmd(0xC0);
        // BAJAR A SEGUNDA LINEA
        lcd_msg(PotenciometroSend);
        // DESPLIEGA EL CHAR
        lcd_msg("mV ");
        // Espacio y V.d
        lcd_msg(ContadorSend); // SIGUIENTE VALOR
        lcd_msg(" ");
        lcd_msg(TemperaturaSend); // EL OTRO VALOR
        lcd_msg("C ");
        //UART_WRITE("Potenciometro:");
        //UART_WRITE(Titlea);
        //UART_WRITE("Contador:");
        //UART_WRITE(Contador);
        UART_Write_Text(ContadorSend);
        //UART_WRITE("Temperatura:");
        //UART_WRITE(Temperatura);
        
    }
}

void ComSPI(void) {
    if (SSbit1 == 1) {
        PORTBbits.RB0 = 0;
        PORTBbits.RB1 = 1;
        PORTBbits.RB2 = 1;
        __delay_ms(1);
        spiWrite(1);
        PotenciometroLectura = spiRead();
        MapPot();
        __delay_ms(1);
        PORTBbits.RB0 = 1;
        __delay_ms(100);
        SSbit1 = 2;
    }
    if (SSbit1 == 2) {
        PORTBbits.RB0 = 1;
        PORTBbits.RB1 = 0;
        PORTBbits.RB2 = 1;
        __delay_ms(1);
        spiWrite(1);
        Contador = spiRead();
        __delay_ms(1);
        PORTBbits.RB1 = 1;
        __delay_ms(100);
        SSbit1 = 3;
    }
    if (SSbit1 == 3) {
        PORTBbits.RB0 = 1;
        PORTBbits.RB1 = 1;
        PORTBbits.RB2 = 0;
        __delay_ms(1);
        spiWrite(1);
        TemperaturaLectura = spiRead();
        Temperatura = (TemperaturaLectura * 125) / 250;
        __delay_ms(1);
        PORTBbits.RB2 = 1;
        __delay_ms(100);
        SSbit1 = 1;
    }
    return;
}

void MapPot(void) {
    Potenciometro = (PotenciometroLectura * 5000.0) / 255;
    return;
}
