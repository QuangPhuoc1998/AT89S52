 #include <main.h>
 #include "..\library\delay.h"
 #include "..\library\LCD4.h"


//  Init()Lcd_;
//   Lcd_Cmd(_LCD_4BIT_2LINE_5x7FONT);
//   P2 = 0xAA;
//   Lcd_Out(1,1,"PHAM QUANG PHUOC");	
//   while(1)
//   { 
//	 
//  	 delay(500);
//   }
   unsigned int i;
   unsigned char code_1[12] = {'*','*','*',' ', 'h','i','h','i',' ','*','*','*'};
   unsigned char code_2[15] = {'*','*','*',' ', 'C','h','a','o', ' ','B','e',' ','*','*','*'};
   unsigned char code_3[16] = {'N','G','U','Y', 'E','N',' ','M', 'A','I',' ','Q','U','Y','E','N'};
   unsigned char code_4[13] = {'<','<','B','e',' ','R','a','t',' ','L','a','>','>'};
   unsigned char code_5[15] = {'_','_',' ','N','h','u','n','g',' ','l','a','i',' ','_','_',};

 

 void main()
 {
   Lcd_Init();
   
   


   while(1)
   {
     // hihi
     Lcd_Chr(1,3,'*');
     for(i=1;i<12;i++)
	 {
	   delay(70);
	   Lcd_Chr_Cp(code_1[i]);  
	 }
	 delay(500);
	 Lcd_Cmd(_LCD_CLEAR);
	 // chao be
     for(i=0;i<15;i++)
	 {
	   delay(150);
	   Lcd_Chr_Cp(code_2[i]);  
	 }
	 delay(200);
	// NGUYEN MAI QUYEN
	 Lcd_Chr(2,1,'N');
     for(i=1;i<16;i++)
	 {
	   delay(100);
	   Lcd_Chr_Cp(code_3[i]);  
	 }
	 delay(500);
	 Lcd_Cmd(_LCD_CLEAR);
	 // be con o do khong ta
	 for(i=0;i<13;i++)
   {
     Lcd_Out(1,1,"* Be Con o do *");
     Lcd_Out(2,16-i,"Khong ta");
	 delay(100);
	 if(i==12); else Lcd_Cmd(_LCD_CLEAR);
   }
   delay(500);
   Lcd_Cmd(_LCD_CLEAR);
	// be ra la
	Lcd_Chr(1,1,'<');
   for(i=1;i<13;i++)
   {
     delay(150);
	 Lcd_Chr_Cp(code_4[i]);
   }
   delay(100);
   Lcd_Chr(2,1,'=');
   for(i=0;i<15;i++)
   {
     if(i==14) Lcd_Chr_Cp('>'); else Lcd_Chr_Cp('=');
	 delay(100);
   }
   delay(200);
   Lcd_Cmd(_LCD_CLEAR);
   // NHong nheo de thuong
   Lcd_Out_Cp("Nhong nheo");
   delay(200);
   Lcd_Out_Cp(" (*_*))");
   delay(700);

   Lcd_Out(2,1,"(~_~)  ");
   delay(200);
   Lcd_Out_Cp(" Kho chiu");
   delay(1000);
   Lcd_Cmd(_LCD_CLEAR);
   // dt
   for(i=0;i<15;i++)
   {
     Lcd_Chr_Cp(code_5[i]);
	 delay(100);
   }
   delay(300);
   Lcd_Out(2,1,"RAT DE THUONG S2");
   delay(1500);
   Lcd_Cmd(_LCD_CLEAR);
   // IU
   Lcd_Out_Cp(" IU CON BE CON");
   delay(500);
   Lcd_Out(2,3,"S2");
   for(i=0;i<4;i++)
   {
     delay(200);
	 if(i==1) Lcd_Out_Cp("(^_^)"); else Lcd_Out_Cp("S2"); 
   }
   delay(5000);
   Lcd_Cmd(_LCD_CLEAR);
   }
 }