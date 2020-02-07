  #ifndef _MAIN_H_
  #define _MAIN_H_
  #include <regx52.h>
       #define LEDchuc P1
	   #define LEDdonvi P3
	   sbit LED_do = P2^0;
	   sbit LED_vang = P2^1;
	   sbit LED_xanh = P2^2;
	   sbit BTN_up = P2^3;
	   sbit BTN_down = P2^4;
	   sbit BTN_next = P2^5;
	   sbit BTN_start = P2^6;
  #define FREQ_OSC 12000000ul

  #endif