.MODEL SMALL
.STACK 100

.DATA
greeting_message DB "**************** Welcome to Crypto Trading Portal************$"
new_line DB 10,13, "$"
login_option_message DB "Press 1 for login.$"
signup_option_message DB "Press 2 for creating a new account.$"  
market_show_message DB "Press 3 for showing current crypto market prices.$"
exit_message DB "Press 4 for to Exit.$"
enter_input DB "Enter your choice: $"  
invalid_input_message DB "Invalid Choice$"
homepage_choice DB ?

.CODE
    mov ax,@data
    mov ds,ax 
    
    main PROC
        lea dx,greeting_message
        mov ah,09h
        int 21h
        
        lea dx,new_line
        mov ah,09h
        int 21h
        
        
        lea dx,login_option_message
        mov ah,09h
        int 21h
        
        lea dx,new_line
        mov ah,09h
        int 21h


        lea dx,signup_option_message
        mov ah,09h
        int 21h
        
        lea dx,new_line
        mov ah,09h
        int 21h
        
        
        lea dx,market_show_message
        mov ah,09h
        int 21h
        
        lea dx,new_line
        mov ah,09h
        int 21h
        
        
        lea dx,exit_message
        mov ah,09h
        int 21h
        
        lea dx,new_line
        mov ah,09h
        int 21h
        
        lea dx,enter_input
        mov ah,09h
        int 21h
        
        mov ah,01h
        int 21h
        
        mov homepage_choice,al
        
        lea dx,new_line
        mov ah,09h
        int 21h
        
        
        
        cmp homepage_choice, '1'
        jz login_procedure
    
        cmp homepage_choice, '2'
        jz signup_procedure
    
        cmp homepage_choice, '3'
        jz market_procedure
    
        cmp homepage_choice, '4'
        jz exit_program
    
        ; Invalid input
        lea dx, invalid_input_message
        mov ah, 09h
        int 21h
        
        lea dx,new_line
        mov ah,09h
        int 21h
        
        jmp main
     main endp
                          
     login_procedure PROC
        
     login_procedure endp     
        

     signup_procedure PROC
        
     signup_procedure endp
    
     market_procedure PROC
    
     market_procedure endp
    
     exit_program PROC
        mov ah, 4Ch
        int 21h
     exit_program endp

                        
