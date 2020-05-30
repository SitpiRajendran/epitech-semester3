/*
** EPITECH PROJECT, 2020
** ASM
** File description:
** strstr_test
*/

#include <criterion/criterion.h>
#include <string.h>

char *my_strstr(char *str1, const char *str2);

Test(my_strstr, normal_sentence)
{
    char str[] = "I as m asm!";
    char str2[] = "asm";
    cr_assert_str_eq(my_strstr(str, str2), strstr(str, str2));
}

Test(my_strstr, normal_sentence2)
{
    char str[] = "I love asm!";
    char str2[] = "love asm";
    cr_assert_str_eq(my_strstr(str, str2), strstr(str, str2));
}

Test(my_strstr, not_in)
{
    char str[] = "asm asm!";
    char str2[] = "asma";
    cr_assert_null(my_strstr(str, str2));
}

Test(my_strstr, last_char)
{
    char str[] = "I love asm!";
    char str2[] = "!";
    cr_assert_str_eq(my_strstr(str, str2), strstr(str, str2));
}

Test(my_strstr, empty)
{
    char str[] = "";
    char str2[] = "!";
    cr_assert_null(my_strstr(str, str2));
}