/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** int
*/

#include <stdio.h>
#include "int.h"
#include "new.h"

typedef struct
{
    Class base;
    int x;
}   IntClass;

static void int_ctor(IntClass *this, va_list *args)
{
    if (!this)
        raise("Int Constructor : No This");
    this->x = va_arg(*args, int);
}

static void int_dtor(IntClass *this)
{
    if (!this)
        raise("Int Destructor : No This");
}

char *int_string(IntClass *this)
{
    char *buffer = malloc(sizeof(char) * 1);
    int size = snprintf(buffer, 1, "<%s (%d)>", this->base.__name__, this->x) + 1;

    buffer = realloc(buffer, sizeof(char) * size + 1);
    snprintf(buffer, size, "<%s (%d)>", this->base.__name__, this->x);
    return (buffer);
}

Object *int_addition(IntClass *p1, IntClass *p2)
{
    Object *integer;

    if (p1 == NULL || p2 == NULL)
        raise("Int addiction : NULL");
    integer = new(Int, p1->x + p2->x);
    return (integer);
}

Object *int_soustraction(IntClass *p1, IntClass *p2)
{
    Object *integer;

    if (p1 == NULL || p2 == NULL)
        raise("Int addiction : NULL");
    integer = new(Int, p1->x - p2->x);
    return (integer);
}

Object *int_multiplication(IntClass *p1, IntClass *p2)
{
    Object *integer;

    if (p1 == NULL || p2 == NULL)
        raise("Int addiction : NULL");
    integer = new(Int, p1->x * p2->x);
    return (integer);
}

Object *int_division(IntClass *p1, IntClass *p2)
{
    Object *integer;

    if (p1 == NULL || p2 == NULL)
        raise("Int addiction : NULL");
    if (p1->x == 0)
        raise("Int addiction : div by 0");
    integer = new(Int, p1->x / p2->x);
    return (integer);
}

bool int_eq(IntClass *p1, IntClass *p2)
{
    Object *integer;

    if (p1 == NULL || p2 == NULL)
        raise("Int addiction : NULL");
    if (p1->x == p2->x)
        return (true);
    return (false);
}

bool int_gt(IntClass *p1, IntClass *p2)
{
    Object *integer;

    if (p1 == NULL || p2 == NULL)
        raise("Int addiction : NULL");
    if (p1->x > p2->x)
        return (true);
    return (false);
}

bool int_lt(IntClass *p1, IntClass *p2)
{
    Object *integer;

    if (p1 == NULL || p2 == NULL)
        raise("Int addiction : NULL");
    if (p1->x < p2->x)
        return (true);
    return (false);
}

static const IntClass _description = {
    {
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&int_ctor,
        .__dtor__ = (dtor_t)&int_dtor,
        .__str__ = (to_string_t)&int_string,
        .__add__ = (binary_operator_t)&int_addition,
        .__sub__ = (binary_operator_t)&int_soustraction,
        .__mul__ = (binary_operator_t)&int_multiplication,
        .__div__ = (binary_operator_t)&int_division,
        .__eq__ = (binary_comparator_t)&int_eq,
        .__gt__ = (binary_comparator_t)&int_gt,
        .__lt__ = (binary_comparator_t)&int_lt
    },
    .x = 0
};

const Class *Int = (const Class *)&_description;