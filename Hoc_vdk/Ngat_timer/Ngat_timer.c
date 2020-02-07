 #include <main.h>
 #include <E:\file Keil C\AT89S52\library\delay.h>
 int cnt = 5;
 int i;
 void main()
 {
   TMOD &= 0xF0;
   TMOD |= 0x01;
   TL0 = 0xB0;
   TH0 = 0x3C;
   ET0 = 1;
   EA = 1;
   TR0 = 1;
   while(1)
   {
     P1 = 0xFE;
     for(i = 0; i < 8; i++)
	 {
	   delay(250);
	   P1 = P1 << 1|1;
	 } 
   }
 }
 void ngat() interrupt 1
 {
    TL0 = 0xB0;
    TH0 = 0x3C;
	cnt--;
	if(cnt==0)
	{
	  cnt = 5;
	  P3_7 = ~P3_7;
	}

 }