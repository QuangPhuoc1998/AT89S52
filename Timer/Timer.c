   #include <main.h>
//   #include "..\library\delay.h"
   void delay_timer(unsigned int t)
 {
//   TMOD = 0x01;
   do
   {
     TL0 = 0x18;
	 TH0 = 0xFC;
	 TR0 = 1;
	 while(!TF0);
	 TF0 = 0;
	 TR0 = 0;
	 t--;
   }  while(t!=0);
 }
   void main()
   { 
       TMOD=(1<<T0_M0_); // timer 0 che do 1
       P3_0 = 0;
	   while(1)
	   { 
	     P3_0 = !P3_0;
		 delay_timer(1000);

	   }
   }