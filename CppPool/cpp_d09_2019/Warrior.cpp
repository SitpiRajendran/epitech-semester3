/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Warrior
*/

#include <iostream>
#include "Warrior.hpp"

Warrior::Warrior(const std::string &name, int level, std::string weapon) : Character(name, level)
{
    _strength = 12;
    _stamina = 12;
    _intelligence = 6;
    _spirit = 5;
    _agility = 7;

    weaponName = weapon;
    Range = Character::RANGE;
    std::cout << "I'm " << _name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" <<  std::endl;
}

Warrior::~Warrior()
{
}

int Warrior::CloseAttack()
{
    int dammage = 0;

    if (_power < 30) {
        std::cout << _name << " out of power" << std::endl;
        return 0;
    } else {
         _power -= 30;
        dammage = 20 + _strength;
        std::cout << _name << " strikes with his " << weaponName << std::endl;
        return dammage;
    }
}
int Warrior::RangeAttack()
{
    if (Range == Character::RANGE) {
        if (_power < 10) {
            std::cout << _name << " out of power" << std::endl;
            return 0;
        } else {
            Range = Character::CLOSE;
            _power -= 10;
            std::cout << _name << " intercepts" << std::endl;
            return 0;
        }
    } else
        return (CloseAttack());
}