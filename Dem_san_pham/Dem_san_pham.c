 #include <main.h>
 #include <mega328P.h>
 #include "..\library\delay.h"
 unsigned char code code7seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
 unsigned int dem;
 unsigned int i, t;
 void time_on( int t);
 void main()
 {
   EX0 = 1;
   IT0 = 1;
   EA = 1;
   while(1)
   {
   while(1)
   {
     time_on(dem);
	 if(P2_2 == 0)
	 {
	   while(P2_2 == 0) time_on(dem);
	   goto here;
	 }
   }
   while(1)
   {
     here:;
	 for(i=dem;i>0;i--)
	 {
	   for(t=0;t<50;t++)
	   {
	     time_on(i);
	   }
	 }
	 P2_3 = 0;
	 delay(5000);
	 P2_3 = 1;
	 dem = 0;
	 break;
	 }
   }
 }
 void time_on( int t)
 {
    int donvi, chuc;
	chuc = (t%100)/10;
	donvi = t%10;
   
    LED = code7seg[donvi];
	L1	= 1;
	delay(10);
	L1 = 0;
	LED = code7seg[chuc];
	L2 = 1;
	delay(10);
	L2 = 0;
 }
 void ngat() interrupt 0
 {
   if(dem==99) dem = 0; 
   else dem++;
 }