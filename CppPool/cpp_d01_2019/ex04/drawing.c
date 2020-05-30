/*
** EPITECH PROJECT, 2020
** Cpp_d01 - exo04
** File description:
** drawing.c
*/

#include "drawing.h"

void draw_square(uint32_t **img, const point_t *ori, size_t size, uint32_t colo)
{
    uint32_t x = 0;
    uint32_t y = 0;

    for (x = 0; x < size; x += 1)
        for (y = 0; y < size; y += 1)
            img[ori->x + x][y + ori->y] = colo;
}