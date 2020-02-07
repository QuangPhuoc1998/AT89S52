  #include <main.h>
  #include <..\library\delay.h>
  unsigned char code code7seg[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
  void main()
  {
    unsigned char dem = 0;
    while(1)
	{
	 if(BTN == 0)
	{
	   while(BTN == 0)
	   { 
	     dem++;
	   }
	   LED = code7seg[dem%9+1];
	   delay(1);
	}
	}
  }