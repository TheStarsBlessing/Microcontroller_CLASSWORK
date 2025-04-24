#include "SST89x5x4.H"
#define uchar unsigned char
#define unit unsigned int		 //重新定义关键字
sbit in = P1^0;
sbit out = P1^7;			     //对P1.0和P1.7进行定义

void main(void)
{
	while(1)					 //无限循环
	{
		in = 1;					 //对P1.0进行置位，排除干扰
		if (in == 0)			 
			out = 0;			 //当按键按下时点亮LED灯
		else
			out = 1;   			 //其他情况LED保持熄灭
	}
}								 //主函数