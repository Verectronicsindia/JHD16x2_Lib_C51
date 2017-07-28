#include<reg51.h>
#include<string.h>
#define ON 1
#define OFF 0
//LED and Push Button Section  (Comment if not  Using)
#if OFF	//LED and Push-Button DEfinitions On/Off
		sbit LED=P1^3;
		sbit PB=P3^3;
#endif
//----------------------------------------------------

// LCD Connections     (Put "# if OFF" if not using the LCD) 
#if ON	//LCD DEfinitions On/Off
		sbit RS=P1^0;
		sbit RW=P1^1;
		sbit EN=P1^2;
		sbit LCD_BL=P1^4;
		#define LCDPORT P3    //Pins to connect the LCD_Data Pins from D0-D7
		#define cmdMode {RS = 0;}
		#define dataMode {RS = 1;}
		//LCD Commands
		#define CLR_LCD {send_cmd(0x01);}
		#define INCRMNT_CRSR {send_cmd(0x06);}
		#define AUTO_DISP_SHIFT_RIGHT {send_cmd(0x05);}
		#define AUTO_DISP_SHIFT_LEFT {send_cmd(0x07);}
		#define DISP_ON_CRSR_OFF {send_cmd(0x0C);}
		#define DISP_ON_CRSR_ON {send_cmd(0x0E);}
		#define MANUAL_SHIFT_DISP_RIGHT {send_cmd(0x1c);}
		#define MANUAL_SHIFT_DISP_LEFT {send_cmd(0x18);}
		#define CRSR_LINE1_BEGIN {send_cmd(0x80);}
		#define CRSR_LINE2_BEGIN {send_cmd(0xc0);}
		#define DUAL_ROW_MODE_ENABLE {send_cmd(0x38);}
		#define LCD_BACKLIGHT_ON {LCD_BL = 1;}
		#define LCD_BACKLIGHT_OFF {LCD_BL = 0;}
#endif
	
//-----------------------------------------------------

int 	myDelay(unsigned long int);
int 	blinkLED_Freq(unsigned int,unsigned int);
int 	blinkLED(unsigned int,unsigned int);
void 	latch_data(void);
int 	send_cmd(unsigned int);
int 	send_data(unsigned int);
int 	send_string(unsigned char*,int);
void 	init_LCD(void);
