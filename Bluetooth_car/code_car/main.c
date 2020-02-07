#include "main.h"
#include "delay.h"
#include "UartMode1.h"


void main()
{
  Uart_Init();
  ES = 1;
  EA = 1;
  P1 = 0x00;
  while(1)
  { 

  }
}
void ngat() interrupt 4
{
  static unsigned char c = 0;
  c = Uart_Read(); 
  EA = 0; 
  switch(c)
  {
    case 'a':
	  P1_0 = !P1_0;
	  break;
	case 'b':
	  P1_1 = !P1_1;
	  break;
	case 'c':
	  P1_2 = !P1_2;
	  break;
	default: break;
  }
  c = 0;
  SBUF = 0x00;
  EA = 1; 
}
