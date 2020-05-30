/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdarg.h>
#include <stdio.h>
#include "point.h"
#include "new.h"

typedef struct
{
    Class base;
    int x;
    int y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    if (!this)
        raise("Point Constructor : No This");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
    if (!this)
        raise("Point Destructor : No This");
}

char *point_string(PointClass *this)
{
    char *buffer = malloc(sizeof(char) * 1);
    int size = snprintf(buffer, 1, "<%s (%d, %d)>", this->base.__name__, this->x, this->y) + 1;

    buffer = realloc(buffer, sizeof(char) * size + 1);
    snprintf(buffer, size, "<%s (%d, %d)>", this->base.__name__, this->x, this->y);
    return (buffer);
}

Object *point_addition(PointClass *p1, PointClass *p2)
{
    Object *point;

    if (p1 == NULL || p2 == NULL)
        raise("Point addiction : NULL");
    point = new(Point, p1->x + p2->x, p1->y + p2->y);
    return (point);
}

Object *point_soustraction(PointClass *p1, PointClass *p2)
{
    Object *point;

    if (p1 == NULL || p2 == NULL)
        raise("Point addiction : NULL");
    point = new(Point, p1->x - p2->x, p1->y - p2->y);
    return (point);
}

Object *point_multiplication(PointClass *p1, PointClass *p2)
{
    Object *point;

    if (p1 == NULL || p2 == NULL)
        raise("Point addiction : NULL");
    point = new(Point, p1->x * p2->x, p1->y * p2->y);
    return (point);
}

Object *point_division(PointClass *p1, PointClass *p2)
{
    Object *point;

    if (p1 == NULL || p2 == NULL)
        raise("Point addiction : NULL");
    if (p1->x == 0 || p1->y == 0)
        raise("Point addiction : div by 0");
    point = new(Point, p1->x / p2->x, p1->y / p2->y);
    return (point);
}

bool point_eq(PointClass *p1, PointClass *p2)
{
    Object *point;

    if (p1 == NULL || p2 == NULL)
        raise("Point addiction : NULL");
    if (p1->x == p2->x && p1->y == p2->y)
        return (true);
    return (false);
}

bool point_gt(PointClass *p1, PointClass *p2)
{
    Object *point;

    if (p1 == NULL || p2 == NULL)
        raise("Point addiction : NULL");
    if (p1->x > p2->x && p1->y > p2->y)
        return (true);
    return (false);
}

bool point_lt(PointClass *p1, PointClass *p2)
{
    Object *point;

    if (p1 == NULL || p2 == NULL)
        raise("Point addiction : NULL");
    if (p1->x < p2->x && p1->y < p2->y)
        return (true);
    return (false);
}


static const PointClass _description = {
    {
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&point_string,
        .__add__ = (binary_operator_t)&point_addition,
        .__sub__ = (binary_operator_t)&point_soustraction,
        .__mul__ = (binary_operator_t)&point_multiplication,
        .__div__ = (binary_operator_t)&point_division,
        .__eq__ = (binary_comparator_t)&point_eq,
        .__gt__ = (binary_comparator_t)&point_gt,
        .__lt__ = (binary_comparator_t)&point_lt
    },
    .x = 0,
    .y = 0
};

const Class *Point = (const Class *)&_description;