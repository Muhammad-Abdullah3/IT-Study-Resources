.model small
.data                      ; Start of Data Segment
prompt_msg1 db "Enter first number: $"
prompt_msg2 db 10,13,"Enter second number: $"
prompt_msg3 db 10,13,"The Difference of input numbers is: $"                               
;End of data segment
.code                                       ; Start of code segment
main proc          ; Start of main procedure
    mov ax,@data
    mov ds,ax   ; Referencing our data segment in code segment
    
    ; Prompt for the first number
    lea dx,prompt_msg1
    mov ah,09
    int 21h 
    
    ; Read first number as character
    mov ah,01
    int 21h 
    
    mov bl,al           ; Store first number as character in BL (8 bit)
    sub bl,30h          ; Convert ASCII character to decimal
    
    ; Prompt for the second number
    lea dx,prompt_msg2
    mov ah,09
    int 21h
    
    ; Read second number as a character
    mov ah,01
    int 21h
    
    mov cl,al           ; Store second number as character in CL (8 bit)
    sub cl,30h          ; Convert ASCII character to decimal
    
    ; Prompt for Displaying Sum
    lea dx,prompt_msg3
    mov ah,09
    int 21h
       
    ; Add the two numbers
    Sub bl,cl           ; Sum of first and second numbers in BL
    add bl,30h          ; Convert result number to ASCII for display
    
    ; Display the result
    mov dl,bl           ; Move result of bl into dl for display
    mov ah,02           ; Display number as a character function
    int 21h  
    
    ; Exit program
    mov ah,4Ch
    int 21h
main endp
end
