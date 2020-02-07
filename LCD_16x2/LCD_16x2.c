  #include <main.h>
  #include <..\library\delay.h>
  #include <lcd8.h>


  void LCD_Cmd(unsigned char Cmd ) //ham gui lenh
  {
   	LCD_RS = 0;
	LCD_DATA = Cmd;
	LCD_EN = 0;
	LCD_EN = 1;
	if(Cmd <= 0x02) delay(2); else delay(1);
  }
  void LCD_chr_cp(char c)  //xuat ra 1 ki tu tai vi tri con tro, cp: current position : vi tri con tro
  {
    LCD_RS = 1;
	LCD_DATA = c;
	LCD_EN = 0;
	LCD_EN = 1;
	delay(1);  
  }
  void LCD_chr(unsigned char row, unsigned char col, char c)
  {
    unsigned char cmd;
	cmd = (row==1?0x80:0xC0) + col-1;
	LCD_Cmd(cmd);
	LCD_chr_cp(c);
  }
  void LCD_Out_cp(char *str)
  {
    unsigned char i = 0;
	while(str[i]!=0)
	{
	  LCD_chr_cp(str[i]);
	  i++;
	}  
  }
  void LCD_out(unsigned char row, unsigned char col, char *str)
  {
    unsigned char cmd;
	cmd = (row==1?0x80:0xC0) + col-1;
	LCD_Cmd(cmd);
	LCD_Out_cp(str);
  }
  void LCD_Init()
  {
    LCD_Cmd(0x30);
	delay(5);
	LCD_Cmd(0x30);
	delay(1);
	LCD_Cmd(0x30);

	LCD_Cmd(0x38); // so dong hien thi la 2

	LCD_Cmd(0x01); // xoa man hinh
	LCD_Cmd(0x0C);  // bat hien thi xoa con tro
  }										  
  void main()
  {
    LCD_Init();
	LCD_out(1,1,".......LOZ DAT 09.......");
	
	
	
    while(1)
	{
	  delay(500);
	  LCD_Cmd(0x18);
	}
  }