#include "JHD162A_defs.h"
// Now The Functional Library
/************************************************************************
___________________________MY_LCD_LIBRARY________________________________
*/ 
	@Author:	Rahul Verma
	@Email: rahulvermag4@gmail.com
	@Indian Coders are Always Best!!!
//-----------------------------------------------------------------------
#if ON 				//LCD_Functions Disable / Enable

		void latch_data(void)
		{
			EN = 1;
			myDelay(1);
			EN = 0;
			myDelay(5);
		}
		//

		int send_cmd(unsigned int cmd)
		{
			cmdMode;
			LCDPORT = cmd;
			latch_data();
			return 0;
		}
		//
		int send_data(unsigned int datum)
		{
			dataMode;
			LCDPORT = datum;
			latch_data();
			return 0;
		}
		//
		int send_string(unsigned char *string, int shifting)
		{
			int len=0;
			int i=0;
			len=strlen(string);
			for(i=0; i<len;i++)
			{
				send_data(string[i]);
				if(shifting && (i>15)) 
				{
					MANUAL_SHIFT_DISP_LEFT;
					myDelay(300);
				}
			}
			return len;
		}
		//

		void init_LCD(void)
		{
			CLR_LCD;
			INCRMNT_CRSR;
			//AUTO_DISP_SHIFT_RIGHT;
			//AUTO_DISP_SHIFT_LEFT;
			DISP_ON_CRSR_OFF;
			//DISP_ON_CRSR_ON ;
			//MANUAL_SHIFT_DISP_RIGHT;
			//MANUAL_SHIFT_DISP_LEFT ;
			//CRSR_LINE1_BEGIN ;
			CRSR_LINE2_BEGIN ;
			DUAL_ROW_MODE_ENABLE;
			LCD_BACKLIGHT_ON;
		}
		//
#endif // End of LCD Function Set
		
		
		
//-------------------------------------------------------------------------------
		
		
//-----------------------------------------------------------------------------		
// Time delay- In Milli Seconds +/- 10%
int myDelay(unsigned long int delayVal)
{
	unsigned int i,j;
	for(i=0; i< delayVal; i++)
		for(j=0; j<130;j++);
	return 0;
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------
#if OFF		// Set LED Funtions On / OFF

			/*	blinkLED_Freq() ---->
						This Function is to Blink the LED
						* freq - Frequency of Toggeling
						*	count - No of times to toggle
			*/
			int blinkLED_Freq(unsigned int freq, unsigned int count) 
			{
				unsigned int delay,i;
				delay = 1000/freq;
				for(i=0;i<count; i++)
				{
					LED = 0;
					myDelay(delay);
					LED=1;
					myDelay(delay);
				}
				LED = 0;
				return 0;
			}
			/*	blinkLED() ---->
						This Function is to Blink the LED
						* Delay - Frequency of Toggeling
						*	count - No of times to toggle
			*/
			int blinkLED(unsigned int delay, unsigned int count) 
			{
				unsigned int i;
				for(i=0;i<count; i++)
				{
					LED = 1;
					myDelay(delay);
					LED=0;
					myDelay(delay);
				}
				LED = 0;
				return 0;
			}
#endif			// End of Blinking Function Set
//----------------------------------------------------------------------------






