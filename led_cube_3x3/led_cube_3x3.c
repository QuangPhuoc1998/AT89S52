#include <main.h>
#include <delay.h>
/* khai bao */
#define cube P0
sbit tang_1 = P2^0;
sbit tang_2 = P2^1;
sbit tang_3 = P2^2;
sbit led9 = P2^7;
/* hieu ung */
void hu1();
void hu2();
void hu3();
void hu4();
void hu5();
/* chuong trình chinh */
unsigned int i;
void main()
{ 
  for(i=0;i<5;i++)
	{
      hu4();
	}
  while(1)
  {
    for(i=0;i<2;i++)
	{
      hu1();
	}
	for(i=0;i<2;i++)
	{
      hu2();
	}
	for(i=0;i<5;i++)
	{
      hu3();
	}   	   
  }
}
void hu1()
{
  cube = 0x00; led9 = 0;
  tang_1 = 1; tang_2 = 0; tang_3 = 0;
  delay(500);
  tang_1 = 0; tang_2 = 1; tang_3 = 0;
  delay(500);
  tang_1 = 0; tang_2 = 0; tang_3 = 1;
  delay(500);
  tang_1 = 0; tang_2 = 1; tang_3 = 0;
  delay(500);
}
void hu2()
{
  tang_1 = tang_2 = tang_3 = 1;
  cube = 0xF8; led9 = 1;
  delay(500);
  cube = 0xC7; led9 = 1;
  delay(500);
  cube = 0x3F; led9 = 0;
  delay(500);
  cube = 0xC7; led9 = 1;
  delay(500);
}
void hu3()
{
  cube = 0xAA; led9 = 0;
  tang_1 = tang_2 = tang_3 = 1; 
  delay(500);
  cube = 0x55; led9 = 1;
  tang_1 = tang_2 = tang_3 = 1; 
  delay(500);
}
void hu4()
{
  cube = 0xEF; led9 = 1;
  tang_1 = 1; tang_2 = 0; tang_3 = 0;
  delay(150);
  tang_1 = 0; tang_2 = 1; tang_3 = 0;
  delay(150);
  tang_1 = 0; tang_2 = 0; tang_3 = 1;
  delay(200);
  cube = 0xAA; led9 = 0;
  delay(250);
  cube = 0x55; led9 = 1;
  delay(250);
  tang_1 = 0; tang_2 = 1; tang_3 = 0;
  delay(200);
  tang_1 = 1; tang_2 = 0; tang_3 = 0;
  delay(200);
}