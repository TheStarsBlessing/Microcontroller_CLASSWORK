ORG 0000H          ; 程序存储器从地址0000H开始
    SJMP START     ; 跳转到程序开始处

START:
    MOV 20H, #01H   ; 将01H存入20H地址，用于后续操作
    MOV 21H, #02H   ; 将02H存入21H地址，用于后续操作    
    MOV 22H, #03H   ; 将03H存入22H地址，用于后续操作
    MOV 23H, #0DH   ; 将0DH存入23H地址，作为结束标志

    MOV DPTR, #7E01H ; 设置DPTR为外部数据存储器的起始地址

    MOV R0, #20H     ; 设置R0为内部RAM数据块的起始地址
    MOV R1, #00H     ; 初始化R2为长度计数器

COUNT_LENGTH:
    MOV A, @R0       ; 读取内部RAM当前地址的数据
    CJNE A, #0DH, COPY_DATA ; 如果数据不是结束标志0DH，跳转到COPY_DATA
    SJMP STORE_LENGTH ; 如果数据是结束标志0DH，跳转到STORE_LENGTH

COPY_DATA:
    MOVX @DPTR, A    ; 将数据写入外部数据存储器
    INC R0           ; 内部RAM地址加1
    INC DPTR         ; 外部数据存储器地址加1
    INC R1           ; 长度计数器加1
    SJMP COUNT_LENGTH ; 继续循环

STORE_LENGTH:
	MOVX @DPTR, A    ; 将数据写入外部数据存储器
    INC R1           ; 长度计数器加1
    MOV DPTR, #7E00H ; 设置DPTR为外部数据存储器的长度存储地址
    MOV A, R1        ; 将长度计数器的值放入累加器A
    MOVX @DPTR, A    ; 将长度写入外部数据存储器的7E00H地址
	
END_PROGRAM:
    SJMP $          ; 无限循环
END  ; 程序结束