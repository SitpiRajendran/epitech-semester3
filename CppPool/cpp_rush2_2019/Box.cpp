/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Box
*/

#include "Box.hpp"

Box::Box(const std::string &title) : Wrap(title)
{
    _object = NULL;
    this->_id = this->BOX;
}

Box::~Box()
{
}