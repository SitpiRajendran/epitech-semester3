/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Elf
*/

#include "Hand.hpp"
#include "Elf.hpp"

Elf::Elf()
{
}

Elf::~Elf()
{
}

Object **create_planche(Object *ted, Object *box, Object *gift)
{
    Object **object = new Object*[3];

    object[0] = ted;
    object[1] = box;
    object[2] = gift;

    return object;
}

Object *Elf::MakeToy(Table *tab)
{
    Object **planch;

    if (tab->isToy() >= 0 && tab->isBox() >= 0 && tab->isPaper() >= 0) {
        planch = create_planche(tab->takeTable(tab->isToy()), tab->takeTable(tab->isBox()), tab->takeTable(tab->isPaper()));
        return MyUnitTests(planch);
    } else {
        std::cout << "Missing Items :" << std::endl;
        if (tab->isToy() < 0)
            std::cout << "\tNo Toy" << std::endl;
        if (tab->isBox() < 0)
            std::cout << "\tNo Box" << std::endl;
        if (tab->isPaper() < 0)
            std::cout << "\tNo Paper" << std::endl;

        return NULL;
    }
}

Hand *Elf::UseHand() const
{
    return (this->_hand);
}