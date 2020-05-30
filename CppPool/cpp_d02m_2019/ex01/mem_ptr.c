/*
** EPITECH PROJECT, 2020
** cpp_d02m - ex01
** File description:
** mem.ptr.c
*/

#include "mem_ptr.h"
#include <string.h>
#include <stdlib.h>

void add_str(const char *str1, const char *str2, char **res)
{
    *res = malloc((strlen(str1) + strlen(str2) + 1));

    if (*res == NULL)
        return;
    strcpy(*res, str1);
    strcat(*res, str2);
}

void add_str_struct(str_op_t *str_op)
{
    str_op->res = malloc((strlen(str_op->str1) + strlen(str_op->str2) + 1));

    if (str_op->res == NULL)
        return;
    strcpy(str_op->res, str_op->str1);
    strcat(str_op->res, str_op->str2);
}