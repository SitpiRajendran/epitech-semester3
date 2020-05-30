/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** True
*/

#include "True.hpp"

True::True(std::string name)
{
    _name = name;
    _maxPin = 1;
    _pins.push_back(Pin(1, I));
    _pins[0].setStatus(nts::TRUE);
}

True::~True()
{
}

nts::Tristate True::compute(std::size_t pin)
{
    return _pins[pin].getStatus();
}

void True::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    return;
}

void True::dump() const
{
}

void True::setPins(std::vector<Pin> pin)
{
    if (pin[0].getStatus() == nts::TRUE)
        _pins = pin;
}
