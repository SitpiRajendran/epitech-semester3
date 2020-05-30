/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Pin
*/

#include "Pin.hpp"

Pin::Pin(std::size_t pin, Type type, nts::Tristate stat)
{
    _name = pin;
    _type = type;
    _status = stat;
}

Pin::Pin(const Pin&to_copy)
{
    _name = to_copy._name;
    _status = to_copy._status;
    _type = to_copy._type;
}

Pin::~Pin()
{
}

std::unique_ptr<Pin> Pin::getLink()
{
}

Pin& Pin::operator=(const Pin&to_copy)
{
    _name = to_copy._name;
    _status = to_copy._status;
    _type = to_copy._type;
}

void Pin::setLink(Pin pin)
{
    _link = std::make_unique<Pin>(pin);
}