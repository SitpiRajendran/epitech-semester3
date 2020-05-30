/*
** EPITECH PROJECT, 2020
** cpp_d02m - ex02
** File description:
** tab_to_2dtab.c
*/

#include <stdlib.h>
#include <stdio.h>

void tab_to_2dtab(const int *tab, int length, int width, int ***res)
{
    int count = 0;
    *res = malloc(sizeof(int*) * length);

    if (res == NULL)
        return;
    for (int y = 0; y < length; y++) {
        (*res)[y] = malloc(width * sizeof(int));
        if ((*res)[y] == NULL)
            return;
    }

    for (int y = 0; y < length; y++) {
        for (int x = 0; x < width; x++)
            (*res)[y][x] = tab[count++];
    }
}