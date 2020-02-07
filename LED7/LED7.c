  #include <main.h>
  #include "E:\file Keil C\AT89S52\library\delay.h"


  unsigned char code code7seg[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

  void main()
  {
    
    unsigned char i;
	while(1)
	{
	   // cho den do
	   dendo = 0;
	   denxanh = 1;
	   denvang = 1;

	   for(i = 10; i > 0 ; i--)
	   {
	      LED1 = code7seg[i/10];
		  LED2 = code7seg[i%10];
		  delay(500);
	   }

	   // cho den vang
	   dendo = 1;
	   denxanh = 1;
	   denvang = 0;

	   for(i = 3; i > 0 ; i--)
	   {
	      LED1 = code7seg[i/10];
		  LED2 = code7seg[i%10];
		  delay(500);
	   }

	   // cho den xanh
	   dendo = 1;
	   denxanh = 0;
	   denvang = 1;

	   for(i = 7; i > 0 ; i--)
	   {
	      LED1 = code7seg[i/10];
		  LED2 = code7seg[i%10];
		  delay(500);
	   }
	   P3 = 00000001;

	}

	
	
  }