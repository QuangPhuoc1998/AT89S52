 #include <main.h>
 #include "..\library\delay.h"

 void I2C_time_start()
 {
          SCL = 1; 
          SDA = 1;
          SDA = 0; 
          SCL = 0; 
 }
 void I2C_write(unsigned char dat)
 {
	unsigned char i;
	for (i=0;i<8;i++)
	{
		SDA = (dat & 0x80); ///? 1:0;
		SCL=1;
		SCL=0;
		dat<<=1;
	}
	SCL = 1; 
	SCL = 0;
 }
 void main()
 {
   I2C_time_start();
   while(1)
   {
     delay(10);
	 I2C_write(0xAA);
   }
 }