/*
** EPITECH PROJECT, 2020
** CppPool - D06
** File description:
** tests
*/

#include  <criterion/criterion.h>

Test(string , valid_fi)
{
    std:: string s;
    cr_assert_eq(s, "");
}

Test(string , assign)
{
    std:: string s;
    s = "test";
    cr_assert_eq(s, "test");
}

Test(string , append)
{
    std:: string s("test");
    s += "ing";
    cr_assert_eq(s, "testing");
}