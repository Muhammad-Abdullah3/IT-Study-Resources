ORG 100H
.CODE
    MOV AH,01
    INT 21H
    
    MOV DL,AL
    MOV AH,02
    INT 21H
    
RET