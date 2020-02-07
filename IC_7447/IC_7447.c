	#include <main.h>
	#include <..\library\delay.h>

	void main()
	{	   
	  unsigned int dem = 0;
	  unsigned char tram, chuc, donvi;
	  unsigned char tam;
	  while(1)
	  {
	      donvi = dem%10;
		  chuc = (dem%100)/10;
		  tram = dem/100;
		  tam = chuc << 4;
		  tam |= donvi;
		  P2 = tam;
		  P3 = tram;
		  delay(100);

		  dem++;
		  dem%=1000;
	  }
	}