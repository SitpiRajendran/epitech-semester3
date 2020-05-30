/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** nm_sort
*/

#include "nm.h"

char str_tolower(char c)
{
    if (c >= 'A' && c <= 'Z')
        c += 32;
    return c;
}

char smaller(char c, Elf64_Shdr *slf, Elf64_Sym symtab)
{
    if (ELF64_ST_BIND(symtab.st_info) == STB_LOCAL)
        c += 32;
    return c;
}

char *change_string(char *to_change)
{
    char *str = malloc(sizeof(char) * (strlen(to_change) + 1));
    int i = 0;

    if (str == NULL)
        exit(84);
    for (int j = 0; to_change[j] != '\0'; j++)
        if (to_change[j] != '.' && to_change[j] != '_' && to_change[j] != '@')
            str[i++] = str_tolower(to_change[j]);
    str[i] = '\0';
    return str;
}

void free_str(char *str1, char *str2)
{
    free(str1);
    free(str2);
}

Elf64_Sym *sort_symtab(Elf64_Sym *symtab, int size, char *tab)
{
    Elf64_Sym *sorted = malloc(sizeof(Elf64_Sym) * size);
    Elf64_Sym temp;
    char *name1;
    char *name2;

    if (sorted == NULL)
        exit(84);
    for (int i = 0; i < size - 1; i++)
            sorted[i] = symtab[i];
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++) {
            name1 = change_string(tab+sorted[i].st_name);
            name2 = change_string(tab+sorted[j].st_name);
            if (strcmp(name1, name2) >= 0) {
                temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
            free_str(name1, name2);
        }
    return sorted;
}