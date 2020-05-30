/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Component
*/

#include "IComponent.hpp"
#include "Component.hpp"
#include "C4001.hpp"

Component::Component()
{
}

nts::Tristate Component::compute(std::size_t pin)
{
    return nts::UNDEFINED;
}

void Component::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
}

void Component::dump() const
{
}

