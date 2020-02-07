#include "main.h"
#include "delay.h"

void main()
{
  while(1)
  {
    delay(20);
	P0_0 = ~P0_0;
  }
}