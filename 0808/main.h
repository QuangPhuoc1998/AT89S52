 #ifndef _MAIN_H_
 #define _MAIN_H_

 #include <regx52.h>
 #define FREQ_OSC 12000000ul
	sbit LCD_RS	= P2^0;
	sbit LCD_RW = P2^1; 
	sbit LCD_EN	= P2^2;
	sbit LCD_D4	= P0^4;
	sbit LCD_D5 = P0^5;
	sbit LCD_D6 = P0^6;
	sbit LCD_D7 = P0^7;

	#define ADC0808_DATA P3
	sbit PA = P1^0;
	sbit PB = P1^1;
	sbit PC = P1^2;
	sbit ALE = P1^3;
	sbit STA = P1^4;
	sbit EOC =  P1^5;
	sbit OE = P1^6;

 #endif