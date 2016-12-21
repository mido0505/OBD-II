/*
===============================================================================
 Name        : main.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include <cr_section_macros.h>
#include "board.h"
// TODO: insert other include files here

#define TX_LED_PORT 0
#define RX_LED_PORT 0
//#define TX_LED_PIN 3
#define RX_LED_PIN 25

// TODO: insert other definitions and declarations here
class complex
{
public:
	int real = 0;
	int image =0;
	complex():real(0),image(0)
	{

	}
	~complex();
};

int main(void)
{

    // TODO: insert code here
	SystemCoreClockUpdate();
	//Chip_SystemInit();
	//Chip_SetupXtalClocking();
	//Board_Configure_Main_Clock();

	Board_Init();


	Chip_GPIO_Init(LPC_GPIO);
	Chip_GPIO_SetPinDIROutput(LPC_GPIO,TX_LED_PORT,3);
	Chip_GPIO_SetPinDIROutput(LPC_GPIO,RX_LED_PORT,RX_LED_PIN);

	Chip_GPIO_SetPinOutHigh(LPC_GPIO,TX_LED_PORT,3);
	Chip_GPIO_SetPinOutHigh(LPC_GPIO,RX_LED_PORT,RX_LED_PIN);
    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    complex compx;
    // Enter an infinite loop, just incrementing a counter
    while(1)
    {
    	Chip_GPIO_SetPinToggle(LPC_GPIO,TX_LED_PORT,3);
    	Chip_GPIO_SetPinToggle(LPC_GPIO,RX_LED_PORT,RX_LED_PIN);
        i++ ;
    }
    return 0 ;
}
