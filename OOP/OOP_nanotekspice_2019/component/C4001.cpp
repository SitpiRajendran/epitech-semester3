/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4001
*/

#include "C4001.hpp"

C4001::C4001(std::string name)
{
    _name = name;
    _maxPin = 12;
    _pins.push_back(Pin(1, I));
    _pins.push_back(Pin(2, I));
    _pins.push_back(Pin(5, I));
    _pins.push_back(Pin(6, I));
    _pins.push_back(Pin(8, I));
    _pins.push_back(Pin(9, I));
    _pins.push_back(Pin(12, I));
    _pins.push_back(Pin(13, I));

    _pins.push_back(Pin(3, O));
    _pins.push_back(Pin(4, O));
    _pins.push_back(Pin(10, O));
    _pins.push_back(Pin(11, O));

    _pins.push_back(Pin(7, U));
    _pins.push_back(Pin(14, U));
}

C4001::~C4001()
{
}

nts::Tristate C4001::compute(std::size_t pin)
{
    _pins[1].setStatus((_pins[1].getLink())->getStatus());
    _pins[2].setStatus((_pins[2].getLink())->getStatus());
    _pins[5].setStatus((_pins[5].getLink())->getStatus());
    _pins[6].setStatus((_pins[6].getLink())->getStatus());
    _pins[8].setStatus((_pins[8].getLink())->getStatus());
    _pins[9].setStatus((_pins[9].getLink())->getStatus());
    _pins[12].setStatus((_pins[12].getLink())->getStatus());
    _pins[13].setStatus((_pins[13].getLink())->getStatus());

    _pins[3].setStatus(xor_gate(_pins[1].getStatus(), _pins[2].getStatus()));
    _pins[4].setStatus(xor_gate(_pins[5].getStatus(), _pins[6].getStatus()));
    _pins[10].setStatus(xor_gate(_pins[8].getStatus(), _pins[9].getStatus()));
    _pins[11].setStatus(xor_gate(_pins[12].getStatus(), _pins[13].getStatus()));

    return _pins[pin].getStatus();
}

void C4001::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    _pins[pin].setLink(other.getPins()[otherPin]);
}

void C4001::dump() const
{
    std::cout << "COMPONENT" << std::endl;
    std::cout << "Name : " << _name << std::endl;
    std::cout << "MaxPin : " << _maxPin << std::endl;
    std::cout << "PINS ::" << std::endl;
}