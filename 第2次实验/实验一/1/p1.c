#include<SST89x5x4.H>

unsigned char code table[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};	  //定义段码

void delay(unsigned char delay_time) 	   //延时函数
{
	unsigned char i,j;

	for(i=0;i<=delay_time;i++) 
	{
		for(j=0;j<=200;j++);
	}
}

void init_tx() 								//中断函数配置
{
	EA=1; EX0=1; IP=0x00;	//CPU开放中断，外部中断0开放，所有中断源均设为低优先级
}

void main()
{
	unsigned char i;
	init_tx();				 //配置中断函数
	while(1)
	{
		for(i=0;i<6;i++)
		{
			P1=table[i]; 
			delay(200);
		}
	}						 //中断未触发时持续循环输出段码
}

void tx0() interrupt 0		   //触发中断后调用该函数
{
	unsigned char i;
	P1=0x00;
	delay(200);
	for(i=0;i<=15;i++)//注意，闪烁8次应该进行16次电平反转 P1=~P1;
	{
		P1=~P1;
		delay(200);			  //闪烁8次
	}
}