/*
** EPITECH PROJECT, 2020
** Cpp_d01 - Ex01
** File description:
** main
*/

#include "menger.h"

void menger_function(int size, int level, int x, int y)
{
    int step = 1;

    if (size > 3)
        step = size/3;
    printf("%03d %03d %03d\n", size/3, size/3 + y, size/3 + x);
    level--;
    if (level <= 0)
        return;
    for (int col = 0; col < size ; col = col + step) {
        for (int line = 0; line < size; line = line + step) {
            (col != step || line != step) ?
            menger_function(step, level, x + line, y + col) : 0;
        }
    }
    return;
}