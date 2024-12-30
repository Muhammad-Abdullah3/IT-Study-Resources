.model small
.stack 100
.data
msg1 db "Enter your first number: $"    
msg2 db 10, 13, "Enter your second number: $" 
msg3 db 10,13, "Sum of two numbers: $" 
msg4 db 10, 13, "Sum after right shift is: $"

.code

mov ax, @data
mov ds, ax 

; Display first input prompt
lea dx, msg1
mov ah, 09h
int 21h     
; Take first input number
mov ah, 01h
int 21h
sub al, 30h        
mov bl, al         

; Display second input prompt
lea dx, msg2
mov ah, 09h
int 21h 

; Take second input
mov ah, 01h
int 21h
sub al, 30h        
mov cl, al         
; Calculate the sum
add bl, cl 
; Display the sum prompt
lea dx, msg3
mov ah, 09h
int 21h

; Convert sum to ASCII for display
add bl, 30h 
mov dl,bl
mov ah,02h
int 21h   
                                
; Convert sum to number for right shift
sub bl,30h                                
; Perform right shift operation 
shr bl,1         
; Convert right shift result to ASCII for display
add bl, 30h        
; Display result after right shift prompt
lea dx, msg4
mov ah, 09h
int 21h   
; Display the result after right shift
mov dl, bl
mov ah, 02h
int 21h
; Terminate program
mov ah, 4Ch
int 21h

