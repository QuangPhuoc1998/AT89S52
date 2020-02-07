 #include <main.h>
 #include <lcd8.h>
  int y, time;
  unsigned char bu_buoc[] = {0x08, 0x04, 0x02, 0x01}; 
  unsigned char du_buoc[] = {0x0C, 0x06, 0x03, 0x09};
  unsigned char nua_buoc[] = {0x08, 0x0C, 0x04, 0x06, 0x02, 0x03, 0x01, 0x09};
  void delay_ms(unsigned int t);
  time = 500;
  void main()
  {
    while(1)
	{
	  if(star==0)
	  while(1)
	  {
	    here:
	    if(quay_trai==0)
		{
		  while(1)
		  {
			for(y=3;y>=0;y--)
			{
			STEP = du_buoc[y];
			delay_ms(time);
			}
			if(tang_toc==0) 
			{
			  if(time==100); else time=time-100;
			}
			if(giam_toc==0) 
			{
			  if(time==1000); else time=time+100;
			}
			if(quay_phai==0) goto here;
			if(dung==0) goto here;
		  }
		}
		if(quay_phai==0)
		{
		  while(1)
		  {
			for(y=0;y<4;y++)
			{
			STEP = du_buoc[y];
			delay_ms(time);
			}
			if(tang_toc==0) 
			{
			  if(time==100); else time=time-100;
			}
			if(giam_toc==0)
			{
			  if(time==1000); else time=time+100;
			}
			if(quay_trai==0) goto here;
			if(dung==0) goto here;
		  }
		}
		if(dung==0) break;
	  }
	}
  }
  void delay_ms(unsigned int t)
  {
    unsigned int x;
	for(x=0;x<t;x++)
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