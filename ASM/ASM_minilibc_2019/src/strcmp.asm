;int strcmp (const char* str1, const char* str2);
;                  rdi                rsi

section .text

%ifdef UNIT_TEST
global my_strcmp

my_strcmp:
    %else

global strcmp

strcmp:
    %endif
    xor rcx, rcx

loop:
    mov r8b, [rdi + rcx]
    mov r9b, [rsi + rcx]
    cmp r8b, r9b
    jne notsame

    cmp r8b, 0
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