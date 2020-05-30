;char * strstr (char * str1, const char * str2 )
;                  rdi             rsi

section .text

%ifdef UNIT_TEST
global my_strstr
my_strstr:
    %else

global strstr
strstr:
    %endif
    xor rbx, rbx

loop1:
    mov r8b, [rdi + rbx]
    mov r9b, [rsi + rbx]

    cmp r9b, 0
    je find

    cmp r8b, r9b
    jne restart

    inc rbx
    jmp loop1

restart:
	cmp r8b, 0
	je stopno
	xor rbx, rbx
	inc rdi
	jmp loop1

find:
    mov rax, rdi
    ret

stopno:
    xor rax, rax
    ret


; char *strstr(char *str1, const char *str2)
; {
;     int a;
;     int asave
;     int b;

;     while (str1[a] != '/0') {
;         if (str1[a] == find[b])
;             compare();
;         a++
;     }

;     return NULL
; }

; compare()
; {
;     asave = a;

;     while (find[b] != '\0') {
;         if (str1[a] != find[b])
;             return;
;         a++;
;         b++;
;     }
;     return find();
; }