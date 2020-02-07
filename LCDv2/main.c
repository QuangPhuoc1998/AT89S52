#include <main.h>
#include <lcd4.h>
#include <delay.h>

void main()
{
  Lcd_Init();
  Lcd_Out_Cp("DO NHONG NHEO");
  Lcd_gotoxy(2,1);
  Lcd_Out_Cp("DE THUONG S2 !!");
  while(1)
  {}
}
