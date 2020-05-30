;char *strpbrk(const char *s1, const char *s2)
;                   rdi            rsi

section .text
%ifdef UNIT_TEST
global my_strpbrk

my_strpbrk:
    %else

global strpbrk:function
strpbrk:
    %endif
    xor rbx, rbx
    jmp bigloop

bigloop:
    xor rcx, rcx
    mov r8b, [rdi + rbx]

    cmp r8b, 0
    je notfound

    jmp smallloop

smallloop:
    mov r9b, [rsi + rcx]

    cmp r9b, 0
    je newloop

    cmp r8b, r9b
    je found

    inc rcx
    jmp smallloop

newloop:
    inc rbx
    jmp bigloop

notfound:
    xor rax, rax
    ret

found:
    mov rax, rdi
    add rax, rbx
    ret