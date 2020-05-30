/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "new.h"
#include "float.h"

typedef struct
{
    Class   base;
    float     x;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    if (!this)
        raise("Float Constructor : No This");
    this->x = va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
{
    if (!this)
        raise("Float Destructor : No This");
}

char *float_string(FloatClass *this)
{
    char *buffer = malloc(sizeof(char) * 1);
    int size = snprintf (
        buffer,
        1,
        "<%s (%f)>",
        this->base.__name__,
        this->x
    ) + 1;

    buffer = realloc(buffer, sizeof(char) * size + 1);
    snprintf(buffer, size, "<%s (%f)>", this->base.__name__, this->x);
    return (buffer);
}

Object *float_addition(FloatClass *p1, FloatClass *p2)
{
    Object *f;

    if (p1 == NULL || p2 == NULL)
        raise("Float addiction : NULL");
    f = new(Float, p1->x + p2->x);
    return (f);
}

Object *float_soustraction(FloatClass *p1, FloatClass *p2)
{
    Object *f;

    if (p1 == NULL || p2 == NULL)
        raise("Float soustraction : NULL");
    f = new(Float, p1->x - p2->x);
    return (f);
}

Object *float_multiplication(FloatClass *p1, FloatClass *p2)
{
    Object *f;

    if (p1 == NULL || p2 == NULL)
        raise("Float multiplication : NULL");
    f = new(Float, p1->x * p2->x);
    return (f);
}

Object *float_division(FloatClass *p1, FloatClass *p2)
{
    Object *f;

    if (p1 == NULL || p2 == NULL)
        raise("Float division : pointer is null");
    if (p2->x == 0)
        raise("Float divison : div by 0");
    f = new(Float, p1->x / p2->x);
    return (f);
}

bool float_eq(FloatClass *p1, FloatClass *p2)
{
    Object *f;

    if (p1->x == p2->x)
        return (true);
    return (false);
}

bool float_gt(FloatClass *p1, FloatClass *p2)
{
    Object *f;

    if (p1->x > p2->x)
        return (true);
    return (false);
}

bool float_lt(FloatClass *p1, FloatClass *p2)
{
    Object *f;

    if (p1->x < p2->x)
        return (true);
    return (false);
}

static const FloatClass _description = {
    {
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&float_string,
        .__add__ = (binary_operator_t)&float_addition,
        .__sub__ = (binary_operator_t)&float_soustraction,
        .__mul__ = (binary_operator_t)&float_multiplication,
        .__div__ = (binary_operator_t)&float_division,
        .__eq__ = (binary_comparator_t)&float_eq,
        .__gt__ = (binary_comparator_t)&float_gt,
        .__lt__ = (binary_comparator_t)&float_lt
    },
    .x = 0
};

const Class *Float = (const Class *)&_description;