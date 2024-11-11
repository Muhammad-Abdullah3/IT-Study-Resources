ORG 100H

.DATA
    character DB '*'               ; Character to display
    newLine DB 10, 13, '$'      

.CODE

    MOV CX, 1                     

OUTER_LOOP:
    PUSH CX                       ; Save the row counter

    MOV BX, CX                    ; Set the number of asterisks to print in this row
INNER_LOOP:
    ; Print an asterisk
    MOV DL, character
    MOV AH, 02H                  
    INT 21H

    DEC BX                        ; Decrement the counter for asterisks
    JNZ INNER_LOOP                ; Repeat if there are still asterisks to print

    ; Print newline after each row
    MOV DX, offset newLine
    MOV AH, 09H                   
    INT 21H

    POP CX                        ; Restore the row counter
    INC CX                        ; Increment the row counter

    CMP CX, 6                     ; Check if 5 rows have been printed
    JNZ OUTER_LOOP                ; If not, repeat the outer loop

    ; Exit program
    MOV AH, 4CH                   ; Function 4CH to exit
    INT 21H
END MAIN
