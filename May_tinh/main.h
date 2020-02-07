  #ifndef _MAIN_H_
  #define _MAIN_H_

  #include <regx51.h>
  #define FREQ_OSC 12000000ul
  sbit Col1 = P1^0;
  sbit Col2 = P1^1;
  sbit Col3 = P1^2;
  sbit Col4 = P1^3;

  sbit Cow1 = P1^4;
  sbit Cow2 = P1^5;
  sbit Cow3 = P1^6;
  sbit Cow4 = P1^7;

  sbit LCD_RS = P2^0;
  #define LCD_DATA P3
  sbit LCD_EN = P2^1;

  #endif		