section .data ;Seção para declaração de CONSTANTES;
    msg1 db "Digite o primeiro nome: ", 10h
    len1 equ $ - msg1
    msg2 db "Digite o sobrenome: ", 10h
    len2 equ $ - msg2
    space db " ", 10h
    msg3 db "Nome completo: ", 10h
    len3 equ $ - msg3
    ;db -> DefineByte
    ;10h ou 0xa aponta o endereco de memoria e seta o line feed;
    ;len EQUals $posicaoAtual - msgTamnhaString;

section .bss
    firstName resb 7 ; resb -> reserva espaço para a variavel -> 7 bytes ->REServeBytes 7;
    lastName resb 8 ; resw -> reserva espaço para variavel -> 8 words ->REServeWord 8;

    ;e?x -> registrador;
    ;c e usado para variavel;

section .text

    global _start

    _start:

    mov ecx, msg1
    mov edx, len1
    call _SHOW

    mov ecx, firstName
    mov edx, 7 ;tamanho da entrada do teclado;
    call _INPUT

    mov ecx, msg2
    mov edx, len2
    call _SHOW

    mov ecx, lastName
    mov edx, 7
    call _INPUT

    mov ecx, msg3
    mov edx, len3
    call _SHOW

    mov ecx, firstName
    mov edx, 6
    call _SHOW

    mov ecx, space
    mov edx, 1
    call _SHOW

    mov ecx, lastName
    mov edx, 8
    call _SHOW

_INPUT:
    mov eax, 3 ;leitura de teclado a->3 b->0;
    mov ebx, 0
    int 80h

_SHOW:
    mov eax, 4
    mov ebx, 1
    int 80h ; chamada de sistema. Para LINUX: 80h, para WINDOWS 21h;

    mov eax, 1
    mov ebx, 0
    int 80h