	#ifndef _MAIN_H_
	#define _MAIN_H_
	
	#include <regx51.h>
	#define FREQ_OSC 12000000ul
	
	    #define LED_PORT P2
		
		sbit giaychuc = P3^2;
		sbit giaydonvi = P3^3;
		sbit phutchuc = P3^0;
		sbit phutdonvi = P3^1;

		sbit BTN_UP = P3^4;
		sbit BTN_DOWN = P3^5;
		sbit BTN_START = P3^6;
		sbit BTN_STOP = P3^7;

		sbit LED = P1^0;
	#endif 