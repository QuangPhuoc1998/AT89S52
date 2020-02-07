 #include <main.h>
 #include <..\..\library\delay.h>

 unsigned char code code7seg[] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6};
 unsigned int chuc, donvi;
 unsigned char Presskey()
 {
   unsigned char key = 0;
   h1 = 0;
   if(c1==0) key = 1;
   if(c2==0) key = 2;
   if(c3==0) key = 3;
   h1 = 1;

   h2 = 0;
   if(c1==0) key = 4;
   if(c2==0) key = 5;
   if(c3==0) key = 6;
   h2 = 1;

   h3 = 0;
   if(c1==0) key = 7;
   if(c2==0) key = 8;
   if(c3==0) key = 9;
   h3 = 1;

   return key;
 }
 void time_on(unsigned int dem)
 {
   chuc = dem/10;
   donvi = dem%10;

   LED7 = code7seg[chuc];
   ledchuc = 0;
   delay(1);
   ledchuc = 1;

   LED7 = code7seg[donvi];
   leddonvi = 0;
   delay(1);
   leddonvi = 1;
 }
 void main()
 {
   unsigned int dem;
   while(1)
   { 
     if(Presskey()!=0) dem = Presskey();
	 time_on(dem);
   }
 }