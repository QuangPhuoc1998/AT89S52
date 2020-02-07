#include "main.h"
#include <rtx51tny.h>

//=========Ham Start up==========
void Startup(void) _task_ 0
{ 
 TMOD = 0x21;             //Timer 1 mode 2 
 os_create_task (1);      //Tao Task "Led_Do" 
 os_create_task (2);      //Tao Task "Led_Xanh"
 os_delete_task (0);      //Xoa Task hien tai (Task 0)
}
void Task_1(void) _task_ 1
{
  while(1)
  {
    P1 = 0xAA;
	os_wait(K_TMO,50,0);
	P1 = 0x55;
	os_wait(K_TMO,50,0);
  }
}
void Task_2(void) _task_ 2
{
  while(1)
  {
    P3 = 0xAA;
	os_wait(K_TMO,50,0);
	P3 = 0x55;
	os_wait(K_TMO,50,0);
  }
}