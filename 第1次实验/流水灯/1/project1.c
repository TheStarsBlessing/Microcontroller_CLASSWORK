#include "SST89x5x4.H"
#include "intrins.h"			  //这个头文件定义了右移函数_crol_()
#define LED_PORT P2				  //定义P2口
unsigned char n;
void Delay_t_100ms(unsigned char t)	//@11.0592MHz
{
	while(t--)
	{
		unsigned char i, j;

		i = 180;
		j = 73;
		do
		{
			while (--j);
		} while (--i);
	}
}
						  //100ms延时函数，本函数由STC-ISP生成
void main()
{
	LED_PORT=0xFE;				  //点亮P2.0LED灯
	while(1)									//循环移动
	{
		for(n=0;n<8;n++)						
		{
			LED_PORT=_crol_(LED_PORT,1);		//从左到右是0~8位，因此这里是左移函数
			Delay_t_100ms(5);					//软件延时
		}						  //右移循环
	}
}