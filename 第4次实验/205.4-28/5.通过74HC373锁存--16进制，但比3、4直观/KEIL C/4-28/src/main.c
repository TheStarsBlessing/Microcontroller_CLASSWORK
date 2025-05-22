#include "reg52.h"
#include "SMGled0.h"

void main(void)
{
    unsigned int result;
    unsigned char a = 75; // 示例值
    unsigned char b = 133; // 示例值
    result = (unsigned int)a * a + (unsigned int)b * b; // 计算 a^2 + b^2
    P1 = smg_code[result%4096/256]; // 显示9-12位
    P1 &= ~0x80; // 设置 P1.7 为 0，不影响其他位
    P1 = smg_code[result/4096] & 0x7F; // 显示13-16位，并保持 P1.7 为 0
    P0 = smg_code[result%16]; // 显示1-4位 
    P0 &= ~0x80; // 设置 P0.7 为 0，不影响其他位
    P0 = smg_code[result%256/16] & 0x7F; // 显示5-8位，并保持 P0.7 为 0
    while (1);
}
//74hc573的LE脚为低电平时，数据被锁存到输出端，此时可以改变输入端的数据，而不会影响输出端的数据。
//但由于高电平切换至低电平需要时间，所以这里应提前将LE脚拉低，以避免数据在锁存过程中被改变。
