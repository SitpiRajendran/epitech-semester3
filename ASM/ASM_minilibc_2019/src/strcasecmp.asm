;int strcasecmp(const char *string1, const char *string2);
;                      rdi                  rsi


section .text
%ifdef UNIT_TEST
global my_strcasecmp

my_strcasecmp:
    %else

global strcasecmp:function
strcasecmp:
    %endif
    xor rdx, rdx

loop_a:
    mov al, [rdi + rdx]
    cmp al, 90
    jg loop_b
    cmp al, 65
    jl loop_b
    add al, 32

loop_b:
    mov bl, [rsi + rdx]
    cmp bl, 90
    jg compare
    cmp bl, 65
    jl compare
    add bl, 32

compare:
    cmp al, bl
    jne notsame
    cmp al, 0
    je stop
    inc rdx
    jmp loop_a

notsame:
    movsx eax, al
    movsx ebx, bl
    sub eax, ebx
    ret

stop:
    xor eax, eax
    ret