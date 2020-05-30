/*
** EPITECH PROJECT, 2020
** CppPool - D07a
** File description:
** KoalaBot
*/

#include "KoalaBot.hpp"

KoalaBot::KoalaBot(std::string serial)
{
    _serial = serial;
}

KoalaBot::~KoalaBot()
{
}

void KoalaBot::setParts(const Arms &arm)
{
    _arm = arm;
}

void KoalaBot::setParts(const Legs &legs)
{
    _leg = legs;
}

void KoalaBot::setParts(const Head &tete)
{
    _head = tete;
}

void KoalaBot::swapParts(Arms &arm)
{
    Arms temp = _arm;

    setParts(arm);
    arm = temp;
}

void KoalaBot::swapParts(Legs &legs)
{
    Legs temp = _leg;

    setParts(legs);
    legs = temp;
}

void KoalaBot::swapParts(Head &tete)
{
    Head temp = _head;

    setParts(tete);
    tete = temp;
}

void KoalaBot::informations() const
{
    std::cout << "[KoalaBot] " << _serial << std::endl;
    _arm.informations();
    _leg.informations();
    _head.informations();
}

bool KoalaBot::status() const
{
    if (_arm.isFunctional() && _leg.isFunctional() && _head.isFunctional())
        return true;
    else
        return false;
}