/*
** EPITECH PROJECT, 2020
** Cpp_d01 - Ex01
** File description:
** main
*/

#include "menger.h"

int my_strisnum(char *str)
{
    if (str[0] == '\0')
        return 1;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return 1;
    return 0;
}

int is_puissance(int av)
{
    double power = 1;
    int draft = 3;

    while ((draft = (int)pow(3.0, power)) <= av) {
        if (draft == av)
            return 1;
        if (draft > av)
            return 0;
        power++;
    }
    return 0;
}

int main(int ac, char **av)
{
    if (ac != 3 || my_strisnum(av[1]) == 1 || my_strisnum(av[2]) == 1)
        return 84;
    if (atoi(av[1]) <= 0 || is_puissance(atoi(av[1])) != 1)
        return 84;

    menger_function(atoi(av[1]), atoi(av[2]), 0, 0);

    return 0;
}