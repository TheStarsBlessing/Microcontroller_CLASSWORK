#include "reg52.h"

void main(void) {
    // 定义一个3x3矩阵
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int primaryDiagonalSum = 0;  // 主对角线和
    int secondaryDiagonalSum = 0; // 副对角线和
    int totalDiagonalSum;       // 总对角线和
    int i; // 循环变量

    // 计算主对角线和副对角线的和
    for (i = 0; i < 3; i++) {
        primaryDiagonalSum += matrix[i][i];          // 主对角线元素
        secondaryDiagonalSum += matrix[i][2 - i];     // 副对角线元素
    }

    // 总和为两条对角线元素之和
    totalDiagonalSum = primaryDiagonalSum + secondaryDiagonalSum-matrix[1][1];

    // 这里假设有一个函数可以输出结果到LED或者串口等设备
    // displayResult(totalDiagonalSum);  

    while (1) {
        // 等待循环
    }
}