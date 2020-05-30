/*
** EPITECH PROJECT, 2020
** cpp_d03 - ex00
** File description:
** string.c
*/

#include "string.h"

void string_init(string_t *this, const char *s)
{
    if (s != NULL) {
        this->str = malloc(strlen(s) + 1);
        strcpy(this->str, s);
    } else
        this->str = NULL;

    this->assign_s = &assign_s;
    this->assign_c = &assign_c;
    this->append_s = &append_s;
    this->append_c = &append_c;
    this->at = &at;
    this->clear = &clear;
    this->size = &size;
    this->compare_s = &compare_s;
    this->compare_c = &compare_c;
    this->copy = &copy;
    this->c_str = &c_str;
    this->empty = &empty;
    this->find_s = *find_s;
    string_allinit(this);
}

void string_destroy(string_t *this)
{
    if (this->str != NULL)
        free(this->str);
}

void assign_s(string_t *this, const string_t *str)
{
    if (str->str == NULL)
        this->str = NULL;
    else {
        free(this->str);
        this->str = malloc(strlen(str->str) + 1);
        strcpy(this->str, str->str);
    }
}

void assign_c(string_t *this, const char *s)
{
    if (s == NULL)
        this->str = NULL;
    else {
        free(this->str);
        this->str = malloc(strlen(s) + 1);
        strcpy(this->str, s);
    }
}

void append_s(string_t *this, const string_t *ap)
{
    char *temp = malloc(strlen(this->str) + 1);

    if (temp == NULL)
        return;
    strcpy(temp, this->str);

    free(this->str);
    this->str = malloc(strlen(temp) + strlen(ap->str) + 1);
    strcpy(this->str, temp);
    strcat(this->str, ap->str);
    free(temp);
}