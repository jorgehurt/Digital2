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

/*
void UARTIntHandler(void);
void UARTSend(const uint8_t *pui8Buffer, uint32_t ui32Count);
*/
int main(void){


    SysCtlClockSet(SYSCTL_SYSDIV_1|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
    //Enable Peripheral Control GPIO
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    /*
    //Assign GPIO UART2
    SysCtlPeripheralEnable (SYSCTL_PERIPH_UART2);
    //IntMasterEnable();
    GPIOPinTypeUART(GPIO_PORTD_BASE, GPIO_PIN_6 | GPIO_PIN_7);
    UARTDisable(UART2_BASE);
    UARTConfigSetExpClk(UART2_BASE, SysCtlClockGet(), 115200,(UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));
    //IntEnable (INT_UART);
    UARTIntEnable (UART2_BASE, UART_INT_RX);
    UARTEnable (UART2_BASE);
    //IntPrioritySet(INT_UART, 0x0);
    //IntRegister(INT_UART, UARTIntHandler);
    UARTFIFOEnable(UART2_BASE);
    UARTFIFOLevelSet(UART2_BASE,UART_FIFO_TX1_8,UART_FIFO_RX1_8);
*/
    //Uart2
    HWREG(GPIO_PORTD_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTD_BASE + GPIO_O_CR) |= GPIO_PIN_7;
    GPIOPinConfigure(GPIO_PD7_U2TX);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART2); // enable uart2
    GPIOPinTypeUART(GPIO_PORTD_BASE, GPIO_PIN_6 | GPIO_PIN_7); // pines de control del uart
    UARTConfigSetExpClk(UART2_BASE, SysCtlClockGet(), 115200, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));
    UARTIntClear(UART2_BASE, UART_INT_RX | UART_INT_RT | UART_INT_TX | UART_INT_FE | UART_INT_PE | UART_INT_BE | UART_INT_OE | UART_INT_RI | UART_INT_CTS | UART_INT_DCD | UART_INT_DSR);


    //Assign GPIO Inputs
    GPIOPinTypeGPIOInput(GPIO_PORTA_BASE, GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4);
    GPIOPinTypeGPIOInput(GPIO_PORTB_BASE, GPIO_PIN_6);
    //Assign GPIO Outputs
    GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7);
    GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_4);
    GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7);
    GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, GPIO_PIN_4|GPIO_PIN_5);
    //Variables de Control
    uint8_t DISPLAYVALUE=4;
    uint8_t P1_LED=0;
    uint8_t P2_LED=0;
    uint8_t P3_LED=0;
    uint8_t P4_LED=0;
    uint32_t P1_LED_DISPLAY=1;
    uint32_t P2_LED_DISPLAY=1;
    uint32_t P3_LED_DISPLAY=1;
    uint32_t P4_LED_DISPLAY=1;

    //Loop Para lectura e impresion de datos.
    while(1)
    {
        // Lectura de los PushButtons
        P1_LED = GPIOPinRead(GPIO_PORTA_BASE, GPIO_PIN_2);
        P2_LED = GPIOPinRead(GPIO_PORTA_BASE, GPIO_PIN_3);
        P3_LED = GPIOPinRead(GPIO_PORTA_BASE, GPIO_PIN_4);
        P4_LED = GPIOPinRead(GPIO_PORTB_BASE, GPIO_PIN_6);
        //Revisamos Cambio de Estado de los Botones
        UARTCharPut(UART2_BASE, P1_LED);
        UARTCharPut(UART2_BASE, P2_LED);
        UARTCharPut(UART2_BASE, P3_LED);
        UARTCharPut(UART2_BASE, P4_LED);
        if(P1_LED==0)
        {
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_7, 0);
        P1_LED_DISPLAY=0;
        }
        if(P1_LED!=0)
        {
        GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_7, GPIO_PIN_7);
        P1_LED_DISPLAY=1;
        }
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
        DISPLAYVALUE=P1_LED_DISPLAY+P2_LED_DISPLAY+P3_LED_DISPLAY+P4_LED_DISPLAY;




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
        else{DISPLAYVALUE=0;}
        SysCtlDelay(1);
    }

}
