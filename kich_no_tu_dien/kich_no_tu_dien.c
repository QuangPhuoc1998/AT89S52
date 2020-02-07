#include <main.h>
#include <E:\file Keil C\AT89S52\library\delay.h>
unsigned char code code7seg[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

void main()
{
   unsigned char i;
   unsigned char y;
   y = 0;
   while(1)
   {
      if (BTN == 0 && y == 0)
	  {
	   while(BTN == 0);
	   
	   for(i=9;i>0;i--)
	   {
	     LED = code7seg[i];
		 delay(500);
	   }
	   LED = 0xC0;
	   relay = 0;
	   y = 1;
	  }
	  if (BTN == 0 && y == 1)
	  {
		while(BTN == 0);
	   
	   for(i=9;i>0;i--)
	   {
	     LED = code7seg[i];
		 delay(500);
	   }
	   LED = 0xC0;
	   relay = 1;
	   y = 0;
	  }
   }
}