/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** s_64
*/

#include "objdump.h"

void display_left(int a, unsigned char *type, int size)
{
    static unsigned int c = 0;

    if (a <= 16)
        c = 0;
    for (unsigned int i = a; i % 16; ++i) {
        printf("  ");
        if (i % 4 == 0)
            printf(" ");
    }
    printf("  ");
    for (; c < a; c++) {
        if (isprint(type[c]) == 0)
            printf(".");
        else
            printf("%c", ((char *)type)[c]);
    }
    for (; c % 16 != 0; c++)
        printf(" ");
    printf("\n");
    c = a;
    return;
}

void print_content(Elf64_Ehdr *elf, Elf64_Shdr *slf, char* str, int i)
{
    int adress = slf[i].sh_addr;
    unsigned char* type = (unsigned char*)((char *)elf + slf[i].sh_offset);

    printf("Contents of section %s:\n", &str[slf[i].sh_name]);

    for (int a = 0; slf[i].sh_size > a ;) {
        if (a % 16 == 0 && strcmp(&str[slf[i].sh_name], ".debug_str") == 0)
            printf(" %05x ", adress);
        else if (a % 16 == 0)
            printf(" %04x ", adress);
        printf("%02x", type[a++]);
        if (slf[i].sh_size > a && a % 16 != 0 && a % 4 == 0)
            printf(" ");
        if (a % 16 == 0) {
            adress += 16;
            display_left(a, type, slf[i].sh_size);
        } else if (slf[i].sh_size <= a) {
            display_left(a, type, slf[i].sh_size);
        }
    }
}

bool to_print(char *str)
{
    if (strcmp(str, ".bss") == 0 || strcmp(str, ".rela.eh_frame") == 0 ||
        strcmp(str, ".rela.text") == 0 || strcmp(str, ".shstrtab") == 0)
        return false;
    else if (strcmp(str, ".strtab") == 0 || strcmp(str, ".symtab") == 0)
        return false;
    else
        return true;
}

void section_64(Elf64_Ehdr *elf, Elf64_Shdr *slf, char* str)
{
    for (int i = 0; i < elf->e_shnum; i++)
        if (slf[i].sh_size && to_print(&str[slf[i].sh_name]) == true)
            print_content(elf, slf, str, i);
}