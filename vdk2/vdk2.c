	#include <main.h>
	#include "..\library\delay.h"
	#include "E:\file Keil C\AT89S52\library\UARTmode1.h"
	
	void main()
		{
		P1_0 = 1;
		UART_Init();
		while(1)
			{
			 if(UART_Data_really()==1)
			 {
			   if(UART_read()==0x01)
			   {
			     while(1)
				 {
				   P1 = 0xAA;
				   delay(500);
				   P1 = ~P1;
				   delay(500);
				   if(UART_read()==0x00) 
				   {
				     P1 = 0xFF;
				     break;
				   }
				 }
			   }
			 }
			}
		}