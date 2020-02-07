 #include <main.h>
 #include <E:\file Keil C\AT89S52\library\PWM.h>
 
 

 
 void PWM_START()
 {
   TR0 = 1;
 }
  void PWM_START()
 {
   TR0 = 1;					      
 }
 void PWM_STOP()
 {
   TR0 = 0;
 }
 void PWM_set_duty(unsigned char duty )
 {
   if(duty==0)
   {
     PWM_PIN = 0;
	 ET0 = 0;
   }
   else 
   if (duty == 100)
   {
     PWM_PIN = 1;
	 ET0 = 0;
   }
   else
   {
   Ton = (unsigned long)T*duty/100;
   Toff = T-Ton;

   Ton_h_reload = (65536-Ton)>>8;
   Ton_l_reload = (65536-Ton)&0x00FF;

   Toff_h_reload = (65536-Toff)>>8;
   Toff_l_reload = (65536-Toff)&0x00FF;

   ET0 = 1;
   }
  d timer0Overlow() interrupt 1
 {
   PWM_PIN = !PWM_PIN;
   if(PWM_PIN==0)
   {
     TH0 = Toff_h_reload;
     TL0 = Toff_l_reload;
   }
   else
   {
     TH0 = Ton_h_reload;
     TL0 = Ton_l_reload;
   }
 }