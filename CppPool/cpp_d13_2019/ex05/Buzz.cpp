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

void Buzz::speak(std::string str)
{
    std::cout << "BUZZ: " << _name << " \"" << str << "\"" << std::endl;
}

bool Buzz::speak_es(std::string str)
{
    std::cout << "BUZZ: " << _name << " senorita \"" << str << "\" senorita" << std::endl;
    return true;
}