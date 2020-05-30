/*
** EPITECH PROJECT, 2020
** CppPool - D08
** File description:
** Droid
*/

#include "Droid.hpp"

Droid::Droid(std::string serial) :
    _attack(25), _toughness(15), _energy(50), _id(serial), _status(new std::string("Standing by"))
{
    std::cout << "Droid '" << _id << "' Activated" << std::endl;
}

Droid::Droid(Droid const &to_copy) :
    _attack(25), _toughness(15), _energy(to_copy._energy), _id(to_copy._id), _status(new std::string(*to_copy._status))
{
    std::cout << "Droid '" << _id << "' Activated, Memory Dumped" << std::endl;
}

Droid& Droid::operator=(const Droid&to_copy)
{
    if (this == &to_copy)
        return *this;
    _id = to_copy._id;
    setEnergy(to_copy._energy);
    if (_status)
        delete _status;
    _status = new std::string(*to_copy._status);
    return *this;
}

Droid::Droid(void) :
    _attack(25), _toughness(15), _energy(50)
{
    _id = "";
    _status = new std::string("Standing by");
    std::cout << "Droid '" << _id << "' Activated" << std::endl;
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
    if (_status)
        delete _status;
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
    if (_id == is._id && _energy == is._energy && *_status == *is._status)
        return true;
    else
        return false;
}

bool Droid::operator!=(const Droid &is) const
{
        if (_id != is._id || _energy != is._energy || *_status != *is._status)
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
    if (droid.getEnergy() > 100)
        out << "Droid '" << droid.getId() << "', " << *droid.getStatus() << ", 100";
    else
        out << "Droid '" << droid.getId() << "', " << *droid.getStatus() << ", " << droid.getEnergy();
    return out;
}