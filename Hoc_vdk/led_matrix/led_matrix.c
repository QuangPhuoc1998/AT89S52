 #include <AT89x52.h>
 
 unsigned char TTCD, TTDC;
 unsigned int i, j;
 void delay(unsigned int time)
 {
   unsigned int x, y;
   for(x=0;x<time;x++)
   for(y=0;y<123;y++);
 }                                                     
 void main()
 {
   while(1)
   {
     TTCD = 0;
	 for(i=8;i>0;i--)
	 {
	   TTDC = 0x01;
	   for(j=0;j<i;j++)
	   {
	     P2 = TTCD|TTDC;
		 delay(500);
		 TTDC = TTDC << 1;
	   }
	   TTCD = P2;
	 }
   }  
 }