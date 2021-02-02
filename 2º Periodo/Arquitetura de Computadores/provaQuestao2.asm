section .data
    men1 db 10, 'Digite um numero de 0 a 8 : ', 0
    lenMen1 equ $ - men1
    
    men2 db 10, 'Programa encerrado', 0
    lenMen2 equ $ - men2

    contEq db 'Contador e igual a ', 0h
    lenContEq equ $ - contEq

    fl db " ", 0xa

section .bss
    cont resb 1
    entrada resb 2

section .text

    global _start:

        _start:
            mov eax, 0
            mov [entrada], eax
            mov ax, 1
            mov [cont], ax

            ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
            repete:
            mov ecx, contEq
            mov edx, lenContEq
            call _printa

            mov ax, [cont]
            add ax, "0"
            mov [cont], ax
            mov ecx, cont
            mov edx, 2
            call _printa

            mov ecx, fl
            mov edx, 2
            call _printa

            mov ecx, men1
            mov edx, lenMen1
            call _printa

            call _scanea

            mov ax, [cont]
            sub ax, "0"

            mov bx, [entrada]
            add ax, bx

            mov [cont], ax

            mov ah, [cont]

            cmp ah, 9
            jl  repete
            ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
            mov ecx, contEq
            mov edx, lenContEq
            call _printa

            mov ax, [cont]
            add ax, "0"
            mov [cont], ax
            mov ecx, cont
            mov edx, 2
            call _printa

            mov ecx, fl
            mov edx, 2
            call _printa

            mov ecx, men2
            mov edx, lenMen2
            call _printa

            mov ecx, fl
            mov edx, 2
            call _printa

        _encerra:
            mov eax, 1
            mov ebx, 0
            int 80h
        
        _printa:
            mov eax, 4
            mov ebx, 1
            int 80h
            ret

        _scanea:
            mov ecx, entrada
            mov edx, 2
            mov eax, 3
            mov ebx, 0
            int 80h

            mov eax, [entrada]
            sub eax, '0'
            mov [entrada], eax   
            ret