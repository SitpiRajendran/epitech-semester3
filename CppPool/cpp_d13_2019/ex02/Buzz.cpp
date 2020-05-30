/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Buzz
*/

#include "Buzz.hpp"

Buzz::Buzz(std::string name, std::string ascii)
{
    _name = name;
    _type = BUZZ;
    _file = Picture(ascii);
}

Buzz::~Buzz()
{
}
