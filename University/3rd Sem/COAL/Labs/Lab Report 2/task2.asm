.MODEL SMALL
.STACK 100
.data
    msg dw "Helo World$"
.code

    MOV AX,@data
    MOV DS,AX
    lea DX,msg 
    MOV AH,09
    INT 21h
    
    MOV AH,4CH
    INT 21h
END