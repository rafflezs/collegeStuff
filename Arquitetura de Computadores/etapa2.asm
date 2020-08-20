section .data

    msg1 db "Informe o nome1: ", 10h
    len1 equ $ - msg1

    idade1 dd 0

    msg2 db "Informe a idade1: ", 10h
    len2 equ $ - msg2

    msg3 db "Informe o nome2: ", 10h
    len3 equ $ - msg3

    idade2 dd 0

    msg4 db "Informe idade2: ", 10h
    len4 equ $ - msg4

    msg5 db "=> Pessoa mais velha é o(a) ", 0x0
    len5 equ $ - msg5

section .bss
    nome1 resb 12
    nome2 resb 12

section .text

    global _start
    _start:

    mov ecx, msg1 ; nome 1
    mov edx, len1
    call _SAIDA

    mov ecx, nome1
    mov edx, 12
    call _ENTRADA

    mov ecx, msg2 ; idade 1
    mov edx, len2
    call _SAIDA

    mov ecx, idade1
    mov edx, 3
    call _ENTRADA

    mov ecx, msg3 ; nome 2
    mov edx, len3
    call _SAIDA

    mov ecx, nome2
    mov edx, 12
    call _ENTRADA

    mov ecx, msg4 ; idade 2
    mov edx, len4
    call _SAIDA

    mov ecx, idade2
    mov edx, 3
    call _ENTRADA

    mov ecx, msg5 ; o mais velho é
    mov edx, len5
    call _SAIDA

    mov eax, DWORD [idade1] 
    mov edx, DWORD [idade2]
    cmp eax, edx
    jge _maior
    mov edx, 12
    mov ecx, nome2
    jmp _final

_maior:        
    mov edx, 12
    mov ecx, nome1

_final:
    mov ebx, 1
    mov eax, 4
    int 80h
    mov eax, 1
    mov ebx, 0
    int 80h

_ENTRADA:
    mov eax, 3
    mov ebx, 0
    int 80h
    ret

_SAIDA:
    mov eax, 4
    mov ebx, 1
    int 80h
    ret