 #include <main.h>
 #include "..\library\delay.h"
 #include "E:\file Keil C\AT89S52\library\UARTmode1.h"

 void main()
 { 
   UART_Init();
   while(1)
   {
     if(BTN_ON==0)
	 {
	   delay(20);
	   UART_write(0x01);
	   while(BTN_ON==0);
	 }
	  if(BTN_OFF==0)
	 {
	   delay(20);
	   UART_write(0x00);
	   while(BTN_OFF==0);
	 }
   }
 }