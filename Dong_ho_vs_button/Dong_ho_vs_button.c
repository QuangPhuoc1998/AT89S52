  #include "main.h"
  #include "..\library\delay.h"

  unsigned char code code7seg[10] = { 0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90}; 
  unsigned char giay = 0;
  unsigned char phut = 0;
  unsigned char chuc, donvi;
  unsigned int i;

  void TIME_ON()
  {
                chuc= phut/10;
		        donvi= phut%10;

		        LED_PORT = code7seg[chuc];
		        phutchuc = 1;
		        delay(1);
		        phutchuc = 0;

		        LED_PORT = code7seg[donvi];
		        phutdonvi = 1;
		        delay(1);
	       	    phutdonvi = 0;

		        chuc=giay/10;
		        donvi=giay%10;

		        LED_PORT = code7seg[chuc];
		        giaychuc = 0;
		        delay(1);
		        giaychuc = 1;

		        LED_PORT = code7seg[donvi];
		        giaydonvi = 0;
		        delay(1);
	       	    giaydonvi = 1;
  }
  void main()
  {
    
	while(1)
		  {
		        TIME_ON();

				if(BTN_UP == 0) 
				{
				  while(BTN_UP==0)
				  {
				   	TIME_ON();
				  }
				  if(phut==59) phut=0;
				  else phut++;
				}
				if(BTN_DOWN == 0) 
				{
				  while(BTN_DOWN==0)
				  {
				   	TIME_ON();
				  }
				  if(phut==0) phut=59;
				  else phut--;
				}
				if(BTN_START==0) break;
		   }
    while(1)
	{   
	   while(phut>0 || giay >0)
	   {
	     for(i=0;i<250;i++)
		 {
		   TIME_ON();
		 }
		 if(giay==0) 
		 {
		   giay=59;
		   phut--;
		 } else 
		 {
		   giay--;
		 }
	   }
	     LED_PORT = code7seg[0];
	     phutchuc = 0;
		 phutdonvi = 0;
		 LED_PORT = code7seg[0];
		 giaychuc = 0;
		 giaydonvi = 0;
	   LED = 0;
	   if(BTN_STOP==0) 
	   {
	    LED = 1;
	    break;
	   } 	  
	}
  }