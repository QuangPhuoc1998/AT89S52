 #include <main.h>
 #include "..\..\library\delay.h"
 unsigned char code code7seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
 unsigned int dv,ch,tr,ngh;
 unsigned int dem = 0;
 int t = 0;
 void time_on(unsigned int dem);
 void main()
 {
   TMOD = 0x01;
   ET0 = 1;
   EA = 1;
   TR0 = 1;
   while(1)
   {
     time_on(dem);
   }
 }
 void ngat() interrupt 1 using 0
 {
   TH0 = 0xFC;
   TL0 = 0x18;
   t++;
   if(t>=1000)
   {
     t = 0;
	 dem++;
   }  
 }
 void time_on(unsigned int dem)
 {
   ngh = dem/1000;
   tr = (dem%1000)/100;
   ch = (dem%100)/10;
   dv = (dem%10);

   Led = code7seg[dv];
   donvi = 0;
   delay(1);
   donvi = 1;
   Led = code7seg[ch];
   chuc = 0;
   delay(1);
   chuc = 1;
   Led = code7seg[tr];
   tram = 0;
   delay(1);
   tram = 1;
   Led = code7seg[ngh];
   nghin = 0;
   delay(1);
   nghin = 1;
 }