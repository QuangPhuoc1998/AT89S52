#include "main.h"
#include "delay.h"



void Soft_SPI_Init();
void Soft_SPI_Write(unsigned char b);
unsigned char Soft_SPI_Read(void);
void EEPROM_25LCxxx_Write(unsigned int add, unsigned char b);
unsigned char EEPROM_25LCxxx_Read(unsigned int add);
unsigned char EEPROM_25LCxxx_WIP();

void main()
{
    unsigned char i;
	// Khoi tao giao tiep SPI
	Soft_SPI_Init();
	for(i=0;i<100;i++)
	{
	 EEPROM_25LCxxx_Write(i,i);
	}
//	delay(500);	   neu co ham kiem tra thi khong can delay
	
	while(1)
	{
	  for(i=0;i<100;i++)
	  {
	    P1 = EEPROM_25LCxxx_Read(i);
		delay(500);
	  }
	}
}

// Ghi mot byte b sang EEPROM, tai dia chi add
void EEPROM_25LCxxx_Write(unsigned int add, unsigned char b)
{
	SPI_CS = 0;
	Soft_SPI_Write(0x06);			// Gui lenh WREN
	SPI_CS = 1;
	
	SPI_CS = 0;
	Soft_SPI_Write(0x02);						// Gui lenh WRITE
	Soft_SPI_Write(add>>8);					// Gui byte cao cua dia chi
	Soft_SPI_Write(add & 0x00FF);		// Gui byte thap cua dia chi
	Soft_SPI_Write(b);
	SPI_CS = 1;

	while(EEPROM_25LCxxx_WIP());
}
unsigned char EEPROM_25LCxxx_Read(unsigned int add)
{
  unsigned char b;

  SPI_CS = 0;
  Soft_SPI_Write(0x03);
  Soft_SPI_Write(add>>8);					// Gui byte cao cua dia chi
  Soft_SPI_Write(add & 0x00FF);		// Gui byte thap cua dia chi
  b = Soft_SPI_Read();
  SPI_CS = 1;
  return b;
}
unsigned char EEPROM_25LCxxx_WIP()
{
  unsigned char result;
  SPI_CS = 0;
  Soft_SPI_Write(0x05);
  result = Soft_SPI_Read();
  SPI_CS = 1;
  return result&0x01;
}
void Soft_SPI_Init()
{
	SPI_CS = 1;	
	SPI_SCLK = 0;
	SPI_MISO = 1;
}

unsigned char Soft_SPI_Read(void)
{
	// software SPI read, MSB read first
	unsigned char i, b;

	for(i=0;i<8;i++)
	{
		b <<= 1;
		SPI_SCLK = 1;
		if(SPI_MISO)
			b |= 0x01;
		SPI_SCLK = 0;
	}

	return b;
}

void Soft_SPI_Write(unsigned char b)
{
	// software SPI, send MSB first
	unsigned char i;

	for(i=0;i<8;i++)
	{
		if((b&0x80)==0x80)
			SPI_MOSI = 1;
		else
			SPI_MOSI = 0;

		SPI_SCLK = 1;
		b <<= 1;
		SPI_SCLK = 0;
	}
}



