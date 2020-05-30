/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Character
*/

#include <iostream>
#include "Character.hpp"

Character::Character(const std::string &name, int level)
{
    _name = name;
    _level = level;
    _health = 100;
    _power = 100;
    _strength = 5;
    _stamina = 5;
    _intelligence = 5;
    _spirit = 5;
    _agility = 5;

    Range = CLOSE;

    std::cout << _name << " Created" << std::endl;
}

Character::~Character()
{
}

int Character::CloseAttack()
{
    int dammage = 0;

    if (_power < 10) {
        std::cout << _name << " out of power" << std::endl;
        return 0;
    } else {
         _power -= 10;
        dammage = 10 + _strength;
        std::cout << _name << " strikes with a wooden stick" << std::endl;
        return dammage;
    }
}

int Character::RangeAttack()
{
    int dammage = 0;

        if (_power < 10) {
        std::cout << _name << " out of power" << std::endl;
        return 0;
    } else {
         _power -= 10;
        dammage = 5 + _strength;
        std::cout << _name << " tosses a stone" << std::endl;
        return dammage;
    }
}
void Character::Heal()
{
    _health += 50;

    if (_health > 100)
        _health = 100;

    std::cout << _name << " takes a potion" << std::endl;
}

void Character::RestorePower()
{
    _power = 100;

    std::cout << _name << " eats" << std::endl;
}

void Character::TakeDamage(int damage)
{
    _health -= damage;
    if (_health > 0) {
        std::cout << _name << " takes " << damage << " damage" << std::endl;
    } else {
        _health = 0;
        std::cout << _name << " out of combat" << std::endl;
    }
}