#include "SST89x5x4.H"
void main(void)
{
	unsigned char data i;		   //data为存储器类型说明
	while(1)
	{
	P3 = P3 | 0x0F ;			   //声明P3口低4位为输入
	i = P3;						   //读取P3低四位状态
	P2 = (i<<4) & 0xF0;			   //将P3低四位结果左移至高四位进行与运算后在P2口输出
	}
}												 