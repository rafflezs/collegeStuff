section .data
    men1 db 10, 'Insira o valor do trabalho 1: ', 0
    lenMen1 equ $ - men1
    men2 db 10, 'Insira o valor da prova 1: ', 0
    lenMen2 equ $ - men2
    men3 db 10, 'Insira o valor do trabalho 2: ', 0
    lenMen3 equ $ - men3
    men4 db 10, 'Insira o valor da prova 1: ', 0
    lenMen4 equ $ - men4

    mf1 db 10, 'A nota do 1 bimestre e: ', 0
    lenMf1 equ $ - mf1
    mf2 db 10, 'A nota do 2 bimestre e: ', 0
    lenMf2 equ $ - mf2

    mff db 10, 'A nota final e: ', 0
    lenMff equ $ - mff

    fl db " ", 0xa

section .bss
    prova1 resb 2
    trab1 resb 2
    
    prova2 resb 2
    trab2 resb 2
    
    res1 resb 2
    res2 resb 2
    mediaFim resb 2

section .text

    global _start:

        _start:
            ;Coleta nota do trabalho 1
            mov ecx, men1
            mov edx, lenMen1
            call _printa
            mov ecx, trab1
            mov edx, 2
            mov eax, 3
            mov ebx, 0
            int 80h

            ;Coleta nota da prova 1
            mov ecx, men2
            mov edx, lenMen2
            call _printa
            mov ecx, prova1
            mov edx, 2
            mov eax, 3
            mov ebx, 0
            int 80h

            ;Coleta nota do trabalho 2
            mov ecx, men3
            mov edx, lenMen3
            call _printa
            mov ecx, trab2
            mov edx, 2
            mov eax, 3
            mov ebx, 0
            int 80h

            ;Coleta a nota da prova 2
            mov ecx, men4
            mov edx, lenMen4
            call _printa
            mov ecx, prova2
            mov edx, 2
            mov eax, 3
            mov ebx, 0
            int 80h

            ;Soma as notas do semestre 1 e armazena em res1
            mov eax, [trab1]
            sub eax, '0'
            mov ebx, [prova1]
            sub ebx, '0'
            add eax, ebx
            add eax, '0'
            mov [res1], eax

            ;Soma as notas do semestre 2 e armazena em res2
            mov eax, [trab2]
            sub eax, '0'
            mov ebx, [prova2]
            sub ebx, '0'
            add eax, ebx
            add eax, '0'
            mov [res2], eax


            mov ecx, mf1
            mov edx, lenMf1
            call _printa
            mov ecx, res1
            mov edx, 1
            call _printa

            mov ecx, mf2
            mov edx, lenMf2
            call _printa
            mov ecx, res2
            mov edx, 1
            call _printa

            mov eax, [res1]
            sub eax, '0'
            mov ebx, [res2]
            sub ebx, '0'
            add eax, ebx
            add eax, '0'
            mov [mediaFim], eax

            mov al, [mediaFim]
            mov bl, '2'
            mov ah, 0
            mov dx, 0
            sub al, '0'
            sub bl, '0'                             
            div bl
            add ax, '0'
            mov [mediaFim], ax

            mov ecx, mff
            mov edx, lenMff
            call _printa
            mov ecx, mediaFim
            mov edx, 2
            call _printa


            mov ecx, fl
            mov edx, 2
            call _printa

            jmp _encerra

        _encerra:
            mov eax, 1
            mov ebx, 0
            int 80h

        _printa:
            mov eax, 4
            mov ebx, 1
            int 80h
            ret