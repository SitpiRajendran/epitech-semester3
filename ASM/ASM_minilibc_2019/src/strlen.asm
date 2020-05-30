
section .text
%ifdef UNIT_TEST
global my_strlen

my_strlen:
    %else

global strlen
strlen:
    %endif
    xor rax, rax
    cmp rdi, 0
    je stop

loop:
    cmp byte [rdi], 0
    je stop
    inc rax
    inc rdi
    jmp loop

stop:
    ret