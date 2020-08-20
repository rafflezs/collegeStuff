section .data
    basicSum equ 1
    opc1        db  10, 'Incremento',0
    lopc1       equ $ - opc1
    opc2        db  10, 'Decremento',0
    lopc2       equ $ - opc2

section .bss
    opc     resb 2
    num1    resb 10
    result  resb 10
section .text
    
    global _start

        _start:
            mov ecx, num1
            mov edx, 10
            mov eax, 3
            mov ebx, 0
            int 80h

            mov ecx, opc1
            mov edx, lopc1
            call mst_saida

            mov ecx, opc2
            mov edx, lopc2
            call mst_saida

            mov ecx, opc
            mov edx, 2
            mov eax, 3
            mov ebx, 0
            int 80h

            mov ah, [opc]

            cmp ah, 'i'
            je  inc
            cmp ah, 'd'
            je  dec

        inc:
            mov eax, [num1]
            sub eax, '0'
            mov ebx, [basicSum]
            add eax, ebx
            add eax, '0'
            mov [result], eax
            mov ecx, result
            mov edx, 10
            call EXIBIR
            jmp exit
        
        dec:
            mov eax, [num1]
            sub eax, '0'
            mov ebx, [basicSum]
            sub eax, ebx
            add eax, '0'
            mov [result], eax
            mov ecx, result
            mov edx, 10
            call EXIBIR
            jmp exit

        exit:
            mov ecx, salLinha
            mov edx, lsalLinha
            call mst_saida            
            mov eax, 1
            mov ebx, 0
            int 80h

        EXIBIR:
            mov eax, 4
            mov ebx, 1
            int 80h
            ret 