section .data
    msg1 db "Informe um número [0-9]: "
    len1 equ $ - msg1

    fl db " ", 0xa

section .bss
    num1   resb 2
    num2   resb 2
    num3   resb 2
    num4   resb 2
    aux1   resb 2
    aux2   resb 2
    soma   resb 2
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

    mov ecx, msg1
    mov edx, len1
    call exit

    mov ecx, num4
    mov edx, 2
    call ent

    mov eax, [num1]
    sub eax, '0'
    mov ebx, [num2]
    sub ebx, '0'

    add eax, ebx ; VAL1 + VAL2
    add eax, '0'
    mov [aux1], eax ; aux1 = VAL1 + VAL2

    mov eax, [num3]
    sub eax, '0'
    mov ebx, [num4]
    sub ebx, '0'

    add eax, ebx ; VAL3 + VAL4
    add eax, '0'
    mov [aux2], eax ; aux2 = VAL3 + VAL4

    mov eax, [aux1]
    sub eax, '0'
    mov ebx, [aux2]
    sub ebx, '0'

    add eax, ebx
    add eax, '0'
    mov [soma], eax

    mov al, [soma]
    mov bl, '4'

    mov ah, 0
    mov dx, 0
    sub al, '0'
    sub bl, '0'

    div bl ; divisão

    add ax, '0'
    mov [resultado], ax

    mov ecx, resultado
    mov edx, 1
    call exit

    mov ecx, fl ; quebra e linha
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