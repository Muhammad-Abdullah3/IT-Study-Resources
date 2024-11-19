.model small
.stack 100h
.data
    result_msg DB "The sum of the two numbers is: $"

.code 
;Start of code segment
main proc            ; start of main procedure (main function in case of c++)
    mov ax, @data    ; loading our data into data segment register (special purpose)
    mov ds, ax

    ; Load the first number into AL
    mov al, 2

    ; Add the second number to AL
    add al, 5    
    mov bl,al ;(move the value in al to bl)

    ; Display message of result showing that is stored in data segment registered
    lea dx, result_msg
    mov ah, 09h
    int 21h

    ; Convert the number sum to ASCII character and display with the use of ah,02
    add bl, 30h
    mov dl,bl   ; move valuein bl to dl for displaying it
    mov ah, 02h
    int 21h

    ; Exit the program (terminating with 4ch
    mov ah, 4Ch
    int 21h
main endp;end of main procedure (main function in case of c++)
end