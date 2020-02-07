#include "main.h"
#include "LCD4.h"
#include "UartMode1.h"
#include "delay.h"
#include <RTX51TNY.H>

void check_led1();
void check_led2();
void check_led3();
void check_led4();
void check_led5();
void check_led6();
void check_led7();
void check_led8();

void main()
{
  
  // value
  unsigned char u;
  // port
  P1 = 0x00;
  // chuong trinh con
  Lcd_Init();
  Uart_Init();
  // begin
  Lcd_Out_Cp("connet...");
  while(1)
  {
      Lcd_gotoxy(1,1);
	  Lcd_Out_Cp("connet...");
	  while(1)
	  {
	    if(Uart_Data_Ready())
		{
		  u = Uart_Read();
		  if(u == 's') break;
		}
	  }
	  Lcd_Cmd(_LCD_CLEAR);
	  Lcd_Out_Cp("READY...");
	  delay(500);
	  Lcd_Cmd(_LCD_CLEAR);
	  check_led1();
	  check_led2();
	  check_led3();
	  check_led4();
	  check_led5();
	  check_led6();
	  check_led7();
	  check_led8();
	  while(1)
	  {
	    if(Uart_Data_Ready())
		{
		  u = Uart_Read();
		  switch(u)
		  {
		    case '0':
			  P1_0 = ~P1_0;
			  check_led1();
			  break;
			case '1':
			  P1_1 = ~P1_1;
			  check_led2();
			  break;	
			case '2':
			  P1_2 = ~P1_2;
			  check_led3();
			  break;
			case '3':
			  P1_3 = ~P1_3;
			  check_led4();
			  break;
			case '4':
			  P1_4 = ~P1_4;
			  check_led5();
			  break;
			case '5':
			  P1_5 = ~P1_5;
			  check_led6();
			  break;
			case '6':
			  P1_6 = ~P1_6;
			  check_led7();
			  break;
			case '7':
			  P1_7 = ~P1_7;
			  check_led8();
			  break;
			case 'e':
			  Lcd_Cmd(_LCD_CLEAR);
			  goto end;
		    default: break;
		  }  
		}
	  }
	  end:;
  }
}
// LED1
void check_led1()
{
  if(P1_0)
  {
	Lcd_gotoxy(1,1);
    Lcd_Out_Cp("ON ");
  }
  else 
  {
    Lcd_gotoxy(1,1);
    Lcd_Out_Cp("OFF");
  }
}
// LED2
void check_led2()
{
  if(P1_1)
  {
	Lcd_gotoxy(1,5);
    Lcd_Out_Cp("ON ");
  }
  else 
  {
    Lcd_gotoxy(1,5);
    Lcd_Out_Cp("OFF");
  }
}
// LED3
void check_led3()
{
  if(P1_2)
  {
	Lcd_gotoxy(1,9);
    Lcd_Out_Cp("ON ");
  }
  else 
  {
    Lcd_gotoxy(1,9);
    Lcd_Out_Cp("OFF");
  }
}
// LED4
void check_led4()
{
  if(P1_3)
  {
	Lcd_gotoxy(1,13);
    Lcd_Out_Cp("ON ");
  }
  else 
  {
    Lcd_gotoxy(1,13);
    Lcd_Out_Cp("OFF");
  }
}
// LED5
void check_led5()
{
  if(P1_4)
  {
	Lcd_gotoxy(2,1);
    Lcd_Out_Cp("ON ");
  }
  else 
  {
    Lcd_gotoxy(2,1);
    Lcd_Out_Cp("OFF");
  }
}
// LED6
void check_led6()
{
  if(P1_5)
  {
	Lcd_gotoxy(2,5);
    Lcd_Out_Cp("ON ");
  }
  else 
  {
    Lcd_gotoxy(2,5);
    Lcd_Out_Cp("OFF");
  }
}
// LED7
void check_led7()
{
  if(P1_6)
  {
	Lcd_gotoxy(2,9);
    Lcd_Out_Cp("ON ");
  }
  else 
  {
    Lcd_gotoxy(2,9);
    Lcd_Out_Cp("OFF");
  }
}
// LED8
void check_led8()
{
  if(P1_7)
  {
	Lcd_gotoxy(2,13);
    Lcd_Out_Cp("ON ");
  }
  else 
  {
    Lcd_gotoxy(2,13);
    Lcd_Out_Cp("OFF");
  }
}