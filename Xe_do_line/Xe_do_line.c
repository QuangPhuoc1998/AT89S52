 #include <main.h>
 #include "..\library\delay.h"

 void main()
 {
     while(1)
   {
     if(IR==0x11) P2_1 = 0;
     delay(1);
   }
 }