/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** ex04
*/

#include "float.h"
#include "new.h"
#include "char.h"
#include "int.h"

void     compareAndDivide(Object *a, Object *b)
{
    if (gt(a, b))
        printf ("a > b\n");
    else if (lt(a, b))
        printf ("a < b\n");
    else
        printf ("a == b\n");
    printf ("b / a = %s\n", str(division(b, a)));
}

int main(void)
{
    Object  *p1 = new(Int, 1);
    Object  *p2 = new(Int, 3);
    Object  *p3 = new(Int, 15);
    Object  *p4 = new(Int, 20);
    Object  *p5 = new(Int, 30);

    compareAndDivide (p1, p2);
    printf ("p3 * p2 = %s\n", str(multiplication(p3, p2)));
    printf ("p3 - p2 = %s\n", str(subtraction(p3, p2)));
    printf ("p3 / p2 = %s\n", str(division(p3, p2)));
    return (0);
}