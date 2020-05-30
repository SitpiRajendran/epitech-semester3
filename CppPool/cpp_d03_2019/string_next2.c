/*
** EPITECH PROJECT, 2020
** cpp_d03
** File description:
** string_next2
*/

#include "string.h"

int compare_c(const string_t *this, const char *s)
{
    if (this && this->str && s)
        return strcmp(this->str, s);
}

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    if ((strlen(this->str) - pos) >=  n)
        return n;
    else
        return (strlen(this->str) - pos);
}

const char *c_str(const string_t *this)
{
    return this->str;
}

int empty(const string_t *this)
{
    if (this->str == NULL)
        return 1;
    else
        return 0;
}

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    return (find_c(this, str->str, pos));
}