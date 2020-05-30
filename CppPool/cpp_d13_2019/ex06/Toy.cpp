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

bool Toy::setAscii(std::string ascii)
{
    if (_file.getPictureFromFile(ascii))
        return true;
    else
        _err.type = _err.PICTURE;
    return false;
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

bool Toy::speak(std::string str)
{
    std::cout << _name << " \"" << str << "\"" << std::endl;
    return true;
}

bool Toy::speak_es(std::string str)
{
    _err.type  = _err.SPEAK;
    return false;
}

std::ostream &operator<<(std::ostream &out, const Toy &droid)
{
    out << droid.getName() << std::endl << droid.getAscii() << std::endl;
    return (out);
}

Toy &Toy::operator<<(const std::string str)
{
    _file.data = str;
    return *this;
}

std::string Toy::Error::what() const
{
    if (type == UNKNOWN)
        return "";
    if (type == SPEAK)
        return "wrong mode";
    if (type == PICTURE)
        return "bad new illustration";
    return "";
}

std::string Toy::Error::where() const
{
    if (type == UNKNOWN)
        return "";
    if (type == SPEAK)
        return "speak_es";
    if (type == PICTURE)
        return "setAscii";
    return "";
}

