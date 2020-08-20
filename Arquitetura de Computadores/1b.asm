section .data

section .bss
    val1    resb 10
    val2    resb 10
    val3    resb 10
    result  resb 10

section .text
    global _start

        _start:
            mov ecx, val1
            mov edx, 10
            mov eax, 3
            mov ebx, 0
            int 80h

            mov ecx, val2
            mov edx, 10
            mov eax, 3
            mov ebx, 0
            int 80h

            mov ecx, val3
            mov edx, 10
            mov eax, 3
            mov ebx, 0
            int 80h

            mov eax, [val1]
            sub eax, '0'
            mov ebx, [val3]
            sub ebx, '0'
            sub eax, ebx

            mov ebx, [val1]
            add eax, ebx

            mov ebx, [val2]
            add eax, ebx

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