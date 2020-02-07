 #include <main.h>
 #include "delay.h"
 
 unsigned int T, Ton, Toff;
 unsigned char Ton_h_reload, Ton_l_reload, Toff_h_reload, Toff_l_reload;

 void PWM_Init(unsigned int ck)
 {
   PWM_PIN = 1;

   TMOD &= 0xF0;
   TMOD |= 0x01;

   ET0 = 1;
   EA = 1;

   T = ck;
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
 }
 void main()
 {
   int duty = 5;
   PWM_Init(20000);
   PWM_START();
   PWM_set_duty(duty);
   while(1)
   {
     if(BTN_UP==0)
	 { 
	   while(BTN_UP==0);
	   delay(20);
	   if(duty==10); else duty+=1;
	 }
	 if(BTN_DOWN==0)
	 { 
	   while(BTN_DOWN==0);
	   delay(5);
	   if(duty==5); else duty-=1;
	 }
	 PWM_set_duty(duty);	  
   }
 }
 void timer0Overlow() interrupt 1
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