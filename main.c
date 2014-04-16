#include <msp430.h>
#include "lcd_driver.h"

#define BUTTON BIT4

int buttonFlag;

int main(void)
{
	//char pulpfiction[] = "The path of the righteous man is beset on all sides by the iniquities of the selfish and the tyranny of evil men. Blessed is he who in the name of charity and good will shepherds the weak through the valley of darkness, for he is truly his brother's keeper and the finder of lost children. And I will strike down upon thee with great vengeance and furious anger those who attempt to poison and destroy my brothers. And you will know my name is the Lord when I lay my vengeance upon thee.";
	char pulpfiction[] = "My name is Maximus Decimus Meridius, commander of the Armies of the North, General of the Felix Legions and loyal servant to the true emperor, Marcus Aurelius. Father to a murdered son, husband to a murdered wife. And I will have my vengeance, in this life or the next.";
	char message[] = "Hello World";

	int data_ports[] = {BIT0, BIT1, BIT2, BIT3};

	int ctrl_ports[] = {BIT0, BIT1, BIT2};

    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

    lcd_setup(data_ports,ctrl_ports);

    lcd_write_message(data_ports,ctrl_ports,pulpfiction);
	
    P2OUT |= BUTTON;
    P2REN |= BUTTON;
    P2IE |= BUTTON;
    P2IES |= BUTTON;
    P2IFG &= ~BUTTON;

    buttonFlag = 0;

    __enable_interrupt();

    while(1)
    {

    	if(buttonFlag)
    	{
    		buttonFlag = 0;
    		lcd_write_message(pulpfiction);
    	 }
    }


	return 0;
}

#pragma vector=PORT2_VECTOR
__interrupt void Port_2(void)
{
	if(P2IFG & BUTTON)
	{
		buttonFlag = 1;
		P2IFG &= ~BUTTON;
		P2IE ^= P2IE;
	}
}
