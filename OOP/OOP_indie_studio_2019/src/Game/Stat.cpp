/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** Stat
*/

#include "Stat.hpp"

indie::Stat::Stat()
{
    maxBomb = 1;
    range = 6.f;
    speed = vector3df(0, 0, -0.2);
}

indie::Stat::Stat(const int _maxBomb, const float _range, const vector3df _speed)
{
    maxBomb = _maxBomb;
    range = _range;
    speed = _speed;
}

indie::Stat &indie::Stat::operator=(const Stat &to_cmp)
{
    maxBomb = to_cmp.maxBomb;
    range = to_cmp.range;
    speed = to_cmp.speed;
    return (*this);
}

indie::Stat::~Stat()
{
}

void indie::Stat::setMaxBomb(const int _maxBomb)
{
    maxBomb = _maxBomb;
}

void indie::Stat::setRange(const float _range)
{
    range = _range;
}

int indie::Stat::getMaxBomb() const
{
    return (maxBomb);
}

float indie::Stat::getRange() const
{
    return (range);
}

void indie::Stat::fireUp()
{
    range += 3.f;
}

void indie::Stat::putBomb()
{
    maxBomb--;
}

void indie::Stat::remBomb()
{
    maxBomb++;
}

vector3df indie::Stat::getSpeed() const
{
    return (speed);
}

void indie::Stat::incSpeed()
{
    speed.Z -= 0.05;
}