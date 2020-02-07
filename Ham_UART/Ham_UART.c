  #include "main.h"
  #include "..\library\delay.h"
  #include "..\library\UARTmode1.h"
  #include <stdio.h>

  void main()
  {
    UART_Init();
	putchar('A');
	printf(" \r hello work ");
    while(1)
	{
	}
  }