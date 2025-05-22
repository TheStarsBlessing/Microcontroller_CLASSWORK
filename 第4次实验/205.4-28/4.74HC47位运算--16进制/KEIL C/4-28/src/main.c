#include "reg52.h"

void main(void)
{
    unsigned char a = 75;   // 示例值
    unsigned char b = 133;   // 示例值
    unsigned int result;

    result = (unsigned int)a * a + (unsigned int)b * b;

    P1 = (unsigned char)((result >> 8) & 0xFF); // 高八位送至P1口
    P0 = (unsigned char)(result & 0xFF);        // 低八位送至P0口

    while (1);
}

//result 是一个 unsigned int 类型（通常是16位），将其右移8位后，得到的是高8位。
//但为了确保只保留低8位（即真正想要的高8位数据），使用 & 0xFF 可以屏蔽掉更高位的影响。