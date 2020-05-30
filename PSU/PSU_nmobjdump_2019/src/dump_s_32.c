/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** s_32
*/

#include "objdump.h"

void print_content_32(Elf32_Ehdr *elf, Elf32_Shdr *slf, char* str, int i)
{
    int adress = slf[i].sh_addr;
    unsigned char* type = (unsigned char*)((char *)elf + slf[i].sh_offset);

    printf("Contents of section %s:\n", &str[slf[i].sh_name]);

    for (int a = 0; slf[i].sh_size > a ;) {
        if (a % 16 == 0 && strcmp(&str[slf[i].sh_name], ".debug_str") == 0)
            printf(" %04x ", adress);
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

void section_32(Elf32_Ehdr *elf, Elf32_Shdr *slf, char* str)
{
    for (int i = 0; i < elf->e_shnum; i++)
        if (slf[i].sh_size && to_print(&str[slf[i].sh_name]) == true)
            print_content_32(elf, slf, str, i);
}