  #include <AT89x52.h>

  void delay_50us();
  void main()
  {
     P2_0 = 1;
    while(1)
	{
	  delay_50us();
	  P2_0 = !P2_0;
	}
  }
  void delay_50us()
  {
    TMOD = 0x02;
	TH0 = 56;
	TF0 = 0;
	TR0 = 1;
	while(1)
	{
	  if(TF0==1) break;
	}
	TR0 = 0;
	TF0 = 0;
  }