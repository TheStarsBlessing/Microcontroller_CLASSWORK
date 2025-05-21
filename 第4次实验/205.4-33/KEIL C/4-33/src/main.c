#include <reg51.h>

// 定义外部RAM的起始地址
#define EXT_RAM_START 0x70

void main(void) {
    unsigned char i;
    // 使用xdata关键字指定指针指向外部RAM
    unsigned char xdata *ext_ram = (unsigned char xdata *)EXT_RAM_START;

    // 已知前两个单元内容为1
    ext_ram[0] = 1;  // 初始化
    ext_ram[1] = 1;  // 初始化

    // 计算接下来的8个斐波那契数并存储在后续地址中
    for (i = 2; i < 10; i++) {
        ext_ram[i] = ext_ram[i - 1] + ext_ram[i - 2];
    }

    // 程序结束后保持循环
    while (1);
}