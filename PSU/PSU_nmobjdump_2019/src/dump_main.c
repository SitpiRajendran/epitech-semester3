/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** main_dump
*/

#include "objdump.h"

char *openFile(char *filepath)
{
    struct stat sb;
    int fd;
    int ret;
    int size;
    char *str;

    if (stat(filepath, &sb) == -1)
        return "nofile";
    size = sb.st_size;
    str = malloc(size + 1);
    fd = open(filepath, O_RDONLY);
    if (str == NULL || fd == -1)
        return "perm";
    str = mmap(NULL, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);

    return (str);
}

int check_file(char *str)
{
    Elf64_Ehdr *elf = (Elf64_Ehdr*)str;

    if (elf->e_ident == NULL)
        return 0;
    if(elf->e_ident[EI_MAG0] == ELFMAG0 && elf->e_ident[EI_MAG1] == ELFMAG1 &&
        elf->e_ident[EI_MAG2] == ELFMAG2 && elf->e_ident[EI_MAG3] == ELFMAG3)
        return 1;
    return 0;
}

int launch(char *arg)
{
    char *str = openFile(arg);

    if (str == "nofile") {
        fprintf(stderr, "objdump: '%s': No such file\n", arg);
        return 84;
    } else if (str == "perm" || str == "nop") {
        fprintf(stderr, "objdump: %s: Permission denied\n", arg);
        return 84;
    }
    if (check_file(str) == 1)
        launch_f(arg, str);
    else {
        fprintf(stderr, "objdump: %s: file format not recognized\n", arg);
        return 84;
    }
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 1)
        return launch("a.out");
    else
        for (int i = 1; i < ac; i++) {
            if (launch(av[i]) == 84)
                return 84;
        }
    return 0;
}