/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** header
*/

#include "objdump.h"

char *getComputer_32(Elf32_Ehdr *elf)
{
    if (elf->e_machine == EM_386)
        return "Intel 80386";
    if (elf->e_machine == EM_X86_64)
        return "i386:x86-64";
    if (elf->e_machine == EM_860)
        return "Intel 80860";
    if (elf->e_machine == EM_NONE)
        return "None";
}
void getFlags_32(Elf32_Ehdr *elf)
{
    if (elf->e_type == ET_NONE || elf->e_type == ET_CORE)
        printf("%08d:\n\n", 0);
    else if (elf->e_type == ET_REL)
        printf("%08d:\nHAS_RELOC, HAS_SYMS\n", 11);
    if (elf->e_type == ET_EXEC)
        printf("%08d:\nEXEC_P, HAS_SYMS, D_PAGED\n", 112);
    else if (elf->e_type == ET_DYN)
        printf("%08d:\nHAS_SYMS, DYNAMIC, D_PAGED\n", 150);
}

void launch_f32(Elf32_Ehdr *elf, char* arg)
{
    printf("\n%s:     file format elf32-i386\n", arg);
    printf("architecture: %s, flags 0x", getComputer_32(elf));
    getFlags_32(elf);
    printf("start address 0x%016x\n\n", elf->e_entry);
}