/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Output
*/

#include "Output.hpp"

Output::Output(std::string name)
{
    _name = name;
    _maxPin = 1;
    _pins.push_back(Pin(1, O));
}

Output::~Output()
{
}

nts::Tristate Output::compute(std::size_t pin)
{
    _pins[pin].setStatus(_pins[pin].getLink()->getStatus());
    return _pins[pin].getStatus();
}

void Output::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    _pins[pin].setLink(other.getPins()[otherPin]);
}

void Output::dump() const
{
}