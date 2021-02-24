/* 
 * File:   spi.h
 * Author: Jorge Hurtado 18052
 * Comments:
 * Revision history: 
 */
//Define Header File Name
#ifndef SPI_H
#define	SPI_H
//Include Compiler Libraries.
#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Define Crystal Frequency
#define _XTAL_FREQ 8000000
//Define Global Variables.

//Define Library Functions.
void SPIInit(void);
//End Header File.
#endif	/* XC_HEADER_TEMPLATE_H */