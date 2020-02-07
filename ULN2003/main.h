  #ifndef _MAIN_H_
  #define _MAIN_H_

  #include <regx51.h>
  #define FREQ_OSC 12000000ul

  #define step_motor P0
  sbit BTN_right = P2^0;
  sbit BTN_left = P2^1;
  sbit tang = P2^2;
  sbit giang = P2^3;
  sbit dung = P2^4;

  #endif