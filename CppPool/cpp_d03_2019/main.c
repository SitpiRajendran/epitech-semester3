/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** main
*/

#include "string.h"

int main()
{
    string_t this;
    string_init(&this, "123");
    printf("%d\n", this.to_int(&this));
    string_destroy(&this);

    return 0;
}