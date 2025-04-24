#include "reg52.h"
#include "intrins.h"
#define uchar unsigned char
#define uint unsigned int
void DelayMS(uint x)
{
    uchar t;
    while(x--)
    {
        for(t=120;t>0;t--);
    }
}                                //延时函数
void main()
{
	uchar i;
    P2=0x01;
    while(1)
    {
        for(i=7;i>0;i--)
        {
            P2=_crol_(P2,1);
            DelayMS(150);
        }                          //循环右移
        for(i=7;i>0;i--)
        {
            P2=_cror_(P2,1);        //第二个参数（2）不正确，应该为1.(cror函数第二个参数指一次移动的位数)
            DelayMS(150);
        }                        //循环左移
    }
}