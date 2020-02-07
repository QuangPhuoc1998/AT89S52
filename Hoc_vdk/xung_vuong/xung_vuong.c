 #include <main.h>
 #include <..\..\library\delay.h>
 sbit PWM = P1^0;
 unsigned int Ton, Toff;
 void set_timer(unsigned int ck);
 void main()
 {
   set_timer(100);
   TR0 = 1;
   while(1)
   {
     delay(1);
   }
 }
 void set_timer(unsigned int ck)
 {
   unsigned int T;
   PWM = 1;
   TMOD = 0x01;
   ET0 = 1;
   EA = 1;
   T = ck; 
   Ton = T/2;
   Toff = T/2;
 }
 void dao() interrupt 1 using 0
 {
   PWM = ~PWM;
   if(PWM==1) 
   {
     TH0 = (65536-Ton)>>8;
	 TL0 = (65536-Ton)&0x00FF;
   }
   if(PWM==0)
   {
     TH0 = (65536-Toff)>>8;
	 TL0 = (65536-Toff)&0x00FF;
   }
    
 }
