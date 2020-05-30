/*
** EPITECH PROJECT, 2020
** cpp_rush1
** File description:
** new.c
*/

#include <stdarg.h>
#include "new.h"
#include "player.h"

Object *new(const Class *class, ...)
{
    Object *obj;
    va_list ap;

    if (class == NULL)
        raise("class.new : No class send");
    if (!(class->__size__))
        raise("class.new : No size in class");

    va_start(ap, class);
    obj = va_new(class, &ap);
    va_end(ap);
    return (obj);
}

void delete(Object *ptr)
{
    if (ptr == NULL)
        raise("class.delete : ptr is NULL");
    if (((Class *)ptr)->__dtor__)
        ((Class *)ptr)->__dtor__(ptr);
    free(ptr);
}

Object *va_new(const Class *class, va_list *ap)
{
    Object *obj;

    obj = malloc(class->__size__);
    memcpy(obj, class, class->__size__);
    if (obj == NULL)
        raise("class.new : Malloc Error");
    if ((class->__ctor__) != NULL)
        class->__ctor__(obj, ap);
    return obj;
}