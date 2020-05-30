/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** nm_launch
*/

#include "nm.h"

char get_type(char c, Elf64_Shdr *slf, Elf64_Sym symtab)
{
    if (symtab.st_shndx == SHN_ABS)
        return smaller('A', slf, symtab);
    if (slf[symtab.st_shndx].sh_type == SHT_NOBITS
        && slf[symtab.st_shndx].sh_flags == SHF_ALLOC + SHF_WRITE)
        return smaller('B', slf, symtab);
    if (symtab.st_shndx == SHN_COMMON)
        return smaller('C', slf, symtab);
    if (slf[symtab.st_shndx].sh_type == SHT_DYNAMIC)
        return smaller('D', slf, symtab);
    if (slf[symtab.st_shndx].sh_type == SHT_PROGBITS) {
        if (slf[symtab.st_shndx].sh_flags == SHF_ALLOC)
            return smaller('R', slf, symtab);
        else if (slf[symtab.st_shndx].sh_flags == SHF_ALLOC + SHF_WRITE)
            return smaller('D', slf, symtab);
        else if (slf[symtab.st_shndx].sh_flags == SHF_ALLOC + SHF_EXECINSTR);
            return smaller('T', slf, symtab);
    }
    return smaller('T', slf, symtab);
}

char get_type_next(Elf64_Shdr *slf, Elf64_Sym symtab)
{
    char c = 0;

    if (ELF64_ST_BIND(symtab.st_info) == STB_WEAK) {
        c = 'W';
        if (ELF64_ST_TYPE(symtab.st_info) == STT_OBJECT)
            c = 'V';
        if (symtab.st_shndx == SHN_UNDEF)
            c += 32;
        return smaller(c, slf, symtab);
    }
    if (symtab.st_shndx == SHN_UNDEF)
        return smaller('U', slf, symtab);
    else if (ELF64_ST_BIND(symtab.st_info) == STB_GNU_UNIQUE)
        return smaller('u', slf, symtab);

    return get_type(c, slf, symtab);
}

void print_all(Elf64_Shdr *slf, char *strtab, Elf64_Sym *symtab, int size)
{
    for (int i = 0; i < size; i++)
        if (symtab[i].st_name != SHN_UNDEF && ELF64_ST_TYPE(symtab[i].st_info) != STT_FILE) {
            if (symtab[i].st_size == 0 && symtab[i].st_shndx == SHN_UNDEF)
                printf("                ");
            else
                printf("%016x", symtab[i].st_value);
            printf(" %c %s\n", get_type_next(slf, symtab[i]), strtab+symtab[i].st_name);
        }
}
void launch_nm_64(Elf64_Ehdr *elf, Elf64_Shdr *slf, char *str)
{
    int size;
    Elf64_Sym *symtab;
    char *strtab;

    for (int i = 0; i < elf->e_shnum; i++) {
        if (strcmp(&str[slf[i].sh_name], ".symtab") == 0) {
            if (&slf[i] == 0)
                return;
            symtab = (void *)elf + (&slf[i])->sh_offset;
            size = (&slf[i])->sh_size / (&slf[i])->sh_entsize;
        } else if (strcmp(&str[slf[i].sh_name], ".strtab") == 0) {
            if (&slf[i] == 0)
                return;
            strtab = (char *)elf + (&slf[i])->sh_offset;
        }
    }
    symtab = sort_symtab(symtab, size, strtab);
    print_all(slf, strtab, symtab, size);
}

void launch_nm(char *file, char *name)
{
    Elf64_Ehdr *elf = (Elf64_Ehdr*)file;
    Elf64_Shdr *slf = (Elf64_Shdr *)(file + elf->e_shoff);
    char *str = (char *)file + slf[elf->e_shstrndx].sh_offset;

    if (elf->e_ident[EI_CLASS] == ELFCLASS64) {
        launch_nm_64(elf, slf, str);
    }
}