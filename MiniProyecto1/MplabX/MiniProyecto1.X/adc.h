/* 
 * File:   
 * Author: Jorge Hurtado 18052
 * Comments:
 * Revision history: 
 */

#ifndef ADC_H
#define	ADC_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "LCD.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// include processor files - each processor file is guarded.  
#define _XTAL_FREQ 4000000
void ADC(void);
void SerialCom (void);
void Counter(void);

#endif	/* XC_HEADER_TEMPLATE_H */