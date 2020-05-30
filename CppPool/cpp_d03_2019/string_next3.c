/*
** EPITECH PROJECT, 2020
** cpp_d03
** File description:
** string_next2
*/

#include "string.h"

int find_c(const string_t *this, const char *str, size_t pos)
{
    if (this && this->str && str) {
        if (strlen(this->str) < pos || strlen(&this->str[pos]) < strlen(str))
            return -1;
        if (strstr(&this->str[pos], str) == NULL)
            return -1;
        return (strstr(&this->str[pos], str) - this->str);
    }
}

void insert_c(string_t *this, size_t pos, const char *str)
{
    int i = 0;
    int isave = 0;
    char *temp;

    if (!this || !this->str || !str)
        return;
    temp = malloc(sizeof(char) * (strlen(this->str) + strlen(str)) + 1);
    if (temp == NULL)
        return;
    for(; pos > i && this->str[i] != '\0'; i++)
        temp[i] = this->str[i];
    isave = i;
    for (int j = 0; str[j] != '\0'; j++)
        temp[i++] = str[j];
    if (this->str[isave] != '\0')
        while (this->str[isave] != '\0')
            temp[i++] = this->str[isave++];
    temp[i] = '\0';
    assign_c(this, temp);
    free(temp);
    return;
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    return insert_c(this, pos, str->str);
}

int to_int(const string_t *this)
{
    if (this && this->str)
        return (atoi(this->str));
    return 0;
}

void string_allinit(string_t *this)
{
    this->find_c = *find_c;
    this->insert_c = *insert_c;
    this->insert_s = *insert_s;
    this->to_int = *to_int;
}