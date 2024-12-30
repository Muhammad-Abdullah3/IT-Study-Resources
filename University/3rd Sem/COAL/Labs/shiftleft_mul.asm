.model small
.stack 100
.data
msg1 db 10,13, "Enter a number: $"    
msg4 db 10, 13, "Shift Arithimetic Left Result: $"
msg5 db 10, 13, "Shift Arithimetic Right Result: $"
.code

mov ax, @data
mov ds, ax 

; Display first prompt
lea dx, msg1
mov ah, 09h
int 21h     
; Take input
mov ah, 01h
int 21h
sub al, 30h        
mov bl, al         

; Multiply input by 2 using MUL       
mov cl, 2          
mul cl             
mov bl, al         
; Display product
lea dx, msg2
mov ah, 09h
int 21h

; Convert product to ASCII for display
add bl, 30h        
mov dl, bl
mov ah, 02h
int 21h
sub bl, 30h        

; Perform left shift operation
shl bl, 1         

; Convert result to ASCII for display                                                      1
add bl, 30h        

; Display result prompt
lea dx, msg3
mov ah, 09h
int 21h   

; Display the result
mov dl, bl
mov ah, 02h
int 21h  

lea dx, msg1
mov ah, 09h
int 21h     
; Take input
mov ah, 01h
int 21h
sub al, 30h        
mov bl, al         


       

; Perform arithimetic left shift operation
sal bl, 1         

; Convert result to ASCII for display                                                      1
add bl, 30h        

; Display result prompt
lea dx, msg4
mov ah, 09h
int 21h   

; Display the result
mov dl, bl
mov ah, 02h
int 21h

; Perform arithimetic right shift operation 
mov al,8
mov bl,al
sar bl, 2         

; Convert result to ASCII for display                                                      1
add bl, 30h        

; Display result prompt
lea dx, msg5
mov ah, 09h
int 21h   

; Display the result
mov dl, bl
mov ah, 02h
int 21h

; Terminate program
mov ah, 4Ch
int 21h
