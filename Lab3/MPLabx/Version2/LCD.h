// This is a guard condition so that contents of this file are not included
// more than once.  
//Funciones obtenidas de https://electrosome.com/lcd-pic-mplab-xc8/
#ifndef LCD
#define	LCD

#include <xc.h> // include processor files - each processor file is guarded.  
#define _XTAL_FREQ 8000000
//#define RS RD2
//#define EN RD3
//#define C0 RC0
//#define C1 RC1
//#define C2 RC2
//#define C3 RC3
//#define C4 RC4
//#define C5 RC5
//#define C6 RC6
//#define C7 RC7


void lcd_Port(char a);
void lcd_Cmd(char a);
void lcd_Clear(void);
void lcd_Set_Cursor(char a, char b);
void lcd_Init(void);
void lcd_Write_Char(char a);
void lcd_Write_String(char *a);
void lcd_Shift_Right(void);
void lcd_Shift_Left(void);


#endif	/* XC_HEADER_TEMPLATE_H */

