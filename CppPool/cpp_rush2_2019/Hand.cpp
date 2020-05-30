/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** Hand
*/

#include "Hand.hpp"

Hand::Hand()
{
    this->_object = NULL;
}

Hand::~Hand()
{
}

void Hand::takeObject(Object *object)
{
    if (this->_object != NULL) {
        std::cerr << "There is already an object in their hand!" << std::endl;
        return;
    }
    this->_object = object;
}

Object *Hand::checkHand() const
{
    return (this->_object);
}

Object *Hand::putObject()
{
    Object *object;

    if (this->_object == NULL) {
        std::cerr << "There is nothing in their hand! O_o" << std::endl;
        return (NULL);
    }
    object = this->_object;
    this->_object = NULL;
    return (object);
}