#include <main.h>
#include <delay.h>
#define Step P0
unsigned char full_drive[4] = {0x09,0x0C, 0x06, 0x03};
void main()
{
  unsigned int i;
  while(1)
  {
    for(i=0;i<4;i++)
	{
	  Step = full_drive[i];
	  delay(50); 
	}  
  }
}