/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** objdump
*/

#ifndef OBJDUMP_H_
#define OBJDUMP_H_

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

#include "flag.h"

void launch_f(char *arg, char *file);
void launch_f32(Elf32_Ehdr *elf, char* arg);
void section_64(Elf64_Ehdr *elf, Elf64_Shdr *slf, char* str);
void section_32(Elf32_Ehdr *elf, Elf32_Shdr *slf, char* str);

bool to_print(char *str);
void display_left(int a, unsigned char *type, int size);
#endif /* !OBJDUMP_H_ */
