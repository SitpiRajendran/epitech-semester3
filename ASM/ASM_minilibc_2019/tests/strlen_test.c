/*
** EPITECH PROJECT, 2020
** ASM
** File description:
** strlen_test
*/

#include <criterion/criterion.h>
#include <string.h>

long unsigned int my_strlen(char const *str);

Test(my_strlen, normal_sentence)
{
    char str[] = "I love asm!";

    cr_assert_eq(my_strlen(str), strlen(str));
}

Test(my_strlen, normal_sentence2)
{
    char str[] = "I love asm and I don't like criterion tests!";

    cr_assert_eq(my_strlen(str), strlen(str));
}

Test(my_strlen, no_sentence)
{
    char str[] = "";

    cr_assert_eq(my_strlen(str), strlen(str));
}