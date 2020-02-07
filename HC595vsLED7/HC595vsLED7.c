		 #include <REGX52.H>
		 unsigned char ma[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
		 unsigned char i, t;
		 void delay(unsigned int t)
		 {
		   unsigned int x, y;
		   for(x = 0; x < t; x++)
		   for(y = 0; y < 123; y++);
		 }
		 void main()
		 {
		   P0 = 0xFF;
		   P1 = 0XFF;
		   while(1)
		   {
		     for(i = 0; i < 100; i++)
			 {
			   P0 = ma[i/10];
			   P1 = ma[i%10];
			   delay(500);
			 }
		   }
		 }