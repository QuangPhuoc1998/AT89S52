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

  #define LED_Port P2
  sbit LED_donvi = P3^1;
  sbit LED_chuc = P3^0;

  #endif