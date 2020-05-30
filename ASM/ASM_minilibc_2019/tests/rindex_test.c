/*
** EPITECH PROJECT, 2020
** ASM
** File description:
** memmove_test
*/

#include <criterion/criterion.h>
#include <stdio.h>

char *my_rindex(const char *string, int c);

Test(my_rindex, normal_in)
{
    cr_assert_str_eq(my_rindex("HelloWorld", 'W'), rindex("HelloWorld", 'W'));
}

Test(my_rindex, not_in)
{
    cr_assert_null(my_rindex("HelloWorld", 'w'));
}

Test(my_rindex, last)
{
    cr_assert_str_eq(my_rindex("HelloWorld!", '!'), rindex("HelloWorld!", '!'));
}

Test(my_rindex, first)
{
    cr_assert_str_eq(my_rindex("HelloWorld!", 'H'), rindex("HelloWorld!", 'H'));
}