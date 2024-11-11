ORG 100H

.DATA
    msg1 DW "Enter a character: $"
    msg2 DW "You entered: $"
    input_char DB ?               ; space for the input character

.CODE
    
    ; Display the first message
    MOV DX, offset msg1
    MOV AH, 09H                    ; Function 09H to display a string
    INT 21H

    ; Take character input from the user
    MOV AH, 01H   
    MOV AH, 08H                 
    INT 21H
    MOV input_char, AL            
    ; Stored the entered character in memory

    ; Move to a new line after input
    MOV DL, 10                    
    MOV AH, 02H
    INT 21H
    MOV DL, 13                    
    MOV AH, 02H
    INT 21H

    ; Display the second message
    MOV DX, offset msg2
    MOV AH, 09H                    
    INT 21H

    ; Display the stored character
    MOV DL, input_char            
    MOV AH, 02H                    
    INT 21H

    MOV AH, 4CH                    
    INT 21H
END
