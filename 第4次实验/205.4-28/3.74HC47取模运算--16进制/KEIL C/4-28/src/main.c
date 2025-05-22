#include "reg52.h"

unsigned int square_sum(unsigned char a, unsigned char b);
void main(void)
{
    unsigned int result;
    result=square_sum(75, 133); // 示例值
    P1 = result/256; // 高八位送至P1口
    P0 = result%256; // 低八位送至P0口
    while (1);
}

unsigned int square_sum(unsigned char a, unsigned char b)
{
    return (unsigned int)a * a + (unsigned int)b * b; // 计算平方和
}   
