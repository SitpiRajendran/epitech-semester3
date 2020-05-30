/*
** EPITECH PROJECT, 2020
** ASM
** File description:
** memcpy_test
*/

#include <criterion/criterion.h>
#include <string.h>

void *my_memcpy(void *str1, const void *str2, size_t n);

Test(my_memcpy, normal_sentence)
{
    char stra[] = "I love asm!";
    char stra2[12];
    char strb[] = "I love asm!";
    char strb2[12];
    my_memcpy(stra2, stra, 5);
    memcpy(strb2, strb, 5);
    cr_assert_str_eq(stra2, strb2);
}

Test(my_memcpy, zero)
{
    char stra[] = "I love asm!";
    char stra2[12];
    char strb[] = "I love asm!";
    char strb2[12];
    my_memcpy(stra2, stra, 0);
    memcpy(strb2, strb, 0);
    cr_assert_str_eq(strb2, strb2);
}

Test(my_memcpy, wrong_number)
{
    char stra[] = "20";
    char stra2[12];
    char strb[] = "20";
    char strb2[12];
    my_memcpy(stra2, stra, 10);
    memcpy(strb2, strb, 10);
    cr_assert_str_eq(stra2, strb2);
}

Test(my_memcpy, overlap)
{
    char b[7] = "abcdef";
    char d[45];
    char a[7] = "abcdef";
    memcpy(a+3, a, 2);
    my_memcpy(b+3, b, 2);
    cr_assert_str_eq(b, a);
}