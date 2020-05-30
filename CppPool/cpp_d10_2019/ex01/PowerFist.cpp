/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** PowerFist
*/

#include "PowerFist.hpp"
#include "AWeapon.hpp"

PowerFist::PowerFist(const std::string &name, int apcost, int damage) : AWeapon(name, apcost, damage)
{
}

PowerFist::~PowerFist()
{
}

void PowerFist::attack() const
{
    std::cout << "* pschhh... SBAM! *" << std::endl;
}