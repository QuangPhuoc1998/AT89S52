  #include <main.h>
  #include "..\library\delay.h"

  unsigned char code code7seg[10] = { 0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90}; 

  void main()
  {
    unsigned char dem, chuc, donvi;
	unsigned int i;
	while(1)
	{
	  for(dem = 0; dem < 100 ; dem++)
	  {
	    	donvi = dem%10;
			chuc = dem/10;

			for(i = 0 ; i < 500 ; i++)
			{
			   LED_PORT = code7seg[donvi];
			   LED2 = 0;
			   delay(1);
			   LED2 = 1;

			   LED_PORT = code7seg[chuc];
			   LED1 = 0;
			   delay(1);
			   LED1 = 1;
			}
	  }
	}
  }