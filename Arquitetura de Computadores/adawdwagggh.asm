section .data
    aprovado db 10, 'Aprovado', 0
    reprovado db 10, 'Reprovado', 0
    lf db " ", 10h, 10h

section .bss
    nota1 resb 10
    nota2 resb 10
    nota3 resb 10
    nota4 resb 10

section .text
    global _start:
        mov ecx, nota1
        mov edx, 10
        call _INPUT

        mov ecx, nota2
        mov edx, 10
        call _INPUT

        mov ecx, nota3
        mov edx, 10
        call _INPUT

        mov ecx, nota4
        mov edx, 10
        call _INPUT

        mov eax, [nota1]
        sub eax, '0'
        mov ebx, [nota2]
        sub ebx, '0'
        add eax, ebx
        mov [res], eax
        mov ebx, [nota3]
        sub eax, '0'
        mov eax, [res]
        add eax, ebx
        mov [res], eax
        mov ebx, [nota4]
        sub eax, '0'
        mov eax, [res]
        add eax, ebx
        mov [res], eax

        mov ebx, 4
        div ebx, eax
        mov [res], eax
        mov al, [res]
        mov bl, 5

        cmp bl, al
        jg aprovado
        mov eax, reprovado
        call _EXIBIR
        mov eax, lf
        call _EXIBIR
        call exit

        exit:
            mov ecx, salLinha
            mov edx, lsalLinha
            call mst_saida            
            mov eax, 1
            mov ebx, 0
            int 80h

    _INPUT:
        mov eax, 3
        mov ebx, 0
        int 80h

    _EXIBIR:
        mov eax, 4
        mov ebx, 1
        int 80h
        ret 