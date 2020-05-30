/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** LittlePony
*/

#include "LittlePony.hpp"

LittlePony::LittlePony(const std::string &title) : Toy(title)
{
    this->_id = this->LITTLEPONY;
}

LittlePony::~LittlePony(void)
{
}

void LittlePony::isTaken(void)
{
    std::cout << "yo man" << std::endl;
}