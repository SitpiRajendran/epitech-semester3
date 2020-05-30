/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** nm
*/

#ifndef NM_H_
#define NM_H_

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <sys/mman.h>
#include <elf.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>

void launch_nm(char *file, char *name);
char smaller(char c, Elf64_Shdr *slf, Elf64_Sym symtab);
Elf64_Sym *sort_symtab(Elf64_Sym *symtab, int size, char *tab);
#endif /* !NM_H_ */