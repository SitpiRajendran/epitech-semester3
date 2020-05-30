/*
** EPITECH PROJECT, 2020
** CppPool - D08
** File description:
** Droid
*/

#include "Droid.hpp"

Droid::Droid(std::string serial) :
    _attack(25), _toughness(15), _energy(50), _id(serial), _status(new std::string("Standing by")), BattleData(new DroidMemory())
{
    std::cout << "Droid '" << _id << "' Activated" << std::endl;
}

Droid::Droid(Droid const &to_copy) :
    _attack(25), _toughness(15), _energy(50), _id(to_copy._id), _status(new std::string(*to_copy._status)), BattleData(to_copy.BattleData)
{
    std::cout << "Droid '" << _id << "' Activated, Memory Dumped" << std::endl;
}

Droid& Droid::operator=(const Droid&to_copy)
{
    if (this == &to_copy)
        return *this;
    _id = to_copy._id;
    if (_status)
        delete _status;
    _status = new std::string(*to_copy._status);
    BattleData = to_copy.BattleData;
    return *this;
}

Droid::~Droid()
{
    if (_status)
        delete _status;
    std::cout << "Droid '" << _id << "' Destroyed" << std::endl;
}

/************* set *****************/

void Droid::setId(std::string value)
{
    _id = value;
}

void Droid::setEnergy(size_t value)
{
    if (value > 100)
        _energy = 100;
    else
        _energy = value;
}

void Droid::setStatus(std::string *value)
{
    _status = value;
}

/************* get *****************/

std::string Droid::getId() const
{
    return _id;
}

size_t Droid::getAttack() const
{
    return _attack;
}

size_t Droid::getToughness() const
{
    return _toughness;
}

size_t Droid::getEnergy() const
{
    return _energy;
}

std::string *Droid::getStatus() const
{
    return _status;
}

/*************** OPERATORS *********************/


bool Droid::operator==(const Droid &is) const
{
    if (*_status == *is._status)
        return true;
    else
        return false;
}

bool Droid::operator!=(const Droid &is) const
{
        if (*_status != *is._status)
        return true;
    else
        return false;
}

Droid &Droid::operator<<(size_t &add)
{
    size_t needed = 100 - _energy;

    if (add <= needed) {
        _energy += add;
        add = 0;
    } else {
        add -= needed;
        _energy = 100;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Droid &droid)
{
    out << "Droid '" << droid.getId() << "', " << *droid.getStatus() << ", " << droid.getEnergy();
    return out;
}

DroidMemory *Droid::getBattleData() const
{
    return BattleData;
}

void Droid::setBattleData(DroidMemory *value)
{
    BattleData = value;
}

bool Droid::operator()(const std::string* task, size_t exp)
{
    if (_energy < 11) {
        if (_status)
            delete _status;
        _status = new std::string("Battery Low");
        _energy = 0;
        return false;
    } else if (BattleData->getExp() < exp) {
        _energy -= 10;
        BattleData->setExp(BattleData->getExp() + exp);
        if (_status)
            delete _status;
        _status = new std::string(*task + " - Failed!");
        return false;
    } else {
        _energy -= 10;
        BattleData->setExp(BattleData->getExp() + (exp / 2));
        if (_status)
            delete _status;
        _status = new std::string(*task + " - Completed!");
        return true;
    }
}