/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** main
*/

#include "Object.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"
#include "Teddy.hpp"
#include "Table.hpp"

Object **test_main(void)
{
    Object **object = new Object*[3];

    object[0] = new Teddy("cuddles");
    object[1] = new Box("cardboard box");
    object[2] = new GiftPaper("christmas paper");
    return object;
}

int main ()
{
    Object **toys = MyUnitTests();
    Object *ready = MyUnitTests(test_main());
    Table tab;

    tab.createTable();
    tab.putTable(ready);
    tab.lookTable();
    tab.takeTable();
}