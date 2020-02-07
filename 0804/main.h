 #ifndef _MAIN_H_
 #define _MAIN_H_

 #include <regx52.h>
 #define FREQ_OSC 12000000ul
	sbit LCD_RS	= P2^0;
	sbit LCD_EN	= P2^2;
	sbit LCD_D4	= P0^4;
	sbit LCD_D5 = P0^5;
	sbit LCD_D6 = P0^6;
	sbit LCD_D7 = P0^7;

 #define ADC_data P2
    sbit ADC_CS = P2^3;
	sbit ADC_RD = P2^4;
	sbit ADC_WR = P2^5;
	sbit ADC_INTR = P2^6;

 #endif