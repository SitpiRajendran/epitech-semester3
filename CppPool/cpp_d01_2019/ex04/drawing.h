/*
** EPITECH PROJECT, 2020
** Cpp_d01 - ex04
** File description:
** drawing.h
*/

#ifndef DRAWING_H_
#define DRAWING_H_

#include <stdint.h>
#include <stdlib.h>

typedef struct point_s
{
    uint32_t x;
    uint32_t y;
} point_t;

#endif /* !DRAWING_H_ */

void draw_square(uint32_t **, const point_t *, size_t, uint32_t);
