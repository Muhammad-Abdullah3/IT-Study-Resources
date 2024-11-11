.MODEL SMALL
.STACK 100
.DATA
  msg1 DW "Enter Your Name: $" 
  msg2 DW 10,13,"Enter Your ID : $" 
  msg3 DW 10,13,"Enter Your Section : $"     
  msg4 DB 10,13,"YOUR NAME IS: $" 
  msg5 DB 10,13,"Your ID is : $"  
  msg6 DB 10,13,"Your Section is : $"
  input_name DB 20 DUP('$') 
  input_id DB 20 DUP('$')
  input_section DB 20 DUP('$')  
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
    
    ; Display the ID prompt message
    LEA DX,msg2  
    MOV AH,09H     
    INT 21H    
    ; Read NAME into input_id
    LEA DX,input_id
    MOV AH,0AH
    INT 21H       
    
    ; Display the Section prompt message
    LEA DX,msg3  
    MOV AH,09H     
    INT 21H    
    ; Read NAME into input_section
    LEA DX,input_section
    MOV AH,0AH
    INT 21H
    
    
    ; Display the your name message
    LEA DX,msg4 
    MOV AH,09H     
    INT 21H    
    ; Display your name 
    LEA DX,input_name+2
    MOV AH,09H
    INT 21H   
    ;Display your id message
    LEA DX,msg5  
    MOV AH,09H     
    INT 21H  
    ; Display id
    LEA DX,input_id+2
    MOV AH,09H
    INT 21H 
    
    ;Display your Section message
    LEA DX,msg6  
    MOV AH,09H     
    INT 21H  
    ; Display Section
    LEA DX,input_section+2
    MOV AH,09H
    INT 21H  

    MOV AH,4CH
    INT 21H
END 
