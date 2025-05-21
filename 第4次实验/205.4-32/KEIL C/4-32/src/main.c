#include "reg52.h"

void main(void)
{
    unsigned char a = 75;   // 示例值
    unsigned char b = 125;   // 示例值
    unsigned int result;

    result = (unsigned int)a * a + (unsigned int)b * b;

    P1 = (unsigned char)((result >> 8) & 0xFF); // 高八位送至P1口
    P0 = (unsigned char)(result & 0xFF);        // 低八位送至P0口

    while (1);
}