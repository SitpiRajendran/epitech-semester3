/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../Character.hpp"
#include <unistd.h>

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(pv, pv_character_1, .init=redirect_all_std)
{
    Character test("Test", 0);
    test.TakeDamage(50);
    cr_assert_eq(test.getPv(), 50);
}
Test(pv, pv_character_2, .init=redirect_all_std)
{
    Character test("Test", 0);
    test.TakeDamage(100);
    cr_assert_eq(test.getPv(), 0);
}
Test(pv, pv_character_3, .init=redirect_all_std)
{
    Character test("Test", 0);
    test.TakeDamage(-100);
    cr_assert_eq(test.getPv(), 100);
}
Test(pv, pv_character_4, .init=redirect_all_std)
{
    Character test("Test", 0);
    test.TakeDamage(200);
    cr_assert_eq(test.getPv(), -100);
}
Test(pv, pv_character_5, .init=redirect_all_std)
{
    Character test("Test", 0);
    test.TakeDamage(90);
    test.Heal();
    cr_assert_eq(test.getPv(), 60);
}
Test(pv, pv_character_6, .init=redirect_all_std)
{
    Character test("Test", 0);
    test.TakeDamage(100);
    test.Heal();
    cr_assert_eq(test.getPv(), 50);
}
Test(pv, pv_character_7, .init=redirect_all_std)
{
    Character test("Test", 0);
    test.TakeDamage(200);
    test.Heal();
    cr_assert_eq(test.getPv(), -50);
}
Test(pv, pv_character_8, .init=redirect_all_std)
{
    Character test("Test", 0);
    test.TakeDamage(10);
    test.Heal();
    cr_assert_eq(test.getPv(), 100);
}


Test(Energy, Energy_character_1, .init=redirect_all_std)
{
    Character test("Test", 0);
    cr_assert_eq(test.getPower(), 100);
}
Test(Energy, Energy_character_2, .init=redirect_all_std)
{
    Character test("Test", 0);
    test.RangeAttack();
    cr_assert_eq(test.getPower(), 90);
}
Test(Energy, Energy_character_3, .init=redirect_all_std)
{
    Character test("Test", 0);
    test.CloseAttack();
    cr_assert_eq(test.getPower(), 90);
}
Test(Energy, Energy_character_4, .init=redirect_all_std)
{
    Character test("Test", 0);
    for (int i = 0; i <= 10; ++i)
        test.CloseAttack();
    cr_assert_eq(test.getPower(), 10);
}
Test(Energy, Energy_character_5, .init=redirect_all_std)
{
    Character test("Test", 0);
    for (int i = 0; i <= 30; ++i)
        test.CloseAttack();
    cr_assert_eq(test.getPower(), 10);
}
Test(pv, Energy_character_5, .init=redirect_all_std)
{
    Character test("Test", 0);
    for (int i = 0; i <= 30; ++i)
        test.CloseAttack();
    test.RestorePower();
    cr_assert_eq(test.getPower(), 100);
}
Test(pv, Energy_character_6, .init=redirect_all_std)
{
    Character test("Test", 0);
    test.CloseAttack();
    test.RestorePower();
    cr_assert_eq(test.getPower(), 100);
}


Test(Range_Attack, Range_Attack_1, .init=redirect_all_std)
{
    Character test("Test", 0);
    for (int i = 0; i <= 30; ++i)
        test.RangeAttack();
    cr_assert_eq(test.RangeAttack(), 0);
}
Test(Range_Attack, Range_Attack_2, .init=redirect_all_std)
{
    Character test("Test", 0);
    cr_assert_eq(test.RangeAttack(), 10);
}


Test(Close_Attack, Close_Attack_1, .init=redirect_all_std)
{
    Character test("Test", 0);
    for (int i = 0; i <= 30; ++i)
        test.CloseAttack();
    cr_assert_eq(test.CloseAttack(), 0);
}
Test(Close_Attack, Close_Attack_2, .init=redirect_all_std)
{
    Character test("Test", 0);
    cr_assert_eq(test.CloseAttack(), 15);
}



Test(Get_Name, Get_Name_1, .init=redirect_all_std)
{
    Character test("Test", 0);
    cr_assert_eq(test.getName(), "Test");
}
Test(Get_Name, Get_Name_2, .init=redirect_all_std)
{
    Character test("tesT", 0);
    cr_assert_eq(test.getName(), "tesT");
}
Test(Get_Name, Get_Name_3, .init=redirect_all_std)
{
    Character test("", 0);
    cr_assert_eq(test.getName(), "");
}
Test(Get_Name, Get_Name_4, .init=redirect_all_std)
{
    Character test("TestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTesTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTesttTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTest", 0);
    cr_assert_eq(test.getName(), "TestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTesTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTesttTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTest");
}


Test(Get_Levle, Get_Level_1, .init=redirect_all_std)
{
    Character test("Test", 0);
    cr_assert_eq(test.getLvl(), 0);
}
Test(Get_Levle, Get_Level_2, .init=redirect_all_std)
{
    Character test("Test", -7473);
    cr_assert_eq(test.getLvl(), -7473);
}
Test(Get_Levle, Get_Level_3, .init=redirect_all_std)
{
    Character test("Test", 999999999);
    cr_assert_eq(test.getLvl(), 999999999);
}
