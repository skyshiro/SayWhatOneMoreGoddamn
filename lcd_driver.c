/**
 * 
 * LCD library will currently use PORT2 for the data lines and PORT1 for the control lines
 * 
 * data_ports and ctrl_ports array go from smallest bit to largest bit
 * 
**/

#include <msp430.h>

//ports = [bit1,bit2,bit3,bit5]
/

//P1OUT = (BIT0 & 0x0D) << ports[0] | (bit1 & 0x0D) << PORTS[1] | (BIT2 & 0x0D) << ports[3]

void lcd_setup(char *data_ports,char *ctrl_ports) //data_ports uses pins on PORT2 and ctrl_ports uses pins on PORT1
{
	P1DIR |= ctrl_ports[0] + ctrl_ports[1] + ctrl_ports[2]; //using PORT1 for control lines
	
	P2DIR |= data_ports[0] + data_ports[1] + data_ports[2] + data_ports[3]; //using PORT2 for data lines

	__delay_cycles(25000);

	//send set function 1
	P1OUT |= (BIT0 & BIT2) << ctrl_ports[0] | (BIT1 & BIT2) << ctrl_ports[1] | (BIT2 & BIT2) << ctrl_ports[2] ; //sets enable pin high
	P2OUT |= (BIT0 & 0x2) << data_ports[0] | (BIT1 & 0x2) << ctrl_ports[1] | (BIT2 & 0x2) << ctrl_ports[2] | (BIT3 & 0x2) << ctrl_ports[3];  //MSB of function set
	P1OUT &= ~((BIT0 & BIT2) << ctrl_ports[0] | (BIT1 & BIT2) << ctrl_ports[1] | (BIT2 & BIT2) << ctrl_ports[2]) ; //sets enable pin high
	P2OUT &= ~((BIT0 & 0x2) << data_ports[0] | (BIT1 & 0x2) << ctrl_ports[1] | (BIT2 & 0x2) << ctrl_ports[2] | (BIT3 & 0x2) << ctrl_ports[3]);
	//send set function 2
	P1OUT |= (BIT0 & BIT2) << ctrl_ports[0] | (BIT1 & BIT2) << ctrl_ports[1] | (BIT2 & BIT2) << ctrl_ports[2] ; //sets enable pin high
	P2OUT |= (BIT0 & 0x8) << data_ports[0] | (BIT1 & 0x8) << ctrl_ports[1] | (BIT2 & 0x8) << ctrl_ports[2] | (BIT3 & 0x8) << ctrl_ports[3];  //MSB of function set
	P1OUT &= ~((BIT0 & BIT2) << ctrl_ports[0] | (BIT1 & BIT2) << ctrl_ports[1] | (BIT2 & BIT2) << ctrl_ports[2]) ; //sets enable pin high
	P2OUT &= ~((BIT0 & 0x8) << data_ports[0] | (BIT1 & 0x8) << ctrl_ports[1] | (BIT2 & 0x8) << ctrl_ports[2] | (BIT3 & 0x8) << ctrl_ports[3]);
	
	__delay_cycles(40);

	//Send display set 1
	P1OUT |= (BIT0 & BIT2) << ctrl_ports[0] | (BIT1 & BIT2) << ctrl_ports[1] | (BIT2 & BIT2) << ctrl_ports[2] ; //sets enable pin high
	P2OUT |= (BIT0 & 0x0) << data_ports[0] | (BIT1 & 0x0) << ctrl_ports[1] | (BIT2 & 0x0) << ctrl_ports[2] | (BIT3 & 0x0) << ctrl_ports[3];  //MSB of function set
	P1OUT &= ~((BIT0 & BIT2) << ctrl_ports[0] | (BIT1 & BIT2) << ctrl_ports[1] | (BIT2 & BIT2) << ctrl_ports[2]) ; //sets enable pin high
	P2OUT &= ~((BIT0 & 0x0) << data_ports[0] | (BIT1 & 0x0) << ctrl_ports[1] | (BIT2 & 0x0) << ctrl_ports[2] | (BIT3 & 0x0) << ctrl_ports[3]);

	//Send display set 2
	P1OUT |= (BIT0 & BIT2) << ctrl_ports[0] | (BIT1 & BIT2) << ctrl_ports[1] | (BIT2 & BIT2) << ctrl_ports[2] ; //sets enable pin high
	P2OUT |= (BIT0 & 0xD) << data_ports[0] | (BIT1 & 0xD) << ctrl_ports[1] | (BIT2 & 0xD) << ctrl_ports[2] | (BIT3 & 0xD) << ctrl_ports[3];  //MSB of function set
	P1OUT &= ~((BIT0 & BIT2) << ctrl_ports[0] | (BIT1 & BIT2) << ctrl_ports[1] | (BIT2 & BIT2) << ctrl_ports[2]) ; //sets enable pin high
	P2OUT &= ~((BIT0 & 0xD) << data_ports[0] | (BIT1 & 0xD) << ctrl_ports[1] | (BIT2 & 0xD) << ctrl_ports[2] | (BIT3 & 0xD) << ctrl_ports[3]);

	__delay_cycles(40);

	//Send clear display 1
	P1OUT |= (BIT0 & BIT2) << ctrl_ports[0] | (BIT1 & BIT2) << ctrl_ports[1] | (BIT2 & BIT2) << ctrl_ports[2] ; //sets enable pin high
	P2OUT |= (BIT0 & 0x0) << data_ports[0] | (BIT1 & 0x0) << ctrl_ports[1] | (BIT2 & 0x0) << ctrl_ports[2] | (BIT3 & 0x0) << ctrl_ports[3];  //MSB of function set
	P1OUT &= ~((BIT0 & BIT2) << ctrl_ports[0] | (BIT1 & BIT2) << ctrl_ports[1] | (BIT2 & BIT2) << ctrl_ports[2]) ; //sets enable pin high
	P2OUT &= ~((BIT0 & 0x0) << data_ports[0] | (BIT1 & 0x0) << ctrl_ports[1] | (BIT2 & 0x0) << ctrl_ports[2] | (BIT3 & 0x0) << ctrl_ports[3]);

	//Send clear display 2
	P1OUT |= (BIT0 & BIT2) << ctrl_ports[0] | (BIT1 & BIT2) << ctrl_ports[1] | (BIT2 & BIT2) << ctrl_ports[2] ; //sets enable pin high
	P2OUT |= (BIT0 & 0x1) << data_ports[0] | (BIT1 & 0x1) << ctrl_ports[1] | (BIT2 & 0x1) << ctrl_ports[2] | (BIT3 & 0x1) << ctrl_ports[3];  //MSB of function set
	P1OUT &= ~((BIT0 & BIT2) << ctrl_ports[0] | (BIT1 & BIT2) << ctrl_ports[1] | (BIT2 & BIT2) << ctrl_ports[2]) ; //sets enable pin high
	P2OUT &= ~((BIT0 & 0x1) << data_ports[0] | (BIT1 & 0x1) << ctrl_ports[1] | (BIT2 & 0x1) << ctrl_ports[2] | (BIT3 & 0x1) << ctrl_ports[3]);

	__delay_cycles(1600);
}

void lcd_write_message(char *message)
{
	unsigned int i,j;

	//Send clear display 1
	P1OUT |= (BIT0 & BIT2) << ctrl_ports[0] | (BIT1 & BIT2) << ctrl_ports[1] | (BIT2 & BIT2) << ctrl_ports[2] ; //sets enable pin high
	P2OUT |= (BIT0 & 0x0) << data_ports[0] | (BIT1 & 0x0) << ctrl_ports[1] | (BIT2 & 0x0) << ctrl_ports[2] | (BIT3 & 0x0) << ctrl_ports[3];  //MSB of function set
	P1OUT &= ~((BIT0 & BIT2) << ctrl_ports[0] | (BIT1 & BIT2) << ctrl_ports[1] | (BIT2 & BIT2) << ctrl_ports[2]) ; //sets enable pin high
	P2OUT &= ~((BIT0 & 0x0) << data_ports[0] | (BIT1 & 0x0) << ctrl_ports[1] | (BIT2 & 0x0) << ctrl_ports[2] | (BIT3 & 0x0) << ctrl_ports[3]);

	//Send clear display 2
	P1OUT |= (BIT0 & BIT2) << ctrl_ports[0] | (BIT1 & BIT2) << ctrl_ports[1] | (BIT2 & BIT2) << ctrl_ports[2] ; //sets enable pin high
	P2OUT |= (BIT0 & 0x1) << data_ports[0] | (BIT1 & 0x1) << ctrl_ports[1] | (BIT2 & 0x1) << ctrl_ports[2] | (BIT3 & 0x1) << ctrl_ports[3];  //MSB of function set
	P1OUT &= ~((BIT0 & BIT2) << ctrl_ports[0] | (BIT1 & BIT2) << ctrl_ports[1] | (BIT2 & BIT2) << ctrl_ports[2]) ; //sets enable pin high
	P2OUT &= ~((BIT0 & 0x1) << data_ports[0] | (BIT1 & 0x1) << ctrl_ports[1] | (BIT2 & 0x1) << ctrl_ports[2] | (BIT3 & 0x1) << ctrl_ports[3]);

	__delay_cycles(1600);

	/** auto center feature is disabled for now

	if(strlen(message)<16)
	{

		for(i=0;i<(16-strlen(message))/2;i++)
			{
				P2OUT = BIT0+BIT2;
				P1OUT |= (int)(' ')>>4;
				P2OUT = BIT0; //turn off enable so data is latched in
				P1OUT &= ~((int)(' ')>>4);
				P2OUT = 0x00;

				P2OUT = BIT0+BIT2;
				P1OUT |= (int)(' ') & 0xF;
				P2OUT = BIT0; //turn off enable so data is latched in
				P1OUT &= ~((int)(' ') & 0xF);
				P2OUT = 0x00;

				__delay_cycles(200);

			}

			for(i=0;i<strlen(message);i++)
			{
				//change CGRAM data

				P2OUT = BIT0+BIT2;
				P1OUT |= (int)message[i]>>4;
				P2OUT = BIT0; //turn off enable so data is latched in
				P1OUT &= ~((int)message[i]>>4);
				P2OUT = 0x00;

				P2OUT = BIT0+BIT2;
				P1OUT |= (int)message[i] & 0xF;
				P2OUT = BIT0; //turn off enable so data is latched in
				P1OUT &= ~((int)message[i] & 0xF);
				P2OUT = 0x00;

				__delay_cycles(200);
			}
	}
	**/

	for(i=0;i<strlen(message);i++)
		{
		if(i == (strlen(message)-15))
		{
			break;
		}
			//Change address back to bottom left 1
			P1OUT |= (BIT0 & BIT2) << ctrl_ports[0] | (BIT1 & BIT2) << ctrl_ports[1] | (BIT2 & BIT2) << ctrl_ports[2] ; //sets enable pin high
			P2OUT |= (BIT0 & 0xC) << data_ports[0] | (BIT1 & 0xC) << ctrl_ports[1] | (BIT2 & 0xC) << ctrl_ports[2] | (BIT3 & 0xC) << ctrl_ports[3];  //MSB of function set
			P1OUT &= ~((BIT0 & BIT2) << ctrl_ports[0] | (BIT1 & BIT2) << ctrl_ports[1] | (BIT2 & BIT2) << ctrl_ports[2]) ; //sets enable pin high
			P2OUT &= ~((BIT0 & 0xC) << data_ports[0] | (BIT1 & 0xC) << ctrl_ports[1] | (BIT2 & 0xC) << ctrl_ports[2] | (BIT3 & 0xC) << ctrl_ports[3]);

			//Change address back to bottom left 2
			P1OUT |= (BIT0 & BIT2) << ctrl_ports[0] | (BIT1 & BIT2) << ctrl_ports[1] | (BIT2 & BIT2) << ctrl_ports[2] ; //sets enable pin high
			P2OUT |= (BIT0 & 0x0) << data_ports[0] | (BIT1 & 0x0) << ctrl_ports[1] | (BIT2 & 0x0) << ctrl_ports[2] | (BIT3 & 0x0) << ctrl_ports[3];  //MSB of function set
			P1OUT &= ~((BIT0 & BIT2) << ctrl_ports[0] | (BIT1 & BIT2) << ctrl_ports[1] | (BIT2 & BIT2) << ctrl_ports[2]) ; //sets enable pin high
			P2OUT &= ~((BIT0 & 0x0) << data_ports[0] | (BIT1 & 0x0) << ctrl_ports[1] | (BIT2 & 0x0) << ctrl_ports[2] | (BIT3 & 0x0) << ctrl_ports[3]);


			__delay_cycles(200);

			for (j = 0; j < 16; j++)
			{
				//change CGRAM data

				P1OUT |= (BIT0 & (BIT0+BIT2)) << ctrl_ports[0] | (BIT1 & (BIT0+BIT2)) << ctrl_ports[1] | ((BIT0+BIT2) & (BIT0+BIT2)) << ctrl_ports[2] ; //sets enable pin high
				P2OUT |= (BIT0 & ( (int)message[i+j]>>4 )) << data_ports[0] | (BIT1 & ( (int)message[i+j]>>4 )) << ctrl_ports[1] | ((BIT0+BIT2) & ( (int)message[i+j]>>4 )) << ctrl_ports[2] | (BIT3 & ( (int)message[i+j]>>4 )) << ctrl_ports[3];  //MSB of function set
				P1OUT &= ~((BIT0 & (BIT2)) << ctrl_ports[0] | (BIT1 & (BIT2)) << ctrl_ports[1] | ((BIT2) & (BIT2)) << ctrl_ports[2]) ; //sets enable pin high
				P2OUT &= ~((BIT0 & ( (int)message[i+j]>>4 )) << data_ports[0] | (BIT1 & ( (int)message[i+j]>>4 )) << ctrl_ports[1] | ((BIT0+BIT2) & ( (int)message[i+j]>>4 )) << ctrl_ports[2] | (BIT3 & ( (int)message[i+j]>>4 )) << ctrl_ports[3]);
				P1OUT &= ~((BIT0 & BIT0) << ctrl_ports[0] | (BIT1 & BIT0) << ctrl_ports[1] | (BIT2 & BIT0) << ctrl_ports[2]) ; //sets enable pin high
				__delay_cycles(200);

			}

			//Change address back to bottom left 1
			P1OUT |= (BIT0 & BIT2) << ctrl_ports[0] | (BIT1 & BIT2) << ctrl_ports[1] | (BIT2 & BIT2) << ctrl_ports[2] ; //sets enable pin high
			P2OUT |= (BIT0 & 0xC) << data_ports[0] | (BIT1 & 0xC) << ctrl_ports[1] | (BIT2 & 0xC) << ctrl_ports[2] | (BIT3 & 0xC) << ctrl_ports[3];  //MSB of function set
			P1OUT &= ~((BIT0 & BIT2) << ctrl_ports[0] | (BIT1 & BIT2) << ctrl_ports[1] | (BIT2 & BIT2) << ctrl_ports[2]) ; //sets enable pin high
			P2OUT &= ~((BIT0 & 0xC) << data_ports[0] | (BIT1 & 0xC) << ctrl_ports[1] | (BIT2 & 0xC) << ctrl_ports[2] | (BIT3 & 0xC) << ctrl_ports[3]);

			//Change address back to bottom left 2
			P1OUT |= (BIT0 & BIT2) << ctrl_ports[0] | (BIT1 & BIT2) << ctrl_ports[1] | (BIT2 & BIT2) << ctrl_ports[2] ; //sets enable pin high
			P2OUT |= (BIT0 & 0x0) << data_ports[0] | (BIT1 & 0x0) << ctrl_ports[1] | (BIT2 & 0x0) << ctrl_ports[2] | (BIT3 & 0x0) << ctrl_ports[3];  //MSB of function set
			P1OUT &= ~((BIT0 & BIT2) << ctrl_ports[0] | (BIT1 & BIT2) << ctrl_ports[1] | (BIT2 & BIT2) << ctrl_ports[2]) ; //sets enable pin high
			P2OUT &= ~((BIT0 & 0x0) << data_ports[0] | (BIT1 & 0x0) << ctrl_ports[1] | (BIT2 & 0x0) << ctrl_ports[2] | (BIT3 & 0x0) << ctrl_ports[3]);


			__delay_cycles(50000);
		}
	
}
