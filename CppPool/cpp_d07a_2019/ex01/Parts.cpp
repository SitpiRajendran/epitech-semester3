/*
** EPITECH PROJECT, 2020
** CppPool - D07a
** File description:
** Parts
*/

#include "Parts.hpp"

/**************** ARMS ****************/

Arms::Arms(std::string serial, bool functional)
{
    _serial = serial;
    _functional = functional;
}

Arms::~Arms()
{
}

bool Arms::isFunctional() const
{
    return _functional;
}

std::string Arms::serial() const
{
    return _serial;
}

void Arms::informations() const
{
    std::cout << "\t[Parts] Arms " << _serial << " status : ";
    if (isFunctional() == true) {
        std::cout << "OK" << std::endl;
    } else
        std::cout << "KO" << std::endl;
}

/**************** LEGS ****************/

Legs::Legs(std::string serial, bool functional)
{
    _serial = serial;
    _functional = functional;
}

Legs::~Legs()
{
}

bool Legs::isFunctional() const
{
    return _functional;
}

std::string Legs::serial() const
{
    return _serial;
}

void Legs::informations() const
{
    std::cout << "\t[Parts] Legs " << _serial << " status : ";
    if (isFunctional() == true) {
        std::cout << "OK" << std::endl;
    } else
        std::cout << "KO" << std::endl;
}

/**************** HEAD ****************/

Head::Head(std::string serial, bool functional)
{
    _serial = serial;
    _functional = functional;
}

Head::~Head()
{
}

bool Head::isFunctional() const
{
    return _functional;
}

std::string Head::serial() const
{
    return _serial;
}

void Head::informations() const
{
    std::cout << "\t[Parts] Head " << _serial << " status : ";
    if (isFunctional() == true) {
        std::cout << "OK" << std::endl;
    } else
        std::cout << "KO" << std::endl;
}