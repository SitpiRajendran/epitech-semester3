/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** AWeapon
*/

#include "AWeapon.hpp"

AWeapon::AWeapon(const std::string &name, int apcost, int damage)
{
    _name = name;
    _ap = apcost;
    _damage = damage;
}

AWeapon::~AWeapon()
{
}
