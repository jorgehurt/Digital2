/* 
 * File:   
 * Author: Jorge Hurtado 18052
 * Comments:
 * Revision history: 
 */

#ifndef ADC_H
#define	ADC_H

#include <xc.h> // include processor files - each processor file is guarded.  
//#include "LCD.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// include processor files - each processor file is guarded.  
#define _XTAL_FREQ 8000000
uint8_t ADC1ADRESH;
void ADCInit(void);
#endif	/* XC_HEADER_TEMPLATE_H */