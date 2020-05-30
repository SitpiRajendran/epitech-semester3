/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy(int type, std::string name, std::string str) : _type(type), _name(name), _file(Picture(str))
{
}

Toy::~Toy()
{
}

void Toy::setName(std::string name)
{
    _name = name;
}

void Toy::setAscii(std::string ascii)
{
    _file = ascii;
    _file.getPictureFromFile(ascii);
}

Toy &Toy::operator=(const Toy &old)
{
    if (this == &old)
        return *this;

    _type = old._type;
    _name = old._name;
    _file = old._file;

    return *this;
}