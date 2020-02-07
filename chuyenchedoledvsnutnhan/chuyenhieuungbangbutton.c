		   #include <main.h>
		   #include "E:\file Keil C\AT89S52\library\delay.h"

		   sbit BTN = P1^0;
		   #define LED P2

		   bit pressedflag = 0;

		   unsigned char delayvakiemtraphim()
		   {  
		     unsigned int i;
			 for(i = 0; i < 50; i++)
			 {  
			   delay(10);
			   if(BTN == 0)
			   {  
			     if(pressedflag == 0)
				 { 
				   pressedflag = 1;
				   return 1;
				   
				   break;
				 }
				 else pressedflag = 0;
			   }
			 }
			 return 0;
		   }
		   void main()
		   {
		     while(1)
			 { 
				  unsigned int i;
				  while(BTN==0);
				  LED = 0xFF;
				  for(i=0; i<20; i++)
				  { 
				       if(delayvakiemtraphim()) break;
				   	   LED = ~LED;
				  }

				  while(BTN==0);
				  LED = 0x55;
				  for(i=0; i<20; i++)
				  { 
				       if(delayvakiemtraphim()) break;
				   	   LED = ~LED;
					   
				  }
				  while(BTN==0);
				  LED = 0x0F;
				  for(i=0; i<20; i++)
				  { 
				       if(delayvakiemtraphim()) break;
				   	   LED = ~LED;
					   
				  }
			 }
		   }