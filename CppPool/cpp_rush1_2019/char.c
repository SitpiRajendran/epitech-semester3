/*
** EPITECH PROJECT, 2020
** cpp_rush_2019
** File description:
** char
*/

#include <stdarg.h>
#include <stdio.h>
#include "char.h"
#include "new.h"

typedef struct
{
    Class base;
    char c;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    if (!this)
        raise("Char Constructor : No This");
    this->c = va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    if (!this)
        raise("Char Destructor : No This");
}

char *Char_string(CharClass *this)
{
    char *buffer = malloc(sizeof(char) * 1);
    int size = snprintf(buffer, 1, "<%s (%c)>", this->base.__name__, this->c) + 1;

    buffer = realloc(buffer, sizeof(char) * size + 1);
    snprintf(buffer, size, "<%s (%c)>", this->base.__name__, this->c);
    return (buffer);
}

Object *Char_addition(CharClass *p1, CharClass *p2)
{
    Object *tmp;

    if (p1 == NULL || p2 == NULL)
        raise("Char addiction : NULL");
    tmp = new(Char, p1->c + p2->c);
    return (tmp);
}

Object *Char_soustraction(CharClass *p1, CharClass *p2)
{
    Object *tmp;

    if (p1 == NULL || p2 == NULL)
        raise("Char addiction : NULL");
    tmp = new(Char, p1->c - p2->c);
    return (tmp);
}

Object *Char_multiplication(CharClass *p1, CharClass *p2)
{
    Object *tmp;

    if (p1 == NULL || p2 == NULL)
        raise("Char addiction : NULL");
    tmp = new(Char, p1->c * p2->c);
    return (tmp);
}

Object *Char_division(CharClass *p1, CharClass *p2)
{
    Object *tmp;

    if (p1 == NULL || p2 == NULL)
        raise("Char addiction : div by 0");
    if (p2->c == 0)
        raise("Char addiction : div by 0");
    tmp = new(Char, (char)(p1->c / p2->c));
    return (tmp);
}

bool Char_eq(CharClass *p1, CharClass *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("Char addiction : div by 0");
    if (p1->c == p2->c)
        return (true);
    return (false);
}

bool Char_gt(CharClass *p1, CharClass *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("Char addiction : div by 0");
    if (p1->c > p2->c)
        return (true);
    return (false);
}

bool Char_lt(CharClass *p1, CharClass *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("Char addiction : div by 0");
    if (p1->c < p2->c)
        return (true);
    return (false);
}

static const CharClass _description = {
    {
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_string,
        .__add__ = (binary_operator_t)&Char_addition,
        .__sub__ = (binary_operator_t)&Char_soustraction,
        .__mul__ = (binary_operator_t)&Char_multiplication,
        .__div__ = (binary_operator_t)&Char_division,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt
    },
    .c = 0,
};

const Class *Char = (const Class *)&_description;