# JHD16x2_Lib_C51

LCD Library for Keil uVision with C51 Compiler for AT89Sxx Devices;
16x2 Alphanumeric LCD in 8 Bit Mode Interfacing with 8051 Microcontroller.


Connections: 
  LCD_PINS              Microcontroller Pins
   	RS          ----->      P1^0		;
	RW          ----->      P1^1		;
	EN          ----->      P1^2		;
    	LED+        ----->      P1^4 (Optional)	;
   	D0 - D7     ----->   P3^0 - P3^7	;
    
    Note: Here we have Provided Functionality to Control the Green Backlight Of LCD from microcontroller.
          You will need a transistor to Get A Fully Bright Display.
Function Documentation:


void 	init_LCD(void);
  This function Initializes the LCD Display, it should be run after Power-Up only.
  
int 	myDelay(unsigned long int Delay_in_ms);
  This function Provides the required delay in microseconds.
  
int 	send_cmd(unsigned int cmd);
  This function Provides 8-bit 'cmd' passed as a command to LCD.
  
int 	send_data(unsigned int data);
    This function Provides 8-bit 'data' passed as a Display Data to LCD.
    
int 	send_string(unsigned char* "string",int Display_Mode);
  "String" --- > The sentence to display on the LCD,
  Display_Mode ----> ON / OFF 
  ON-> Display and Shift the Display
  OFF-> Stationary Display
  
Any problem ?
Write us on verectronics.help@gmail.com
or Like us on FB : https://www.facebook.com/VerectronicsIndia/
