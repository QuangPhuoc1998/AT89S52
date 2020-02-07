#include<AT89x51.h>
void delay(int k);    
void main()
{  while(1)
 { 
if(P3_5==0)  
{ P2=0xFF;  
delay(500); 
P3_0=0; 
P3_1=1; 
P3_2=1;} 
if(P3_6==0) 
{ P2_0=0;
 delay(500);  
 P2_1=1; 
P3_0=1;
 P3_1=0;
 }
if(P3_7==0) 
{ 
P2_0=1;
 delay(500); 
P2_1=0;
 P3_0=1;
 P3_1=1;
 P3_2=0; 
} }}  
void delay(int k) 
{  int i,j;  
for(i=0;i<k;i++)
{ 
for(j=0;j<100;j++);   
} 
}