/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Mage
*/

#include <iostream>
#include "Mage.hpp"

Mage::Mage(const std::string &name, int level) : Character(name, level)
{
    _strength = 6;
    _stamina = 6;
    _intelligence = 12;
    _spirit = 11;
    _agility = 7;

    std::cout << _name << " teleported" <<  std::endl;
}

Mage::~Mage()
{
}

int Mage::CloseAttack()
{
    if (_power < 30) {
        std::cout << _name << " out of power" << std::endl;
        return 0;
    } else {
        _power -= 30;
        std::cout << _name << " blinks" << std::endl;
        std::cout << _name << " launches a fire ball" << std::endl;
        return (20 + _spirit);
    }
}

int Mage::RangeAttack()
{
    int dammage = 0;

    if (_power < 25) {
        std::cout << _name << " out of power" << std::endl;
        return 0;
    } else {
        _power -= 25;
        dammage = 20 + _spirit;
        std::cout << _name << " launches a fire ball" << std::endl;
        return dammage;
    }
}

void Mage::RestorePower()
{
    _power = 50 + _intelligence;

    std::cout << _name << " takes a mana potion" << std::endl;
}