/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** False
*/

#include "False.hpp"

False::False(std::string name)
{
    _name = name;
    _maxPin = 1;
    _pins.push_back(Pin(1, I));
    _pins[0].setStatus(nts::FALSE);
}

False::~False()
{
}

nts::Tristate False::compute(std::size_t pin)
{
    return _pins[pin].getStatus();
}

void False::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    return;
}

void False::dump() const
{
}

void False::setPins(std::vector<Pin> pin)
{
    if (pin[0].getStatus() == nts::FALSE)
        _pins = pin;
}
