#include "SST89x5x4.H"
void main(void)
{
	unsigned char data i;	//data为存储器类型说明
	while(1)
	{
	P1 = P1 | 0xF0 ;	    //声明高4 位为输入
	i = P1;					//读取P1高四位状态
	P1 = (i>>4) & 0x0F;		//将高四位结果右移至低四位进行与运算后输出
	}
}