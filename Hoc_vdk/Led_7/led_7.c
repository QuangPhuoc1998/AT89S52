 #include <AT89x52.h>
 #include "E:\file Keil C\AT89S52\library\delay.h"
 #define LED P0
 sbit L1 = P3^4;
 sbit L2 = P3^5;
 sbit L3 = P3^4;
 sbit L4 = P3^5;
 int i, x, y;
 int ngan, tram, chuc, donvi;
 void delay_ms(unsigned char t)
 {
   unsigned int x;
   for(x=0; x<t;x++)
   {
	   TMOD = 0x01;
	   TH0 = 0xFC;
	   TL0 = 0x18;
	   TF0 = 0;
	   TR0 = 1;
	   while(!TF0); 
	   TF0 = 0;
	   TR0 = 0;
   }

 }
 
 unsigned char code code7seg[] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6};
 void main()
 {
   while(1)
   {
     for(i=0;i<99;i++)
	 {  
	   chuc = i/10;
	   donvi = i%10;
	   for(x=0;x<500;x++)
	   {
		   LED = code7seg[donvi];
		   L1 = 0;
		   delay_ms(1);
		   L1 = 1;
		   LED = code7seg[chuc];
		   L2 = 0;
		   delay_ms(1);
		   L2 = 1;
	   }
	 }
   }
 }
 