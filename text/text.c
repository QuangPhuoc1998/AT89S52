  #include <main.h>
  #include "..\library\delay.h"
  int i;
  void main()
  {
    LED = 0xFE;
    while(1)
	{
	  LED = 0xFE;
	  for(i=0;i<8;i++)
	  {
	    delay(100);
		LED = LED << 1;
	  }	
	  for(i=0;i<8;i++)
	  {
	    delay(100);
		LED = LED << 1|1;
	  }	
	}
  }