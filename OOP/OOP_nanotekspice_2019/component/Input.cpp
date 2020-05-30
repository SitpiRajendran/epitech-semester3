/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Input
*/

#include "Input.hpp"

Input::Input(std::string name)
{
    _name = name;
    _maxPin = 1;
    _pins.push_back(Pin(1, I));
}

Input::~Input()
{
}

nts::Tristate Input::compute(std::size_t pin)
{
    return _pins[pin].getStatus();
}

void Input::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    return;
}

void Input::dump() const
{
}