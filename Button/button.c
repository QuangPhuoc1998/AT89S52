		#include <regx51.h>
		#include <E:\file Keil C\AT89S52\library\delay.h>
		#include <port.h>
	
		void main()
		{
		  LED = 1;
		  while(1)
		  {
		       delay(20);	// chong doi phim
		       if (BTN == 0)  // dam bao BTN = 0
			   {
			    LED = !LED;
				while(BTN == 0);	// dung chay cho den khi an phim
			   }	
		  }
		}