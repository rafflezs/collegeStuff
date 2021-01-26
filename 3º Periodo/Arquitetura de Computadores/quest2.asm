section .data
    msg1 db "Digite um valor [0-9]: "
    len1 equ $ - msg1

    fl db " ", 0xa

section .bss
    num1   resb 2
    num2   resb 2
    num3   resb 2
    aux1   resb 2
    aux2   resb 2
    resultado resb 2

section .text
    global _start
    _start:

    mov ecx, msg1
    mov edx, len1
    call exit

    mov ecx, num1
    mov edx, 2
    call ent

    mov ecx, msg1
    mov edx, len1
    call exit

    mov ecx, num2
    mov edx, 2
    call ent

    mov ecx, msg1
    mov edx, len1
    call exit

    mov ecx, num3
    mov edx, 2
    call ent

    mov eax, [num1]
    sub eax, '0'
    
    mov ebx, [num3]
    sub ebx, '0'

    sub eax, ebx      ; VAL1 - VAL3
    add eax, '0'

    mov [aux1], eax   ; aux1 = VAL1 - VAL3

    mov eax, [num2]
    sub eax, '0'

    mov ebx, [num1]
    sub ebx, '0'

    mul ebx           ; VAL2 * VAL1

    add eax, '0'
    mov [aux2], eax   ; aux2 = VAL2 * VAL1

    mov eax, [aux2]
    sub eax, '0'

    mov ebx, [aux1]
    sub ebx, '0'

    add eax, ebx      ; aux2 + aux1
    add eax, '0'

    mov [resultado], eax ; result = aux2 + aux1

    mov ecx, resultado
    mov edx, 1
    call exit

    mov ecx, fl       ; quebra e linha
    mov edx, 2
    call exit

    jmp final

    exit:
        mov eax, 4
        mov ebx, 1
        int 80h
        ret

    ent:
        mov eax, 3
        mov ebx, 0
        int 80h
        ret

final:
    mov eax, 1
    mov ebx, 0
    int 80h