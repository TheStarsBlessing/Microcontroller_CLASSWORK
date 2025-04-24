ORG 0000H          ; 程序存储器从地址0000H开始
    SJMP START     ; 跳转到程序开始处

START:
    ; 初始化数据
    MOV 30H, #8    ; 数据1
    MOV 31H, #7    ; 数据2
    MOV 32H, #6    ; 数据3
    MOV 33H, #4    ; 数据4
    MOV 34H, #4    ; 数据5
    MOV 35H, #6    ; 数据6
    MOV 36H, #7    ; 数据7
    MOV 37H, #8    ; 数据8

    MOV R0, #30H    ; 设置R0为数据起始地址
    MOV R1, #0      ; R1用于累加和
    MOV R2, #8      ; R2用于计数

SUM_LOOP:
    MOV A, @R0    ; 将当前地址的数据加载到累加器A
    ADD A, R1     ; 将累加器A中的数据与R1累加
    MOV R1, A     ; 将累加结果存入R1
    INC R0        ; 地址指针加1
    DJNZ R2, SUM_LOOP ; 计数器减1，不为零则继续循环       
    ; 此时R1中存储的是8个数的累加和
    
    ; 计算平均值
    MOV A, R1       ; 将累加和加载到累加器A
    MOV B, #8       ; 将除数8加载到B寄存器
    DIV AB          ; 用A除以B，结果在A中，余数在B中

    MOV 38H, A      ; 将平均值存入38H单元

END_PROGRAM:
    ;程序结束，进入死循环
     SJMP $  // 跳转到当前地址，程序停止运行

END