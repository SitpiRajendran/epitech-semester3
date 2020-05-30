;int strncmp(const char *str1, const char *str2, size_t n)
;                  rdi                rsi           rdx


section .text
%ifdef UNIT_TEST
global my_strncmp

my_strncmp:
    %else

global strncmp:function
strncmp:
    %endif
    xor rcx, rcx
    dec rdx

loop:
    mov r8b, [rdi + rcx]
    mov r9b, [rsi + rcx]
    cmp r8b, r9b
    jne notsame

    cmp r8b, 0
    je stop
    cmp r9b, 0
    je stop

    cmp rdx, rcx
    je stop

    inc rcx
    jmp loop

notsame:
    sub r8b, r9b
    movsx rax, r8b
    ret

stop:
    xor rax, rax
    ret