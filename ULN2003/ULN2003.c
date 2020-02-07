#include <main.h>
#include <..\library\delay.h>

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
    if(BTN_right == 0)
	{
	  while(BTN_right == 0);
	  stepper_motor_right();
	}
	if(BTN_left == 0)
	{
	  while(BTN_left == 0);
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
	   step_motor = full_drive_right[t];
	   delay_ms(50);
	   if(BTN_left == 0)
	 {
	  while(BTN_left == 0);
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
	   step_motor = full_drive_left[t];
	   delay_ms(50);
	   if(BTN_right == 0)
	{
	  while(BTN_right == 0);
	  stepper_motor_right();
	} 
	 }
   }
}