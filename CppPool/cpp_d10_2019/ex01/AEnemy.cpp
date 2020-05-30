/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** AEnemy
*/

#include "AEnemy.hpp"

AEnemy::AEnemy(int hp, const std::string &type)
{
    _hp = hp;
    _type = type;
}

AEnemy::~AEnemy()
{
}

void AEnemy::takeDamage(int damage)
{
    if (damage > 0)
        _hp -= damage;
    if (_hp <= 0)
        this->~AEnemy();
}