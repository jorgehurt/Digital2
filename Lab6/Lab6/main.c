//Jorge Hurtado
//Carnet 18052
//Main Proyect

#include <stdint.h>
#include <stdbool.h>
#include "driverlib/gpio.c"
#include "driverlib/gpio.h"
#include "driverlib/debug.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.c"
#include "driverlib/sysctl.h"

 //Declaramos la cantidad de tiempo que corresponde al delay. Esta magnitud esta en nanosegundos.
uint32_t segundos = 10000000;

int main(void)
{
    //Declaramos en el setup los puertos y el clock del sistema. Activamos el uso de los perifericos.
    SysCtlClockSet ( SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ ) ;
    SysCtlPeripheralEnable ( SYSCTL_PERIPH_GPIOF ) ;
    //Configuramos Inputs y Outputs
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE , GPIO_PIN_4 ) ;
    GPIOPadConfigSet(GPIO_PORTF_BASE,GPIO_PIN_4, GPIO_STRENGTH_2MA , GPIO_PIN_TYPE_STD_WPU ) ;
    GPIOPinTypeGPIOOutput (GPIO_PORTF_BASE, GPIO_PIN_3) ;
    GPIOPinTypeGPIOOutput (GPIO_PORTF_BASE,GPIO_PIN_1) ;
    GPIOPinTypeGPIOOutput (GPIO_PORTF_BASE, GPIO_PIN_2) ;
    while(1){
        //Leemos el puerto del Push 1 y aplicamos debouncing.
        if((GPIOPinRead (GPIO_PORTF_BASE,GPIO_PIN_4 ) & 0x16)==0){
        while((GPIOPinRead (GPIO_PORTF_BASE,GPIO_PIN_4 ) & 0x16)==0){}
        //Encendemos y apagamos los leds a requerimiento para que cumpla con las funciones del semaforo
        GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,0x08);
        SysCtlDelay (40000000) ;
        GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,0x00);
        SysCtlDelay (segundos) ;
        GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,0x08);
        SysCtlDelay (segundos) ;
        GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,0x00);
        SysCtlDelay (segundos) ;
        GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,0x08);
        SysCtlDelay (segundos) ;
        GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,0x00);
        SysCtlDelay (segundos) ;
        GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,0x0A);
        SysCtlDelay (40000000) ;
        GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,0x00);
        SysCtlDelay (10000000) ;
        GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,0x02);
    }
    }
}
