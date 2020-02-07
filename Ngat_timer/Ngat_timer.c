  #include <main.h>
  #include <..\library\delay.h>

 
  void main()
  {
   TMOD = 0x01;
   EX0 = 1;	 // cho phep ngat ngoai 0
   IT0 = 0;
   TR0 = 1;
   EA = 1;	 // cho phep ngat toan cuc
    while(1)
	{
	  	 P2 = 0x00;
		 delay(500);
		 P2 = 0xFF;
		 delay(500);
	}
  }
  void ngat() interrupt 0
  {
    long a = 50000;
	P1_3 = 0;
	while(a--); //delay(50000)
	P1_3 = 1;
  }