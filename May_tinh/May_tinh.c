  #include <main.h>
  #include "..\library\delay.h"

  unsigned char KeyPress()
 {
   unsigned char key = 0;
   Col1 = 0;
   if(Cow1==0) key = 1;
   if(Cow2==0) key = 2;
   if(Cow3==0) key = 3;
   if(Cow4==0) key = 4; 
   Col1 = 1;

   Col2 = 0;
   if(Cow1==0) key = 5;
   if(Cow2==0) key = 6;
   if(Cow3==0) key = 7;
   if(Cow4==0) key = 8;
   Col2 = 1;

   Col3 = 0;
   if(Cow1==0) key = 9;
   if(Cow2==0) key = 10;
   if(Cow3==0) key = 11;
   if(Cow4==0) key = 12;
   Col3 = 1;

   Col4 = 0;
   if(Cow1==0) key = 13;
   if(Cow2==0) key = 14;
   if(Cow3==0) key = 15;
   if(Cow4==0) key = 16;
   Col4 = 1;

   return key;
 }
  void LCD_cmd(unsigned char cmd) //khoi tao LCD
  {
    LCD_RS = 0;
	LCD_DATA = cmd;
	LCD_EN = 0;
	LCD_EN = 1;
	if(cmd <= 0x02) delay(2);
	else delay(1);
  }
  void LCD_chr_cp(char c) // ham gui 1 ki tu
  {
    LCD_RS = 1;
	LCD_DATA = c;
	LCD_EN = 0;
	LCD_EN = 1;
	delay(1);
  }
  void LCD_out_cp(char *str)
  {
    unsigned char i = 0;
	while(str[i]!=0)
	{
	  LCD_chr_cp(str[i]);
	  i++;
	}
  }
  void LCD_Init()
  {
    LCD_cmd(0x30);
	delay(5);
	LCD_cmd(0x30);
	delay(1);
	LCD_cmd(0x30);
	LCD_cmd(0x38);
	LCD_cmd(0x01);
	LCD_cmd(0x0C);
  }
  void Key_in()
  {
    unsigned char tmp;
	    delay(20);
		switch(KeyPress())
		{
		  case 1: LCD_cmd(0x01); 
		          break;
		  case 2: tmp = '1';
		          break;
		  case 3: tmp = '4';
		          break;
		  case 4: tmp = '7';
		          break;
		  case 5: tmp = '0';
		          break;
		  case 6: tmp = '2';
		          break;
		  case 7: tmp = '5';
		          break;
		  case 8: tmp = '8';
		          break;
		  case 9: tmp = '=';
		          break;
		  case 10: tmp = '3';
		          break;
		  case 11: tmp = '6';
		          break;
		  case 12: tmp = '9';
		          break;
		  case 13: tmp = '/';
		          break;
		  case 14: tmp = 'x';
		          break;
		  case 15: tmp = '-';
		          break;
		  case 16: tmp = '+';
		          break;
		  default: break;
		   
		}
		while(KeyPress()!=0)
		{
		  LCD_chr_cp(tmp);
		  while(KeyPress()!=0);
		} 
  }

  void main()
  {
	
	LCD_Init();
	while(1)
	{	 
	  Key_in();  
	}

  }