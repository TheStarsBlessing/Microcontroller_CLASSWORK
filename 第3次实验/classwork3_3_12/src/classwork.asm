ORG 0000H          ; 设置程序的起始地址为0000H
    SJMP START     ; 跳转到程序的入口点START

START:
    MOV 34H, #0AAH  ; 将0AAH存入34H地址，用于后续操作 
	MOV 50H, #0AAH  ; 将0AAH存入50H地址，用于后续操作

    MOV R0, #32H    ; 初始化R0寄存器，设置其值为32H，用于后续操作
    MOV R1, #42H    ; 初始化R1寄存器，设置其值为42H，用于后续操作
    CLR C           ; 清除进位标志C，用于后续的条件判断

FIND_LOOP:
    MOV 30H, @R0    ; 将R0寄存器指向的内存地址中的值存入30H地址
    MOV A, #0AAH    ; 将立即数0AAH存入累加器A
    CJNE A, 30H, NEXT ; 比较累加器A的内容与30H地址中的值，如果不相等则跳转到NEXT
    SETB C          ; 设置进位标志C，表示找到了匹配的值
    SJMP END_FIND   ; 跳转到END_FIND，结束查找循环

NEXT:
    INC R0          ; 增加R0寄存器的值，指向下一个内存地址
    MOV A, R0       ; 将R0寄存器的值存入累加器A
    MOV 30H, R1     ; 将R1寄存器的值存入30H地址
    CJNE A, 30H, FIND_LOOP ; 比较累加器A的内容与30H地址中的值，如果不相等则继续查找循环

END_FIND:
    JNC NOT_FOUND   ; 如果没有找到匹配的值（进位标志C未被设置），则跳转到NOT_FOUND
    MOV 50H, #0FFH  ; 找到匹配的值，将0FFH存入50H地址
    SJMP END_PROGRAM ; 跳转到END_PROGRAM，结束程序

NOT_FOUND:
    MOV 50H, #00H   ; 未找到匹配的值，将00H存入50H地址

END_PROGRAM:
    SJMP $          ; 无限循环，程序结束

END                ; 程序结束标志