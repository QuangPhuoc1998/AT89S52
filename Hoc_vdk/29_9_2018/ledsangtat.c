 #include <AT89x52.h>
 void delay_ms(unsigned int t);
 int i;
 void main()
 {
   TMOD = 0x01;
   while(1)
   {
     P0 = P1 = P2 = P3 = 0x55;
	 delay_ms(500);
	 P0 = P1 = P2 = P3 = 0xAA;
	 delay_ms(500);
   }
 }
 void delay_ms(unsigned int t)
 {
   unsigned int x;
   for(x=0;x<t;x++)
   {
     TL0 = 18;
	 TH0 = 0xFC;
	 TR0 = 1;
	 while(!TF0);
	 TF0 = 0;
	 TR0 = 0;
   }
 }