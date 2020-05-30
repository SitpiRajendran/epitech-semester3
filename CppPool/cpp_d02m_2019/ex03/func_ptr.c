/*
** EPITECH PROJECT, 2020
** cppd02m - ex03
** File description:
** func_ptr.
*/

#include "func_ptr.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    for (int a = strlen(str) - 1; a >= 0; a--)
        printf("%c", str[a]);
    printf("\n");
}

void print_upper(const char *str)
{
    for (int a = 0; a < (int)strlen(str); a++)
        if (str[a]>= 97 && str[a] <= 122)
            printf("%c", str[a]-32);
        else
            printf("%c", str[a]);
    printf("\n");
}

void print_42(const char *str)
{
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    void (*arr[])(const char*) = {print_normal, print_reverse, print_upper, print_42};
    (*arr[action])(str);
}