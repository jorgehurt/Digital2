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
#include "LCD.h"
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
char contadorJB = 0;

//**************************
// Prototipos de funciones
//**************************
void setup(void);
void semaforo(void);

//**************************
// Ciclo principal
//**************************

void main(void) {

    setup();

    //**************************
    // Loop principal
    //**************************




    while (1) {
        //Libreria para Pantalla y ejecucion del Codigo 
        Lcd_Clear();
        Lcd_Set_Cursor(1, 1);
        Lcd_Write_String("Hola Mundo");
        Lcd_Set_Cursor(2, 1);
        Lcd_Write_String("Adios Mundo");
        __delay_ms(2000);
        Lcd_Clear();
        Lcd_Set_Cursor(1, 1);
        Lcd_Write_String("Developed By");
        Lcd_Set_Cursor(2, 1);
        Lcd_Write_String("electroSome");
        __delay_ms(2000);
        Lcd_Clear();

    }
}

//**************************
// Configuración
//**************************

void setup(void) {
    ANSEL = 0;
    ANSELH = 0;
    TRISA = 0b00000111;
    PORTA = 0;
    TRISB = 0;
    PORTB = 0;
    TRISC = 0;
    PORTC = 0;
    TRISD = 0;
    PORTD = 0;
    TRISE = 0;
    PORTE = 0;
    Lcd_Init();
}

//**************************
// Funciones
//**************************

void adc(void) {
    //Lee los dos potenciometros
    
    contadorJB = 0;
}
void usart(void) {
    //Lee la comunicacion USART y una libreria USART
    
    tempUsart=0;
    //Define Ports 
    
}