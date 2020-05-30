/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Woody
*/

#include "Woody.hpp"

Woody::Woody(std::string name, std::string ascii)
{
    _name = name;
    _type = WOODY;
    _file = Picture(ascii);
}

Woody::~Woody()
{
}

bool Woody::speak(std::string str)
{
    std::cout << "WOODY: " << _name << " \"" << str << "\"" << std::endl;
    return true;
}