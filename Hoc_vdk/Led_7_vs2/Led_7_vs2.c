  #include <AT89x52.h>
  unsigned char code code7seg[] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6};
  void delay(long k);
  void main()
  {
    unsigned int i;
    while(1)
	{
	  for(i = 9; i > 0; i--)
	  {
	    P0 = code7seg[i];
		delay(500);
	  }
	}
  }
  void delay(long k )
  {
    unsigned int x;
    for(x = 0; x < k ;x++)
	{
	    TMOD = 0x01;
		TH0 = 0xFC;
		TL0 = 0x18;
		TF0 = 0;
		TR0 = 1;
		while(!TF0);
		TF0 = 0;
		TR0 = 0;  
	}
  }