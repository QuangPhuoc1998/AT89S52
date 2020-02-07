 #include <main.h>
 #include "..\..\library\delay.h"

 void thuan();
 void nghich();
 void main()
 {
   if(STA==0)
   {
     while(STA==0);
	 delay(1);
	 while(1)
	 {
	   if(THUAN==0) thuan();
	   if(NGHICH==0) nghich();
	   if(STO==0) 
	   {
	     P2_0 = P2_1 = 0;
		 Led_thuan = Led_nghich = 1;
		 while(STO==0) Led_sto = 0;
		 Led_sto = 1;
		 break;
	   }
	 }
   }
 }
 void nghich()
 {
   P2_0 = 1;
   Led_nghich = 0;
   Led_thuan = 1;
   P2_1 = !P2_0;
 }
 void thuan()
 {
   P2_0 = 0;
   Led_nghich = 1;
   Led_thuan = 0;
   P2_1 = !P2_0;
 }