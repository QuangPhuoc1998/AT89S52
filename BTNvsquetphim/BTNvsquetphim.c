	 #include <main.h>
	 #include "E:\file Keil C\AT89S52\library\delay.h"

	 #define LED P2
	 sbit BTN_START = P1^0;
	 sbit BTN_STOP = P1^1;

	 unsigned char delay1svaquetphim()
	 { 
	   unsigned int i;
	   for( i = 0 ; i < 100 ; i++)
	   {
	     delay(10);
		 if(BTN_STOP == 0)
		 { 
		   LED = 0xFF;
		   return 1;
		 }
	   }
	   return 0;
	 }
	 void main()
	 {
	    LED = 0xFF;
		while(1)
		{  
		   if(BTN_START == 0)
		   while(1)
		   { 
		    LED = ~LED;
			if(delay1svaquetphim())
			{
			 break;
			}
		   }
		}
	 }