;char *rindex(const char *string, int c);
;                  rdi             rsi


section .text
%ifdef UNIT_TEST
global my_rindex

my_rindex:
    %else

global rindex:function
rindex:
    %endif
    xor eax, eax

loop:
    cmp byte [rdi], 0
    je search
    inc eax
    inc rdi
    jmp loop

search:
    cmp byte [rdi], sil
    je stop
    cmp eax, 0
    je stopno
    dec rdi
    dec eax
    jmp search

stop:
    mov rax, rdi
    ret

stopno:
    xor rax, rax
    ret