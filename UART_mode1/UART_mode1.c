 #include <main.h>
 #include "..\library\delay.h"
 #include "..\library\UARTmode1.h"
 void main()
 {
   char i;
   UART_Init();
   for(i='a'; i<='z'; i++)
   {
  	 UART_write(i);
	 delay(500);
   }

   while(1)
   {
//     if(UART_Data_really()==1)
//	 {
//	   P2 = UART_read();
//	   delay(1);
//	 }
   }
 }