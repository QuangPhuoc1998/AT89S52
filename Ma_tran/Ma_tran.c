 #include "main.h"
 #include "..\library\delay.h"
 unsigned char code code7seg[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
 
 unsigned char donvi, chuc;
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

 void Time_on(unsigned char a)
 {
   chuc = a/10;
   donvi = a%10;

   LED_Port = code7seg[donvi];
   LED_donvi = 0;
   delay(1);
   LED_donvi = 1;

   LED_Port = code7seg[chuc];
   LED_chuc = 0;
   delay(1);
   LED_chuc = 0;
 }
 void main()
 {		
   unsigned char tmp;   
   while(1)
   {
      if(KeyPress()!=0) tmp = KeyPress();
  	  Time_on(tmp);
   }
 }