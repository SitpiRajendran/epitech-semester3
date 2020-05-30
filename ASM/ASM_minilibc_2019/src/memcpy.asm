;void *memcpy(void *str1, const void *str2, size_t n)
;                rdi              rsi         rdx

section .text

%ifdef UNIT_TEST
global my_memcpy

my_memcpy:
    %else
global memcpy

memcpy:
    %endif
    xor rcx, rcx
    xor bl, bl

loop:
    cmp rdx, rcx
    je stop

    cmp byte [rsi + rcx], 0
    je stopend

    mov bl, byte[rsi + rcx]
    mov byte [rdi + rcx], bl
    inc rcx
    jmp loop

stop:
    mov rax, rdi
    ret

stopend:
    mov bl, byte[rsi + rcx]
    mov byte [rdi + rcx], bl
    mov rax, rdi
    ret