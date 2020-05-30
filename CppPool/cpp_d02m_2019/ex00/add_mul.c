/*
** EPITECH PROJECT, 2020
** cpp_d02m - ex00
** File description:
** add_mul.c
*/

void add_mul_4param(int first, int second, int *sum, int *product)
{
    *sum = first + second;
    *product = first * second;
}

void add_mul_2param(int *first, int *second)
{
    int a = *first;
    int b = *second;

    *first = a + b;
    *second = a * b;
}