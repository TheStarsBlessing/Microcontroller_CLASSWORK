#include "reg52.h"
#include "SMGled0.h"

unsigned char square_sum(unsigned char a, unsigned char b);
void main(void)
{
    unsigned char result;
    result=square_sum(3, 5); // 示例值
    P1 = smg_code[result/10]; // 显示十位
    P0 = smg_code[result%10]; // 显示个位
    while (1);
}

unsigned char square_sum(unsigned char a, unsigned char b)
{
    return a * a + b * b; // 计算平方和
}   
