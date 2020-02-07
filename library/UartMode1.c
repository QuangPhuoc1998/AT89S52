#include"main.h"
#include"UartMode1.h"

#if(FREQ_OSC != 11059200)
	#error "Thu vien UartMode1 chi ho tro tan so hoat dong la 11059200"
#endif

void Uart_Init()
{
	SM0 = 0; SM1 = 1;		// Chon UART mode 1

	TMOD &= 0x0F;            // 0010 xxxx - Timer1 hoat dong o che do 8bit tu dong nap lai
	TMOD |= 0x20;

	#if(BAUD_RATE==9600)
	TH1 = 0xFD;				// Toc do baud 9600
	#elif(BAUD_RATE==2400)
	TH1 = 0xF4;
	#elif(BAUD_RATE==1200)
	TH1 = 0xE8;
	#elif(BAUD_RATE==19200)
	TH1 = 0xFD;
	PCON|=0x80;
	#else
		#error "Toc do Baud chi co the la 19200, 9600, 2400, 1200"
	#endif

	TR1 = 1;				// Timer1 bat dau chay
	TI = 1;					// San sang gui du lieu
	REN = 1;				// Cho phep nhan du lieu
}

void Uart_Write(char c)
{
 	while(TI == 0);
	TI = 0;
	SBUF = c;
}

void Uart_Write_Text(char * str)
{
	unsigned char i = 0;
 	while(str[i]!=0)
	{
		Uart_Write(str[i]);
		i++;
	}
}

char Uart_Data_Ready()
{
	return RI;
}

char Uart_Read()
{
	RI = 0;
	return SBUF;
}