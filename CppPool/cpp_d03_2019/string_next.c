/*
** EPITECH PROJECT, 2020
** cpp_d3 - ex2
** File description:
** string_next
*/

#include "string.h"

void append_c(string_t *this, const char *ap)
{
    char *temp = malloc(strlen(this->str) + 1);

    if (temp == NULL)
        return;
    strcpy(temp, this->str);

    free(this->str);
    this->str = malloc(strlen(temp) + strlen(ap) + 1);
    strcpy(this->str, temp);
    strcat(this->str, ap);
    free(temp);
}

char at(const string_t *this, size_t pos)
{
    if (pos > strlen(this->str) -1)
        return -1;
    return (this->str[pos]);
}

void clear(string_t *this)
{
    if (this) {
        free(this->str);
        this->str = malloc(sizeof(char) * 1);
        this->str[0] = '\0';
    }
}

int size(const string_t *this)
{
    if (this) {
        if (this->str == NULL)
            return -1;
        return strlen(this->str);
    }
    return -1;
}

int compare_s(const string_t *this, const string_t *s)
{
    if (this && this->str && s && s->str)
    return strcmp(this->str, s->str);
}