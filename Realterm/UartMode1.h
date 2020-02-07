#ifndef _UARTMODE1_H_
#define _UARTMODE1_H_

// Khoi tao UART o mode 1
void Uart_Init();

// Gui 1 ky tu ra UART
void Uart_Write(char c);

// Gui 1 chuoi ra UART
void Uart_Write_Text(char * str);

// Kiem tra xem co nhan duoc byte du lieu chua
// Tra ve 1: Da nhan duoc
//        0: Chua nhan duoc
char Uart_Data_Ready();

// Doc byte nhan duoc tu UART
char Uart_Read();

#endif
