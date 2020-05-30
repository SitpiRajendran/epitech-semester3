/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Victim
*/

#include "Victim.hpp"

Victim::Victim(std::string name)
{
    _name = name;
    std::cout << "Some random victim called " << _name << " just popped!" << std::endl;
}

Victim::~Victim()
{
    std::cout << "Victim " << _name << " just died for no apparent reason!" << std::endl;
}

void Victim::getPolymorphed() const
{
    std::cout << _name << " has been turned into a cute little sheep!" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Victim &vict)
{
    out << "I'm " << vict.getName() << " and I like otters!" << std::endl;
    return out;
}