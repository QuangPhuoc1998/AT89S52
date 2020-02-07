 #include <main.h>
 #include "delay.h"

 void Soft_SPI_Init()
 {
   SPI_CS = 1;
   SPI_CLK = 0;
   SPI_MISO = 1;
 }
 void Soft_SPI_write(unsigned char b)
 {
   unsigned int i;
   for(i=0;i<8;i++)
   {
     if(b&0x80==1)
	   SPI_MOSI=1;
	 else 
	   SPI_MOSI=0;
	 SPI_CLK = 1;
	 SPI_CLK = 0;
   }
 }
 void main()
 {
   Soft_SPI_Init();
   while(1)
   {
     Soft_SPI_write(0xAA);
	 delay(20);  
   }
 }