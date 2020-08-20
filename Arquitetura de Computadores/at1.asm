section     .text
global      _start                           

_start:                                        

    call _getName
    call _getSurname
    call _printName
    call _printSurName
                        
    mov     ebx,1                             
    mov     eax,4                              
    int     0x80                               
    mov     eax,1                            
    int     0x80 


section     .data

section     .bss
    name resb 16
    surname resb 16

_getName:
    mov     rax, 0
    mov     rdi, 0
    mov     rsi, name

_getSurname:
    mov     rax, 0
    mov     rdi, 0
    mov     rsi, surname

_printName:
    mov     rax, 1
    mov     rdi, 1
    mov     rsi, name
    mov     rdx, 19
    syscall
    ret

_printSurName:
    mov     rax, 1
    mov     rdi, 1
    mov     rsi, surname
    mov     rdx, 19
    syscall
    ret
