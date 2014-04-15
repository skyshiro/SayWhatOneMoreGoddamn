#include <msp430.h>

#include "lcd_driver.h"


/*
 * main.c
 */

#define BUTTON BIT5

int buttonFlag = 0;

int main(void)
{
	char pulpfiction[] = "The path of the righteous man is beset on all sides by the iniquities of the selfish and the tyranny of evil men. Blessed is he who in the name of charity and good will shepherds the weak through the valley of darkness, for he is truly his brother's keeper and the finder of lost children. And I will strike down upon thee with great vengeance and furious anger those who attempt to poison and destroy my brothers. And you will know my name is the Lord when I lay my vengeance upon thee.";

	char message[] = "Hello World";

    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	
    P1OUT |= BUTTON;
    P1REN |= BUTTON;
    P1IE |= BUTTON;
    P1IES |= BUTTON;
    P1IFG &= ~BUTTON;

    lcd_setup();

    __enable_interrupt();

    while(1)
    {
    	//insert hello world

    	buttonFlag = 0;

    	lcd_write_message(message);

    	do
    	{

    	}
    	while(!buttonFlag);

    	if(buttonFlag)
    	{
    		buttonFlag = 0;
    		P1IE |= BUTTON;

    		lcd_write_message(pulpfiction);

    		do
    		{

    		}
    		while(buttonFlag);

    	 }


    }


	return 0;
}

#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
	if(P1IFG & BUTTON)
	{
		buttonFlag = 1;
		P1IE &= ~BUTTON;
		P1IFG &= ~BUTTON;
	}
}
