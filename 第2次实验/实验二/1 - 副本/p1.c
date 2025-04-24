#include "SST89x5x4.h"
#include "Intrins.h"

void delay(void)
{
	unsigned int x;
	for(x=0; x<0xFFFF; x++);
}

void int0_isr() interrupt 0		 //INT0 中断，外部中断0 的中断号为0
{
	unsigned char j;
	for(j=0; j<4; j++)
	{
		P1 = 0xFF; //使LED 闪烁
		delay();
		P1 = 0x00;
		delay();
	}	
}

void int2_isr() interrupt 2 //INT1 中断，外部中断1 的中断号为2
{
	unsigned char i=0x03, j;
	for(j=0; j<16; j++)
	{
		P1 = i; //使LED 流水显示
		i = _crol_(i, 2);
		delay();
	}
	P1 = 0x00;
}

void main()
{
	P1 = 0x00;
	IP=0x04;
	IT0 = 1; EX0 = 1; //中断0
	IT1 = 1; EX1 = 1; //中断1
	EA = 1;
	while(1);
}
