/* 
 * File:  LCD.h 
 * Author: Jorge Rafael Hurtado Garcia 18052.
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef LCD_H
#define	LCD_H

#include <xc.h> // include processor files - each processor file is guarded.  

#define __XLAT_FREQ 8000000
#define  LCD PORTD
#define  RS  RE0
#define  RW  RE1
#define  EN  RE2

#include <xc.h> // include processor files - each processor file is guarded.  
void lcd_cmd(unsigned char x);
void lcd_dwr(unsigned char x);
void lcd_msg(unsigned char *c);
void lcd_ready(void);
void lcd_lat(void);
void inicializacion(void);

#endif	/* XC_HEADER_TEMPLATE_H */