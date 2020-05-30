;int strcspn(const char *str1, const char *str2)
;                    rdi           rsi

section .text
%ifdef UNIT_TEST
global my_strcspn

my_strcspn:
    %else

global strcspn:function
strcspn:
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
    add rax, rbx
    ret

found:
    xor rax, rax
    add rax, rbx
    ret