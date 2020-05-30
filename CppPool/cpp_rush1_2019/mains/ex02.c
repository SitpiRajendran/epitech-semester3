/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** ex02
*/

#include <stdio.h>
#include "new.h"
#include "point.h"
#include "vertex.h"

int main(void)
{
    Object  *point = new(Point, 2147483647, -2147483647);
    Object  *vertex = new(Vertex, 2147483647, 2147483647, 2147483647);

    printf("point = %s\n", str(point));
    printf("vertex = %s\n", str(vertex));

    delete(point);
    delete(vertex);
    return (0);
}