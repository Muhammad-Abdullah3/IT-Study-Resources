.MODEL SMALL
.STACK 100H

.DATA
    newLine DB 10,13,'$'

.CODE

    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH, 01H 
    MOV AH, 08H       
    INT 21H            
    MOV DL, AL         
    MOV AH, 02H        
    INT 21H
    LEA DX,newLine
    MOV AH,09H
    INT 21H            
    
    ;Displaying Abdullah one character at a time
    
    MOV DL, 'A'
    MOV AH, 02H
    INT 21H
    LEA DX,newLine
    MOV AH,09H
    INT 21H
    
    
    MOV DL, 'B'
    MOV AH, 02H
    INT 21H
    LEA DX,newLine
    MOV AH,09H
    INT 21H
    
    MOV DL, 'D'
    MOV AH, 02H
    INT 21H
    LEA DX,newLine
    MOV AH,09H
    INT 21H
    
    
    MOV DL, 'U'
    MOV AH, 02H
    INT 21H
    LEA DX,newLine
    MOV AH,09H
    INT 21H


    MOV DL, 'L'
    MOV AH, 02H
    INT 21H
    LEA DX,newLine
    MOV AH,09H
    INT 21H
        
    
    MOV DL, 'L'
    MOV AH, 02H
    INT 21H
    LEA DX,newLine
    MOV AH,09H
    INT 21H
    
    
    
    MOV DL, 'A'
    MOV AH, 02H
    INT 21H
    LEA DX,newLine
    MOV AH,09H
    INT 21H   
    
    MOV DL, 'H'
    MOV AH, 02H
    INT 21H
    LEA DX,newLine
    MOV AH,09H
    INT 21H

END
