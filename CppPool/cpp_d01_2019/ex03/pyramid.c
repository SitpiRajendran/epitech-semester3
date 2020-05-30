/*
** EPITECH PROJECT, 2020
** Cpp_day01 - ex03
** File description:
** pyramid.c
*/

#include <stdio.h>
#include <stdlib.h>

int smallest(int *last_line, int size)
{
    int small = last_line[0];

    for (int x = 0; x < size; x++)
        if (small > last_line[x])
            small = last_line[x];

    return small;
}

int add(int y, int x, int **total, const int **map)
{
    if (x == 0)
        return (map[y][0] + total[y-1][0]);

    if (x == y && x != 0)
        return (map[y][x] + total[y-1][x-1]);

    if (total[y-1][x-1] > total[y-1][x])
        return (map[y][x] + total[y-1][x]);

    if (total[y-1][x-1] <= total[y-1][x])
        return (map[y][x] + total[y-1][x-1]);

    return (map[y][x]);
}

int pyramid_path(int size, const int **map)
{
    int x;
    int **total = malloc(sizeof(int *) * size + 1);

    for (x = 0; x != size; x++)
        total[x] = malloc(sizeof(int) * size);
    for (x = 0; x <= size; x+=1)
        total[0][x] = map[0][x];
    for (int y = 1; y < size; y+= 1) {
        for (x = 0; x <= y; x+= 1) {
            (x == 0) ? total[y][x] = (map[y][0] + total[y-1][0]) : 0;
            total[y][x] = add(y, x, total, map);
        }
        for (x; x <= size; x+=1)
            total[y][x] = 0;
    }

    return smallest(total[size-1], size);
}