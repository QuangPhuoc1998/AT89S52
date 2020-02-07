#include <main.h>
#include "E:\file Keil C\AT89S52\library\delay.h"

				sbit RELAY = P2^1;
				sbit BTN = P1^0;  
void main()
{
     RELAY = 1;
	 BTN = 1;
  	 while(1)
	 { 
	   delay(20);
	   if(BTN == 0)
	   { 
	     RELAY = ! RELAY;
		 while(BTN==0);
	   }
	 }
}