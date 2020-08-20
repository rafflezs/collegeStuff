section .data
    age1 dd 0
    age2 dd 0
    msg1 db " é mais velho que ", 0x0
    len1 equ $ - msg1

section .bss
    name1 resb 7
    name2 resb 7

section .text

    global _start

    _start:

        mov ecx, name1
        mov edx, 7 ;tamanho da entrada do teclado;
        call _input
        mov ecx, age1
        mov edx, 3
        call _input
        mov ecx, name2
        mov edx, 7 ;tamanho da entrada do teclado;
        call _input
        mov ecx, age2
        mov edx, 3
        call _input

        mov ecx, DWORD [age1]
        mov edx, DWORD [age2]
        cmp ecx, edx       ; comparacao
        jge _bigger          ; je = jg > jge >= jl < jle <= jne !=
        mov ecx, name2
        mov edx, 7
        call _output
        jmp _end

    _bigger:
        mov ecx, name1
        mov edx, 7
        call _output

    _end:
        mov ebx, 1
        mov eax, 4
        int 0x80
        mov eax, 1
        int 0x80

    _input:
        mov eax, 3
        mov ebx, 0
        int 80h
        ret

    _output: 
        mov eax, 4
        mov ebx, 1
        int 80h
        ret