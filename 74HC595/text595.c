 #include <main.h>
 #include "..\library\delay.h"
 unsigned char i;
 void HC595(unsigned char *p, unsigned char n);
 void main()
 {
   unsigned char buffer[2];
   while(1)
   {
     for(i=0;i<2;i++)
	 {
	   buffer[i] = 0;
	 }
	 HC595(buffer,2);
	 delay(500);
	 for(i=0;i<2;i++)
	 {
	   buffer[i] = 0xFF;
	 }  
	 HC595(buffer,2);
	 delay(500);
   }
 }
 void HC595(unsigned char *p, unsigned char n)
 {
   unsigned char j,i,b;
   for(j=0;j<n;j++)
   {
     b = *(p+n-j-1);
	 for(i=0;i<8;i++)
	 {
	   DS = b&(0x80>>i);
	   SHCP = 0;
	   SHCP = 1;
	 }
   }
   STCP = 0;
   STCP = 1;
 }