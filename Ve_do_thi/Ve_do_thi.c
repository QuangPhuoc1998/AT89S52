 #include "main.h"
 #include "delay.h"
 #include "stdio.h"

 void main()
 {
   unsigned char c;
   SCON = 0x50; //0101000
   TMOD = 0x20; //8 bit auto load
   TH1 = 0xFD; // Baudrate 9600
   TR1 = 1;	// bat dau time 1
   TI = 1; // sang sang gui du lieu
   while(1)
   {
     for(c=0;c<255;c++)
	 {
	   putchar(c);
	   delay(100);
	 }
   }
 }