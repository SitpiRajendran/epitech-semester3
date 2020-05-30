;void * memmove(void *to, const void *from, size_t numBytes)
;                rdi              rsi             rdx


section .text
%ifdef UNIT_TEST
global my_memmove

my_memmove:
    %else

global memmove:function
memmove:
    %endif
    xor rcx, rcx
    cmp rdx, 0
    je stopno

loop:
    cmp rdx, rcx
    je stop

    cmp byte [rsi + rcx], 0
    je stopend

    mov bl, byte[rsi + rcx]
    mov byte [rdi + rcx], bl
    inc rcx
    jmp loop

stopend:
    mov bl, byte[rsi + rcx]
    mov byte [rdi + rcx], bl
    mov rax, rdi
    ret

stop:
    mov rax, rdi
    ret

stopno:
    mov rdi, 0x2
    mov rax, rdi
    ret