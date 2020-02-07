 #include <main.h>
 #define LED P0
 sbit L4 = P3^3;
 sbit L3 = P3^2;
 sbit L2 = P3^1;
 sbit L1 = P3^0;
 sbit BTN_Up = P3^3;
 sbit BTN_Down = P3^2;
 int donvi, chuc, tram, ngan;
 char bytethap, bytecao;
 
 
 int i, x, dem;
 unsigned char code code7seg[10] = {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE0, 0xFE, 0xF6};	//catot chung
 unsigned int doc_ADC();
 void delay_ms(unsigned int t);
 void time_on( int t);
 void main()
 {
   while(1)
   {
     if(BTN_Up==0)
	 {
	   while(BTN_Up==0) time_on(dem);
	   if(dem==9999);  else dem++;
	 }
	 if(BTN_Down==0)
	 {
	   while(BTN_Down==0) time_on(dem);
	   if(dem==0); else dem--;
	 }
	 time_on(dem);
  }
 }
 void delay_ms(unsigned int t)
 {
   unsigned int y;
   for(y=0;y<t;y++)
   {
	   TMOD = 0x01;
	   TH0 = 0xFC;
	   TL0 = 0x18;
	   TF0 = 0;
	   TR0 = 1;
	   while(!TF0);
	   TF0 = 0;
	   TR0 = 0;
   }
 }
 unsigned int doc_ADC()
 {
   int giatri;
   P2_1 = P2_2 = P2_3 = 0;
   P2_0 = 0;
   P2_0 = 1;
   P2_0 = 0;
   giatri = P0;
   return giatri;
 }
 void time_on( int t)
 {
	ngan = t/1000;
	tram = (t%1000)/100;
	chuc = (t%100)/10;
	donvi = t%10;
   
    LED = code7seg[donvi];
	L1	= 0;
	delay_ms(1);
	L1 = 1;
	LED = code7seg[chuc];
	L2 = 0;
	delay_ms(1);
	L2 = 1;
	LED = code7seg[tram];
	L3	= 0;
	delay_ms(1);
	L3 = 1;
	LED = code7seg[ngan];
	L4 = 0;
	delay_ms(1);
	L4 = 1;  
 }
 