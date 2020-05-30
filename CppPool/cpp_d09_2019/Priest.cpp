/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Priest
*/

#include <iostream>
#include "Priest.hpp"

Priest::Priest(const std::string &name, int level) : Mage(name, level)
{
    _strength = 6;
    _stamina = 6;
    _intelligence = 12;
    _spirit = 11;
    _agility = 7;

    std::cout << _name << " enters in the order" <<  std::endl;
}

Priest::~Priest()
{
}

int Priest::CloseAttack()
{
    int dammage = 0;

    if (_power < 30) {
        std::cout << _name << " out of power" << std::endl;
        return 0;
    } else {
         _power -= 30;
        dammage = 10 + _spirit;
        std::cout << _name << " uses a spirit explosion" << std::endl;
        dammage = dammage + 20 + _spirit;
        std::cout << _name << " launches a fire ball" << std::endl;
        return (dammage);
    }
}

int Priest::RangeAttack()
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

void Priest::RestorePower()
{
    _power = 50 + _intelligence;

    std::cout << _name << " takes a mana potion" << std::endl;
}


void Priest::Heal()
{
    if (_power < 10)
        return;
    _power -= 10;
    _health += 70;

    if (_health > 100)
        _health = 100;

    std::cout << _name << " casts a little heal spell" << std::endl;
}