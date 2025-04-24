ORG 0000H          ; 定义程序从内存地址0000H开始
VAR DATA 30H       ; 在地址30H处定义一个名为VAR的数据存储位置
FUNC DATA 31H      ; 在地址31H处定义一个名为FUNC的数据存储位置
	
START:  MOV VAR,#21  ; 将数值21存入VAR
        MOV A,VAR   ; 将VAR的值存入累加器A
        SUBB A,#0AH ; 累加器A减去数值10（0AH），并进行借位操作
        JZ COMP     ; 如果累加器A的结果为0，则跳转到COMP标签处
        JNB ACC.7,POST1 ; 如果累加器A的第7位（最高位）为0，则跳转到POST1标签处
        MOV A,#0FFH ; 将数值-1（0FFH）存入累加器A
        SJMP COMP   ; 无条件跳转到COMP标签处
		
POST1:  SUBB A,#0AH ; 累加器A再次减去数值10（0AH），并进行借位操作
		JZ COMP     ; 如果累加器A的结果为0，则跳转到COMP标签处
        JNB ACC.7,POST2 ; 如果累加器A的第7位（最高位）为0，则跳转到POST2标签处
        MOV A,#0H   ; 将数值0存入累加器A
        SJMP COMP   ; 无条件跳转到COMP标签处
		
POST2:  MOV A,#01H ; 将数值1存入累加器A

COMP:   MOV FUNC,A ; 将累加器A的值存入FUNC
        SJMP $      ; 无条件跳转到当前地址，即无限循环
			
END      ; 程序结束
                                        