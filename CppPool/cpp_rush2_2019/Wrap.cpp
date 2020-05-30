/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Wrap
*/

#include "Wrap.hpp"

Wrap::Wrap(const std::string &title) : Object(title)
{
    this->_isOpen = true;
}

Wrap::~Wrap(void)
{
}

void Wrap::isTaken(void)
{
    std::cout << "whistles while working" << std::endl;
}

void Wrap::openMe(void)
{
    if (_isOpen)
        std::cerr << "Wrap already open :/" << std::endl;
    else
        _isOpen = true;
}

void Wrap::closeMe(void)
{
    if (!_isOpen)
        std::cerr << "Wrap already close :/" << std::endl;
    else
        _isOpen = false;
}

void Wrap::wrapMeThat(Object *object)
{
    if (!object)
        return;
    if (!_isOpen) {
        std::cerr << "this box is closed :-(" << std::endl;
        return;
    }
    if (this->_object != NULL)
        std::cerr << "There is already something there oO" << std::endl;
    else {
        std::cout << "tuuuut tuuut tuut" << std::endl;
        this->_object = object;
    }
}