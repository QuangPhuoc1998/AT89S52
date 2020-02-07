		 #include <REGX52.H>
		 sbit xung = P0^0;
		 sbit dl = P0^1;
		 sbit chot = P0^2;
		 unsigned char ma[] = {254, 245};
		 void docma(unsigned char datal)
		 {
		   unsigned int i;
		   for(i = 0; i < 8; i++)
		   {
		      dl = ((datal&0x80)==0x80);
			  xung = 1;
			  xung = 0;
			  datal = datal*2;
		   }
		   chot = 1;
		   chot = 0;
		 }
		 void delay(unsigned int t)
		 {
		   unsigned int x, y;
		   for(x = 0; x < t; x++)
		   for(y = 0; y < 123; y++);
		 }
		 void main()
		 {
		   int i;
		   while(1)
		   {
		     for(i = 0; i < 2; i++)
			 {
			   docma(ma[i]);
			   delay(500);
			 }
		   }
		 }