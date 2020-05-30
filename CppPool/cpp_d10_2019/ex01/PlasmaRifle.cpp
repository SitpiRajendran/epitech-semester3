/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** PlasmaRifle
*/

#include "PlasmaRifle.hpp"
#include "AWeapon.hpp"

PlasmaRifle::PlasmaRifle(const std::string &name, int apcost, int damage) : AWeapon(name, apcost, damage)
{
}

PlasmaRifle::~PlasmaRifle()
{
}

void PlasmaRifle::attack() const
{
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
}