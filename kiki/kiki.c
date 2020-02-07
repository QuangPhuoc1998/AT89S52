#include <regx51.h>
#include <E:\file Keil C\AT89S52\kiki\delay.h>
void main()
{
   P0 = P1 = P2 = P3 = 0x55;
   while(1)
   {
     	delay(500);
		P0 = ~P0;
		P1 = ~P1;
		P2 = ~P2;
		P3 = ~P3;
   }
}