 #include <main.h>
 #include "delay.h"

 void Soft_SPI_Init()
 {
   SPI_CS = 1;
   SPI_CLK = 0;
   SPI_MISO = 1;
 }
 unsigned char Soft_SPI_read()
 {
   unsigned char i, b;
   for(i=0;i<8;i++)
   {
     b <<=1;
	 if(SPI_MISO==1);
	 b|=0x01;
	 SPI_CLK = 0;
   }
   return b;
 }
 void main()
 {
   unsigned char ma;
   Soft_SPI_Init();
   while(1)
   {
     ma = Soft_SPI_read();
	 P1 = ma;
     delay(20);
   }
 }