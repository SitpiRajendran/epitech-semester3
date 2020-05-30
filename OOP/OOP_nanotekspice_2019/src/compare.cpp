/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** compare
*/

#include "IComponent.hpp"

nts::Tristate and_gate(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::TRUE && b == nts::TRUE)
        return nts::TRUE;
    if (a == nts::FALSE || b == nts::FALSE)
        return nts::FALSE;
    return nts::UNDEFINED;
}

nts::Tristate or_gate(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::TRUE || b == nts::TRUE)
        return nts::TRUE;
    if (a == nts::FALSE && b == nts::FALSE)
        return nts::FALSE;
    return nts::UNDEFINED;
}

nts::Tristate xor_gate(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::UNDEFINED || b == nts::UNDEFINED)
        return nts::UNDEFINED;
    if (a == b)
        return nts::FALSE;
    return nts::TRUE;
}

nts::Tristate nor_gate(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::TRUE || b == nts::TRUE)
        return nts::FALSE;
    if (a == nts::FALSE && b == nts::FALSE)
        return nts::TRUE;
    return nts::UNDEFINED;
}

nts::Tristate nand_gate(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::TRUE && b == nts::TRUE)
        return nts::FALSE;
    if (a == nts::FALSE || b == nts::FALSE)
        return nts::TRUE;
    return nts::UNDEFINED;
}