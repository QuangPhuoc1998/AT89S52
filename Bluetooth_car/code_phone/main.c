#include "main.h"
#include "delay.h"
#include "UartMode1.h"

sbit BTN1 = P1^0; 
sbit BTN2 = P1^1; 
sbit BTN3 = P1^2; 
void main()
{
  Uart_Init();
  while(1)
  {
    if( BTN1 == 0)
	{
	  while(BTN1 == 0);
	  Uart_Write('a');
	}
	if( BTN2 == 0)
	{
	  while(BTN2 == 0);
	  Uart_Write('b');
	}
	if( BTN3 == 0)
	{
	  while(BTN3 == 0);
	  Uart_Write('c');
	}
  }
}