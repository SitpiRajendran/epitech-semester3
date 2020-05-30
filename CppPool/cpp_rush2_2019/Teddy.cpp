/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Teddy
*/

#include "Teddy.hpp"

Teddy::Teddy(const std::string &title) : Toy(title)
{
    this->_id = this->TEDDY;
}

Teddy::~Teddy(void)
{
}

void Teddy::isTaken(void)
{
    std::cout << "gra hu" << std::endl;
}