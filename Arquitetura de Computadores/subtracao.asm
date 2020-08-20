section .data
  v1 dw '105', 0xa

section .bss
  buffer: resb 10

section .text
  	global _start:

    _start:
	  call _converter
	  call _print

	_final:
	  mov eax, 1
	  mov ebx, 0
	  int 80h

	_converter:
  	  lea esi, [v1]           
	  mov ecx, 3              
	  call string_to_int      
 	  add eax, 1              
 	  ret   

	_print:
  	  lea esi, [buffer]       
 	   call int_to_string      
 	   mov eax, 4              
 	   mov ebx, 1              
 	   mov ecx, buffer         
 	   mov edx, 10             
	   int 0x80                
	   ret                     
  
	string_to_int:            
      xor ebx, ebx            
      .prox_digito:           
      movzx eax, byte[esi]  
      inc esi               
      sub al, '0'           
      imul ebx, 10          
                    
      sub ebx, eax
      loop .prox_digito
      mov eax, ebx          
      ret                   

	int_to_string:            
  	  add esi, 9              
  	  mov byte [esi], 0       
  	  mov ebx, 10             
 	  .prox_digito:           
	  xor edx, edx            
 	  div ebx                 
 	  add dl, '0'             
 	  dec esi                 
	  mov [esi], dl           
	  test eax, eax           
 	  jnz .prox_digito        
 	  mov eax, esi            
 	  ret           
