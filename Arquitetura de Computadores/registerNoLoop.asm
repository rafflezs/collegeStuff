section .data
    msgName db "Digite o nome do caboclo: ", 10h
    lenName equ $ - msgName
    msgLastName db "Digite o sobrenome do caboclo: ", 10h
    lenLastName equ $ - msgLastName
    msgBirth db "Digite a data de nascimento do ser: ", 10h
    lenBirth equ $ - msgBirth
    msgId db "Digite o CPF do jovem: ", 10h
    lenId equ $ - msgId
    msgAddress db "Digite o endereço para mandar entrega errado: ", 10h
    lenAddress equ $ - msgAddress

    spaceSep db " ", 10h

section .bss
    firstName resb 7
    lastName resb 8
    id resb 12
    birth resb 10 
    address resb 30

section .text

    global _start

    _start:
    mov ecx, msgName
    mov edx, lenName
    call _PRINT

    mov ecx, firstName
    mov edx, 8
    call _INPUT

    mov ecx, msgLastName
    mov edx, lenLastName
    call _PRINT

    mov ecx, lastName
    mov edx, 7
    call _INPUT

    mov ecx, msgBirth
    mov edx, lenBirth
    call _PRINT

    mov ecx, birth
    mov edx, 10
    call _INPUT

    mov ecx, msgId
    mov edx, lenId
    call _PRINT

    mov ecx, id
    mov edx, 13
    call _INPUT

    mov ecx, msgAddress
    mov edx, lenAddress
    call _PRINT

    mov ecx, address
    mov edx, 31
    call _INPUT

    mov ecx, firstName
    mov edx, 7
    call _PRINT

    mov ecx, spaceSep
    mov edx, 1
    call _PRINT

    mov ecx, lastName
    mov edx, 9
    call _PRINT

    mov ecx, spaceSep
    mov edx, 1
    call _PRINT

    mov ecx, birth
    mov edx, 11
    call _PRINT

    mov ecx, spaceSep
    mov edx, 1
    call _PRINT

    mov ecx, id
    mov edx, 13
    call _PRINT

    mov ecx, spaceSep
    mov edx, 1
    call _PRINT

    mov ecx, address
    mov edx, 31
    call _PRINT

_INPUT:
    mov eax, 3
    mov ebx, 0
    int 80h

_PRINT:
    mov eax, 4
    mov ebx, 1
    int 80h

    mov eax, 1
    mov ebx, 0
    int 80h