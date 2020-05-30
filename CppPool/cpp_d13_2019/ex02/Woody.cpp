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
