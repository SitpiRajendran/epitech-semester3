/*
** EPITECH PROJECT, 2020
** NWP
** File description:
** error
*/

#include "ftp.h"

void error_handle(char *str, int value)
{
    printf("%s", str);
    exit(value);
}