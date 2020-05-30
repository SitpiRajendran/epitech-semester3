/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Clock
*/

#include "Clock.hpp"

Clock::Clock(std::string name)
{
    _name = name;
    _maxPin = 1;
    _pins.push_back(Pin(1, I));
}

Clock::~Clock()
{
}

nts::Tristate Clock::compute(std::size_t pin)
{
    if (_pins.[0].getStatus() == nts:: )
    _pins.[0].setStatus();
    return _pins[pin].getStatus();
}

void Clock::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    return;
}

void Clock::dump() const
{
}