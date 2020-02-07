  #include <main.h>
  #include "delay.h"
  
 
  /****************Khai báo chân giao tiep I2C***************************/
	
	sbit SDA = P0^0;
    sbit SCL = P0^1;

/****************Cac ham giao tiep I2C***************************/
void I2C_time_start(){
          SCL = 1; 
          SDA = 1;
          SDA = 0; 
          SCL = 0; 
}
void I2C_time_stop(){
          SCL = 1; 
          SDA = 0; 
          SDA=1;
          SCL=1; 
}
unsigned char I2C_write(unsigned char dat){
          unsigned char i;
          for (i=0;i<8;i++){
                    SDA = (dat & 0x80); ///? 1:0;
                    SCL=1;
                    SCL=0;
                    dat<<=1;
          }
          SCL = 1; 
          SCL = 0;
          return dat;
}
unsigned char I2C_read(void){
          bit rd_bit;
          unsigned char i, dat;
          dat = 0x00;
          for(i=0;i<8;i++){ /* For loop read data 1 byte */
                    SCL = 1;
                    rd_bit = SDA; /* Keep for check acknowledge */
                    dat = dat<<1;
                    dat = dat | rd_bit; /* Keep bit data in dat */
                    SCL = 0; /* Clear SCL */
          }
          return dat;
}
  void main()
  {
    I2C_time_start();
    while(1)
	{
	  I2C_write(0x55);
	  delay(1);
	}
  }