/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Sorcerer
*/

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title)
{
    _name = name;
    _title = title;

    std::cout << _name << ", " << _title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
    std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same!" << std::endl;
}

void Sorcerer::polymorph(const Victim &victim) const
{
    return victim.getPolymorphed();
}

std::ostream &operator<<(std::ostream &out, const Sorcerer &sorcer)
{
    out << "I am " << sorcer.getName() << ", " << sorcer.getTitle() <<  ", and I like ponies!" << std::endl;
    return out;
}