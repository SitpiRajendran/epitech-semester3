/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** vertex
*/

#include <stdio.h>
#include <stdarg.h>
#include "vertex.h"
#include "new.h"

typedef struct
{
    Class base;
    int x;
    int y;
    int z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    if (!this)
        raise("Vertex Constructor : No This");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
}

char *vertex_string(VertexClass *this)
{
    char *buffer = malloc(sizeof(char) * 1);
    int size = snprintf(buffer, 1, "<%s (%d, %d, %d)>", this->base.__name__, this->x, this->y, this->z) + 1;

    buffer = realloc(buffer, sizeof(char) * size + 1);
    snprintf(buffer, size, "<%s (%d, %d, %d)>", this->base.__name__, this->x, this->y, this->z);
    return (buffer);
}

Object *vertex_addition(VertexClass *p1, VertexClass *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("Vertex_addition : mul by 0");
    Object *point = new(Vertex, p1->x + p2->x, p1->y + p2->y, p1->z + p2->z);

    return (point);
}

Object *vertex_soustraction(VertexClass *p1, VertexClass *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("Vertex_soustraction : mul by 0");
    Object *point = new(Vertex, p1->x - p2->x, p1->y - p2->y, p1->z - p2->z);

    return (point);
}

Object *vertex_multiplication(VertexClass *p1, VertexClass *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("Vertex_multiplication : mul by 0");
    Object *point = new(Vertex, p1->x * p2->x, p1->y * p2->y, p1->z * p2->z);

    return (point);
}

Object *vertex_division(VertexClass *p1, VertexClass *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("Vertex_division : div by 0");
    if (p1->x == 0 || p1->y == 0 || p1->z == 0)
        raise("Vertex_division : div by 0");
    Object *point = new(Vertex, p1->x / p2->x, p1->y / p2->y, p1->z / p2->z);

    return (point);
}

bool vertex_eq(VertexClass *p1, VertexClass *p2)
{
    Object *point;

    if (p1 == NULL || p2 == NULL)
        raise("Vertex equals : div by 0");
    if (p1->x == p2->x && p1->y == p2->y && p1->z == p2->z)
        return (true);
    return (false);
}

bool vertex_gt(VertexClass *p1, VertexClass *p2)
{
    Object *point;

    if (p1 == NULL || p2 == NULL)
        raise("Vertex addiction : div by 0");
    if (p1->x > p2->x && p1->y > p2->y && p1->z > p2->z)
        return (true);
    return (false);
}

bool vertex_lt(VertexClass *p1, VertexClass *p2)
{
    Object *point;

    if (p1 == NULL || p2 == NULL)
        raise("Vertex addiction : div by 0");
    if (p1->x < p2->x && p1->y < p2->y && p1->z < p2->z)
        return (true);
    return (false);
}

static const VertexClass _description = {
    {
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&vertex_string,
        .__add__ = (binary_operator_t)&vertex_addition,
        .__sub__ = (binary_operator_t)&vertex_soustraction,
        .__mul__ = (binary_operator_t)&vertex_multiplication,
        .__div__ = (binary_operator_t)&vertex_division,
        .__eq__ = (binary_comparator_t)&vertex_eq,
        .__gt__ = (binary_comparator_t)&vertex_gt,
        .__lt__ = (binary_comparator_t)&vertex_lt
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class *Vertex = (const Class *)&_description;