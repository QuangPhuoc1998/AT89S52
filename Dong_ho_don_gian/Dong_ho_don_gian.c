  #include <main.h>
  

  void delay(unsigned int t)
  {
    TMOD = 0x01;
    do
	{
	  TL0 = 0x18;
	  TH0 = 0xFC;
	  TR0 =1;
	  while(!TF0);
	  TF0 = 0;
	  TR0 = 0;
	  t--;
	} while(t!=0);
  }

  unsigned char code code7seg[10] = { 0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90}; 
  unsigned char chuc, donvi;
  unsigned char  giay, phut, gio;
  
  unsigned int i;

  void TIME_ON()
  {
     // hien gio
		  chuc = gio/10;
		  donvi = gio%10;
		  
		  LED_PORT = code7seg[chuc];
		  giochuc = 0;
		  delay(1);
		  giochuc = 1;

		  LED_PORT = code7seg[donvi];
		  giodonvi = 0;
		  delay(1);
		  giodonvi = 1;

		  // hien phut
		  chuc = phut/10;
		  donvi = phut%10;
		  
		  LED_PORT = code7seg[chuc];
		  phutchuc = 0;
		  delay(1);
		  phutchuc = 1;

		  LED_PORT = code7seg[donvi];
		  phutdonvi = 0;
		  delay(1);
		  phutdonvi = 1;

		  // hien giay
		  chuc = giay/10;
		  donvi = giay%10;
		  
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
	giay = phut = gio = 0;
	while(1)  // chinh thoi gian
	{
	   while(1) // chinh gio
	   {  
	       TIME_ON();
		   if(BTN_UP==0)
		   {
		     while(BTN_UP==0)
			 {
			   TIME_ON();
			 }
			 if(gio==23) gio=0;
			 else gio++;
		   }
		   if(BTN_DOWN==0)
		   {
		     while(BTN_DOWN==0)
			 {
			   TIME_ON();
			 }
			 if(gio==0) gio=23;
			 else gio--;
		   }
		   if(BTN_NEXT == 0)
		   {
		     while(BTN_NEXT==0)
			 {
			   TIME_ON();
			 }
			 break;
		   }
		   if(BTN_START==0)
		   {
		     while(BTN_START==0)
			 {
			  TIME_ON();
			  goto here;
			 }
		   }
	   }
	   while(1) // chinh phut
	   {
	   	 TIME_ON();
		   if(BTN_UP==0)
		   {
		     while(BTN_UP==0)
			 {
			   TIME_ON();
			 }
			 if(phut==59) phut=0;
			 else phut++;
		   }
		   if(BTN_DOWN==0)
		   {
		     while(BTN_DOWN==0)
			 {
			   TIME_ON();
			 }
			 if(phut==0) phut=59;
			 else phut--;
		   }
		   if(BTN_NEXT == 0)
		   {
		     while(BTN_NEXT==0)
			 {
			   TIME_ON();
			 }
			 break;
		   }
		   if(BTN_START==0)
		   {
		     while(BTN_START==0)
			 {
			  TIME_ON();
			  goto here;
			 }
		   }
	   }
	}
	here :
    while(1)   // hien thoi gian
	{
	   	for(i=0;i<166;i++)
		{
		  	TIME_ON();
		}
		  // tang giay len 1
		  giay++;
		  if(giay==60)
		  {
     		   giay=0;
	     	   phut++;
		       if(phut==60)
		       {
				  phut=0;
				  gio++;
				  if(gio==24) gio=0;
		       }
		  }
		
	}
  }