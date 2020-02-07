#include "main.h"
#include "delay.h"

#define step_motor P0
sbit Quangtro = P2^0;
sbit HT1 = P2^1;
sbit HT2 = P2^2;

unsigned char full_drive_right[4] = {0x09,0x0C, 0x06, 0x03};
unsigned char full_drive_left[4] = {0x03,0x06, 0x0C, 0x09};
unsigned int x, t;
void delay_ms(unsigned int t);
void stepper_motor_right();
void stepper_motor_left();
void main()
{
  while(1)
  {
    if(Quangtro == 1 && HT2 != 0)
	{
	  stepper_motor_right();
	}
	if(Quangtro == 0 && HT1 != 0)
	{
	  stepper_motor_left();
	}
  }
}
void delay_ms(unsigned int t)
{
  for(x=0;x<t;x++)
  {
	TMOD = 0x01;
	TF0 = 0;
	TH0 = 0xFC;
	TL0 = 0x18;
	TR0 = 1;
	while(!TF0);
	TR0 = 0;
	TF0 = 0;
  }
}
void stepper_motor_right()
{
   while(1)
   {
     for(t=0;t<4;t++)
	 {
	   if(HT2 != 0)
	   {
	     step_motor = full_drive_right[t];
	     delay_ms(3); 
	   }
	   if(Quangtro == 0)
	   {
	     stepper_motor_left();
	   }
	 }
   }  
}
void stepper_motor_left()
{	while(1)
   {
     for(t=0;t<4;t++)
	 {
	   if(HT1 != 0)
	   {
	     step_motor = full_drive_left[t];
	     delay_ms(3);
	   } 
	   if(Quangtro == 1)
	   {
	     stepper_motor_right();
       }
	 }
   }
}