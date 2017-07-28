#include "JHD162A_defs.h"   //[#include<reg51.h>] is already Included in the JHD162A_defs.h, Hence not included Here
int main()
{
	//Setting the Input and Output Pins to Allow internal Pullups
	LCDPORT = 0x00;
	RS=0;
	EN=0;
	RW=0;
	LCD_BL=0;
	
	while(1)
	{
		init_LCD();
		send_string("HEllo MyName IS Aarvee :D :D ", ON);
		//myDelay(1000);
		//blinkLED(100,50);
		while(1);
	}
}
//
