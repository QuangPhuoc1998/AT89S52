  #include <main.h>
  #include <..\library\delay.h>

  unsigned char code code7seg[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
  unsigned char i;
  void Time_run(unsigned char number)
  {
    unsigned char i;
    for(i=number;i>00;i--)
	  {
	    LEDchuc = code7seg[i/10];
		LEDdonvi = code7seg[i%10];
		delay(500);
	  }
	  LEDchuc = 0xC0;
      LEDdonvi = 0xC0;
	  delay(500);
  }
  void Time_on(unsigned char number)
  {
    LEDchuc = code7seg[number/10];
	LEDdonvi = code7seg[number%10];
  }
  void color()
  {
     int i;
	 for(i=0;i<3;i++)
	 {
     Time_on(0);
	 LED_do = 0;
	 LED_vang = 0;
	 LED_xanh = 0;
	 delay(500);
	 Time_on(0);
	 LED_do = 1;
	 LED_vang = 1;
	 LED_xanh = 1;
	 delay(500);
	 }
  }
  void main()
  {
    unsigned char time_do, time_vang, time_xanh;
	time_do = time_vang = time_xanh = 0;
    P0_0 = 0;
	P0_1 = 0;
	while(1)
	{
     while(1)
	 {
	   LED_do = 0;
	   LED_vang = 1;
	   LED_xanh = 1;
	   Time_on(time_do);
	   if(BTN_up == 0 )
	   {
	     while(BTN_up == 0 ) Time_on(time_do);
		 if(time_do == 59) time_do = 0; else time_do++;
	   }
	   if(BTN_down == 0)
	   {
	     while(BTN_down == 0 ) Time_on(time_do);
		 if(time_do == 0) time_do = 59; else time_do--;
	   }
	   if(BTN_next == 0) 
	   {
	     while(BTN_next == 0) Time_on(time_do);
		 break;
	   }
	   if(BTN_start == 0) 
	   {
	     color();
		 goto here;
	   }
      }
	   while(1)
	 {
	   LED_do = 1;
	   LED_vang = 0;
	   LED_xanh = 1;
	   Time_on(time_vang);
	   if(BTN_up == 0 )
	   {
	     while(BTN_up == 0 ) Time_on(time_vang);
		 if(time_vang == 59) time_vang = 0; else time_vang++;
	   }
	   if(BTN_down == 0)
	   {
	     while(BTN_down == 0 ) Time_on(time_vang);
		 if(time_vang == 0) time_vang = 59; else time_vang--;
	   }
	   if(BTN_next == 0)
	   {
	     while(BTN_next == 0) Time_on(time_vang);
		 break;
	   }
	   if(BTN_start == 0) 
	   {
	     color();
		 goto here;
	   }
      }
	  while(1)
	 {
	   LED_do = 1;
	   LED_vang = 1;
	   LED_xanh = 0;
	   Time_on(time_xanh);
	   if(BTN_up == 0 )
	   {
	     while(BTN_up == 0 ) Time_on(time_xanh);
		 if(time_xanh == 59) time_xanh = 0; else time_xanh++;
	   }
	   if(BTN_down == 0)
	   {
	     while(BTN_down == 0 ) Time_on(time_xanh);
		 if(time_xanh == 0) time_xanh = 59; else time_xanh--;
	   }
	   if(BTN_next == 0) 
	   {
	     while(BTN_next == 0) Time_on(time_xanh);
		 break;
	   }
	   if(BTN_start == 0) 
	   {
	     color();
	   	 goto here;
	   }
      }  
	 }
	 here:
	while(1)
	{
	  LED_do = 0;
	  LED_vang = 1;
	  LED_xanh = 1;
	  Time_run(time_do);
	  LED_do = 1;
	  LED_vang = 0;
	  LED_xanh = 1;
	  Time_run(time_vang);
	  LED_do = 1;
	  LED_vang = 1;
	  LED_xanh = 0;
	  Time_run(time_xanh);
	  LED_do = 1;
	  LED_vang = 0;
	  LED_xanh = 1;
	  Time_run(time_vang);
	}
  }