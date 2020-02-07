   #include <main.h>
   #include <delay.h>
   #include <LCD4.h>
  void ADC0808_Init()
{
 	STA = 0;
	ALE = 0;
	OE = 0;	
}
  unsigned char ADC0808_Read(unsigned char channel)
{
	unsigned char kq;

 	PA = channel & 0x01;
	PB = channel & 0x02;
	PC = channel & 0x04;

	ALE = 1;
	STA = 1;
	ALE = 0;
	STA = 0;

	while(EOC);
	while(EOC);

	OE = 1;
	kq = ADC0808_DATA;
	OE = 0;

	return kq;
}
  void main()
  {
    unsigned char adc_value;
	unsigned char t;

	ADC0808_Init();
	Lcd_Init();

	//Lcd_Out(1,1,"Hello ");
	Lcd_Out(1,1,"Nhiet do: ");
	while(1)
	{
	  adc_value = ADC0808_Read(2);
	  t = adc_value*1.961f + 0.5f;
	  Lcd_Chr(1,10,t/100+0x30);
	  Lcd_Chr_Cp(t%100/10+0x30);
	  Lcd_Chr_Cp(t%10+0x30);
	  Lcd_Chr(2,1,adc_value/100+0x30);
	  Lcd_Chr_Cp(adc_value%100/10+0x30);
	  Lcd_Chr_Cp(adc_value%10+0x30);
      delay_ms(500);	 
	}
  }
  