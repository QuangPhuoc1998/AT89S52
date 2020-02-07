  #ifndef _MAIN_H_
  #define _MAIN_H_

  #include <regx51.h>
  #define FREQ_OCS 12000000ul
         
		 #define LED_PORT P2
		 sbit giochuc = P3^0;
		 sbit giodonvi = P3^1;
		 sbit phutchuc = P3^2;
		 sbit phutdonvi = P3^3;
		 sbit giaychuc = P3^4;
		 sbit giaydonvi = P3^5;

		 sbit BTN_UP = P1^0;
		 sbit BTN_DOWN = P1^1;
		 sbit BTN_NEXT = P1^2;
		 sbit BTN_START = P1^3;


  #endif