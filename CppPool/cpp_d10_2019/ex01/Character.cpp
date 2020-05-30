/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Character
*/

#include "Character.hpp"
#include "AWeapon.hpp"
#include "AEnemy.hpp"
#include <iostream>

Character::Character(const std::string &name)
{
    _name = name;
    _ap = 40;
    _weapon = NULL;
}

Character::~Character()
{
}

void Character::recoverAP()
{
    _ap += 10;
    if (_ap > 40)
        _ap = 40;
}

void Character::attack(AEnemy *enemy)
{
    if (!_weapon || !enemy)
        return;
    if (_ap >= _weapon->getAPCost()) {
        _ap -= _weapon->getAPCost();
        std::cout << _name << " attacks " << enemy->getType() << " with a " << _weapon->getName() << std::endl;
        _weapon->attack();
        enemy->takeDamage(_weapon->getDamage());
        if (enemy->getHP() <= 0)
            enemy->~AEnemy();
    }
}

std::ostream &operator<<(std::ostream &out, const Character &cara)
{
    if (cara.getWeapon())
        out << cara.getName() << " has " << cara.getAP() << " AP and wields a " << cara.getWeapon()->getName() << std::endl;
    else
        out << cara.getName() << " has " << cara.getAP() << " AP and is unarmed" << std::endl;
    return out;
}