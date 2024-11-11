.MODEL SMALL
.STACK 100
.DATA
  msg1 DW "Enter Your Name: $" 
  msg2 DW 10,13,"Enter Your SEMESTER : $"     
  msg3 DB 10,13,"YOUR NAME IS: $" 
  msg4 DB 10,13,"Your Semester is : $"
  input_name DB 20 DUP('$') 
  input_sem DB 20 DUP('$')
.CODE
    MOV AX,@DATA
    MOV DS,AX         
    ; Display the name prompt message
    LEA DX,msg1  
    MOV AH,09H     
    INT 21H    
    ; Read NAME into input_name
    LEA DX,input_name
    MOV AH,0AH
    INT 21H   
    
    ; Display the Semester prompt message
    LEA DX,msg2  
    MOV AH,09H     
    INT 21H    
    ; Read NAME into input_sem
    LEA DX,input_sem
    MOV AH,0AH
    INT 21H   
    ; Display the your name message
    LEA DX,msg3 
    MOV AH,09H     
    INT 21H    
    ; Display your name 
    LEA DX,input_name+2
    MOV AH,09H
    INT 21H   
    ;Display your semeter message
    LEA DX,msg4  
    MOV AH,09H     
    INT 21H  
    ; Display Semester
    LEA DX,input_sem+2
    MOV AH,09H
    INT 21H  

    MOV AH,4CH
    INT 21H
END 
