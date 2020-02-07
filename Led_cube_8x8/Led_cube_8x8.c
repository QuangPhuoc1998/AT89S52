 #include <main.h>
 #include <delay.h>

 void HC595(unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4,
 unsigned char  b5, unsigned char b6, unsigned char b7, unsigned char b8);
 void main()
 {
   while(1)
   {
     HC595(0xFF, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xFF);
     delay(500);
	 HC595(0x81, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x81);
	 delay(500);
   }
 }
 void HC595(unsigned char b1, unsigned char b2, unsigned char b3, unsigned char b4, 
 unsigned char b5, unsigned char b6, unsigned char b7, unsigned char b8)
 {
   unsigned int i;
   for(i=0;i<8;i++)
   {
     DS1 = b1&(0x80>>i);
	 DS2 = b2&(0x80>>i);
	 DS3 = b3&(0x80>>i);
	 DS4 = b4&(0x80>>i);
	 DS5 = b5&(0x80>>i);
	 DS6 = b6&(0x80>>i);
	 DS7 = b7&(0x80>>i);
	 DS8 = b8&(0x80>>i);
	 SH_CP = 0;
	 SH_CP = 1;
   }
   ST_CP = 0;
   ST_CP = 1;
 }