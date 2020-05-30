/*
** EPITECH PROJECT, 2020
** CppPool - D08
** File description:
** DroidMemory
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory() : _exp(0), _finger(random())
{
}

DroidMemory::~DroidMemory()
{
}

void DroidMemory::setFingerprint(size_t finger)
{
    _finger = finger;
}

void DroidMemory::setExp(size_t exp)
{
    _exp = exp;
}

size_t DroidMemory::getFingerprint() const
{
    return _finger;
}

size_t DroidMemory::getExp() const
{
    return _exp;
}

DroidMemory &DroidMemory::operator<<(DroidMemory const &right)
{
    setExp(_exp + right.getExp());
    _finger = _finger ^ right.getFingerprint();

    return *this;
}

DroidMemory &DroidMemory::operator>>(DroidMemory &right)
{
    right.setExp(_exp + right.getExp());
    right._finger = right._finger ^ _finger;

    return *this;
}

DroidMemory &DroidMemory::operator+=(DroidMemory &right)
{
    setExp(_exp + right.getExp());
    _finger = _finger ^ right.getFingerprint();

    return *this;
}

DroidMemory &DroidMemory::operator+=(size_t add)
{
    setExp(_exp + add);
    _finger = _finger ^ add;

    return *this;
}

DroidMemory DroidMemory::operator+(DroidMemory &right) const
{
    DroidMemory a;

    a.setExp(_exp + right._exp);
    a.setFingerprint(_finger ^ right._finger);

    return a;
}

DroidMemory DroidMemory::operator+(size_t add) const
{
    DroidMemory a;

    a.setExp(_exp + add);
    a.setFingerprint(_finger ^ add);

    return a;
}

std::ostream &operator<<(std::ostream &out, const DroidMemory &droid)
{
    out << "DroidMemory '" << droid.getFingerprint() << "', " << droid.getExp();
    return (out);
}