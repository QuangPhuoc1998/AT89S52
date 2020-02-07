 #include <main.h>

 unsigned int a, b, c;
 void hien_s(unsigned int a, b, c);
 void hien_c(unsigned int a, b, c);
 void main()
 {
   while(1)
   {
     if(BTN1==0) a = 1; else a = 0;
	 if(BTN2==0) b = 1; else b = 0;
	 if(BTN3==0) c = 1; else c = 0;
	 hien_s(a, b, c);
	 hien_c(a, b, c); 
   }
 }
 void hien_c(unsigned int a, b, c)
 {
   led2 = !((a&b)|(a&c)|(b&c));
 }
 void hien_s(unsigned int a, b, c)
 {
   led1 = !((((!a&b)|(a&!b))&!c)|(!((!a&b)|(a&!b))&c));
 }