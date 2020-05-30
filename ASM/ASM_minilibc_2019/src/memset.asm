;void *memset(void *str, int char, size_t n);
;                rdi      rsi     rdx
;                        sil


section .text
%ifdef UNIT_TEST
global my_memset

my_memset:
    %else

global memset:function
memset:
    %endif
    xor rcx, rcx

loop:
    cmp byte [rdi + rcx], 0
    je stop
    cmp rdx, rcx
    je stop
    mov byte [rdi + rcx], sil
    inc rcx
    jmp loop

stop:
    mov rax, rdi
    ret