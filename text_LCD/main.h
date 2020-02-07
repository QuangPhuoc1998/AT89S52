 #ifndef _MAIN_H_
 #define _MAIN_H_

 #define FREQ_OSC 12000000ul
 #include <regx52.h>
	sbit LCD_RS	= P0^0;
	sbit LCD_RW = P0^1; 
	sbit LCD_EN	= P0^2;
	sbit LCD_D4	= P0^4;
	sbit LCD_D5 = P0^5;
	sbit LCD_D6 = P0^6;
	sbit LCD_D7 = P0^7;
 #endif