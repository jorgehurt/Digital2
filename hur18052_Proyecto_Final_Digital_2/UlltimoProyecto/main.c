//Jorge Rafael Hurtado Garcia
//18052
//Programacion de TIVAC para sistema de parqueos


//Llamado de Librerias
#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_ints.h"
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/gpio.h"
#include "driverlib/uart.h"
#include "driverlib/pin_map.h"
void uart_test(void);


int main(void){

    //Set System Clock
    SysCtlClockSet(SYSCTL_SYSDIV_1|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
    //Enable Peripheral Control GPIO
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    //Prepare System for Uart2
    HWREG(GPIO_PORTD_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTD_BASE + GPIO_O_CR) |= GPIO_PIN_7;
    //Config UART2 pinout Config BaudRate 115200
    GPIOPinConfigure(GPIO_PD7_U2TX);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART2); // enable uart2
    GPIOPinTypeUART(GPIO_PORTD_BASE, GPIO_PIN_6 | GPIO_PIN_7); // pines de control del uart
    UARTConfigSetExpClk(UART2_BASE, SysCtlClockGet(), 115200, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));
    UARTIntClear(UART2_BASE, UART_INT_RX | UART_INT_RT | UART_INT_TX | UART_INT_FE | UART_INT_PE | UART_INT_BE | UART_INT_OE | UART_INT_RI | UART_INT_CTS | UART_INT_DCD | UART_INT_DSR);
    //Assign GPIO Inputs for Sensors
    GPIOPinTypeGPIOInput(GPIO_PORTA_BASE, GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4);
    GPIOPinTypeGPIOInput(GPIO_PORTB_BASE, GPIO_PIN_6);
    //Assign GPIO Outputs for Leds and 7 segments Display.
    GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7);
    GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_4);
    GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7);
    GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, GPIO_PIN_4|GPIO_PIN_5);
    //Variables de Control Display
    uint8_t DISPLAYVALUE=4;
    // Sensor Variables
    uint8_t P1_LED=0;
    uint8_t P2_LED=0;
    uint8_t P3_LED=0;
    uint8_t P4_LED=0;
    //Printing Variables
    uint32_t P1_LED_DISPLAY=1;
    uint32_t P2_LED_DISPLAY=1;
    uint32_t P3_LED_DISPLAY=1;
    uint32_t P4_LED_DISPLAY=1;

    //Loop Para lectura e impresion de datos.
    while(1)
    {
        // Lectura de los PushButtons.

        // If variable Names are not familiar please refer to the associated pdf file with pinout and Electric Scheme.
        // Same applies for port management in GPIO read and write.

        P1_LED = GPIOPinRead(GPIO_PORTA_BASE, GPIO_PIN_2);
        P2_LED = GPIOPinRead(GPIO_PORTA_BASE, GPIO_PIN_3);
        P3_LED = GPIOPinRead(GPIO_PORTA_BASE, GPIO_PIN_4);
        P4_LED = GPIOPinRead(GPIO_PORTB_BASE, GPIO_PIN_6);
        //Enviamos estado de los PushButtons por UART a la TIVAC
        UARTCharPut(UART2_BASE, P1_LED);
        UARTCharPut(UART2_BASE, P2_LED);
        UARTCharPut(UART2_BASE, P3_LED);
        UARTCharPut(UART2_BASE, P4_LED);
        //Iniciamos la revision de que parqueos estan ocupados.

        //if P1 busy, reset red led (same led, reset>red, set>green )print parking not available in display(0)
        if(P1_LED==0)
        {
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_7, 0);
        P1_LED_DISPLAY=0;
        }
        //if P1 clear, set green led and print parking available in display(1)
        if(P1_LED!=0)
        {
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_7, GPIO_PIN_7);
        P1_LED_DISPLAY=1;
        }
        //Same from P1 applies to P2, P3, P4. Uncommented for this reason.
        if(P2_LED==0)
        {
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6, 0);
        P2_LED_DISPLAY=0;
        }
        if(P2_LED!=0)
        {
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6, GPIO_PIN_6);
        P2_LED_DISPLAY=1;
        }
        if(P3_LED==0)
        {
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 0);
        P3_LED_DISPLAY=0;
        }
        if(P3_LED!=0)
        {
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, GPIO_PIN_5);
        P3_LED_DISPLAY=1;
        }
        if(P4_LED==0)
        {
        GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_4, 0);
        P4_LED_DISPLAY=0;
        }
        if(P4_LED!=0)
        {
        GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_4, GPIO_PIN_4);
        P4_LED_DISPLAY=1;
        }
        //Concat Display Value from the sum of individual values from each parking.
        DISPLAYVALUE=P1_LED_DISPLAY+P2_LED_DISPLAY+P3_LED_DISPLAY+P4_LED_DISPLAY;

        // Display value concat printer. Set the necessary pins for display numbers. PINMAP available in aditional pdf.
        // Individual Sections uncommented due to if statement is clear enough.
        if(DISPLAYVALUE==4)
        {
           GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_5, GPIO_PIN_5);
           GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, 0);
           GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_1, GPIO_PIN_1);
           GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0, GPIO_PIN_0);
           GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 0);
           GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 0);
           GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, GPIO_PIN_5);
        }

        if(DISPLAYVALUE==3)
        {
           GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_5, GPIO_PIN_5);
           GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, GPIO_PIN_4);
           GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_1, 0);
           GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0, GPIO_PIN_0);
           GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 0);
           GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, GPIO_PIN_6);
           GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, GPIO_PIN_5);
        }
        if(DISPLAYVALUE==2)
        {
           GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_5, GPIO_PIN_5);
           GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, GPIO_PIN_4);
           GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_1, 0);
           GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0, GPIO_PIN_0);
           GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, GPIO_PIN_7);
           GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, GPIO_PIN_6);
           GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, 0);
        }
        if(DISPLAYVALUE==1)
        {
           GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_5, GPIO_PIN_5);
           GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, 0);
           GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_1, 0);
           GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0, 0);
           GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, 0);
           GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, 0);
           GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, GPIO_PIN_5);
        }
        if(DISPLAYVALUE==0)
        {
           GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_5, GPIO_PIN_5);
           GPIOPinWrite(GPIO_PORTE_BASE, GPIO_PIN_4, GPIO_PIN_4);
           GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_1, GPIO_PIN_1);
           GPIOPinWrite(GPIO_PORTB_BASE, GPIO_PIN_0, 0);
           GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_7, GPIO_PIN_7);
           GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_6, GPIO_PIN_6);
           GPIOPinWrite(GPIO_PORTC_BASE, GPIO_PIN_5, GPIO_PIN_5);
        }
        //In case something breaks display may show 0 available parking spots to prevent mayor issues.
        else{DISPLAYVALUE=0;}
        //System delay on loop to restart system
        SysCtlDelay(1);
    }

}
