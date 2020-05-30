/*
** EPITECH PROJECT, 2020
** bootstrap_malloc
** File description:
** main
*/

#include <unistd.h>

void myputchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(char *str)
{
    int i = 0;
    for(; str[i] != 0; i++);
    return i;
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

void *malloc(void)
{
    write(2, "Flying cats are the best!!!", 28);
}