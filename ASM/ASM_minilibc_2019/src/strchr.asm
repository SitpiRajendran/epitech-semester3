;char *strchr(const char *str, int c)
;                rdi            rsi
section .text
%ifdef UNIT_TEST
global my_strchr

my_strchr:
    %else

global strchr:function
strchr:
    %endif
    xor rax, rax
    cmp rdi, 0
    je stopno

loop:
    cmp byte [rdi], sil
    je stop
    cmp byte [rdi], 0
    je stopno
    inc rdi
    jmp loop

stop:
    mov rax, rdi
    ret

stopno:
    xor rax, rax
    ret