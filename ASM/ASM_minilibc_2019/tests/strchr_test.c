/*
** EPITECH PROJECT, 2020
** ASM
** File description:
** strchr_test
*/

#include <criterion/criterion.h>
#include <string.h>

char *my_strchr(const char *str, int c);

Test(my_strchr, normal_sentence)
{
    char str[] = "I as m asm!";
    char str2 = 'a';
    cr_assert_str_eq(my_strchr(str, str2), strchr(str, str2));
}

Test(my_strchr, first)
{
    char str[] = "I love asm!";
    char str2 = 'I';
    cr_assert_str_eq(my_strchr(str, str2), strchr(str, str2));
}

Test(my_strchr, not_in)
{
    char str[] = "asm asm!";
    char str2 = 'z';
    cr_assert_null(my_strchr(str, str2));
}

Test(my_strchr, last_char)
{
    char str[] = "I love asm!";
    char str2 = '!';
    cr_assert_str_eq(my_strchr(str, str2), strchr(str, str2));
}

Test(my_strchr, back_slash)
{
    char str[] = "I love asm!";
    char str2 = '\0';
    cr_assert_str_eq(my_strchr(str, str2), strchr(str, str2));
}

Test(my_strchr, empty)
{
    char str[] = "";
    char str2 = 'a';
    cr_assert_null(my_strchr(str, str2));
}