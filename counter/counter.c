#include <main.h>
#include <..\library\delay.h>

unsigned char code code7seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
int donvi, chuc, tram, nghin, dem;
void time_on(unsigned int dem);
void delay_time(unsigned int t);

void main()
{  
  unsigned char high, low;
  unsigned int number; 
  TMOD = 0x51;
  TR1 = 1;
  while(1)
  {
    do
	{
	  high = TH1;
	  low = TL1;
	} while(high!=TH1);
	number = high;
	number <<= 8;
	number |= low;
	time_on(number);
  }
}
void delay_ms(unsigned int t)
{
  unsigned int x;
  for(x=0;x<t;x++)
  {
	TH0 = 0xFC;
	TL0 = 0x18;
	TF0 = 0;
	TR0 = 1;
	while(!TF0);
	TF0 = 0;
	TR0 = 0;
  }
}
void time_on(unsigned int dem)
{
  nghin = dem/1000;
  tram = (dem%1000)/100;
  chuc = (dem%100)/10;
  donvi = dem%10;
  
    LED = code7seg[donvi];
	L1= 0;
	delay_ms(1);
	L1 = 1;
	LED = code7seg[chuc];
	L2 = 0;
	delay_ms(1);
	L2 = 1;
	LED = code7seg[tram];
	L3 = 0;
	delay_ms(1);
	L3 = 1;
	LED = code7seg[nghin];
	L4 = 0;
	delay_ms(1);
	L4 = 1;  
}