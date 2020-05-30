/*
** EPITECH PROJECT, 2020
** ASM
** File description:
** memmove_test
*/

#include <criterion/criterion.h>
#include <stdio.h>

void *my_memmove(void *to, const void *from, size_t numBytes);

Test(my_memmove, normal_sentence)
{
    char stra[] = "I love asm!";
    char stra2[12];
    char strb[] = "I love asm!";
    char strb2[12];
    my_memmove(stra2, stra, 5);
    memmove(strb2, strb, 5);
    cr_assert_str_eq(stra2, strb2);
}

Test(my_memmove, zero)
{
    char stra[] = "I love asm!";
    char stra2[12];
    char strb[] = "I love asm!";
    char strb2[12];
    my_memmove(stra2, stra, 0);
    memmove(strb2, strb, 0);
    cr_assert_str_eq(strb2, strb2);
}

Test(my_memmove, wrong_number)
{
    char stra[] = "20";
    char stra2[12];
    char strb[] = "20";
    char strb2[12];
    my_memmove(stra2, stra, 10);
    memmove(strb2, strb, 10);
    cr_assert_str_eq(stra2, strb2);
}

Test(my_memmove, overlap)
{
    char b[7] = "abcdef";
    char d[45];
    char a[7] = "abcdef";
    memmove(a+3, a, 2);
    my_memmove(b+3, b, 2);
    cr_assert_str_eq(a, b);
}